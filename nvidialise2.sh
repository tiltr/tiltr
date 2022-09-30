#!/bin/bash
TEMP_PATH="/tmp/docker_nvidia_tmp"
TEMP_DOCKERFILE="Dockerfile"
OUTPUT_TEMP_FILE="${TEMP_PATH}/${TEMP_DOCKERFILE}"


if test -f "$OUTPUT_TEMP_FILE"; then
    echo "$OUTPUT_TEMP_FILE file exists, removing..."
    rm $OUTPUT_TEMP_FILE
fi

if [ -d "$TEMP_PATH" ]; then
    echo "$TEMP_PATH dir exists, removing"
    rm -r $TEMP_PATH
fi

bash <(curl -Ls https://github.com/shadow-robot/sr-build-tools/raw/master/docker/utils/docker2_nvidialize.sh) $1
