# Introduction

In the modern era, software is commonly delivered as a service: called _web apps_, or _software-as-a-service (SaaS)_.

The twelve-factor app is a methodology for building software-as-a-service apps that:
- Use declarative formats for setup automation, to minimize time and cost for new developers joining the project
- Have a clean contract with the underlying operating system, offering maximum protability between execution environments
- Are suitable for deployment on modern cloud platforms, obviating the need for servers and systems administration
- Minimize divergence between deployment and production, enabling continuous deployment for maximum agility
- And can scale up without significant changes to tooling, architecture, or development practices

The twelve-factor methodology can be applied to apps written in any programming language, and which use any combination of backing services (database, queue, memory cache, etc).

<br>

# I. Codebase

### _One codebase tracked in revision control, many deploys_
A twelve-factor app is always tracked in a version control system, such as Git.
A copy of the revision tracking database is known as a _code repository_.

<br>

A _codebase_ is any single repo, or any set of repos who share a root commit.

<br>

There is always a **one-to-one** correlation between the codebase and the app:
  - If there are multiple codebases, it’s not an app – it’s a distributed system. Each component in a distributed system is an app, and each can individually comply with twelve-factor.
  - Multiple apps sharing the same code is a violation of twelve-factor. The solution here is to factor shared code into libraries which can be included through the dependency manager.
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/2d8ff907-2543-47e8-8870-ec1723231432)

<br>

There is only one codebase per app, but there will be many **deploys** of the app. A **deploy** is a running instance of the app.
This is typically a production site, and one or more staging sites.
Additionally, every developer has a copy of the app running in their local development environment, each of which also qualifies as a deploy.

<br>

<br>

# II. Dependencies

### _Explicitly declare and isolate dependencies_
Most programming languages offer a packaging system for distributing support libraries.

<br>

**A twelve-factor app never relies on implicit existence of system-wide packages.**
It declares all dependencies, completely and exactly, via a _dependency declaration_ manifest.
Furthermore, it uses a _dependency isolation_ tool during execution to ensure that no implicit dependencies "leak in" from the surrounding system.
The full and explicit dependency specification is applied uniformly to both production and development.
Example: In Python there are 2 separate tools - Pip is used for declaration and Virtualenv for isolation.
No matter the toolchain, dependency **declaration** and **isolation** must **always** be used **together**.

<br>

<br>

# III. Config

### _Store config in the environment_
An app's _config_ is everything that is likely to vary between deploys (staging, production, developer environments, etc).
This includes:
- Resource handles to the database, Memcached, and other backing services
- Credentials to external services such as Amazon S3 or Twitter
- Per-deploy values such as the canonical hostname for the deploy

Apps sometimes store config as constants in the code. This is a **violation** of twelve-factor, which requires **strict separation of config from code**.
Config varies substantially across deploys, code does not.

<br>

**The twelve-factor app stores config in _environment variables_**.
Environment variables are easy to change between deploys without chaning any code; unlike config files, there is little chance of them being checked into the code repo accidentally.
They are a language- and OS-agnostic standard.

<br>

In a twelve-factor app, env vars are granular controls, each **fully orthogonal** to other env vars. They are never grouped together as "environments", but instead are independently managed for each deploy.
This is a model that scales up smoothly as the app naturally expands into more deploys over its lifetime.

<br>

<br>

# IV. Backing services

### _Treat backing services as attached resources_
A _backing service_ is any service the app consumes over the network as part of its normal operation (example: databases).
Backing services like the database are traditionally managed by the same system administrators who deploy the app's runtime.
In addition to these locally-managed services, the app may also have services provided and managed by third parties.

<br>

**The code for a twelve-factor app makes no distinction between local and third party services.**
To the app, both are attached resources, accessed via a URL or other locator/credentials stored in the config.

<br>

Easy distinct backing service is a **resource**. For example, a MySQL database is a resource; 2 MySQL databases (used for sharding at the application layer) qualify as 2 distinct resources.
The twelve-factor app treats these databases as _attached resources_, which indicates their loose coupling to the deploy they are attached to.

<br>

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/f665bfbd-95be-45bd-a769-abe277560ee3)

<br>

Resources can be attached to and detached from deploys at will!

<br>

<br>

# V. Build, release, run

### _Stricly separate build and run stages_

A codebase is transformed into a (non-development) deploy through 3 stages:
  1. The **build stage** is a transform which converts a code repo into an executable bundle known as a **build**.
     Using a version of the code at a commit specified by the deployment process, the build stage fetches vendors dependencies and compiles binaries and assets.
  2. The **release stage** takes the build produced by the build stage and combines it with the deploy's current config. The resulting **release** contains both the build and the config and is ready for immediate execution in the execution environment.
  3. The **run stage** (also known as "runtime") runs the app in the execution environment, by launching some set of the app's processes against a selected release.

<br>

**The twelve-factor app uses strict separation between the build, release, and run stages.**

<br>

Builds are initiated by the app's developers whenever new code is deployed. Runtime execution, by contrast, can happen automatically in cases such as a server reboot, or a crashed process being restarted by the process manager.
Therefore, the **run stage** should be kept to as few moving parts as possible, since problems that prevent an app from running can cause it to break in the middle of the night.
The **build stage** can be more complex.

<br>

<br>

# VI. Processes

### _Execute the app as one or more stateless processes_

The app is executed in the execution environment as one or more _processes_.

<br>

**Twelve-factor processes are stateles and share-nothing.** Any data that needs to persist must be stored in a stateful _backing service_, typically a database.

The memory space or filesystem of the process can be used as a brief, single-transaction cache.
The twelve-factor app never assumes that anything ached in memory or on disk will be available on a future request or job.
Example: The execution environment relocating the process to a different physical location will usually wipe out all local (memory and filesystem) state.

<br>

Some web systems rely on "sticky sessions" - that is, caching user session data in the memory of the app's process.
This is a **violation** of twelve-factor and should never be relied upon!

<br>

<br>















