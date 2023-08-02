# How to bring back previous states of the repo

## Remove files from stage
* syntax : **git rm --cached file**
* **git rm --cached -r .** : delete all (-r = recursively, . = everything from here)
* **git status**

## Restore previous state of the file
* syntax : **git log**
* syntax : **git checkout file** restores file to the state of the previos commit
* **git checkout .** for all files

## Reset the current HEAD to the selected state
* syntax : **git reset** moves the current pointer in **HEAD** and **branch refs** to specific state
* **git checkout** does a similar thing, but, in fact, these commands operate on different levels
* **reset** has 3 ways of operating (we look at 2, --mixed is not covered):
  1. --soft
     * **git log** shows that we have many changes done, we have one commit for each file
     * **git reset --soft HEAD~1** : reset HEAD to the state before commiting the last file
     * we come back to the prevoius HEAD of the repository, but all changes which we commited are unchanged
  2. --hard
     * **git reset --hard HEAD~2**
     * we came back two more commits (~HEAD~2) and we said:
     * this time we want to not only move back, but also remove all the changes we have done
