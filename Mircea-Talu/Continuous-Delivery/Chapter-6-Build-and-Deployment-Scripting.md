# Build and Deployment Scripting

On simple projects, building and testing the software can be accomplished using the capabilities of your IDE.

However, this is not enough as the application gets bigger and is split into **components**.

The **first step** is easy. Every modern platform has a way to **run the build** from the **command line**.

<br>

## An Overview of Build Tools

All build tools have a common core: they allow you to model a **dependency network**.

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/bdab86c5-6a99-448d-8a0c-6f27d9987395)

There are 2 types of build tools:

- _task-oriented_:
  + each task will know whether or not it has already been **executed** as part of the build

- _product-oriented_:
  + the world is modeled as a **set of files**
  + a **target** is executed only if the timestamp of the dependencies is later than its timestamp
  + this is very useful because it is ensured that you **only** compile source code files that have **changed** since the last time the build was run
 
<br>

### _Make_

- Product-oriented build tool

- Makefiles

<br>

### _Ant_

- Java

- XML -> **declarative language**

<br>

### _NAnt and MSBuild_

- for the .NET framework

<br>

### _Maven_

- makes **assumptions** about structure and lifecycle

- **self-updating** each time it is run

<br>

### _Buildr_

- drop-in replacement for Maven

<br>

### _Psake_

- internal DSL written in PowerShell for Windows

<br>

## Principles and Practices of Build and Deployment Scripting (IMPORTANT !!!)

### _Create a Script for Each Stage in Your Deployment Pipeline_

Keep all your scripts in a version control **repository**, preferably the same one that your **source code** lives in.

It is essential for **developers** and **operations** people to be able to **collaborate** on build and deployment scripts.

<br>

### _Use an Appropriate Technology to Deploy Your Application_

Use the **right tool** for the job when automating deployment, **not a general-purpose** scripting language (unless the deployment process is extremely simple).

Example: If you're using the WebSphere Application Server, use the Wsamin tool

<br>

### _Use the Same Scripts to Deploy to Every Environment_

**Differences** between **environments** must be managed separately as **configuration information**.

We must be able to deploy on **developer machines**, as well as on **production-like environments**.

<br>

### _Use Your Operating System's Packaging Tools_

If you're targeting a single operating system, use that OS's **packaging technology** to bundle up everything that needs to be deployed.

<br>

### _Ensure the Deployment Process is Idempotent_

**Always the same result, no matter how many times we run the script**

- Deploy the application as a whole

- Or, if it has many components, and **the combination of components has been tested in a previous environment**, we can deploy

<br>

### _Evolve Your Deployment System Incrementally_

The deployment process looks very **complex** from the outside.

In fact, if you examine one of the deployment systems, it is merely a collection of very **simple, incremental steps**, that, over time, create a **sophisticated** system

<br>

## Project Structure for Applications That Target the JVM

### _Project Layout_

This is the project **layout** assumed by **Maven**.

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/686c4eaf-6899-41ca-9cb4-05e1e9bd508a)

<br>

### _Managing Source Code_

- use naming **conventions**

- keep your files in directories named after the **package** that they contain

- any generated configuration or metadata should **not** be in the _src_ directory; instead, put them in the _target_ directory => **deleted** when you run a clean build, **don't check** them into VC

<br>

### _Managing Tests_

- source code for tests goes into the _test/language_ directory

- tests for a given class should be in the **same package** as that class

<br>

### _Managing Build Output_

- when Maven builds your project, it puts everything in the _target_ directory

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/93b10ebe-737f-4898-a41f-df7b56d392f6)

- the build process should ultimately **generate binaries** in the form of JARs, WARs, and EARs

<br>

### _Managing Libraries_

2 options:

- **delegate** library management to a tool like Maven

- **check into** source control all the libraries your project requires to build, test, or run the system (put them into a directory called _lib_)

<br>

## Deployment Scripting

**Changes to testing and production environments should only be made through an automated process.**

### _Deploying and Testing Layers_

You should always strive to build on **foundations** that are **known to be good**.

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/d9ab547c-d63c-42e0-9d81-f067472239d4)

<br>

### _Testing Your Environments's Configuration_

Create very simple **smoke tests** that assert the presence or absence of key resource.

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/48998bf2-8f6d-4cda-b2cd-cb3c99a499d2)

Check every **tier** of your _N-Tier Architecture_.

<br>

## Tips and Tricks

### _Always Use Relative Paths_

Using **absolute** paths creates a **tight** dependency between the configuration of a specific machine and your build process.

However, there are some unique situations when this is **very difficult to avoid**.

<br>

### _Eliminate Manual Steps_

Q: When should you think about **automating** a process?

R: **When you have to do it a second time.**

<br>

### _Build In Tracebility from Binaries to Version Control_

It's essential to be able to **determine** from any given binary which revision in version control was used to generate it.

<br>

### _Don't Check Binaries into Version Control as Part of Your Build_

The general rule is **not to check in** anything _created_ as part of your build, test, and deploy cycle into source control.

<br>

### _Test Targets Should Not Fail the Build_

**Flag** them and let them run **until the end** in order to see all the failed tests.

<br>

### _Constrain Your Application with Integrated Smoke Tests_

Make deployment scripts **check** that they are running on the **correct machine** before deploying.

<br>

## Summary

- by "script", we generally mean all the **automation** that helps us build, test, deploy, and release our software

- each task is **simple**, and the process itself is not a complex one

- involve both **developers** and **operations** in the creation of these mechanisms

- scripts are **_first-class_** parts of your system, they should live for its **entire life**

- they should be **version-controlled, maintained, tested, and refactored**

- they should be the **only** mechanism that you use to deploy your software
