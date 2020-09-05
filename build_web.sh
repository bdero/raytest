#!/bin/bash
set -e

if [[ ! -d "deps/emsdk/upstream/emscripten/" ]]; then
  echo "Emscripten not downloaded"
  bash setup_web.sh
fi

source deps/emsdk/emsdk_env.sh

echo ""
echo "Running CMake..."
echo ""
emcmake cmake . -G Ninja -B cmake-build-emscripten -D PLATFORM=Web

echo ""
echo "Building target..."
echo ""
cmake --build cmake-build-emscripten
