# Soft and hard links

## Links are a very powerful tool in Linux system and they can be used for many purposes
* we can treat links as **shortcuts** to original destination/file
* it is very handy to use libraries, executables, configurations in multiple places without multiplicating the files
* but it is not **JUST** a shortcut
* it is also something we call **pseudo-file**
* the difference is simple; imagine you created a shortcut to file or directory in Windows system
* when you open this shortcut, in fact you open the original location
* in linux, when you open the link, the system sees it as object opened from the location where it resides, not the original (or source) location
* the effect will be similar on the end, but this is the important difference to understand
* **the syntax to create both types of links is simple : ln**
* **ln SOURCE TARGET**
* SOURCE is the original object
* TARGET is the actual link
* the difference between **soft** and **hard** links is in the argument we use in the **ln** command
* to create a soft link, we need to add the **-s** argument (**ln -s SOURCE TARGET**)
* **unlink LINK** : removing links

### There are 2 types of links:
1. **Soft Links**
   * these links are easily visible in the system and they are used in wide applications in our work
   * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/b98a83f6-c974-4a2a-9448-60b1b5f6401d)
   * **l** at the beginning of the permissions matrix informs us clearly that it is a link
2. **Hard link**
   * **syntax : ln SOURCE TARGET** (no -s argument)
   * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/1613b242-02fa-407c-87cc-afc90dab436c)
   * a difference between soft and hard links is that when the source gets removed, the softlink becomes useless, while the hardlink still retains the contents of the source

### Inodes (index nodes)
* an inode is a fundamental concept used in the file system to represent a file or a directory
* it is a data structure that stores metadata about a file or directory, such as file permissions, ownership, size, timestamps, and the **location of the data blocks on disk**

### Easy explanation
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/6025235f-ffb3-4aba-b1f4-0b2d524a9d14)
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/bfc91a52-d3aa-4261-a84d-9632e5cdb1ce)

