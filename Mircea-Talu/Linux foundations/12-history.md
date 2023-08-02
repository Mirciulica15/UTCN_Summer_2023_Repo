# History in command line
## Arrows
* Arrows (up and down) help us run commands from the past and toggle between them easily

### However, when we have many commands (1000 for example), we cannot rely on arrows

## The "history" command
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/48fe6211-da7d-41ec-9f90-f80e4f53f6e8)
* syntax : **!n** , where n = number in front of the command we want to run
* we can further narrow the search with grep : **history | grep cat**
* **history n** will show the last n commands executed

### Interactive search
* press **CTRL + r** after executing **history**
* start typing the search time ( **cat** for example )
* pressing **CTRL + r** will toggle between suitable comands
* **ESC** leaves the search
* **ENTER** executes the command

### Files
* where is the history file?
* current it's doesn't exist, we need to create it (it doesn't append in real time)
* history is written in **.bash_history** and it is written at the end of the session
* syntax : **history -a** -> dumps the session history to the file
* then, we can do **cat .bash_history**

### Variables
* **echo HISTSIZE** outputs HISTSIZE
* **echo $HISTSIZE** outputs 1000
* **$ refers to the value of the variables**

### Clear history
* syntax : **history -c** (this removes the history from memory, NOT files)
* if we want to remove the history from files too, we do: **> .bash_history** (redirect "nothing" to the file)

### Disable history
* syntax : **set +o history**
* if we want to disable history for the current user : **echo 'set +o history' >> ~/.bashrc**
* for all users : **echo 'set +o history' >> /etc/profile**
