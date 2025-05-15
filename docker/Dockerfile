# ===========================
# Stage 1: Build OpenCV
# ===========================
FROM nvidia/cuda:12.6.0-cudnn-devel-ubuntu24.04 AS opencv_builder

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
RUN wget https://github.com/Kitware/CMake/releases/download/v3.29.2/cmake-3.29.2-linux-x86_64.sh -O /cmake-install.sh && \
    chmod +x /cmake-install.sh && \
    /cmake-install.sh --skip-license --prefix=/usr/local


# Setup for opencv 
ENV OPENCV_VERSION=4.10.0
RUN wget https://github.com/opencv/opencv/archive/refs/tags/${OPENCV_VERSION}.zip -O opencv.zip && \
    wget https://github.com/opencv/opencv_contrib/archive/refs/tags/${OPENCV_VERSION}.zip -O opencv_contrib.zip && \
    unzip opencv.zip && unzip opencv_contrib.zip && \
    mkdir -p /opencv/opencv-${OPENCV_VERSION}/build

# Building opencv
WORKDIR /opencv/opencv-${OPENCV_VERSION}/build

# Change this to your GPU architecture
ENV CUDA_ARCH_BIN=8.6
RUN cmake -DCMAKE_BUILD_TYPE=RELEASE \
    -DWITH_CUDA=ON \
    -DWITH_CUDNN=ON \
    -DOPENCV_DNN_CUDA=ON \
    -DOPENCV_EXTRA_MODULES_PATH=/opencv/opencv_contrib-${OPENCV_VERSION}/modules \
    -DCMAKE_INSTALL_PREFIX=/opt/opencv \
    -DBUILD_TESTS=OFF \
    -DBUILD_PERF_TESTS=OFF \
    -DBUILD_EXAMPLES=OFF \
    -DCUDA_ARCH_BIN="${CUDA_ARCH_BIN}}" \
    -DCUDA_ARCH_PTX="" \
    .. && \
    make -j"$(nproc)" && make install && ldconfig


# ===========================
# Stage 2: Build Torch + ROS Installation
# ===========================
FROM nvidia/cuda:12.6.0-cudnn-devel-ubuntu24.04

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

# Install ROS 2
ENV ROS_DISTRO=jazzy
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
RUN set -eux; \
    # Remove user with same UID if exists
    EXISTING_USER_BY_UID=$(getent passwd "${USER_UID}" | cut -d: -f1 || true); \
    if [ -n "$EXISTING_USER_BY_UID" ]; then \
    userdel -r "$EXISTING_USER_BY_UID" || true; \
    fi; \
    \
    # Remove user with same name if exists
    if id "${USERNAME}" >/dev/null 2>&1; then \
    userdel -r "${USERNAME}" || true; \
    fi; \
    \
    # Remove group with same GID if exists
    if getent group "${USER_GID}" >/dev/null; then \
    groupdel "$(getent group "${USER_GID}" | cut -d: -f1)"; \
    fi; \
    \
    # Remove group with same name if exists
    if getent group "${USERNAME}" >/dev/null; then \
    groupdel "${USERNAME}"; \
    fi; \
    \
    # Now create group and user cleanly
    groupadd --gid "${USER_GID}" "${USERNAME}"; \
    useradd -m -u "${USER_UID}" -g "${USER_GID}" "${USERNAME}"; \
    usermod -aG sudo "${USERNAME}"; \
    echo "${USERNAME} ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Setup bashrc for ROS
RUN echo "source /opt/ros/${ROS_DISTRO}/setup.bash" >> /home/${USERNAME}/.bashrc
ENV USER=${USERNAME}
ENV HOME=/home/${USERNAME}
WORKDIR /home/${USERNAME}