# First Alpine Linux Containers

## 1. Running your first container
  * **docker run container hello-world**
  * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/eb18c015-e1f2-40af-83b1-d081b5fe5d93)
  * The VM is a **hardware** abstraction: it takes physical CPUs and RAM from a host, and divides and shares it across several smaller virtual machines
  * There is an OS and application running inside the VM, but the virtualization software usually has no real knowledge of that
  * A container is an **aplication** abstraction: the focus is really on the OS and the application, and not so much on the hardware abstraction

## 2. Docker images
  * **docker image pull alpine**
  * the **pull** command fetches the alpine **image** from the **Docker registry** and saves it in the system
  * in this case the registry in **Docker Hub**
  * **docker image ls** to see all the images on your system

## 3. Docker container run
  * **docker container run alpine ls -l**
  * when you can **run**, the Docker client finds the image (alpine in our case), creates the container and then runs a command in that container
  * after the **ls** command executed, the container shut down
  * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/68c29645-ba4c-4828-98aa-d105209256f5)
  * the fact that the container exited after running our command is **important**
  * Docker containers function at the application layer so they skip most of the steps VMs require and just run what is required for the app
  * now you know why they say containers are fast
  * **docker run container alpine /bin/sh** : the container ran the command **/bin/sh**, but no command was specified so it just launched the shell, exited the shell and then stopped the container
  * **docker run container -it alpine /bin/sh** allows to run the container in an **interactive terminal (it)**
  * **docker container ls** shows all the containers which are currently running
  * **docker container ls -a** is more useful, it shows all container that you ran (including exited ones)
  * **docker container run --help** to list the flags it supports

## 4. Container isolation
  * the **docker container ls -a** command showed us that there were **several** containers listed
  * why are there so many containers listed if they are all from the **alpine** image?
  * this is a critical **security** concept in the world of Docker containers!
  * even though each docker container run command used the same alpine image, each execution was a **separate, isolated container**
  * each container has a separate **filesystem** and runs in a different **namespace**
  * by default a container has no way of interacting with other containers, even those from the same image
  * **docker container start <container ID>** runs the container instance with the given ID
  * **pro tip**: instead of using the full container ID you can use just the first few characters, as long as they are enough to uniquely ID a container
  * **docker container exec <container ID> ls** : the **exec** command is used to send a command into the container (**ls** in our case)
  * ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/b1237829-ecf0-4418-83b4-a813df0df704)

## 5. Terminology
  + **Images**
    - the file system and configuration of our application which are used to create containers
    - to find out more about a Docker image, run **docker image inspect alpine**
    - in the demo above, you used the **docker image pull** command to download the alpine image
    - when you executed the command **docker container run hello-world**, it also did a **docker image pull** behind the scenes to download the hello-world image
  
  + **Containers**
    - running instances of Docker images — containers **run** the actual applications
    - a container includes an **application** and all of its **dependencies**
    - it shares the **kernel** with other containers, and runs as an **isolated process** in user space on the host OS
    - you created a container using **docker run** which you did using the **alpine** image that you downloaded
    - a list of running containers can be seen using the **docker container ls** command

  + **Docker daemon**
    - the background service running on the host that manages building, running and distributing Docker containers

  + **Docker client**
    - the command line tool that allows the user to interact with the Docker daemon

  + **Docker Hub**
    - store is, among other things, a registry of Docker images
    - you can think of the registry as a directory of all available Docker images
