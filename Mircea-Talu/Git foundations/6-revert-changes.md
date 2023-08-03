# Revert changes

### Explanation
* if you do **git reset** and all works for you, it's ok, right?
* you moved the **HEAD** of your local repo somewhere
* but that's just you, **only you**
* what will happen if someone else commits his changes in the same time?
* the best practica to **revert** is to create a new commit from the previous one
* to avoid the **HEAD** moving somewhere it shouldn't be

### The "git revert" command
* syntax : **git revert --no-edit HEAD** : we move back by one commit
* **--no-edit** means that we don't want to specify any message and we use the default
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/3b08f744-fcc6-4898-a428-b63a8afe0274)
* **we go back by going forward**
* what happened?
* we created a new commit, which reverts the previous one
* **git revert --edit HEAD~3** : reverts multiple commits
* **IMPORTANT** : very often you can experience problems when reverting more than one commit and the same file is involved
* we will learn to troubleshoot this issue
