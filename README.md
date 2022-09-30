# wheely_good_robot
Repo for the ROS components of the bigger balance bot (and dockerfiles for the dev environment)

## How to build

```bash
docker build . -t tiltr/base-dev:latest
docker build - < Dockerfile_add_cartographer -t tiltr/cartographer-dev:latest
./nvidialise2.sh tiltr/cartographer-dev:latest
docker create --privileged --net=host -it --gpus all -v /tmp/.X11-unix:/tmp/.X11-unix -e DISPLAY -e QT_X11_NO_MITSHM=1 -e XDG_RUNTIME_DIR=/run/user/1000 -e LOCAL_USER_ID=$(id -u) --name tilter_cartographer tiltr/cartographer-dev:latest-nvidia2
docker start tilter_cartographer
```

or

```bash
./build_all.sh
docker start tilter_cartographer
```

## Build environment

Arduino works, but currently trialing cubemx/truestudio for cmsis HAL 

https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-ides/truestudio.html?dl=qX3dxD%2FV1ClpPeuPcbo%2B4A%3D%3D%2C%2FAqFiBs1j2XeHmjlAo2c5Q4gXjxwqLaEqWSJTHkfdtBOFQaaKZwvb7V4Wqy03aTzzwJGmsU46NqtHsX%2FygKpD15DJcwN%2FTnM48NXqntLk%2FgAtCWlzJEDYmUuYtbE3Gomv9r56FefeYTppl4HVKNh8%2F8yPZmZ6AAH5iyDjEHXRHppx8rQ%2BEIj3pNXepH6F79qX%2BdHf30Du4PAkvLM1Ra26eqRB2xN1BFKctqo8v%2B049yN65LwYpnL%2FGwowx4BAYooDVxzW6QiAo9rJNUCt6VtOpKM4tG9zI9%2BM3ZqphD9Owb1LR9PSaxss3x5Um1D7uAmmwnaUiRj2M8FcE61PY1Ah0AUO3T24WniPfP80%2F8JDmA%3D&uid=8cLceiBTYxUTRYysFZmtS71WMKIsWRCC

https://www.st.com/en/development-tools/stm32cubemx.html#get-software
