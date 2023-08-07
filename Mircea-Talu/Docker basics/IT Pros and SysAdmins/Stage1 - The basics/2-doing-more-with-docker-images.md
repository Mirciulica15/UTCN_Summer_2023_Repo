# Doing more with docker images

## Image creation from a container
* **docker container commit CONTAINER_ID** commits (creates) the image
* once it has been commited, we can see the newly created image in the list of available images with **docker image ls**
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/768081f0-2d7a-42cc-9f2d-15b1b12b6673)
* our custom image has no information in the REPOSITORY or TAG columns
* that would make it tough to identify exactly what was in this container if we wanted to share amongst multiple team members
* **docker image tag <IMAGE_ID> ourfiglet**
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/f4969aeb-e671-4252-ae04-acee42574dd6)
* now we can run containers using our new image
* to share the image, we would want to **push** it to a registry somewhere (**Docker Hub**)
* this can be done from your own system using **Docker for Windows** (or **Docker for Mac**)

## Image creation using a Dockerfile
* instead of creating a static binary image, we can use a file called a **Dockerfile** to create an image
* the final result is essentially the same, but with a Dockerfile we are supplying the **instructions** for building the image, rather than just the raw binary files
* this is useful because it becomes much easier to manage changes, especially as your images get bigger and more complex
### "Give a sysadmin an image and their app will be up-to-date for a day, give a sysadmin a Dockerfile and their app will always be up-to-date."
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/67bc965f-5b69-4822-885c-375b1be3bc51)

## Image layers
* when running Docker images, they appear to be a single OS and application
* however, the images themselves are built in **layers**
* the **docker image build** command has a few steps and each step has several tasks (**fetch** and **pull**)
* **docker image history <image ID>** shows a list of **intermediate** container images that were built along the way
* some of these images will become **layers** in the final container image
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/61607a9c-07c2-4c09-88d1-06c93b547ea8)
* ![image](https://github.com/bogdandragosvasile/UTCN_summer_2023/assets/36898665/629648f6-9142-4ff4-9d46-5450b209b83f)
* Docker realized that we have built some of these layers in our earlier image builds and since nothing changed, it could simply use a cached version of the layer
* rather than pulling down code a second time and running those steps
* this is **very useful** to IT teams when patching systems, updating or upgrading to the latest version of the code, or making configuration changes to the app

## Image inspection


