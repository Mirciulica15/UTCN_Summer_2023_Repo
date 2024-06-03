# Chroot and how it relates to containers

[YouTube video](https://www.youtube.com/watch?v=sizFqFpMbIE&ab_channel=NullLabs)

Chroot can be very useful as a build, when trying to package all your dependencies, because you start from scratch, you can set the root to an empty directory.

**ldd** command tells you the dependencies of something.

Example: **ldd** /bin/bash
