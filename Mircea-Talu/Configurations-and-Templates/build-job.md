# Build image and run container job configuration for CI

```
stages:
  - build

build:
  stage: build
  image: docker:24.0.5
  services:
    - docker:24.0.5-dind
  script:
    - docker build -t my-app -f resource-util/Dockerfile .
    - docker image ls -a
    - CONTAINER_ID=$(docker run -d -p 8082:8082 my-app)
    - sleep 30s
    - docker stop $CONTAINER_ID
  after_script:
    - docker ps -a
```
