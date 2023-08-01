# Working with users
## There are 3 types of users in Linux:
1. Standard user
2. User with elevated priviliges
3. Root

## Users are the way we interact with the OS (operating system)
### We need to log in:
* using a user and a password OR
* even better, using a user and a ssh (Secure Shell) key
* when logged in, we can interact with the hardware, the file system, applications etc (depending on permissions)

## The "whoami" command
* syntax : whoami -> outputs current user

## The "id" command
* syntax : id (optional user)
* <img width="218" alt="image" src="https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/6443372a-82d1-47bc-827b-7effba8861bf">
* UID : unique User Identifier
  * uid=0 root
  * uid=1-99 predefined accounts
  * uid=100-99 system and administrative accounts
  * uid=1000+ users 
* GID : Group Identifier
  * combines several users in the same entity
  * gid=0 root
  * gid=1-99 system and application use
  * gid=100+ users

## Files involved in user configuration
### The "passwd" file
* location : /etc/passwd
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/6801b308-8e2f-4fa1-af9c-c25a57be5ba2)
* structure : username:password:UID:GID:description:homedir:shell
* the password used to be stored in the "password" field but that changed due to security reasons
* homedir : "home" of the user
* bash = **B**ourne **A**gain **Sh**ell
* available shells are found at /etc/shells
* /sbin/nologin : makes sure that the user cannot log in (it is not required for that specific user to log in)

### The "shadow" file
* contains sensitive information about the user
* such as the password and other configurations
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/4f3a2e35-ce33-4adf-809b-fea1ec93ee51)
* if the password is set for user, then it is hashed and not retrievable (however there are tools which allow us to crack passwords)
* '*' means that there is no password set -> very good (we want to use passwordless access, with access keys, not passwords)
* '!' means that the password was never set

### The "group" file
* contains information about groups
* <img width="215" alt="image" src="https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/d6c330c7-0972-499b-9d47-b1158151793f">
* groupname:password:GID:users belong to the group
 
 ### The "gshadow" file
 * contains encrypted passwords for group
 * <img width="153" alt="image" src="https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/bf61f352-bf85-4bb2-ba46-1247cd8020d0">

## Create user
### There are 2 ways to create a new user:
1. useradd -> binary file
2. adduser -> Perl script, it uses useradd to createa a user in the backend
#### Differences:
* adduser is more verbose and it is interactive, it asks for password and other information
* we prefer useradd, it's available on every Linux distribution and works the same way

### Important arguments
* -d : create home directory in specified location, if we want to change
* -m : create the home directory
* -p : password
* -s : provide shell
* -c : comments, or description of the account
* useradd -h : for more options

## Modify existing user
### Changing the password
* syntax : passwd <user> , the bash will prompt you to add a new password and retype it
* if no <user> if specified, the command will target the current user

### Changing the user
* syntax : usermod <user> <changes>
* example : usermod testuser3 -g testuser2
* we changed the _group_ of testuser3 to testuser2

// TODO finish Working with users
