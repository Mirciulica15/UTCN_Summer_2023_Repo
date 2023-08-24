# Work with logs

## Logs are essential to understand what our system is doing

* by default, all logs are stored in the /var/log directory
* however, every system has a diffrent approach to files structure
* in this notes, we look at how Ubuntu works with logs

### There are 2 approaches:
1. _old_ one, where records are stored in plain text files
2. _new_ one, which comes with **systemd**

### Logs in /var/log
* **syslog** : the main system log, contains all important information about the system and applications; if someone is not writting their own logs, it will be here
* **auth.log** : contains information about authorizations, all user login attempts (with info), logout, password changes, remote logins and use of **sudo**
* **dmesg** : a kernel ring buffer, not the logs; it allows us to interact with the kernel and get information by querying bootup messages
*  **kern.log** : stores Kernel messages
*  **boot.log** : contains system's starting sequences (not kernel boot); information about started devices, applications, disks configurations etc
*  **lastlog** : file to be used with **lastlog** utility; contains information about last logins
*  **faillog** : similar to lastlog, use this file with **faillog** utility; logs fail, like login failures
*  **wtmp.og** : contains login information; it doesn't show information similar to **lastlog**, but used by other utilities, like **who**
*  **dpkg.log** : contains data about packages management - install, remove, update etc

### Watching logs
* **tail -f** : keeps the stream open and lets us watch the logs change in real time

### Pushing messages to log
* we cannot inject messages to log files
* we can use the **logger** command
* syntax : **logger "This is a test message"**

### Journalctl - another approach to logs
* data stored by journalctl is binary
* however, it is a very powerful tool and the possibilities of creating queries are nearly infinite
* Message levels (severity)
0. **emerg** : (emergency) is the highest level and it shouldn't be used by applications; it means that the system is unusable 
1. **alert**
2. **crit**
3. **err**
4. **warning**
5. **notice**
6. **info**
7. **debug** : very often used during development

* syntax : **journalctl** -> shows all systemd logs
* we use **journalctl -b -n** to see the data collected during the run of the system done 10 reboots (stop/starts) ago
* boot offset : if < 0 , it happened in the past, if = 0, current boot
* example : journalctl --since "$(date '+%Y-%m-%d %H:%M:%S' --date='5 minutes ago')"
* there are more cool arguments available
