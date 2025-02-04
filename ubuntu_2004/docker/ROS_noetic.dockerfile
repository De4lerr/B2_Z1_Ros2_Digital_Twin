# Use an official ROS Noetic full desktop image as the base
FROM osrf/ros:noetic-desktop-full

ENV TERM=xterm-256color

# Avoid prompts from APT during build by specifying non-interactive as the frontend
ARG DEBIAN_FRONTEND=noninteractive
# Set the timezone environment variable
ENV TZ=America/Sao_Paulo

# Define user-related arguments to create a non-root user inside the container
ARG USERNAME=ros_ws
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Create a new group and user with the specified UID and GID, create a config directory, and set ownership
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd -s /bin/bash --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && mkdir /home/$USERNAME/.config && chown $USER_UID:$USER_GID /home/$USERNAME/.config

# Update the package list, install sudo, configure sudoers for the new user without password prompts, and clean up APT lists
RUN apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME \
    && rm -rf /var/lib/apt/lists/*

# Update package list and install git
RUN apt-get update \
    && apt-get install -y git-all

# Update package list and install various packages for development with ROS, including visualization tools, development libraries, and Python packages
RUN apt-get update \
    && apt-get install -y wget git build-essential \
    && apt-get install -y liburdfdom-dev liboctomap-dev libassimp-dev --no-install-recommends gcc libc-dev\
    && apt-get install -y nano \
    && apt-get install -y ffmpeg    

# Install Python packages
RUN apt-get update \
    && apt-get install -y python3 \
    && apt-get install -y python3-pip \
    && apt-get install -y python3-opencv \
    && apt-get install -y python3 python3-pip \
    && apt-get install -y python-numpy \
    && apt-get install -y python3-colcon-common-extensions

# Install Catkin
RUN apt purge \
   && apt-get install -y python3-catkin-tools

# Install ROS packages
RUN apt-get update \
    && apt-get install -y ros-noetic-rviz

# # Install ROS2 Foxy dependencies
# RUN apt-get update && apt-get -y install locales \
#     && locale-gen en_US en_US.UTF-8 \
#     && update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8 \
#     && export LANG=en_US.UTF-8 \
#     && apt-get -y install software-properties-common \
#     && add-apt-repository universe 

# # Install ROS2 Foxy
# ENV ROS_DISTRO=foxy
# RUN apt update && apt install curl -y && apt-get upgrade -y\
#     curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg && \
#     echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null && \
#     apt-get update && \
#     apt-get install -y --no-install-recommends ros-${ROS_DISTRO}-desktop && \
#     apt-get install -y --no-install-recommends python3-argcomplete python3-colcon-common-extensions python3-rosdep python3-colcon-mixin python3-vcstool && \
#     apt-get install -y --no-install-recommends ros-${ROS_DISTRO}-gazebo-ros-pkgs ros-${ROS_DISTRO}-xacro ros-${ROS_DISTRO}-joint-state-publisher-gui

# # Install Unitree ROS2 Package dependencies
# RUN apt-get update \
#     && apt-get install -y ros-foxy-rmw-cyclonedds-cpp \                                               
#     && apt-get install -y ros-foxy-rosidl-generator-dds-idl 

# Install Unitree Z1 SDK on system (sudo sed foi usado para corrigir um problema do python)
RUN apt-get update \
    && apt-get install -y libboost-dev \
    && apt-get install -y libeigen3-dev \
    && git clone https://github.com/unitreerobotics/z1_sdk.git \
    && cd z1_sdk \
    && mkdir build \
    && cd build \
    && cmake .. \
    # && sudo sed -i '30s|<Eigen/Core>|<eigen3/Eigen/Core>|; 31s|<Eigen/SparseCore>|<eigen3/Eigen/SparseCore>|' /usr/include/pybind11/eigen.h \
    && sudo make

# Install Unitree Z1 control on system
RUN git clone https://github.com/unitreerobotics/z1_controller.git \
    # && sed -i '48s|.*|        ctrlComp->cmdPanel = new ARMSDK(events, emptyAction, "127.0.0.1", 8074, 8073, 0.002);|' /z1_controller/main.cpp \
    # && sed -i '4s|.*|    <Port>8881</Port>|' /z1_controller/config/config.xml \
    && cd z1_controller \
    && mkdir build \
    && cd build \
    && cmake .. \
    && sudo make \
    && cd / \
    && sudo chmod 777 /z1_controller

# Finish packages intalation
RUN rm -rf /var/lib/apt/lists/*

# Copy custom entrypoint script and .bashrc configuration from the host to the container
COPY config/entrypoint.sh /entrypoint.sh
COPY config/bashrc /home/${USERNAME}/.bashrc

# Set the custom script to be the container's entrypoint, this script is executed when the container starts
ENTRYPOINT [ "/bin/bash", "/entrypoint.sh" ]

# Default command when the container is run, if no other commands are specified
CMD [ "bash" ]