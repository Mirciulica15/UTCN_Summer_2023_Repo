# Working with files
## Creating a file:
* touch myfile
* same cool trick: touch my{01..10}file

## Using * and ? wildcards:
  * '*' - anything can be there
  * '?' - anything of length 1 (character) can be there
  * example : we have 3 files -> f1, f2 and f01
  * ls f* -> f1, f2, f01
  * ls f? -> f1, f2 (NOT f01, because 01 is of length 2)

## Removing a file:
  * rm myfile
  * can also remove using the same cool trick

## Using VIM:
  * vim mynewfile -> creates new file called "mynewfile" and opens the vim editor
  * use "i" to enter insert mode (modify file)
  * use "ESC" to go back to command mode
  * use ":wq" to save changes and exit vim (write and quit)
