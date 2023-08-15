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

# VII. Port binding

### _Export services via port binding_

Web apps are sometimes executed inside a webserver container. For example, PHP apps might run as a module inside Apache HTTPD, or Java apps might run inside Tomcat.

<br>

**The twelve-factor app is completely self-contained** and does not rely on runtime injection of a webserver into the execution environment to create a web-facing service.
The web app **exports HTTP as a service by binding to a port**, and listening to requests coming in on that port.

In a local development environment, the developer visits a service URL like ```http://localhost:5000/``` to access the service exported by their app.
In deployment, a routing layer handles routing requests from a public-facing hostname to the port-bound web processes.

This happens entirely in _user space_, that is, within the app's code. The contract with the execution environment is binding to a port to serve requests.
HTTP is not the only service that can be exported by port binding.

<br>

The port-binding approach means that one app can become the **backing service** for another app, by providing the URL to the backing app as a resource handle in the **config** for the consuming app.

<br>

<br>

# VIII. Concurrency

### _Scale out via the process model_

Any computer program, once run, is represented by one or more processes. Web apps have taken a variety of process-execution forms.
For example, PHP processes run as child processes of Apache, started on demand as needed by request volume.
Java processes take the opposite approach, with the JVM providing one massive uberprocess that reserves a large block of system resources (CPU and memory) on startup, with concurrency managed internally via threads.
In both cases, the running process(es) are only minimally visible to the developers of the app.

<br>

**In the twelve-factor app, processes are a first class citizen.**
Processes in the twelve-factor app take strong cues from the unix process model for running service daemons.
Using this model, the developer can architect their app to handle diverse workloads by assigning each type of work to a **process type**.
For example, HTTP requests may be handled by a web process, and long-running background tasks handled by a worker process.

<br>

An individual VM can only grow so large (vertical scale), so the application must also be able to span multiple processes running on multiple physical machines.
The process model truly shines when it comes time to scale out.
The **share-nothing, horizontally partitionable nature** of twelve-factor app processes means that adding more concurrency is a simple and reliable operation.
The array of process types and number of processes of each type is known as the **process formation**.

<br>

Twelve-factor app processes should **never daemonize or write PID files**.
Instead, rely on the operating system’s process manager (such as systemd, a distributed process manager on a cloud platform, or a tool like Foreman in development) to manage output streams, respond to crashed processes, and handle user-initiated restarts and shutdowns.

<br>

<br>

# IX. Disposability

### _Maximize robustness with fast startup and graceful shutdown_

**The twelve-factor app's processes are _disposable_, meaning that they can be started or stopped at a moment's notice.**
This facilitates fast elastic scaling, rapid deployment of code or config changes, and robustness of production deploys.

Processes should strive to **minimize startup time**.

Processes **shut down gracefully when they receive a SIGTERM** signal from the process manager.
For a web process, graceful shutdown is achieved by ceasing to listen on the service port (thereby refusing any new requests), allowing the current requests to finish, and then exiting.

Implicit in this model is that all jobs are reentrant, which typically is achieved by wrapping the results in a transaction, or making the operation idempotent.

Processes should also be robust against **sudden death**, in the case of a failure in the underlying hardware.
While this is a much less common occurrence than a **graceful shutdown with SIGTERM**, it can still happen.
A twelve-factor app is architected to handle unexpected, non-graceful terminations. [Crash-only design](https://lwn.net/Articles/191059/) takes this concept to its logical conclusion.

<br>

<br>

# X. Dev/prod parity

### _Keep development, staging, and production as similar as possible_

Historically, there have been substantial gaps between development and production. These gaps manifest in 3 areas:
* **The time gap**: A developer may work on code that takes days, weeks, or even months to go into production
* **The personnel gap**: Developers write code, ops engineers deploy it
* **The tools gap**: Developers may be using a stack like Nginx, SQLite, and OS X, while production deploy uses Apache, MySQL, and Linux

<br>

**The twelve-factor app is designed for continuous deployment by keeping the gap between development and production small.**
Looking at the gaps described above:
* Make the time gap small: a developer may write code and have it deployed hours or even just minutes later
* Make the personnel gap small: developers who wrote code are closely involved in deploying it and watching its behaviour in production
* Make the tools gap small: keep development and production as similar as possible

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/c334e0bb-d4b4-43f1-a1e0-53daf823841a)

**Backing services**, such as the app's database, queueing system, or cache, is one area where dev/prod parity is important.
Many languages offer libraries which simplify access to the backing service, including _adapters_ to different types of services.

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/85f7f032-0afe-4ebd-9e04-e53134d82734)

<br>

Developers sometimes find great appeal in using a lightweight backing service in their local environments, while a more serious and robust backing service will be used in production.
For example, using SQLite locally and PostgreSQL in production; or local process memory for caching in development and Memcached in production.

**The twelve-factor developer resists the urge to use different backing services between development and production**, even when adapters theoretically abstract away any differences in backing services.
Differences between backing services mean that tiny incompatibilities crop up, causing code that worked and passed tests in development or staging to fail in production.

Adapters to different backing services are still useful, because they make porting to new backing services relatively painless.
But all deploys of the app (developer environments, staging, production) should be using the **same type and version of each of the backing services**.

<br>

<br>

# XI. Logs

### _Treat logs as event streams_

_Logs_ provide visibility into the behaviour of a running app. In server-based environments they are commonly written to a file on disk (a "logfile"); but this is only an output format.

Logs are the **stream of aggregated, time-ordered events** collected from the output streams of all running processes and backing services.
Logs in their raw form are typically a text format with one event per line.
Logs have no fixed beginning or end, but flow continuously as long as the app is operating.

<br>

**A twelve-factor app never concerns itself with routing or storage of its output stream.**
It should not attempt to write to or manage logfiles.
Instead, each running process writes its event stream, unbeffered, to ```stdout```.
During local development, the developer will view this stream in the foreground of their terminal to observe the app's behaviour.

In staging or production deploys, each process’ stream will be captured by the **execution environment**, collated together with all other streams from the app, and routed to one or more final destinations for **viewing and long-term archival**.
These archival destinations are not visible to or configurable by the app, and instead are **completely managed by the execution environment**.

<br>

The event stream for an app can be routed to a file, or watched via realtime tail in a terminal. Most significantly, the stream can be sent to a log indexing and analysis system such as Splunk, or a general-purpose data warehousing system such as Hadoop/Hive.
These systems allow for great power and flexibility for introspecting an app’s behavior over time, including:
* Finding specific events in the past
* Large-scale graphing of trends (such as requests per minute)
* Active alerting according to user-defined heuristics (such as an alert when the quantity of errors per minute exceeds a certain threshold)

<br>

<br>

# XII. Admin processes

### _Run admin/management tasks as one-off processes_

The _process formation_ is the array of processes that are used to do the app’s regular business (such as handling web requests) as it runs.
Separately, developers will often wish to do one-off administrative or maintenance tasks for the app, such as:
* Running database migrations (e.g. manage.py migrate in Django, rake db:migrate in Rails)
* Running a console (also known as a REPL shell) to run arbitrary code or inspect the app’s models against the live database
  Most languages provide a REPL by running the interpreter without any arguments (e.g. python or perl) or in some cases have a separate command (e.g. irb for Ruby, rails     console for Rails)
* Running one-time scripts committed into the app’s repo (e.g. php scripts/fix_bad_records.php)

One-off admin processes should be run in an identical environment as the regular long-running processes of the app.
They run against a release, using the same codebase and config as any process run against that release.
**Admin code must ship with application code to avoid synchronization issues.**

<br>

**Twelve-factor strongly favors languages which provide a REPL shell out of the box**, and which make it easy to run one-off scripts.
In a local deploy, developers invoke one-off admin processes by a direct shell command inside the app’s checkout directory.
In a production deploy, developers can use ssh or other remote command execution mechanism provided by that deploy’s execution environment to run such a process.
