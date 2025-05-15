#!/bin/bash

# Auto-config
VOCAB="./ORB-SLAM3/Vocabulary/ORBvoc.txt"
VIEWER_FLAG="no_viewer"
RESULTS_DIR="./results"

if [ "$#" -lt 3 ]; then
  echo "Usage: $0 <group: tum|replica|euroc> <mode: mono|rgbd|stereo> <sequence_name> [repeat_id]"
  exit 1
fi

GROUP=$1
MODE=$2
SEQ=$3
ID=${4:-0}  # default to 0 if not provided

# Sanitize casing
GROUP=${GROUP,,}
MODE=${MODE,,}
SEQ=${SEQ,,}

# Executable name
EXE="${GROUP}_${MODE}"
EXE_PATH="./install/photo-slam-ros/lib/photo-slam-ros/$EXE"

# Config paths
CFG_ROOT="./cfg"
SEQ_ROOT="./data"

ORB_CFG="$CFG_ROOT/ORB_SLAM3"
MAP_CFG="$CFG_ROOT/gaussian_mapper"

# Settings files
case "$GROUP" in
  tum)
    ORB_YAML="$ORB_CFG/$( [ "$MODE" = "mono" ] && echo Monocular || echo RGB-D )/TUM/tum_${SEQ}.yaml"
    MAP_YAML="$MAP_CFG/$( [ "$MODE" = "mono" ] && echo Monocular || echo RGB-D )/TUM/tum_${MODE}.yaml"
    SEQ_PATH="/home/rapidlab/dataset/VSLAM/TUM/rgbd_dataset_${SEQ}"
    ASSOC="$ORB_CFG/$( [ "$MODE" = "mono" ] && echo Monocular || echo RGB-D )/TUM/associations/tum_${SEQ}.txt"
    OUT="$RESULTS_DIR/${EXE}_${ID}/rgbd_dataset_${SEQ}"
    ;;
  replica)
    ORB_YAML="$ORB_CFG/$( [ "$MODE" = "mono" ] && echo Monocular || echo RGB-D )/Replica/${SEQ}.yaml"
    MAP_YAML="$MAP_CFG/$( [ "$MODE" = "mono" ] && echo Monocular || echo RGB-D )/Replica/replica_${MODE}.yaml"
    SEQ_PATH="$SEQ_ROOT/Replica/${SEQ}"
    OUT="$RESULTS_DIR/${EXE}_${ID}/${SEQ}"
    ;;
  euroc)
    ORB_YAML="$ORB_CFG/Stereo/EuRoC/EuRoC.yaml"
    MAP_YAML="$MAP_CFG/Stereo/EuRoC/EuRoC.yaml"
    SEQ_PATH="/home/rapidlab/dataset/VSLAM/EuRoC/${SEQ}"
    ASSOC="$ORB_CFG/Stereo/EuRoC/EuRoC_TimeStamps/${SEQ/MH_/MH}.txt"
    OUT="$RESULTS_DIR/${EXE}_${ID}/${SEQ}"
    ;;
  *)
    echo "Unsupported group: $GROUP"
    exit 1
    ;;
esac

# Print and run
echo "========== Running $EXE =========="
echo "$EXE_PATH"
echo "Vocabulary: $VOCAB"
echo "ORB Config: $ORB_YAML"
echo "Mapper Config: $MAP_YAML"
echo "Sequence: $SEQ_PATH"
echo "Output: $OUT"

mkdir -p "$OUT"

if [[ "$GROUP" == "euroc" ]]; then
  echo "Associations: $ASSOC"
  $EXE_PATH "$VOCAB" "$ORB_YAML" "$MAP_YAML" "$SEQ_PATH" "$ASSOC" "$OUT" "$VIEWER_FLAG"
else
  $EXE_PATH "$VOCAB" "$ORB_YAML" "$MAP_YAML" "$SEQ_PATH" "$OUT" "$VIEWER_FLAG"
fi
