#include "utils.h"
#include "consts.h"
#define SV_AXIS_THICKNESS 5
int data[SV_WIDTH * SV_HEIGHT];

const auto WHITE = createRGBA(254, 254, 254, 255);
const auto BACKGROUND = createRGBA(30, 31, 51, 255);
const auto AXIS = createRGBA(102, 204, 255, 255);

extern "C" void init() {
    for (int y = 0; y < SV_HEIGHT; y++) {
        int yw = y * SV_WIDTH;
        for (int x = 0; x < SV_WIDTH; x++) {
            auto color = BACKGROUND;

            auto tmp = SV_AXIS_THICKNESS / 2;
            if (y >= (SV_HEIGHT / 2 - tmp) && y <= (SV_HEIGHT / 2 + tmp)) {
                color = AXIS;
            }
            if (x >= (SV_WIDTH / 2 - tmp) && x <= (SV_WIDTH / 2 + tmp)) {
                color = AXIS;
            }
            if (y % 40 == 0 || x % 40 == 0) {
                color = AXIS;
            }
            data[yw + x] = color;
        }
    }
}

void draw_point(float __x, float __y) {
    // x: -10 ~ 10 -> 0 ~ 800
    // x +10 *40
    int x = SV_WIDTH / 2 + __x * (float) 40;
    int y = SV_HEIGHT / 2 - __y * (float) 40;
    for (int _y = y - 5; _y < y + 5; _y++) {
        int yw = _y * SV_WIDTH;
        for (int _x = x - 5; _x < x + 5; _x++) {
            data[yw + _x] = WHITE;
        }
    }
}

extern "C" int *render() {
    return &data[0];
}

extern "C" void command_point(float *input) {
    draw_point(input[0], input[1]);
}

int main() {
    init();
    return 0;
}
