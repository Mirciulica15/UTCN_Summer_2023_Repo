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
* Press **CTRL + r** after executing **history**
* Start typing the search time ( **cat** for example )
* Pressing **CTRL + r** will toggle between suitable comands
* **ESC** leaves the search
* **ENTER** executes the command
