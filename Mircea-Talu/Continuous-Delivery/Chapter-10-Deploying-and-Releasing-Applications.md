# Deploying and Releasing Applications

The main difference between deploying and releasing is the ability to **roll back**.

<br>

## Creating a Release Strategy

The application's **stakeholders** need to meet up and work out a **common understanding** concerning the deployment and maintenance of the application throughout its lifecycle.

A vital component of the release strategy is the **release plan** describing how releases are performed.

### _The Release Plan_

The **first** release is usually the one which carries the most risk.

The results of this planning may be **automated scripts, documentation** or other procedures needed to **reliably** and **repeatedly** deploy the application into the production environment.

This **plan** will need to be **maintained** as the project progresses and **new insights** are gained.

<br>

### _Releasing Products_

For software destined to be released as a **commercial product**, you need to consider the following:

- Pricing model

- Licensing strategy

- Copyright issues around third-party technologies used

- Packaging

- Marketing materials

- Product documentation

- Installers

- Preparing sales and support teams

<br>

## Deploying and Promoting Your Application

Use the **same process** to deploy to every environment.

### _The First Deployment_

Choose one or two **requirements** that are of **high priority** but very simple to deliver in your first iteration (you should choose more if your team is bigger).

Use this **showcase** as a reason to make the application deployable to a production-like environment like UAT.

The principal **goal** of the first iteration of a project is to get the early stages of the **deployment pipeline** running and to be able to deploy and demonstrate _something_, no matter how small.

_How different is my environment from the production environment?_

- use the **same OS**

- if the prod has a cluster, build a **small, limited cluster** for your environment

- if the prod environment is a **distributed** one with many different nodes, make sure your environment has **at least one** separate process

**Virtualization** and **chicken-counting (0, 1, many)** are your friends here. _(if many, 2 should be enough)_

<br>

### _Modeling Your Release Process and Promoting Builds_

- **stages**

- **gates**

- **authority** to pass through gates

![image](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/5414410f-d8ac-4b8a-94b8-336ffc3d6ea7)

Each of the people deploying (to testing, staging, prod, etc) can **select** the version of the application they want to deploy into their environment.

It must be **simple to use**. (just click a button)

<br>

### _Promoting Configuration_

Make **smoke tests** that verify that you are pointing at the right things.

In the case of service-oriented architectures and componentized applications, all the services or components need to be **promoted together**. -> _System integration testing environment_

<br>

### _Orchestration_

Sometimes environments are **shared** between several applications.

Solutions:

- **Virtualization**

- **System integration testing**

<br>

### _Deployments to Staging Environments_

Perform some **final tests** in a **staging** environment that is very **similar** to production.

Measure the **warm-up period** for your application.

A **warm-up period** is necessary to make sure that the state of server resources, such as **memory** or **cache**, is prepared for the normal operating mode.

<br>

## Rolling Back Deployments and Zero-Downtime Releases

There are 2 important **constraints**:

- data (if the release process makes **changes** to your data, it can be **hard** to roll back)

- other systems you integrate with

There are 2 general **principles** you should follow when creating a **plan** for rolling back a release:

- ensure that the **state** of your production system, including databases and state held on the filesystem, is **backed up** before doing a release

- **practice** your rollback plan, including **restoring** from the backup or **migrating** the database

<br>

### _Rolling Back by Redeploying the Previous Good Version_

It is the **same process** you have tested hundreds of times before.

**Rollbacks** are performed much **less frequently**, and therefore are more likely to contain bugs.

However, it takes **time** to redeploy the old version -> **downtime**

You will **lose data** created following the deployment.

<br>

### _Zero-Downtime Releases_

A **zero-downtime release**, also known as hot deployment, is one in which the actual process of **switching users** from one release to another happens nearly **instantaneously**.

### _Blue-Green Deployments_

![image](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/647adbd1-57c8-4428-b8c4-742e13d4491c)

Deploy into the **blue environment**, let the application **warm up**.

This does **not affect** the green environment.

When we're ready, simply change the **router configuration** to point to blue instead of green.

If something goes wrong, simple **switch back** to green.

One problem is **migrating data**.

Solution: Shortly before switchover, put the application in **read-only** and migrate the data. If everything checks out, put it back in **read-write**.

You can use your **staging** environment as the **blue** environment and simply switch between **staging** and **production**.

<br>

### _Canary Releasing_

![image](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/53d5653b-1cce-4b3e-a4a6-8900c5dd3bdf)

Can be used for **capacity** testing.

You can use it for **A/B testing**.

You can **gradually** ramp up the **load**, measuring the response time and metrics, and watching the logs.

You can have **multiple** versions in production, but the recommendation is to **keep it at 2**.

<br>

## Emergency Fixes

**Do not, under any circumstance, subvert your process.**

Emergency fixes have to go through the **same process** as any other change.

Changes made directly into production makes them **not tested properly** and puts the environment in an **unknown, impossible to reproduce state**.

Good practices for production deployments:

- Never do them **late** at night, and always **pair** with somebody else

- Make sure you have **tested** your emergency fix process

- Only under **extreme** circumstances circumvent the usual process

- Make sure you have tested making an emergency fix using your **staging** environment

- Sometimes it's better to **roll back**

<br>

## Continuous Deployment

Motto of Extreme Programming: **_if it hurts, do it more often!_**

Deploy every **change** that **passes** your automated tests to production.

The crucial point is that it is continuous deployment to **_production_**.

Continuous deployment is **not for everyone**, but it is a great way to _reduce_ the risk for any particular release, since changes are **smaller**.

<br>

### _Continuously Releasing User-Installed Software_

There are several **issues** to consider:

- Managing the **upgrade experience**

- **Migrating** binaries, data, and configuration

- **Testing** the upgrade process

- Getting **crash reports** from users

A serious issue is managing the large number of versions of your software that, over time, end up in the wild.

There are several ways in which clients can handle the upgrade process:

1. Have your software check for new versions and prompt the user to download and install.

2. Download in the background and prompt for installation.

3. Download in the background and silently install the next time the app is restarted.

The correct option is **option 3**.

Giving users a **choice** simply tells them that the developers have **no confidence** in the upgrade process.

Make the upgrade process **bullet proof**.

You can create a new directory and simple change the **symbolic link** in UNIX systems to the new version.

**Report crashes** (they can be caused by user's sytem: broken software, out-of-memory conditions, foreign-language OSs, etc).

<br>

## Tips and Tricks

### _The People Who Do the Deployment Should be Involved in Creating the Deployment Process_

**Things Go Better When Development and Operations are Friends!**

<br>

### _Log Deployment Activities_

<br>

### _Don't Delete the Old Files, Move Them_

<br>

### _Deployment Is the Whole Team's Responsibility_

A "build and deployment expert" is an **antipattern**.

<br>

### _Have a Warm-Up Period for a New Deployment_

Many applications have **internal caches** that are eagerly filled at deployment time.

Until the caches are full, the application will often have a **poor response time** and may even fail.

<br>

### _Fail Fast_

Production environments should be completely **locked down**, so that only the **deployment pipeline** can make changes to it.

<br>

### _Don't Make Chages Directly on the Production Environment_

**Audit everything!**

<br>

## Summary

Your implementation should make it **possible** to deploy **any version** of your app that has made it past the automated tests into any of your environments at the **push of a button**.

**Rehearse releases!**

The **release strategy** should **evolve** over time.

Assemble **representatives** from every part of your organization involved in delivery: build, infrastructure, operations teams, dev teams, testers, DBAs, support personnel.
