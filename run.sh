#!/bin/bash

source install/setup.bash
export LD_LIBRARY_PATH=$(pwd)/install/photo-slam-ros/lib:$LD_LIBRARY_PATH

echo "========== ROS 2 Run: Photo-SLAM-ROS =========="

# List executables
echo "Available Executables:"
echo "1) train_colmap"
echo "2) view_result"
echo "3) replica_mono"
echo "4) replica_rgbd"
echo "5) tum_mono"
echo "6) tum_rgbd"
echo "7) euroc_stereo"
echo "8) realsense_rgbd"

# Command-line arg #1 = executable name or number
choice=$1
shift

# If not given, ask interactively
if [ -z "$choice" ]; then
  read -p "Enter number of the executable to run: " choice
fi

# Map to executable name
case $choice in
  1|train_colmap)   exe=train_colmap ;;
  2|view_result)    exe=view_result ;;
  3|replica_mono)   exe=replica_mono ;;
  4|replica_rgbd)   exe=replica_rgbd ;;
  5|tum_mono)       exe=tum_mono ;;
  6|tum_rgbd)       exe=tum_rgbd ;;
  7|euroc_stereo)   exe=euroc_stereo ;;
  8|realsense_rgbd) exe=realsense_rgbd ;;
  *) echo "Invalid selection: $choice"; exit 1 ;;
esac

exe_path="./install/photo-slam-ros/lib/photo-slam-ros/$exe"

# Fill args if not passed directly
args="$@"
if [[ -z "$args" ]]; then
  if [[ "$exe" =~ ^(replica_mono|replica_rgbd|tum_mono|tum_rgbd|euroc_stereo|realsense_rgbd)$ ]]; then
    echo "This executable requires 5–6 positional arguments:"
    read -p "→ Path to vocabulary: " vocab
    read -p "→ Path to ORB_SLAM3 settings: " orb_settings
    read -p "→ Path to Gaussian mapper settings: " mapper_settings
    read -p "→ Path to sequence (dataset): " sequence
    read -p "→ Path to results output directory: " output_dir
    read -p "→ Disable viewer? Type 'no_viewer' or leave blank: " viewer_opt
    args="$vocab $orb_settings $mapper_settings $sequence $output_dir $viewer_opt"
  elif [[ "$exe" == "train_colmap" ]]; then
    echo "train_colmap requires 4 arguments:"
    read -p "→ Path to COLMAP data directory: " colmap_data
    read -p "→ Path to vocabulary: " vocab
    read -p "→ Path to ORB_SLAM3 settings: " orb_settings
    read -p "→ Path to output directory: " output_dir
    args="$colmap_data $vocab $orb_settings $output_dir"
  fi
fi

# Confirm and run
echo "========== Executing =========="
echo "$exe_path $args"
chmod +x "$exe_path"
$exe_path $args
