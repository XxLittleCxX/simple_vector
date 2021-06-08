clang --target=wasm32 -Wl,--no-entry -Wl,--export-all -O3 -nostdlib -o build/main.wasm src/wasm.cpp -flto -Wl,--lto-O3 \
-Wl,-z,stack-size=$[8 * 1024 * 1024] # Set maximum stack size to 8MiB