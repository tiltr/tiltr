FROM shadowrobot/build-tools:xenial-kinetic-ide

LABEL Description="This ROS Kinetic image contains Toms latest attempt at an autonomous mobile manipulator" Version="1.0"

ENV remote_shell_script="https://raw.githubusercontent.com/shadow-robot/sr-build-tools/$toolset_branch/ansible/deploy.sh"

ENV PROJECTS_WS=/home/user/projects/wheely_good_robot/catkin_ws

RUN set +x && \
    \
    echo "Running tom_setup..." && \
    bash <(curl -Ls bit.ly/tom_setup) --container true && \
    \
    mkdir -p $PROJECTS_WS && \
    echo "Creating and initialising the workspace..." && \
    sudo apt-get update && \
    sudo apt-get install -y python-wstool python-rosdep ninja-build && \
    cd $PROJECTS_WS && \
    wstool init src && \
    wstool merge -t src https://raw.githubusercontent.com/googlecartographer/cartographer_ros/master/cartographer_ros.rosinstall && \
    wstool update -t src && \
    echo "Installing cartographers ROS dependencies..." && \
    \
    src/cartographer/scripts/install_proto3.sh && \
    sudo rosdep init && \
    rosdep update && \
    rosdep install --from-paths src --ignore-src --rosdistro=${ROS_DISTRO} -y && \
    \
    echo "Installing cartographer..." && \
    catkin_make_isolated --install --use-ninja


ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

CMD ["/usr/bin/terminator"]
