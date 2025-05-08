#!/bin/bash

echo "========== ROS 2 Build: Photo-SLAM-ROS =========="

# Ask for build type
read -p "Enter CMAKE_BUILD_TYPE (default: Release): " build_type
build_type=${build_type:-Release}

# Ask for extra colcon arguments
read -p "Enter extra colcon build args (e.g. --parallel-workers 8): " extra_args

# Confirm
echo ">>> Building with type: $build_type"
echo ">>> Extra colcon args: $extra_args"

# Clean old build if requested
read -p "Clean build directory before building? (y/N): " clean
if [[ "$clean" == "y" || "$clean" == "Y" ]]; then
    rm -rf build install log
    echo ">>> Cleaned build/install/log folders"
fi

# Build
colcon build --symlink-install \
    --cmake-args -DCMAKE_BUILD_TYPE=$build_type \
    $extra_args

echo "========== Build Complete =========="
