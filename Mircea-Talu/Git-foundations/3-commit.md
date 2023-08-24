# Commit your first lines

1. Initialize the repository
  * create a directory
  * navigate there
  * check the directory is empty
  * **git init**
  * **git status**
  * **ls -al** : check for the **.git** directory

2. Commit your first file
  * create file
  * **git status**
  * the new file will be **untracked**
  * **git add newfile** : add file to staging area
  * **git status** : file is tracked and ready to be commited
  * **IMPORTANT** : if you stage the file once, you don't need to repeat this action again during the work
  * **git commit newfile -m "my first commit"** : commit the file
  * **-m** is the message flag
  * **-a** commits all files from the repository
  * **.** commits changes from current path recursively
  * **git status**
  * **IMPORTANT** : **git add .** will add all files **from your current directory and subdirectories, not from repository's root**
