# Linux Kernel Architecture

<br>

## What is Kernel?
* Modules or sub-systems that provide the operating system function
* The Core of OS

## Types of kernels
* Micro kernel (Modular kernel)
* Monolithic kernel

<br>

# Micro kernel
* It includes code only necessary to allow the system to provide major functionality
  + IPC
  + Some memory management
  + Low level process management & scbeduling
  + Low level input / output
* Such as Amoeba, Mach etc

# Monolithic kernel
* It includes all the necessary functions
* Such as Linux etc

## Micro vs Monolithic
* Micro
  + Flexible
  + Modular
  + Easy to implement

* Monolithic
  + Performance
 
## Kernel Architecture Overview
* User Space
* Kernel Space
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/da1e11b2-8ab4-4cd7-9a92-ee8d7b14853a)

<br>

# User Space
* The User Space is the space in memory where user processes run
* This Space is protected
  + The system prevents one process from interfering with another process
  + Only Kernel processes can access a user process

# Kernel Space
* The Kernel Space is the space in memory where kernel proceses run
* The user has access to it only through the system call

# System Call
* User Space and Kernel Space are in different spaces
* When a System Call is executed, the arguments to the call are passed from User Space to Kernel Space
* A user process becomes a kernel process when it executes a system call

## User Space and Kernel Space Relationship
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/2ad06e13-d790-4169-877d-884cf0c837ce)

<br>

# Kernel Functional Overview
* File System
* Process Management
* Device Driver
* Memory Management
* Networking
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/22433dcd-696c-48f4-8a6d-1ffb4a896954)

<br>

# Functional Layer & Architectural Layer
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/420cdf74-1595-4d2e-883a-1f08bc44f2b2)

<br>

# File System
* It is responsible for storing information on disk and retrieving and updating this information
* The File System is accesed through **system calls** such as: **open, read, write etc**
* Example:
  + FAT16, FAT32, NTFS
  + ext2, ext3
  + etc

## Types of Files
* The Unix system has the following types of files
  + Ordinary Files
    - Contain information entered into them by a user, an application etc
  + Directory Files
    - Manage the cataloging of the file system
  + Special Files (devices)
    - Used to access the peripheral devices
  + FIFO Files for Pipes

## Extended File System
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/12cee824-bc1b-43a1-ac8e-ff498176b6fc)

<br>

## File System Structure
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/83f6d31c-9b1c-4b47-926b-6ea697686493)

* Boot Block : information needed to boot the system
* Super Block : File System Specifications
  + Size
  + Max number of files
  + Free blocks
  + Free inodes
* inode List
* Block List : The files data

## Inode
* Each file has an inode structure that is identified by an **i-number**
* The inode contains the information required to access the file
* It doesn't contain the file name
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/0235daf7-1195-4777-9d43-a931ce7c4bd2)

<br>

## Directories
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/9852c182-aecb-4840-a2b7-423a578bc995)

<br>

## Virtual File System
* It manages all the different file systems
* It is an abstraction layer between the application program and the file system implementations
* It describes the system's file in terms of **superblocks** and **inodes** (the same way as the Ext2)
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/caed5d4a-96f0-4ac1-851e-911538a40e76)

* Inode cache
* Directory Cache
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/74d3a5a1-1900-45c0-93fe-4443ffd59dcc)

## Process Management
* The Unix OS is a time-sharing system
* Eeery process is scheduled to run for a period of time (time slice)
* Kernel creates, manages and deletes the proceses
* Every process (except **init**) in the system is created as the result of a **fork** system call
* The fork system call splits a process into two processes (**Parent** and **Child**)
* Each process has a unique identifier (**Process ID**)

## Process Structure
* Eeach process is represented by a **task_Struct** data structure
  + It contains the specifications of each process such as:
    - State
    - Scheduling information
    - Identifier
    - etc
    - ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/355bde27-c90f-4ecd-9a21-3f5f564e8355)
* The **task_vector** is an array of pointers to every task_Struct data structure in the system
  + This means that the maximum number of processes in the system is limited by the size of the task vector
  
## Types of Processes
* **Running**
  + The process is either running or it is ready to run
* **Waiting**
  + The process is waiting for an event or for a resource
* **Stopped**
  + The process has been stopped, usually by receiving a signal
* **Zombie**
  + This is a halted process which, for some reason, still has a task_struct data structure in the task vector

<br>

# Device Driver
* One of the purposes of an OS is to hide the system's hardware from the user
* Instead of putting code to manage the HW controller into every application, the code is kept in the Linux kernel
  + It abstracts the handling of devices
  + All HW devices look like regular files

## Types of Devices
* Character devices
  + A character device is one that can be accessed as a stream of bytes
  + Example: Keyboard, Mouse etc
* Block devices
  + A block device can be accessed only as multiples of a block
  + Example: disk
* Network devices
  + They are created by Linux kernel

## Major Number and Minor Number
* Major Number
  + The major number identifies the driver associated with the device
* Minor Number
  + The minor number is used only by the driver specified by the major number, other parts of the kernel don't use it
  + It is common for a driver to control several devices, the minor number provides a way for the driver to differentiate among them
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/6d6697b4-c747-4117-84f9-7facb7ff6443)

<br>

# Memory Management
* Physical memory is limited
* **Virtual memory** is developed to overcome this limitation

## Virtual Memory
* Large Address Space
* Protection
* Memory mapping
* Fair physical memory allocation
* Shared virtual memory
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/1acf2c8c-9198-4c89-87d8-3dfb2c0ee404)

## Swap Memory
* It is a configurable partition on disk treated in a manner similar to memory

<br>

# Network Layers
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/d8b6269e-8586-4500-ae7d-9b006a78e94d)

## Linux network layers
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/a864b8a7-ed83-4635-8b9d-e0ab33efe3fc)

## BSD socket layer
* It is a general interface (abstract layer)
  + Used in networking and IPC
* Socket address familiar:
  + UNIX
  + INET
  + AX25
  + IPX
  + APPLETALK
  + X25

## What is socket?
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/de9484de-c4d5-42a7-b764-26d3a36c19a2)

## INET socket layer
* It supports the **Internet address** family
* Its interfaece with BSD socket layer is through a set of operations which is registered with a BSD socket layer

## Types of sockets
* Stream Socket
  + Provide a reliable, sequenced, two-way connection (such as **TCP**)
* Datagram Socket
  + A connection-less and unreliable connection (such as **UDP**)
* Raw Socket
  + Used for internal network protocols
