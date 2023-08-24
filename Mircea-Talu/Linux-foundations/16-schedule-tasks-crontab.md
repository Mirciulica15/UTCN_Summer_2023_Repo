# Schedule tasks, Crontab

## [Important & useful link](https://crontab.guru/)

## These notes are about the Linux scheduler - cron

### Cron, the daemon
* **cron** is a service responsible for control and execution of scheduled tasks
* it is started when system is booting and works until the system is shut down
* **systemctl status cron.service** : this is a management command for systemd
* **cron** is a service which controls multiple **crontabs**

### Crontab
* **crontab** is simply a list of tasks or commands which are scheduled to be executed on specific date and time
* Linux has many crontabs:
1. * */etc/crontab
   * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/9595d5ea-2097-412f-b9d4-a216169da7d1)
   * the crontab has an associated directory : **/etc/cron.d**
2. * */etc/cron.daily and others
   * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/c4c4e1a2-2ba5-4932-9088-5e981f681aa3)

### Anacron
* **anacron** is a scheduler too, but it works differently
* unlike cron, anacron doesn't assume that the maschine run continously without stops
* it is crucial for system's scripts which must be executed daily

### /var/spool/cron/crontabs
* this is where the user's crontabs are stored
* it is related to root's crontab as well
 
### Set the task in crontab
* syntax (check image above) : **1 17 7 4 2 /usr/bin/ls >/dev/null 2>&1**
* user - we do not set user for user related crontabs, but for system wife crontab this possibility is valuable
* each entry in crontab is called **cronjob**
* to list our jobs, we execute **crontab -l**
* **crontab -e** : opens crontab editor
* we need to set the default editor (**vim**)
* when executed, **crontab will create another shell**
