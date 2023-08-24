# Configure git

* Different tables:
1. **--system** : relevant for the whole machine
2. **--global** : for the current user
3. **--local** : (default) for the current repository

## Configure our "personality"
* git config --global user.name "John Doe"
* git config --global user.email johndoe@myemail.com
* it can be **overwritten** with --local in any of the repos
* now the file .gitconfig in the root directory of our user exist
* git config --global core.editor vim
* git config --list : all settings are printed
* git config --list --global : only --global table is listed
* git config user.name : selected record is printed (user.name here)

## Configuration of the repository
* there is a .git directory, which is hidden
* it is created during **git init**
* let's see what is inside:
1. hooks : directory containing all custom hooks; these are small(scripts) which have to be executed before commit, or after, before push, etc
2. branches : this is deprecated!
3. HEAD : pointer to the current branch and its latest commit
4. config : configuration file for the repository
5. info : the place where you stage the files using **git add**
6. refs : the current state of the whole repo
7. objects : commits, trees and blobs are stored here; may be very big
