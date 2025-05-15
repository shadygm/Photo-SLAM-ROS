#!/bin/bash

set -e

echo "========== ROS 2 Build: Photo-SLAM-ROS =========="

# Defaults
BUILD_TYPE="Release"
PARALLEL_WORKERS=$(nproc)

# Optional clean flag via arg
if [[ "$1" == "clean" ]]; then
    echo ">>> Cleaning build/install/log directories..."
    rm -rf build install log
    shift
fi

# === Build DBoW2 ===
echo ">>> Building DBoW2..."
cd ORB-SLAM3/Thirdparty/DBoW2
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE
make -j$PARALLEL_WORKERS
cd ../../g2o

# === Build g2o ===
echo ">>> Building g2o..."
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE
make -j$PARALLEL_WORKERS
cd ../../Sophus

# === Build Sophus ===
echo ">>> Building Sophus..."
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE
make -j$PARALLEL_WORKERS

# === Unpack ORB Vocabulary ===
cd ../../../Vocabulary
if [ ! -f ORBvoc.txt ]; then
    echo ">>> Uncompressing ORB vocabulary..."
    tar -xf ORBvoc.txt.tar.gz
else
    echo ">>> ORBvoc.txt already unpacked."
fi

pwd

# === Build ORB-SLAM3 core ===
echo ">>> Building ORB-SLAM3 core..."
mkdir  -p ../build
cd ../build
cmake .. -DCMAKE_BUILD_TYPE=$BUILD_TYPE
make -j$PARALLEL_WORKERS

# === Build ROS workspace ===
echo ">>> Building Photo-SLAM ROS workspace with colcon..."
cd ../..
colcon build --symlink-install \
    --parallel-workers $PARALLEL_WORKERS \
    --cmake-args -DCMAKE_BUILD_TYPE=$BUILD_TYPE "$@"

echo "========== Build Complete =========="
