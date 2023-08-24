# Elevate priviliges and login as another user

## When we log in to Linux, we are "normal" users (with limited access)

## Root is the master of the system, root can do anything

### The "su" command
* "su" is short for "substitute"
* it allows us to change the user
* syntax : **su -l newuser** or **su - newuser**
* **root** doesn't have a password

### The "sudo" command
* "sudo" elevates our priviliges to **root** priviliges
* syntax : **sudo command**
* we can use the **sudo -i** command to have elevated priviliges for the whole session

### Configuration of /etc/sudoers
* we can edit this file in order to give the student1 user sudo priviliges
* we can do this by using **vim**
* but, Linux provides a special tool to _safely_ edit the sudoers file : **visudo**
* configure **visudo** to use **vim**
* **update-alternatives --config editor** and select **vim.basic**
* then, **visudo**
* each config line looks like this: **user pos1=(pos2:pos3) pos4**
* OR **%group pos1=(po2:po3) po4**
1. pos1 applies to all hosts
2. pos2 - user can use all commands as all users (i.e. root can _ls_ as user03)
3. pos2 - user can use commands as all group
4. pos4 - user can use all commands

### The "sudoers.d" directory for better granulation
* we can use this directory to create files for users
* example : **echo "student2 ALL=(ALL:ALL) NOPASSWD:ALL" > /etc/sudoers.d/student2**
* this gives all permissions to user student2, also without having to login via password
