FROM shadowrobot/build-tools:xenial-kinetic-ide

LABEL Description="This ROS Kinetic image contains Toms latest attempt at an autonomous mobile manipulator" Version="1.0"

ENV HOME_DIR=/home/user
ENV PROJECTS_WS=$HOME_DIR/projects/wheely_good_robot/catkin_ws
ENV remote_shell_script=bit.ly/tom_setup
ENV MY_USERNAME=user
USER $MY_USERNAME

RUN set +x && \
    \
    echo "Running tom_setup..." && \
    wget -O /tmp/tom_setup "$( echo "$remote_shell_script" | sed 's/#/%23/g' )" && \
    chmod +x /tmp/tom_setup && \
    bash -c /tmp/tom_setup --container true && \
    \
    echo "Creating download links for test bags..." && \
    echo "wget -P ~/Downloads https://storage.googleapis.com/cartographer-public-data/bags/backpack_2d/cartographer_paper_deutsches_museum.bag" >> $HOME_DIR/download_test_bag.sh && \
    chmod +x $HOME_DIR/download_test_bag.sh && \
    \    
    echo "roslaunch cartographer_ros demo_backpack_2d.launch bag_filename:=${HOME}/Downloads/cartographer_paper_deutsches_museum.bag" >> $HOME_DIR/run_demo.sh && \
    chmod +x $HOME_DIR/run_demo.sh && \    
    \
    echo "wget -P ~/Downloads https://github.com/ElliWhite/proj515_ws/raw/master/map/303/303_pushing.bag" >> $HOME_DIR/download_303_bag.sh && \    
    echo "roslaunch cartographer_ros play_2d_scan.launch bag_filename:=${HOME}/Downloads/303_pushing.bag" >> $HOME_DIR/run_303_bag.sh && \    
    chmod +x $HOME_DIR/run_303_bag.sh && \        
    chmod +x $HOME_DIR/download_303_bag.sh && \            
    \
    echo "Creating and initialising the workspace..." && \
    mkdir -p $PROJECTS_WS && \
    sudo apt-get update && \
    sudo apt-get install -y python-wstool python-rosdep ninja-build ros-kinetic-rplidar-ros && \
    cd $PROJECTS_WS && \
    wstool init src && \
    wstool merge -t src https://raw.githubusercontent.com/carebare47/cartographer_ros/master/cartographer_ros.rosinstall && \
    wstool update -t src && \
    echo "Installing cartographers ROS dependencies..." && \
    \
    src/cartographer/scripts/install_proto3.sh
    
RUN set +x && \        
    sudo rosdep init; exit 0
    
RUN set +x && \        
    rosdep update && \
    \
    cd $PROJECTS_WS && \    
    rosdep install --from-paths src --ignore-src --rosdistro=${ROS_DISTRO} -y && \
    \
    cd $PROJECTS_WS && \    
    source /opt/ros/kinetic/setup.bash && \
    echo "Installing cartographer..." && \
    catkin_make_isolated --install --use-ninja && \
    echo "source /opt/ros/kinetic/setup.bash" >> $HOME_DIR/.bashrc && \
    echo "source $PROJECTS_WS/install_isolated/setup.bash" >> $HOME_DIR/.bashrc && \
    \
    echo "Adding user to dialout group..." && \
    sudo usermod -a -G dialout $MY_USERNAME

RUN set +x && \        
    cd ~/ && wget https://www.arduino.cc/download_handler.php?f=/arduino-1.8.9-linux64.tar.xz && \
    tar -xJf arduino-1.8.9-linux64.tar.xz && \
    rm arduino-1.8.9-linux64.tar.xz && \
    cd arduino-1.8.9 && \
    sudo ./install.sh && \
    PATH=$PATH:/home/user/arduino-1.8.9/bin && \
    curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh && \
    arduino-cli core update-index --additional-url shttps://github.com/stm32duino/BoardManagerFiles/raw/master/STM32/package_stm_index.json && \
    cd ~/Arduino/libraries && \
    wget https://raw.githubusercontent.com/tiltr/tiltr-firmware/master/libraries && \
    while read repo; do git clone "$repo"; done < libraries && \
    cd ~/Arduino && \
    git clone https://github.com/tiltr/tiltr-firmware && \
    arduino-cli lib install "MPU6050"


USER root

ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]

CMD ["/usr/bin/terminator"]
