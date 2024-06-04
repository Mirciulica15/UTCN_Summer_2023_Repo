# containerd

[YouTube video](https://www.youtube.com/watch?v=VWuHWfEB6ro&ab_channel=Docker)

[GitHub repo](https://github.com/crosbymichael/dockercon-2016)

- Fast, lightweight container supervisor.

- It is a **container** supervisor, not **process** supervisor! (It does not want to replace systemd)

- runc (OCI) multiplexer

- Container lifecycle operations

- Abstracts away the execution from the daemon

## Why?

- runc integration

- **Multiple** runtime support

- Execution v2

- **Decouple** execution from filesystem

- **Daemonless** containers

- Cleaner development

- **gRPC API**

- Fixes another problem: previously whenever the Docker daemon was **upgraded**, all the containers were killed!

- Uses an event loop which controls the feed

- Bring back the speed, the **performance**

## How to manage state?

- Managing state is easy when you don't have any!

- Don't keep **anything** in memory!

- /run is your friend (/run is a temporary filesystem)

- You only need the process ID (**PID**) of the process and the **path** to its root to restore everything about the container

## Daemonless problems

- Exit code and wait4() (We want to know the exit code of the container process without waiting for it)

- tty / stdio

- re-parenting

- Solution: Use **shims**!!!

## containerd-shim

- **Every** container has a **shim** process (1 to 1)

- It handles getting the exit code of the process, notifying containerd or higher levels when it exits, holding open the parent side of a tty or standard I/O

## Exit status

- **FIFO** (pipe with an inode) for blocking + **file** -> FIFO for exit event, FIFO for exit status

- You can use a FIFO to **transfer data** or for its **blocking** semantics

- In this exit cases, it is used for blocking (opens it with O_WRONLY using the O_CLOEXEC flag); whenever someone opens it O_RDONLY from the other side, it will block until either you send data or it's closed -> shim waits, doesn't have to do anything; also works for **multiple subscribers**

![FIFO-containerd-shim](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/003a28fd-807a-42ea-8b77-4900ac37e544)

## Stdio (Standard I/O)

- Includes logging, tty, stdin, stdout, stderr

- We still use FIFOs, but this time for **data**

- FIFOs have a **buffer** -> /proc/sys/fs/pipe-max-size

- The container Stdio are basically files

- Even if the daemon and the runtime (containerd) go down, containers can keep running and, when restored, they **reopen** these FIFOs

## Re-parenting

![shim-runc-container](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/9c3b9923-2c93-432e-93d9-ce3cee03e888)

1. shim launches runc

2. runc launches container

3. runc exits

4. shim becomes parent of container

![shim-container](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/28240c54-4255-43bd-9b06-5698537355c3)

Re-parenting rules:

1. Your parent is the process that forked you

2. If your parent dies, your new parent is PID 1

This was the code until Linux Kernel **3.4**!

Afterwards, you can do **prctl** - PR_SET_CHILD_SUBREAPER!

"In effect, a subreaper fulfills the role of init(1) for its descendant processes."

![re-parenting](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/30cae595-9d7a-45d9-bfd3-e707b3918fcf)

## The OOM (Out-of-Memory) Problem

How do you connect to OOM notifications before the user process starts?

**Runtime workflow:**

- **create** -> initialize namespaces and config

- **start** -> exec the user's process

- **delete** -> destroy the container

**Solution:** in between create and start, hook the OOM notifications, so that the container does not exit before having the chance to do so.
