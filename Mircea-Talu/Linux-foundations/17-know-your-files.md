# Know your files

## Get information with the "file" command
* we can use this command to every file in Linux
* as we know, in Linux **everything is a file**
* here is a list of entities we will check out:
    * empty text file
    * text file with content
    * diretory
    * binary executable (i.e. /bin/bash)
    * packed file
    * /dev/vda (or another device)
  * we can use **file** command with **-i** argument, which will return mime data about the file (which is less readable for humans)
  * **-s** argument can be used for devices to get more information

## Get information with the "stat" command
* **stat** allows us to get different types of information
* with **file** we learn the type of the file
* **stat** shows information, which we can clasify like more system-oriented
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/fba85208-e72e-47ce-9f7e-66556b6253e2)
* **Blocks** : the size of the file, but i blocks
* **IO Block** : size of each of the blocks
* _Observation: every block device, like hard drive, is structured in blocks; blocks is the largest disk space which can be allocated by **one I/O opeation**_
* **regular file** : the type of the object
* **Device** : hex/decimal ID of the device on which the object is located
* **Inode** : Inode ID; Inode and Device create the unique identification of the object
* **Links** : number of hard links created; 0 means that the file is deleted, 1 means that there are no hard links created
* trick : if you run **stat** against the directory, **Links** will show number of files in the directory
* **Access** : the permission matrix for the object
* **Uid and Gid** : owner and owner's group identifiers
* **Access, Modify and Change** : these 3 represent timestamps when some specific action was taken against the file
    * Access shows **almost** the time of last access to the file
    * Modify shows the last modification of the content
    * Change is about all changes (content and attributes)
* **Birth** : reserved for the time when file was created, but is not implemented in Linux systems

### "stat" parameters
* -f : gives information about filesystem
* -t : returns condensed version of the informatoin; very cool for automation and use in scripts
