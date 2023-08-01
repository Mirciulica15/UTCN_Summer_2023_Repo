# "top" command
## This is an administrative command
### It tells us everything we have to know about the memory, CPU, processes and history

## The first line
* top - 19:38:28 up 2 days, 20:47, 0 users, load average: 0.52, 0.58, 0.59
* current hour, uptime, number of _active_ users
* load average : the load average of the system in the last 1, 10 and 15 minutes
* these load values must be put in the context of the cores and threads of the system

## The second line
* Tasks: 6 total, 1 running, 5 sleeping, 0 stopped, 0 zombie
* total shows all the processes in the system
* running shows the currently active processes
* sleeping - processes that are waiting for something (like an I/O operation)
* stopped - stopped processed (for example by Ctrl + Z)
* **zombie - a process that finished its job but still has an entry in the process table;
             simply put, these processes are waiting for exit(). It may happen when the parent process deteriorated**
* total doesn't represent all processes, you will not find **idle** state here

## The third line
* %Cpu(s): 13.9 us, 9.5 sy, 0.0 ni, 76.3 id, 0.0 wa, 0.4 hi, 0.0 si, 0.0 st
* us : user
* sy : system - processes owned by system (kernel)
* **ni : nice - this allows us to change the priority of the process;
                the standard value is 0, but we can modify it from 19(lowest) to highest(-20)**
* id : idle - the system is bored and doesn't do anything
* hi - hardware interrupts
* si - software interrupts
* **st - steal time : this number represents the time "stolen" from the virtual machine by hypervisor;
                      in other words, how long our system needs to wait for resources from hypervisor**

## The fourth and fifth lines
* MiB Mem :  16217.5 total,   6184.9 free,   9808.7 used,    224.0 buff/cache
* MiB Swap:  49152.0 total,  48436.2 free,    715.8 used.   6278.3 avail Mem
* they represent memory information
* first line is about **physical memory**
* second line is about **swap**
* total, free and used are obvious
* **buff/cache is a combine value of _buffer_ memory, used by kernel and _cache_, memory by page cache**
* available refers to the max size the new starting program/application can use

## Processes list
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/9bc80f72-3f30-49f1-8224-5debee24d200)
* PID - Process ID number
* USER - owner of the process
* PR - default priority of the process, scheduled by kernel when process was started
* NI - nice
* VIRT - total amount of memory used by the process
* RES - RAM memory used by the process
* SHR - amount on memory shared with other processes
* %CPU - amount of CPU used by process
* %MEM - amount of memory used by process
* TIME+ - total time of CPU usage by process
* COMMAND - the executed process

## Different views
* press 1
* press m
* press t
* standard view is ordered by CPU usage
* press M -> order by memory usage
* press N -> order by PID
* press T -> order by running time
* press P -> go back to CPU usage view
* press H -> toggle between threads and processes
* press c -> toggle between simple command name and full path
* press v, V -> get tree of processes instead of simple list (good visual)
* press n -> limit number of displayed processes (0 = unlimited)
* press u -> select processes of specified user
* press o, O -> search through processes
* press s -> change refresh rate (default = 3 seconds)
* **Killing processes : press k and provide the PID of the process to kill**
* press W -> if we want to keep the settings for longer; they will be written in the "toprc" file
* **we can also execute the commands with the settings right away (example : top -o %MEM )
