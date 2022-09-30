#!/bin/bash

docker build . -t tiltr/base-dev:latest
docker build - < Dockerfile_add_cartographer -t tiltr/cartographer-dev:latest
./nvidialise2.sh tiltr/cartographer-dev:latest

docker create --privileged --net=host -it --gpus all -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY \
              -e QT_X11_NO_MITSHM=1 -e XDG_RUNTIME_DIR=/run/user/1000 -e LOCAL_USER_ID=$(id -u) \
              --name tilter_cartographer tiltr/cartographer-dev:latest-nvidia2


docker start tilter_cartographer
