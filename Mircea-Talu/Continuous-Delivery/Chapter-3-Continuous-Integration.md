# Continuous Integration

In many software projects, the application is **not in a working state** for long periods of time during the development process.

They often schedule **lengthy integration phases at the end of development** to allow the development team time to get the branches merged and the application working so it can be acceptance-tested.

The goal of continuous integration is that the **software is in a working state all the time**.

"Continuously is more often than you think!" -> Every time someone **commits** a change to version control.

<br>

## Implementing Continuous Integration

<br>

### _What You Need Before You Start_

1. Version Control

2. An Automated Build

3. Agreement of the Team: **Continuous integration is a practice, not a tool.**

<br>

### [_A Basic Continuous Integration System_](https://www.jamesshore.com/v2/blog/2006/continuous-integration-on-a-dollar-a-day)

<br>

## Prerequisites for Continuous Integration

<br>

### _Check in Regularly_

- Frequent check-ins to trunk or mainline (at least a couple of times a day)

- Long-lived branches are not recommended

<br>

### _Create a Comprehensive Automated Test Suite_

There are 3 tests we are interested in running from our CI build:

- **Unit tests**:
  + test behaviour of small pieces of your application in isolation
  + they can usually run without starting the whole application
  + they don't hit the database, the filesystem, or the network
  + they run very fast

- **Component tests**:
  + test the behaviour of several componenets
  + they don't always require starting the whole application
  + they might hit the database, the filesystem, or other system
  + they typically take longer to run

- **Acceptance tests**
  + test that the application meets the acceptance criteria decided by the business
  + both functional and non-functional
  + they run against the whole application is a production-like environment
  + they can take a long time to run
 
These 3 sets of tests, combine, provide an extremely **high level of confidence** that any introduced change has not broken existing functionality.

<br>

### _Keep the Build and Test Process Short_

They shouldn't take a long time, because this discourages frequent commit and check-in.

It's good practice to add a **simple smoke test suite** into the commit stage; this smoke test should perform a few simple acceptance and integration tests to make sure that the most commonly used functionality isn't broken.

<br>

### _Managing Your Development Workspace_

Developers should always work from a **known-good starting point** when they begin a fresh piece of work.

Running the application in a local environment should use the **same automated processes** that are used in the CI and testing environments and ultimately in production.

A sign of a good application architecture is that it allows the application to be run without much trouble on a development machine.

<br>

## Using Continuous Integration Software

<br>

### _Basic Operation_

CI server software has 2 components:

1. A long-running process which can execute a simple workflow at regular intervals

2. Provides a view of the results of the processes that have been run, notifies the success or failure of the build and test runs, providing access to test reports, installers, and so on

<br>

### _Bells and Whistles_

Notify the current state of the build!

<br>

## Essential Practices

CI requires a significant degree of **discipline from** the development team as a whole.

<br>

### _Don't Check In on a Broken Build_

<br>

### _Always Run All Commit Tests Locally before Commiting, or Get Your CI Server to Do It for You_

When developers are ready to commit, they should **refresh their local copy of the project by updating (pulling)** from the version control system.

Then, they should **initiate a local build and run the commit tests**.

Only when this is successful is the developer **ready to commit** the changes to the VCS.

<br>

### _Wait for Commit Tests to Pass before Moving On_

**Pay attention** to the state of the pipeline, don't go for lunch!

<br>

### _Never Go Home on a Broken Build_

Either **fix the issues**, or **revert to a previously known-good state**!

**Don't commit right before leaving work!** (You need time to fix the issues)

**Build Discipline on Distributed Projects!**

<br>

### _Always Be Prepared to Revert to the Previous Revision_

You should assume that your commit will fail and you must be ready to revert.

<br>

### _Time-Box Fixing before Reverting_

Establish a team rule: **If the build breaks on check-in, try to fix it for 10 minutes. If, after 10 minutes, you aren't finished with the solution, revert to the previous version from your VCS.**

<br>

### _Don't Comment Out Failing Tests_

You should **very rarely** comment out tests.

It's better to **modify** them, or **delete** them.

You can also set a **threshold**: If more than 2% of the tests are commented out, the build should fail.

<br>

### _Take Responsability for All Breakages That Result from Your Changes_

If you introduced a [regression bug](https://en.wikipedia.org/wiki/Software_regression), it's your **responsability** to fix it.

<br>

### _Test-Driven Development (TDD)_

**First create a test** that is an executable specification of the **expected behaviour of the code** to be written.

<br>

## Suggested Practices

<br>

### _Extreme Programming (XP) Development Practices_

**Refactoring** means making a series of **small, incremental changes** that **improve** your code without changing your **application's behaviour**.

<br>

### _Failing a Build for Architectural Breaches_

- Enforcing Remote Calls at Build Time (example: business logic executed in client systems, real business logic executed at the server too => need remote calls, rather than local)

<br>

### _Failing the Build for Slow Tests_

CI works best with **small, frequent commits** => if commit tests take a **long time** to run, it has a **detrimental effect on productivity**.

Developers should write **quick tests**!

<br>

### _Failing the Build for Warnings and Code Style Breaches_

This might seem like a draconian practice, often labeled as "code Nazi".

But, it enforces **good practices** in the team, ensuring **high-quality** code.

One approach worth mentioning is **ratcheting**. This means comparing the number of things like warnings or TODOs with the number in the previous check-in.

Using this approach, you can easily **enforce a policy** that every commit should **reduce** thhe number of warnings or TODOs at least by one.

<br>

## Distributed Teams

<br>

### _The Impact on Process_

**Instant messaging** (Teams) is of enormous importance to enable **fine-grained communications** necessary to keep things running smoothly.

<br>

### _Centralized Continuous Integration_

It's essential that development teams can **easily self-service** new environments, configurations, build, and deployments in an **automated** fashion.

<br>

### _Technical Issues_

You have to provide **sysadmin-level access** to all of the systems from every location.

<br>

## Distributed Version Control Systems (DVCS)

Git makes it **incredibly easy to pull patches** back and forth between developers and teams and to **branch and merge** work streams.

DVCS allow you to **work easily offline, commit changes locally, and rebase or shelve** them before pushing them to other users.

The core characteristic of a DVCS is that every repo contans the **entire history** of the project => no repo is privilged except by convention.

Fork -> Make changes -> Ask the owners of the original repo to pull your changes.

However, this model challenges a **fundamental assumption** of the practice of CI: That there is a **single, canonical version of code**.

<br>

## Summary

Without CI, your application is **broken** until you prove otherwise.

With CI, the default state of your application is **working**, albeit with a level of confidence that depends upon the extent of your automated test coverage.

CI creates a **tight feedback loop** which allows you to find problems as soon as they are introduced, when they are **cheap to fix**.

An established CI system is a foundation on which you can build more infrastructure:

- Big visible displays which **aggregate information** from your build system to provide **high-quality feedback**

- A system of reference for **reports** and **installers** for your testing team

- A provider of **data on the quality of the application** for project managers

- A system that can be **extended out to production**, using the **deployment pipeline**, which provides testers and operations staff with **push-button deployments**
