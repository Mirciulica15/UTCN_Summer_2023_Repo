# Container runtimes (using cgroups and namespaces)

As of 2015.

**LXC**

- set of userland tools

- a container is a directory in /var/lib/lxc

- small config file + root filesystem

- early versions had no support for CoW

- early versions had no support to move images

- requires significant amount of elbow grease, easy for sysadmins/ops, hard for devs

**systemd-nspawn**

- seems to position itself as plumbing

- recently added support for docker images

**Docker Engine**

- daemon controlled by REST(ish) API

- first versions shelled out to LXC, now uses its own libcontainer runtime

- manages containers, images, build, and more

- **some people think it does too many things!**

## rkt, runC

- back to the **basics!**

- focus on container execution - no API, no image management, no build, etc

- they implement different specifications: rkt implements appc, runC implements OCP, runC leverages Docker's libcontainer
