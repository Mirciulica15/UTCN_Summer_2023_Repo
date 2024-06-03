# Linux namespaces - what is their part in Linux containers?

They provide **isolation** of your processes.

You don't allow the child process to see the parent.

![ChildProcessIsolation](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/f1d810e0-ebef-410e-9a37-02edaedd5cc3)

But these processes can use as many **resources** as they want! Namespaces don't solve that problem, they only isolate the processes -> we need something else, control groups (**cgroups**).

Namespaces provide processes with their **own system view**.

**Cgroup** = limits how much you can use;

**Namespace** = limits what you can see;

**Reason**: you can't use/affect what you can't see

There are **multiple** namespaces:

- pid

- net

- mnt

- uts

- ipc

- user

Each process is in **one** namespace of **each** type!

## Pid namespace

Processes within a PID namespace only see processes in the **same PID namespace**.

Each PID namespace has its **own numbering**, starting at 1.

## Net namespace

Processes within a given network namespace get their own private network stack, including:

- network interfaces (including I/O)

- routing tables

- iptables rules

- sockets (ss, netstat)

They have their own localhost, their own eth0, etc.

You can **move** a network interface across net namespaces.

```bash
ip link set dev eth0 netns PID
```

Usually, in practice, we have a **bridge** network.

All the containers are connected to the host, we have a bridge between each container and the host.

## Mnt namespace

Processes can have their own root filesystem (conceptually close to chroot).

Processes can also have "private" mounts.

No easy way to pass along a mount from a namespace to another :(.

## Ipc namespace

IPC = inter-process communication

Allows a process (or group of processes) to have own:

- IPC semaphores

- IPC message queues

- IPC shared memory

without risk of conflict with other instances.

## Usr namespace

You can map UIDs/GIDs.

UID 0 is root.

Example:

UID 0->1999 in container C1 is mapped to UID 10000->11999 on host.

You can be **root** inside the container, but outside you are a **non-priviliged user**.

## Namespace manipulation

Namespaces are created with the **clone()** syscall.

Namespaces are **materialized** by pseudo-files /proc/<pid>/ns.

## Copy-on-write storage

Create a new container **instantly** instead of copying its whole filesystem.

Storage keeps track of what has **changed**.

Considerably reduces **footprint** and **boot** times.

## Orthogonality

All those things can be used **independently**.

If you only need **resource isolation**, use a few selected cgroups.

If you want to simulate a network of routers, use **network namespaces**.

Put the **debugger** in a container's namespaces, but not its cgroups, so that the debugger doesn't steal resources.

Setup a network interface in a container, then move it to another.

Etc...

## Some missing bits (at the time, 2015)

Capabilities:

- break down **"root/non-root"** into fine-grained rights

- allow to keep root, but **without the dangerous bits**

- however, [CAP_SYS_ADMIN](https://man7.org/linux/man-pages/man7/capabilities.7.html) remains a big catchall

SELinux/AppArmor - containers that **actually** contain
