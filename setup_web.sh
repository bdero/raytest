#!/bin/bash
set -e

git submodule update --init --recursive

if [[ "$OSTYPE" =~ ^(cygwin|msys|win32)$ ]]; then
  WINDOWS=true
fi

pushd deps/emsdk
  echo ""
  echo "Fetching emscripten..."
  echo ""
  ./emsdk install latest
  ./emsdk activate latest
  if [[ -n "$WINDOWS" ]]; then
    echo ""
    echo "Fetching MinGW..."
    echo ""
    ./emsdk install mingw-4.6.2-32bit
    ./emsdk activate mingw-4.6.2-32bit
  fi
popd

echo ""
echo "Done!"
echo ""

echo "To build for web, run \`build_web.sh\`."
