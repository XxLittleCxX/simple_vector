#include "../emscripten/system/include/emscripten/emscripten.h"

#define HEIGHT 400
#define WIDTH 800
int data[WIDTH * HEIGHT];

// maybe big endian
// https://stackoverflow.com/a/14375308/8308032
int createRGBABig(int r, int g, int b, int a) {
    return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8)
           + (a & 0xff);
}

int createRGBA(int r, int g, int b, int a) {
    return ((r & 0xff)) + ((g & 0xff) << 8) + ((b & 0xff) << 16)
           + ((a & 0xff) << 24);
}

extern "C" {
int *render();
}

int *EMSCRIPTEN_KEEPALIVE render() {
    for (int y = 0; y < HEIGHT; y++) {
        int yw = y * WIDTH;
        for (int x = 0; x < WIDTH; x++) {
            data[yw + x] = createRGBA(30, 31, 51, 255);
        }
    }
    return &data[0];
}