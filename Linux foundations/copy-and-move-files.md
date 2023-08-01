# Copy and move files
## The "tree" command:
* recursively shows the content of the directory
* looks cute
* syntax : tree

## The "cp" command -> used to copy
* **syntax : cp source target**
* copy and change the filename:
1. cp source target/newfile
2. "newfile" **doesn't** exist before running the command
* copy two or more files:
* **syntax : cp file1 file2 file3 targetdir**
* copy one directory into another:
1. **syntax : cp -R mydirectory newdirectory**
2. __Observations__:
   * *newdirectory must **NOT** exist before running the command*
   * *otherwise, mydirectory will be copied **inside** newdirectory*

## The "mv" command -> used to move
* **syntax : mv source target**
* move is very similar to copy
* we can also move multiple files
* mv file1 file2 file3 targetdir

## Comparing files
**syntax : diff file1 file2**
* if no output => no difference between the files
