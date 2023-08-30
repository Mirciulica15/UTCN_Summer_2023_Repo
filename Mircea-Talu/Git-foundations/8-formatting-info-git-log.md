# Getting and formatting information from git log

* if logs are longer than your sreen, it always goes to **interactive mode**
* you can exit this with **q**

## Best for programmatic access
* sometimes you need to check commits through sctipts
* in this case  **git log** is unhandy
* **git log --oneline** : _--oneline_ shows only the most important info about commits, you have only hash and commit message
* **git log p-** : this shows more details about all commits
* **git log --stat** : this shows the amount of work done in the commit
* **git log shortlog**
* **git shortlog** : only important information, sorted by author of the commits

## Prettier output
* **git log --graph** : visualize branches (tree)
* we can combine this with **--oneline** : **git log --oneline --graph**
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/f553de27-b2f6-41c7-b965-ae02c7942fa4)

## Formatting
* you can create aliases for the most commonly used commands
* **git config --global alias.lg 'log --color --graph --pretty="%Cred%h%Creset -%C(yellow)%d%Creset %s %Cgreen(%cr) %C(bold blue)<%an>%Creset" --abbrev-commit'**
* we instruct **git** that we want to change **configuration**, on **global** table, and we a configure the alias called **lg**
* => **git lg**

## Querying
* we often need to search through **git log**
* **git log --author="John Doe"**
* **git log --author="John Doe\|Joe Smith"** : with this regex we ask for all commits authored by these 2 people
* **THEORY** : it is a good practice to have standards of creating messages for commits; most often we use an identifier (example : **JIRA-1234 my commit message)**
* **git log --grep="JIRA-1234"**
* **git log -- testfile** : looks at a specific file
* notice the **--** : this informs **git** that we are looking for **files**, not **branches**
* **git log master..second-branch** : this compares 2 branches
* but **git log second-branch..master** : gives different results
* why?
* because **git log branch1 branch2** shows the commit history of **branch2**  that is not reachable from **branch1**; in other words, it shows all the commits that are exclusive to **branch2** since the last common commit with the **branch11**
* **git log --merges** : looks for merges
* **git log --no-merges** : excludes merges
* we can search using dates
* example : **git log --after=2021-4-21**
* **git log -n** : limits the number of returned commits to **n**
