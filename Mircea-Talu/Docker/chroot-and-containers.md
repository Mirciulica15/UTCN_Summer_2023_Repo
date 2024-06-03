# Chroot and how it relates to containers

[YouTube video](https://www.youtube.com/watch?v=sizFqFpMbIE&ab_channel=NullLabs)

Chroot can be very useful as a build, when trying to package all your dependencies, because you start from scratch, you can set the root to an empty directory.

**ldd** command tells you the dependencies of something.

Example: **ldd** /bin/bash

I've written the smallest possible Dockerfile to run /bin/bash.

First, get all the dependencies of bash:

![GetBashDependencies](https://github.com/Mirciulica15/UTCN_Summer_2023_Repo/assets/36898665/cc9c2c89-96c1-4b46-b225-92c48dde172c)

Then, add everything to the Dockerfile.

```Dockerfile
FROM scratch

COPY bin/bash /bin/bash

COPY lib /lib

COPY lib /lib64

ENTRYPOINT [ "/bin/bash" ]
```

The resulting Docker image has a size of 6.72 MB.

_Note:_ Notice the use of **FROM scratch** as base image.
