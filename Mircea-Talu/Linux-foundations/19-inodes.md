# Inodes (index nodes)

* unique identifier for a specific piece of metadata on a given filesystem, and the disk block location of this object
* the theoretical maximum number of inodes is equal to 2^32 (aprox 4.3 billion inodees)
* more important is the number of inodes of your system
* generally, the ratio of 1:16KB of system capacity (however, every system is different)

## How many nodes do we have?
* we can use the **df** command, it shows information about the file system
* syntax : **df /dev/vda1**
* with inodes : **df -i /dev/vda1**
* to check inode of specific file : **ls -i file**

## Good explanation (parallel)
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/b71c1144-4346-47db-8afd-fab541a90b93)
