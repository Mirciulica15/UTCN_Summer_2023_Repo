"tree" command -> recursively shows the content of the directory
               -> looks cute
**syntax : tree**

"cp" command -> used to copy
**syntax : cp source target**

Copy and change the filename:
💠 cp source target/newfile
💠 "newfile" **doesn't** exist before running the command

Copy two or more files:
**syntax : cp file1 file2 file3 targetdir**

Wildcards:
💠 '*' replaces all characters with nay length
💠 '?' replaces one character

Copy one directory into another:
**syntax : cp -R mydirectory newdirectory**
*Observations: - newdirectory must **NOT** exist before running the command*
               - *otherwise, mydirectory will be copied **inside** newdirectory*

Moving files
"mv" command
**syntax : mv source target**
- move is very similar to copy
- we can also move multiple files
- mv file1 file2 file3 targetdir

Comparing files
**syntax : diff file1 file2**
- if no output => no difference between the files
