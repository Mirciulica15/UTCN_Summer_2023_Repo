"tree" command -> recursively shows the content of the directory
               -> looks cute
**syntax : tree**.

"cp" command -> used to copy
**syntax : cp source target**.

Copy and change the filename:
1. cp source target/newfile
2. "newfile" **doesn't** exist before running the command.

Copy two or more files:
**syntax : cp file1 file2 file3 targetdir**.

Wildcards:
1. '*' replaces all characters with nay length
2. '?' replaces one character.

Copy one directory into another:
1. **syntax : cp -R mydirectory newdirectory**
2. *Observations: - newdirectory must **NOT** exist before running the command*
               - *otherwise, mydirectory will be copied **inside** newdirectory*.

Moving files
"mv" command
**syntax : mv source target**
* move is very similar to copy
* we can also move multiple files
* mv file1 file2 file3 targetdir.

Comparing files
**syntax : diff file1 file2**
* if no output => no difference between the files.
