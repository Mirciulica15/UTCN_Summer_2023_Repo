# The "ps" command
## This is an administrative command
### It allows us to understand what the system is doing at the moment

## Running "ps" with no arguments
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/09c91b41-498e-4686-b4be-fad5370b5f25)
* PID : process ID
* TTY : terminal associated with the process
* [Interesting read about TTY]([https://link-url-here.org](https://www.howtogeek.com/428174/what-is-a-tty-on-linux-and-how-to-use-the-tty-command/)
* TTY - teletypewriter
* TIME : total time of CPU usage
* CMD : the command which is running
* **These are NOT all the processes associated with this terminal**

## Running "ps" with arguments
* ps is _special_, it doesn't require a dash ('-') before arguments
* "ps a" and "ps -a" give different outputs however
* "ps T" command
![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/b8816dec-1713-424b-a6e3-b77d43988ac9)
* we notice a new column, STAT -> refers to the status of the process

## STATUSES (most important to understand):
1. 'D' - uninterruptible sleep (usually IO)
2. 'I' - idle kernel thread
3. 'R' - running or runable (on run queue)
4. 'S' - interruptible sleep (waiting for an event to complete)
5. 'T' - stopped by jon control signal
6. 't' - stopped by debugger during tracing
7. 'X' - dead (should never be seen)
8. 'Z' - defunct ("zombie") process, terminated but not killed by parent
### Some statuses may have a second letter:
1. '<' - high-priority (not nice to other users)
2. 'N' - low-priority (nice to other users)
3. 's' - session leader
4. 'l' - multi-threaded
5. '+' - is in the foreground process group

## Important arguments
* ps -A : list all processes
* ps -ef : used when someone wants to determine the PID of the process
* ps aux : additional info (resource usage etc.)
* ps aux --forest : also shows the hierarchy of processes
* pstree : shows just the hierarchy
* ps -f --ppid 1 : shows all processes with the parent process having id 1 (PPID = parent process ID)
