# What is eBPF?

eBPF is a revolutionary technology with origins in the Linux kernel that can **run sandboxed programs** in a **privileged context** such as the **operating system kernel**.

It is used to **safely** and **efficiently** extend the **capabilities of the kernel** without requiring to change kernel source code or load kernel modules.

<br>

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/6bfef7a6-a00c-4e0d-b05d-bf37b2afbb08)

Wide variety of **use cases**:

- high-performance networking

- load-balancing

- fine-grained security observability data at low overhead

- trace applications

- provide insights for performance troubleshooting

- preventive application and container runtime security enforncement

- etc

BPF = Berkeley Packet Filter (e = extended)

<br>

### Hook Overview

- eBPF programs are **event-driven**

- they are run when the kenrel or an application passes a certain **hook point**

- pre-defined hooks include system calls, function entry/exit, kernel tracepoints, network events, and several others

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/96ae085a-dc47-4c2f-a78c-94924ca9491c)


















