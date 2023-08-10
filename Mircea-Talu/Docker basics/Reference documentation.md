# Reference documentation

* Format : **INSTRUCTION arguments**
* Case-insensitive, but we have conventions
* Dockerfile **must begin with a _FROM_ instruction**
* This may be after **parser directives, comments and globally scoped ARGs**
* **\#** denotes a comment, unless it is a **parser directive**

## Parser directives
* Optional
* **\# directive=value**
* A single directive may only be used once
* The following parser directives are supported:
  + **syntax**
  + **escape** : \# escape=\ (backslash)   -> very useful for **Windows** (since / is used for directory paths)

## Environment replacement
* Environment variables are declared with the **ENV** statement
* They can also be used to certain instructions as variables to be interpreted by the Dockerfile
* Notation : **$variable_name** or **${variable_name}**

## .dockerignore file
* If this file exists, the CLI modifies the context to exclude file and directories that match patterns in it

# FROM
* **FROM [--platform=\<platform>\] \<image> [AS \<name>\]**
* **FROM [--platform=\<platform>\] \<image>[:\<tag>\] [AS \<name>\]**
* **FROM [--platform=\<platform>\] \<image>[@\<digest>\] [AS \<name>\]**
* **FROM** initializes a new build stage and sets the **Base Image** for subsequent instructions
* **ARG** is the only instruction that may precede **FROM** in the **Dockerfile**
* **FROM** can appear multiple times in a **Dockerfile** to create multiple images or use one build stage as a dependency for another
* Optionally a name can be given to a new build stage by adding **AS name** to the **FROM** instruction
* **tag** and **digest** are optional
* An **ARG** declared before a **FROM** is outside of a build stage, so it cannot be used in any instruction after a **FROM**

<br>

# RUN
* **RUN <command>** (_shell_ form, the command is to run in a shell, which by defauly is **/bin/sh -c** on Linux or **cmd /S /C** on Windows)
* **RUN ["executable", "param1", "param2"]** (_exec_ form)
* The **RUN** instruction will execute any commands in a new layer on top of the current image and commit the results
* The resulting committed image will be used for the next step in the **Dockerfile**
* Layering **RUN** instructions and generating commits conforms to the core concepts of Docker, where commits are **cheap** and containers can be created from **any point** in an image's history, much like source control
* The default shell for the _shell_ form can be changed using the **SHELL** command

### RUN --mount
* Alows you to create system mounts that the build can access
* This can be used to
  + Create bind mount to the host filesystem or other build stages
  + Access build secrets or ssh-agent sockets
  + Use a persistent package management cache to steep up your build
* **Syntax** : --mount=[type=<TYPE>][,option=<value>[,option=<value>]...]

### RUN --network
* Allows control over which networking environment the command is run in
* **Syntax** : --network=<TYPE>

### RUN --security
* Not yet avaialbble in table syntax

<br>

# CMD
* The **CMD** instruction has 3 forms:
  + CMD [\"executable","param1","param2"\] (_exec_ form, this is the preferred form)
  + CMD [\"param1","param2"\] (as default parameters to ENTRYPOINT)
  + CMD command param1 param2 (_shell_ form)
* **The main purpose of a CMD command is to provide defaults for an executing container**
* Do not confuse **RUN** with **CMD** ; **RUN** actually runs a command and commits the result ; **CMD** does not execute anything at build time, but specifies the intended command for the image

<br>

# LABEL
* The **LABEL** instruction adds metadata to an image
* A **LABEL** is a key-value pair
```
LABEL "com.example.vendor"="ACME Incorporated"
LABEL com.example.label-with-value="foo"
LABEL version="1.0"
```
* **docker image inspect** to see an image's labels

<br>

# MAINTAINER (deprecated)
* Sets the **Author** field of the generated image
* The **LABEL** instruction is a much more flexible version of this and should be used instead

<br>

# EXPOSE
* Syntax: **EXPOSE <port> [\<port>/<protocol>...\]**
* The **EXPOSE** instruction informs that the container listens on the specified network ports at runtime
* You can specify whether the port listens on TCP or UDP, the default is TCP
* The **EXPOSE** instruction does not actually publish the port
* It functions as a type of documentation between the person who build the image and the person who runs the container, about which ports are intended to be published
* To actually publish the port when running the container, use the **-p** flag on the **docker run** to publish and map one or more ports, or the **-P** flag to publish all exposed ports and map them to high-order ports

<br>

# ENV
* Syntax : **ENV <key>=<value>**
* The **ENV** instruction sets the environment variable **<key>** to the value **<value>**
* This value will be in the environment for all subsequent instructions in the build stage

<br>

# ADD
* **ADD [--chown=<user>:<group>\] [--chmod=<perms>\] [--checksum=<checksum>\] <src>... <dest>**
* **ADD [--chown=<user>:<group>\] [--chmod=<perms>\] ["<src>",... "<dest>"\]**
* --chown and --chmod only work on Linux containers

### Adding a git repo
* **ADD <git ref> <dir>**
* **ADD --keep-git-dir=true https://github.com/moby/buildkit.git#v0.10.1 /buildkit**
* The --kep-git-dir=true** flag adds the **.git** directory

<br>

# COPY
* **COPY [--chown=<user>:<group>\] [--chmod=<perms>\] <src>... <dest>**
* **COPY [--chown=<user>:<group>\] [--chmod=<perms>\] ["<src>",... "<dest>"\]**
* The **COPY** instruction copies new files or directory from **<src>** and add them to the filesystem of the container at the path **<dest>**

<br>

# ENTRYPOINT
* Has 2 forms:
  + The _exec_ form : **ENTRYPOINT [\"executable", "param1", "param2"\]**
  + The _shell_ form : **ENTRYPOINT command param1 param2**
* **ENTRYPOINT** alows you to configure a container that will run as an executable

<br>

# Understand how CMD and ENTRYPOINT interact
* Both the **CMD** and **ENTRYPOINT** instructions define what command gets executed when running a container
* There are a few rules that describe their co-operation:
  + Dockerfile should specify at least one of **CMD** or **ENTRYPOINT**
  + **ENTRYPOINT** should be defined when using the container as an executable
  + **CMD** should be used as a way of defining default arguments for an **ENTRYPOINT** command or for executing an ad-hoc command in a container
  + **CMD** will be overridden when running the container with alternative arguments
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/0fdab652-02d0-439b-958c-08ee76fdbeb5)

<br>

* If **CMD** is defined from the base image, setting **ENTRYPOINT** will reset **CMD** to an empty value
* In this scenario, **CMD** must be defined in the current image to have a value

<br>

# VOLUME
* Syntax : **VOLUME ["data"\]**
* The **VOLUME** instruction creates a mount point with the specified name and marks it as holding externally mounted volumes from native host or other containers

<br>

# USER
* Syntax : USER <user>[:<group>\]
* OR
* Snytax : USER <UID>[:<GID>\]
* The **USER** instruction sets the user name (or UID) and optionally the user group (or GID) to use as the default user and group for the remainder of the current stage
* The specified user is used for **RUN** instructions and at runtime, runs the relevant **ENTRYPOINT** and **CMD** commands
* _NOTE_: When specifying a group for a user, the user will have **only** the specified group membership; any other configured group memberships will be ignored

<br>

# WORKDIR
* Syntax : **WORKDIR /path/to/workdir**
* The **WORKDIR** instruction sets the working directory for any **RUN, CMD, ENTRYPOINT, COPY and ADD** instructions that follow it in the Dockerfile
* If the **WORKDIR** doesn't exist, it will be created even if it's not used in any subsequent Dockerfile instruction

<br>

# ARG
* Syntax : **ARG <name>[=<default value>\]**
* The **ARG** instruction defines a variable that users can pass at build-time to the builder with the **docker build** command using the **--build-arg <varname<=<value>** flag
* If a user specifies a build argument that was not defined in the Dockerfile, the build outputs a warning
* A Dockerfile may contain one or more **ARG** instructions
* **WARNING** : It is not recommended to use build-time varaibles for passing secrets like GitHub keys, user credentials etc. Build-time variable values are visible to any user of the image with the **docker history** command
* Instead, use **RUN --mount=type=secret**

### Predefined ARGs
* HTTP_PROXY
* http_proxy
* HTTPS_PROXY
* https_proxy
* FTP_PROXY
* ftp_proxy
* NO_PROXY
* no_proxy
* ALL_PROXY
* all_proxy
* To use these, pass them on the command line using the **--build-arg** flag
* Example : **docker build --build-arg HTTPS_PROXY=https://my-proxy.example.com**
* By default, these pre-defined variables are excluded from the output of **docker history**

<br>

# ONBUILD
* Syntax : **ONBUILD <INSTRUCTION>**
* The **ONBUILD** instruction adds to the image a _trigger_ to be executed at a later time, when the image is used as the base for another build
* The trigger will be executed in the context of the downstream build, as if it had been inserted immediately after the **FROM** insutrction in the downstream **Dockerfile**
* Any build instruction can be registered as a trigger
* This is useful if you are building an image which willl be used as a base to build other images, for example an application build envirnment or a daemon which may be customized with user-specific configuration
* _OBS_: Chaining **ONBUILD** instructions using **ONBUILD ONBUILD** is not allowed
* _OBS_: The **ONBUILD** instruction may not trigger **FROM** or **MAINTAINER** instructions

<br>

# STOPSIGNAL
* Syntax : **STOPSIGNAL signal**
* The **STOPSIGNAL** instruction sets the system call signal that will be sent to the container to exit
* This signal can be a signal name in the format **SIG<NAME>**, for instance **SIGKILL**, or an unsigned number that matches a position in the kernel's syscall table, for instance **9**
* The default is **SIGTERM** if not defined

<br>

# HEALTHCHECK
* The **HEALTHCHECK** instruction has 2 forms:
  + **HEALTHCHECK [OPTIONS\] CMD command** (check container health by running a command inside the container)
  + **HEALTHCHECK NONE** (disable any healthcheck inherited from the base image)
* The **HEALTHCHECK** instruction tells Docker how to test a container to check that is it still working
* This can detect cases such as a web server that is stuck in an infinite loop and unablle to handle new connectoins, even though the server process is still running

<br>

# SHELL
* Syntax : **SHELL ["executable", "parameters"\]**
* The **SHELL** instruction allows the default shell used for the _shell_ form of commands to be overriden
* The **SHELL** command is especially useful on Windows where there are 2 commonly used and quite different native shells: **cmd** and **powershell**

<br>

# Here-documents
* Here-documents allow redirectioon of subsequent Dockerfile lines to the input of **RUN** and **COPY** commands
* If such command contains a **here-document** the Dockerfile considers the next lines until the line only containing a here-doc delimiter as part of the same command
