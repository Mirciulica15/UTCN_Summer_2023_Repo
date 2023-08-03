# Merge branches

## git merge
### One of the strengths of version control is the ability to work on different versions of the code simultaneously. In order to achieve that, we have the branch functionality.
* **git checkout -b newbranch** creates a new branch; **-b** argument is used to create a new branch
* **git checkout** moves us between branches
* **git branch -r** lists branches from remote
* **git merge newbranch --no-edit** merges the newbranch to the **master** or **main**
* after merging, we can delete the auxiliary branch
* **git branch -d newbranch**

## Conflicts
* during the work on 2 branches, it is possible that the changes will be implemented to the same file
* we can deal with these manually, keeping the version we want
* **IMPORTANT** : the **better approach** is to **merge the master to your branch before merge to master**
* it doesn't help to solve conflicts, but conflict will be on your branch, not master
* which is more comfortable for everyone
