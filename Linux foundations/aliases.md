# Working with aliases
## What do we do when we have to use long commands with numerous arguments for many times?
## We use ALIASES
### Syntax: alias <name_of_command>="<command>"
### example: alias lh="ls -alh"
* Aliases are available **only in the current session**
* We can remove aliases, using the unalias command
* example : unalias lh

## How do we make aliases permanent (forever)?
### There are 2 ways to do this:
1. Using the .bashrc file:
   * add the alias to .bashrc
   * load the .bashrc file into the session ( source ./.bashrc )
   * **source** reads and executes scripts in the **current** shell
   * by default, when we execute a script, it will be executed in its own shell
2. Using a different ".bash_aliases" file:
   * this file should be loaded automatically when .bashrc is loaded
   * ```
    if [ -f ~/.bash_aliases ]; then
    . ~/.bash_aliases
    fi
    ```
  * we must check that this block belongs in the .bashrc file
  * add alias to .bash_aliases
  * load .bashrc ( source ./.bashrc )

## How do we make aliases for ALL users?
### Here we touch the administrative part
### We have to add to the global configuration
* The place where we have to add out aliases if /etc/profile.d
* When we log into the system, the ~/.profile file is loaded
<img width="392" alt="image" src="https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/cb157eee-bc2e-4c70-bdd6-3da8574dc4e4">
* *Observation: we saved it as a .sh file (shell script)*
