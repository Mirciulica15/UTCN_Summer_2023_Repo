# Permissions and the allow/deny matrix

## On the first place:
* **d** means **directory**
* **l** means **soft (symbolic) link**
* **-** means **normal file**
* **b** means **block special file (like hard drive)**
* **c** means **character special file**
* **n** means **network file**
* **p** means **FIFO**
* **s** means **socket** 

## Permissions elements
* the full picture is composed from this matrix and information about owner (and the owning group) of this file

## Matrix explained
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/28353494-e482-44c8-b44a-bf7ebaa89866)
* each group is buiilt with 3 parts:
  1. **r** means **Read** permission is granted
  2. **w** means **Write** permission is granted
  3. **x** means **eXecute** permission is granted
* example : **drwx------ 2 root root 4096 May 2 10:20 .ssh** => directory, all permissions for owner, no permission for group and others

## There are 2 methods of setting permissions
1. Absolute (numeric) mode
* each block is represented by one digit
* each digit has specific meaning
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/24609c33-afe2-4c7e-824b-09192b91728c)
* so, to represent the example from above, we can say: 700
* _Observation: eXecute doesn't simply mean **execute the file or program**, it also means **execute the directory**, which allows us to enter into the directory_
2. Symbolic mode
* this mode allows us to work in an easier, more visual way
* here we use **operator** and the **user denotation** to define the permission matrix
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/74442130-b86d-4865-8638-9ce50cba0a14)
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/18583c8b-d860-4ae8-9664-2e8e79f4e427)

## How does the bash know who is the owner? Or the group?
* the answer is here: **-rw-r--r-- 1 root adm 48194 May 2 10:20 dmesg**
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/bb622e6f-2394-4c95-9090-6510112f35de)




