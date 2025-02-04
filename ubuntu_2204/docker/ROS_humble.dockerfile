# Use an official ROS Noetic full desktop image as the base
FROM osrf/ros:humble-desktop-full

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
    && apt-get install -y liburdfdom-dev liboctomap-dev libassimp-dev \
    && apt-get install -y nano \
    && apt-get install -y net-tools \
    && apt-get install -y ffmpeg    \
    && apt-get install -y libeigen3-dev \
    && apt-get install -y libboost-all-dev \
    && apt-get install -y libncurses5-dev
    
# Install Python packages
RUN apt-get update \
    && apt-get install -y python3 \
    && apt-get install -y python3-pip \
    && apt-get install -y python3.10-venv \
    && apt-get install -y python3-opencv \
    && apt-get install -y python3-numpy \
    && apt-get install -y python3-colcon-common-extensions

# Install Catkin
# RUN apt purge \
#    && apt-get install -y python3-catkin-tools

# Install ROS2 packages
RUN apt-get update \
    && apt-get install -y ros-humble-ament-cmake \
    && apt-get install -y ros-humble-ros-base \
    && apt-get install -y ros-humble-xacro \
    && apt-get install -y ros-humble-joint-state-publisher-gui \
    && apt-get install -y ros-humble-ros-gz \
    && apt-get install -y ros-humble-ros-ign-bridge \
    && apt-get install -y ros-humble-gazebo-ros-pkgs \
    && apt-get install -y ros-humble-ros2-control \
    && apt-get install -y ros-humble-ros2-controllers \
    && apt-get install -y ros-humble-gazebo-ros2-control \
    && apt-get install -y ros-humble-teleop-twist-keyboard \
    && apt-get install -y ros-humble-tf-transformations \
    && apt-get install -y '~nros-humble-rqt*' 

# Install Unitree ROS2 Package dependencies
RUN apt-get update \
    && apt-get install -y ros-humble-rmw-cyclonedds-cpp \                                               
    && apt-get install -y ros-humble-rosidl-generator-dds-idl \
    && apt-get install -y iputils-ping \
    && apt-get install -y libgstreamer1.0-dev \
    libgstreamer-plugins-base1.0-dev \
    libgstreamer-plugins-bad1.0-dev \
    gstreamer1.0-plugins-base \
    gstreamer1.0-plugins-good \
    gstreamer1.0-plugins-bad \
    gstreamer1.0-plugins-ugly \
    gstreamer1.0-libav \
    gstreamer1.0-tools \
    gstreamer1.0-x \
    gstreamer1.0-alsa \
    gstreamer1.0-gl \
    gstreamer1.0-gtk3 \
    gstreamer1.0-qt5 \
    gstreamer1.0-pulseaudio

# Install OpenCv (B2 SDK Requirement) ~Demorado demais
RUN git clone https://github.com/opencv/opencv/tree/4.1.1 \
    && cd opencv \
    && mkdir build \
    && cd build \
    && cmake .. \
    && make \
    && sudo make install

# Install Unitree SDK2 on system
RUN git clone https://github.com/unitreerobotics/unitree_sdk2.git \
    && cd unitree_sdk2 \
    && mkdir build \
    && cd build \
    && cmake .. \
    && sudo make install

# Install Unitree python SDK2 on system
RUN git clone https://github.com/unitreerobotics/unitree_sdk2_python.git \
    && cd unitree_sdk2_python \
    && mkdir build \
    && pip3 install -e .

# Install Unitree Z1 SDK on system (sudo sed foi usado para corrigir um problema do python)
RUN apt-get update \
    && apt-get install -y libboost-dev \
    && apt-get install -y libeigen3-dev \
    && git clone https://github.com/unitreerobotics/z1_sdk.git \
    && cd z1_sdk \
    && mkdir build \
    && cd build \
    && cmake .. \
    && sudo sed -i '30s|<Eigen/Core>|<eigen3/Eigen/Core>|; 31s|<Eigen/SparseCore>|<eigen3/Eigen/SparseCore>|' /usr/include/pybind11/eigen.h \
    && sudo make \
    && sudo cp /z1_sdk/lib/libZ1_SDK_x86_64.so /usr/lib/ \
    && sudo cp /z1_sdk/lib/unitree_arm_interface.cpython-310-x86_64-linux-gnu.so /usr/lib/ \
    && sudo cp /z1_sdk/lib/unitree_arm_interface.cpython-38-x86_64-linux-gnu.so /usr/local/lib/ 
    
# Install Unitree Z1 control on system
RUN git clone https://github.com/unitreerobotics/z1_controller.git \
    # && sed -i '48s|.*|        ctrlComp->cmdPanel = new ARMSDK(events, emptyAction, "127.0.0.1", 8074, 8073, 0.002);|' /z1_controller/main.cpp \
    # && sed -i '4s|.*|    <Port>8882</Port>|' /z1_controller/config/config.xml \
    && cd z1_controller \
    && mkdir build \
    && cd build \
    && cmake .. \
    && sudo make \
    && sudo cp /z1_controller/lib/libZ1_x86_64.so /usr/lib/

# Crie o arquivo limits.conf com permissões de tempo real
RUN echo "ros_ws - rtprio 99" >> /etc/security/limits.conf \
    && echo "ros_ws - memlock unlimited" >> /etc/security/limits.conf \
    && echo "ros_ws - nice 19" >> /etc/security/limits.conf

# Configuração para o arquivo /etc/pam.d/common-session
RUN echo "session required pam_limits.so" >> /etc/pam.d/common-session

# Configuração para o Docker permitir tempo real com chrt
RUN echo "ulimit -l unlimited" >> /etc/profile

# Adicione bibliotecas externas para linkagem (diretórios onde as bibliotecas estão localizadas)
RUN echo "/z1_sdk/lib" >> /etc/ld.so.conf.d/z1_sdk.conf \
    && echo "/z1_controller/lib" >> /etc/ld.so.conf.d/z1_controller.conf \
    && ldconfig

# Finish packages intalation
RUN sudo ldconfig
RUN rm -rf /var/lib/apt/lists/*

# Copy custom entrypoint script and .bashrc configuration from the host to the container
COPY config/entrypoint.sh /entrypoint.sh
COPY config/bashrc /home/${USERNAME}/.bashrc

# Set the custom script to be the container's entrypoint, this script is executed when the container starts
ENTRYPOINT [ "/bin/bash", "/entrypoint.sh" ]

# Default command when the container is run, if no other commands are specified
CMD [ "bash" ]