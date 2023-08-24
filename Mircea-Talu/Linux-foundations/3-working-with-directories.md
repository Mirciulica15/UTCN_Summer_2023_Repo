# Working with directories
## Basics:
  * pwd : print working directory
  * cd : change directory
  * ls : list directory contents
  * $HOME (OR ~) : home directory
  * we can cd using relative path or absolute bath (from the ~)

## Creating directories:
  * mkdir : make directory
  * cool trick : mkdir name{01..10} -> creates 10 directories numbered from 01 to 10
  * rmdir : remove directory
  * observation -> we cannot remove a directory that is not empty
  * => we have to remove contents first OR
  * => we have to forcefully remove the directory (THIS IS NOT SAFE)
  * rmdir directory/* -> removes contents first
  * rm -rf directory -> forcefully removes directory
