# Compare changes with commited work

* **git status** gives us the current status
* **git log** tells us the commit history

## The "git diff" command
* syntax : **git diff SOURCE FILES**
* check the differences between SOURCE and current directory
* if no **SOURCE** is specified, the **HEAD** is taken by default
* if no **FILES** are specified, all are taken by default
* example : **git diff HEAD~1** checks all the differences between HEAD~1 commit and current directory

## Staged differences
* let's say we create a file with content and **add** it to staging
* if we do **git diff**, there is no difference (no commit was made)
* if we want to see the differences, we need to specify this explicitly:
* **git diff --staged**

## The "git show" command
* gives additional information to **git log**
* works against **HEAD** by default

![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/f0cc186b-5748-4638-8fa1-410458982584)
