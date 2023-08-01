# Reading the file
## "cat" command
* cat comes from "concatenate" (OR "catenate")
* the downside of "cat" is that it prints the whole file (no matter how big)
* the "file" command tells us the kind of file we have

## VIM
* vim is a very weird but efficient editor
* we have 3 modes in vim: COMMAND, INSERT and VISUAL
1. COMMAND : where we interact with vim and do actions
2. INSERT : where we change the content of the file
3. VISUAL : where we can do selection of text
* once we change the content, we exit using "ESC" and writing:
  1. ":q" for quitting
  2. ":q!" for quitting without making the changes
  3. ":wq" for writing and then quitting (changes are made)
* if we want to enter a file in read-only mode, we use **"view"** instead of **"vim"**
* example : vim myfile, view myfile

## more & less
* more and less are used for printing a file in a controlled way
* "more" only shows a portion of the file, and we can use Enter to keep going further
* "less" is a more sophisticated command, which allows us to go **both ways**, up and down, in the file

## head & tail
* head myfile -> display the first **10** lines of the file (by default)
* we can the -n flag for specific number of lines
* example : head -n2 myfile -> first 2 lines
* tail : same as head, but from the end
