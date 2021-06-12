#include "utils.h"
#include "consts.h"

#define SV_AXIS_THICKNESS 5
#define SV_POINT_THICKNESS 3
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

void draw_point(int x, int y, int color = WHITE) {
    // x: -10 ~ 10 -> 0 ~ 800
    // x +10 *40
    for (int _y = y - SV_POINT_THICKNESS; _y < y + SV_POINT_THICKNESS; _y++) {
        if (_y <= 0 || _y > SV_HEIGHT) {
            continue;
        }
        int yw = _y * SV_WIDTH;
        for (int _x = x - SV_POINT_THICKNESS; _x < x + SV_POINT_THICKNESS; _x++) {
            if (_x <= 0 || _x > SV_WIDTH) {
                continue;
            }
            data[yw + _x] = color;
        }
    }
}

void DrawALine(int x0, int y0, int x1, int y1) {
    bool reversed = false;
    if(x0 > x1){
        int tmp = x0;
        x0 = x1;
        x1 = tmp;

        tmp = y0;
        y0 = y1;
        y1 = tmp;
        reversed = true;
    }
    double k = (y1 - y0) * 1.0 / (x1 - x0);
    double y = y0;
    for (auto x = x0; x <= x1; ++x) {
        if (!reversed ? (x1 - x <= 10) : (x - x0 <= 10)) {
            draw_point(x, y, createRGBA(255, 0, 0, 255));
        } else {
            draw_point(x, y);
        }
        y += k;
    }
}

extern "C" int *render() {
    return &data[0];
}

extern "C" void command_point(float *input) {

    int x = SV_WIDTH / 2 + input[0] * (float) 40;
    int y = SV_HEIGHT / 2 - input[1] * (float) 40;
    draw_point(x, y);
}

extern "C" void command_vector(float *input) {
    int x = SV_WIDTH / 2 + input[0] * (float) 40;
    int y = SV_HEIGHT / 2 - input[1] * (float) 40;
    DrawALine(SV_WIDTH / 2, SV_HEIGHT / 2, x, y);
}

extern "C" void command_add_vector(float *input) {
    DrawALine(SV_WIDTH / 2 + input[0] * (float) 40, SV_WIDTH / 2 - input[1] * (float) 40,
              SV_WIDTH / 2 + input[2] * (float) 40, SV_WIDTH / 2 - input[3] * (float) 40);
}

int main() {
    init();
    return 0;
}
