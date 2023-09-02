# Configuration Management

Configuration management refers to the process by which all artifacts relevant to your project, and the relationships between them, are stored, retrieved, uniquely identified, and modified.

<br>

## Using Version Control

- access to previous versions

- Git

<br>

### _Keep Absolutely Everything in Version Control_

- At the bare minimum, you need **everything** required to **re-create** your application's binaries and the environments in which they run.

- Don't recompilate! Keep the same artifact for the pipeline.

- Don't store the binary output of the build! You should be able to re-create it easily using the automated build system. 

<br>

### _Check In Regularly to Trunk_

- Commit frequently!

- Don't create many branches!

- Merging between very different branches if difficult.

<br>

### _Use Meaningful Commit Messages_

The more detailed, the better!

<br>

## Managing Dependencies

- Libraries are typically deployed in the form of binary files, never changed by your application's dev team, and are updated very infrequently.

- Components and modules are typically under **active development** by other teams and change **frequently**.

### _Managing External Libraries_

- Keep copies of your external libraries somewhere.

- Specify the **exact version** of the external libraries.

<br>

### _Managing Components_

- Split into small components as much as you can!

- Create different pipelines for each, and use the **binary dependencies** between them (NOT source dependencies).

<br>

## Managing Software Configuration

- Treat the configuration of your system the same way you treat your code!

- Make it subject to proper **management** and **testing**.

<br>

### _Configuration and Flexibility_

- Avoid the **antipattern** of **"ultimate configurability"**!

- Test the configuration!

<br>

### _Types of Configuration_

- Configuration information can be injected into your application at several points in your **build, deploy, test, and release** process, and it's usual for it to be included at more than one point.

- Avoid injecting during **build** and **packaging**!

- Supply all configuration information for all the applications and environments in your organization through the **same mechanism**!

<br>

### _Managing Application Configuration_

1. How do you represent your configuration information?

2. How do your deployment scripts access it?

3. How does it vary between environments, applications, and versions of applications?

Configuration information is often modeled as a set of **name-value strings**.

Keep configuration information separate from your source code!

**Don't Check Passwords into Source Control or Hard-Code Them in Your Application!**

<br>

### _Accessing Configuration_

- Via the filesystem

- Fetch configuration from a centralized repository or a web service

Whatever the nature of the configuration information store, **insulate** the detail of the technology from your application with a simple **façade** class.

<br>

### _Modeling Configuration_

The configuration for an application consists of a set of tuples.

The set of the tuples and their values typically depend on 3 things:

- The application

- The version of the application

- The environment it runs in (development, UAT, performance, staging, or production)

<br>

### _Testing System Configuration_

There are 2 parts to testing configuration:

1. Ensure that the references to external services in your configuration settings are good (pinging all external services is a great **smoke test**)

2. Run smoke tests once the application is installed to make sure it is operating as expected (just a few tests exercising functionality that depends on the configuration being correct)

<br>

### _Managing Configuration across Applications_

- It's important to know what the current configuration of each running application is.

- If possible, make the applications in your ecosystem use the same configuration management method.

<br>

### _Principles of Managing Application Configuration_

- Use the DRY (Don't Repeat Yourself) principles: define elements of your configuration so that each concept has only one representation in the set of configuration information!

- Be minimalist: keep the configuration as simple and as focused as possible!

- Avoid **overengineering**!

<br>

## Managing Your Environments

- The key to managing environments is to make their creating a **fully automated process**.

- **Creating** a new environment should always be **cheaper** than **repairing** an old one.

- Make copies of **production environments**.

- In terms of software configuration, testing environments should be exact replicas of the production ones, so configuration problems can be found early.

- There are 2 principles that form the basis of an effective configuration management strategy:

  1. Keep binary files **independent** from configuration information!
 
  2. Keep all configuration information in **one place**!

- When evaluating third-party products and services, ask the following questions:

  1. Can we deploy it?
 
  2. Can we version its configuration effectively?
 
  3. How will it fit into our automated deployment strategy?
 
<br>

### _Tools to Manage Environments_

- Terraform

- easy to replicate new environments

<br>

### _Managing the Change Process_

- A production environment should be **completely locked down**!

- It should not be possible for **anybody** to make a change to it without going through your organization's change management process.

- Testing environments must go through the same configuration management mechanism as the production environment.

- This does not mean that they should be clones of expensive production environments.

<br>

## Summary

<br>

You should be able to answer "yes" to the following questions:

1. Could you completely **re-create** your production system, excluding production data, from scratch from the version-controlled assets that you store?

2. Could you **regress** to an earlier, known good state of your application?

3. Could you be sure that each deployed environment in production, in staging, and in test is set up in precisely the same way?

<br>

Have a strategy for storing **baselines** and controlling changes to:

- Your application's source code, build scripts, tests, documentation, requirements, database scripts, libraries, and configuration files

- Your development, testing, and operations toolchain

- All environments used in development, testing, and production

- The entire aplication stack associated with your applications - both binaries and configuration

- The configuration associated with every application in every environment it runs in, across the entire application lifecycle (building, deployment, testing, operation)
