docker run \
  --rm \
  -v $(pwd):/src \
  -u $(id -u):$(id -g) \
  emscripten/emsdk \
  em++ src/main.cpp -o build/main.js -O3 -s WASM=1 -s EXPORT_ALL=1