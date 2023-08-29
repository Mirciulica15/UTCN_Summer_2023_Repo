# Anatomy of the Deployment Pipeline

CI is not enough, it mainly focuses on **development** teams.

Much of the waste in releasing software comes from the progress of software through testing and operations.

<br>

## What Is a Deployment Pipeline?

A deployment pipeline is **an automated manifestation of your process for getting software from version control into the hands of your users**.

When deployment and production release are **automated**, they are **rapid, repeatable and reliable**.

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/a4335c19-97c4-4cad-80fe-e14b18f1a5cb)

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/de22684d-6299-4429-b82a-b7b21b5353f8)

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/362c87f9-46d2-468e-a5fb-9881df6d5ee8)

1. **_The commit stage_** asserts that the system works at the technical level (compiles, passes a suite of primarily unit-level automated tests, and runs code analysis)

2. **_Automated acceptance test stages_** assert that the system works at the functional and nonfunctional level

3. **_Manual test stages_** assert that the system is usable and fulfills its requirements (typically includes exploratory, integration and UAT testing)

4. **_Release stage_** delivers the system to users

<br>

### _A Basic Deployment Pipeline_

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/a3190f44-242c-4eed-9674-cf19544c54a6)

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/243107da-3485-4069-80af-564c49f4829c)

<br>

## Deployment Pipeline Practices (IMPORTANT !!!)

<br>

### _Only Build Your Binaries Once_

Not following this practice creates the **Rebuilding-from-Source Antipattern**.

This antipattern violates 2 important principles:

1. Keep the deployment pipeline **efficient**, so the team gets **feedback** as soon as possible.

2. Build upon foundations **known to be sound**.

You shouldn't bother to make sure binaries are backed up - it should be possible to exactly re-create them by running your automated build process from version control.

<br>

### _Deploy the Same Way to Every Environment_

By the time you get to **production**, you will have already **rehearsed** dozens of times in other environments.

This way, if a specific deployment doesn't work to a **particular environment** you can narrow it down to one of 3 **causes**:

1. A setting in your application's environment-specific configuration file

2. A problem with your infrastructure or one of the services on which your application depends

3. The configuration of your environment

<br>

### _Smoke-Test Your Deployments_

Simple test to check that the app and its services are **up and running**.

<br>

### _Deploy into a Copy of Production_

Make sure that:

1. **Network topology and firewall configuration** is the same

2. **OS configuration, including patches** is the same

3. **Application stack** is the same

4. The application's data is in a **known, valid state**. Migrating data when performing upgrades can be a major **source of pain**.

<br>

### _Each Change Should Propagate through the Pipeline Instantly_

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/de056fb3-3f8b-4c88-9604-947c421410cf)

<br>

### _If Any Part of the Pipeline Fails, Stop the Line_

The **whole team** owns the failure.

Stop and fix it before doing anything else!

<br>

## The Commit Stage

The aim of the first stage is to **eliminate builds** that are unfit for production and **signal breakage** as quickly as possible.

The **commit stage** typically includes the following steps:

1. **Compile** the code (if necessary)

2. Run a set of **commit tests**

3. Create **binaries** for use by later stages

4. Perform **analysis** of the code to check its health

5. Prepare **artifacts**, such as test databases, for use by later stages

<br>

Useful **metrics** include:

- Test coverage

- Amount of duplicated code

- Cyclomatic complexity

- Afferent and efferent coupling

- Number of warnings

- Code style

<br>

### _Commit Stage Best Practices_

Most of the practices in **Chapter 3 - Continuous Integration** apply to the **commit stage**.

Developers are expected to **wait** until the commit stage of the deployment pipeline **succeeds**.

The term **"deployment pipeline"** originates from how CPUs pipeline their instructions.

<br>

## The Automated Acceptance Test Gate

**Unit tests** are great and fast, but they are **not enough**.

Acceptance Tests can be broken into different parallel jobs if they require a substantial amount of time.

They include both **functional** and **nonfunctional** tests.

<br>

### _Automated Acceptance Test Best Practices_

Make sure the **developers** are **closely involved** in writing the tests.

_The whole team owns the acceptance tests._

Abstraction should work at the level of **business behaviour** ("place order" rather than "click order button").

<br>

## Subsequent Test Stages

- Continuous Deployment (to production)

- Production once you deployed to UAT and staging

<br>

### _Manual Testing_

- **exploratory** testing

- **usability** testing

- **showcases**

**Automated** acceptance testing frees up **time** for testers so they can **concentrate** on **high-value activities**, such as the previously mentioned tests.

<br>

## Preparing to Release

1. Have a **release plan** involving **everybody**

2. Minimize the effect of people making **mistakes** by **automating**

3. **Rehearse** the procedure in **production-like environments**

4. Have the ability to **back out** a release

5. Have a strategy for **migrating configuration** and **production data** as part of the upgrade and rollback processes

<br>

### _Automating Deployment and Release_

**Production environments should be completely locked down.**

<br>

### _Backing Out Changes_

**Blue Green**

Always roll back by either **keeping an old version** of the application deployed or by completely redeploying a previous **known-good state**.

<br>

### _Building on Success_

By the time a **release candidate** is available for deployment into production, we will know with certainty that:

- The code can **compile**

- The code does what our developers think it should because it passed its **unit tests**

- The system does what our analysts or users think it should because it passed all of the **acceptance tests**

- **Configuration of infrastructure and baseline environments** is managed appropriately, because the application has been tested in an analog of production

- The code has all the right components in place because it was deployable

- The **deployment system** works

- The version control system holds everything we need to deploy

_"Building upon success"_

<br>

## Implementing a Deployment Pipeline

1. Model your **value stream** and create a **walking skeleton**.

2. Automate the **build** and **deployment** process.

3. Automate **unit tests** and **code analysis**.

4. Automate **acceptance tests**.

5. Automate **releases**.

<br>

### _Modeling Your Value Stream and Creating a Walking Skeleton_

Start from a **basic _Hello world_ application** and create a **pipeline** with a **simple test** for it.

Use the _"bare minimum"_ example.

Add **placeholders** for stages in your pipeline and step by step make them actually do something.

<br>

### _Automating the Build and Deployment Process_

At the **push of a button**, take the "binaries" from the CI pipeline and use them for **deployment**.

<br>

### _Automating the Unit Tests and Code Analysis_

A full commit stage means running unit tests, code analysis, and ultimately a selection of acceptance and integration tests on every check-in.

Once the commit stage gets over 5 minutes, it makes sense to split it into suites that run in parallel.

<br>

### _Automating Acceptance Tests_

A good set of automated acceptance tests will help you track down **intermittent** and **hard-to-reproduce** problems such as **race conditions, deadlocks, and resource contention**.

<br>

### _Evolving your Pipeline_

Once the project gets bigger, we might need to split in into **components** and have a **pipeline** for each of them.

**The deployment pipeline is a living system.**

As you work continuously to improve your delivery process, you should continue to **take care** of your deployment pipeline, working to **improve** and **refactor** it.

<br>

## Metrics

**Make feedback cycles short and the results visible.**

What should you measure? -> [Hawthorne effect](https://en.wikipedia.org/wiki/Hawthorne_effect)

- lines of code

- number of defects fixed

- etc

You need to remove the **bottleneck** that is **constraining** your delivery process.

The most important global metric is **CYCLE TIME**.

You need to use the [Theory of Constraints](https://www.leanproduction.com/theory-of-constraints/):

1. Identify the **limiting constraint** on your system.

2. **Exploit** the constraint. Maximize the **throughput** of that part of the process.

3. **Subordinate** all other processes to the constraint.

4. **Elevate** the constraint. If **cycle time** is still too long, you need to **increase the resources available** (hire more, invest more effort in automating, etc)

5. **Rinse and repeat.**

<br>

There are also a number of other _diagnostics_ that can warn you of problems:

- Automated test coverage

- Properties of the code (duplication, cyclomatic complexity, efferent and afferent coupling, style problems, etc)

- Number of **defects**

- **Velocity**, the rate at which the team delivers ready for use code

- Number of **commits** to VCS per day

- Number of **builds** per day

- Number of **build failures** per day

- **Duration** of build, including automated tests

Create **visualizations** that aggregate the data and present them in a form where humans can use their **pattern-matching skills**.

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/f8568c10-97ec-4813-850a-df299b623572)

<br>

## Summary

- Give everyone involved in delivering software **visibility** into the progress from check-in to release

- Implement a **deployment pipeline**

- This will enforce good practices
