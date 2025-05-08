# ===========================
# Stage 1: Build OpenCV
# ===========================
FROM nvidia/cuda:11.8.0-cudnn8-devel-ubuntu22.04 AS opencv_builder

ENV DEBIAN_FRONTEND=noninteractive
WORKDIR /opencv

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    git \
    wget \
    unzip \
    libjpeg-dev \
    libpng-dev \
    libtiff-dev \
    libavcodec-dev \
    libavformat-dev \
    libswscale-dev \
    libv4l-dev \
    libxvidcore-dev \
    libx264-dev \
    libgtk-3-dev \
    libatlas-base-dev \
    gfortran \
    python3-dev \
    && rm -rf /var/lib/apt/lists/*

# cmake install
RUN wget https://github.com/Kitware/CMake/releases/download/v3.22.1/cmake-3.22.1-Linux-x86_64.sh -O /cmake-3.22.1.sh && \
    chmod +x /cmake-3.22.1.sh && \
    /cmake-3.22.1.sh --skip-license --prefix=/usr/local


# Setup for opencv 
RUN wget https://github.com/opencv/opencv/archive/refs/tags/4.8.0.zip -O opencv.zip && \
    wget https://github.com/opencv/opencv_contrib/archive/refs/tags/4.8.0.zip -O opencv_contrib.zip && \
    unzip opencv.zip && unzip opencv_contrib.zip && \
    mkdir -p /opencv/opencv-4.8.0/build

# Building opencv
WORKDIR /opencv/opencv-4.8.0/build
RUN cmake -DCMAKE_BUILD_TYPE=RELEASE \
    -DWITH_CUDA=ON \
    -DWITH_CUDNN=ON \
    -DOPENCV_DNN_CUDA=ON \
    -DOPENCV_EXTRA_MODULES_PATH=/opencv/opencv_contrib-4.8.0/modules \
    -DCMAKE_INSTALL_PREFIX=/opt/opencv \
    .. && \
    make -j"$(nproc)" && make install && ldconfig

# ===========================
# Stage 2: Build Torch + ROS Installation
# ===========================
FROM nvidia/cuda:11.8.0-cudnn8-devel-ubuntu22.04

ENV DEBIAN_FRONTEND=noninteractive

# Common dependencies
RUN apt-get update && apt-get install -y --no-install-recommends \
    software-properties-common \
    build-essential \
    wget \
    git \
    curl \
    sudo \
    libeigen3-dev \
    libboost-all-dev \
    libjsoncpp-dev \
    libglfw3-dev \
    libglm-dev \
    python3-pip \
    python3-dev \
    libssl-dev \
    locales \
    lsb-release \
    gnupg2 \
    ca-certificates \
    x11-apps \
    openssh-client \
    libglvnd-dev \
    libgl1 \
    libglx0 \
    libegl1 \
    libx11-6 \
    unzip \
    && rm -rf /var/lib/apt/lists/*

# Install Libtorch
# libtorch
RUN cd / && \
    wget https://download.pytorch.org/libtorch/cu118/libtorch-cxx11-abi-shared-with-deps-2.0.1%2Bcu118.zip -O libtorch-cu118.zip && \
    unzip libtorch-cu118.zip && rm libtorch-cu118.zip
ENV Torch_DIR /libtorch/share/cmake/Torch

# Copy OpenCV from builder
COPY --from=opencv_builder /opt/opencv /usr/local

# Setup locale
RUN locale-gen en_US.UTF-8 && update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# Install ROS 2 Humble
ENV ROS_DISTRO=humble
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key | gpg --dearmor -o /usr/share/keyrings/ros-archive-keyring.gpg && \
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2.list && \
    apt-get update && apt-get install -y --no-install-recommends \
    ros-${ROS_DISTRO}-desktop \
    python3-colcon-common-extensions \
    ros-dev-tools \
    && rm -rf /var/lib/apt/lists/*

# User setup
ARG USER_UID
ARG USER_GID
ARG USERNAME
RUN groupadd -g ${USER_GID} ${USERNAME} && \
    useradd -m -u ${USER_UID} -g ${USER_GID} -s /bin/bash ${USERNAME} && \
    usermod -aG sudo ${USERNAME} && \
    echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Setup bashrc for ROS
RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> /home/${USERNAME}/.bashrc
ENV USER=${USERNAME}
ENV HOME=/home/${USERNAME}
WORKDIR /home/${USERNAME}