# Introduction

- BPF = Berkeley Packet Filter

<br>

## What are Tracing, Sampling, and Observability?

- **Tracing** is event-based recording

- **Sampling** refers to tools that take a subset of measurements to paint a coarse picture of the target (a.k.a. **profiling**)

- **Observability** refers to understanding a system through observation (includes _tracing_ and _sampling_ tools)

<br>

## What are BCC, bftrace, and IO Visor?

- **BCC** (BPF Compiler Collection)
  + was the 1st higher-level tracing framework developed for BPF
  + provides C programming environment for writing kernel BPF code

- **bpftrace**
  + newer front end that privdes a special-purpose, high-level language for developing BPF tools

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/a8a83e1a-f2d0-432d-9ad0-2a30110c0855)

BCC and bpftrace do not live in the kernel code base, but in a Linux Foundation project on github called **IO Visor**.

These are the repos:

[BCC](https://github.com/iovisor/bcc)

[bpftrace](https://github.com/iovisor/bpftrace)

<br>

















