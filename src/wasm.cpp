#include "utils.h"
#include "consts.h"
int data[SV_WIDTH * SV_HEIGHT];

extern "C" void init(){
    for (int y = 0; y < SV_HEIGHT; y++) {
        int yw = y * SV_WIDTH;
        for (int x = 0; x < SV_WIDTH; x++) {
            auto color = createRGBA(30, 31, 51, 255);

            if(y >= (SV_HEIGHT / 2 - 5) && y <= (SV_HEIGHT / 2 + 5)){
                color = createRGBA(102, 204, 255, 255);
            }
            data[yw + x] = color;
        }
    }
}

extern "C" int* render(){
    return &data[0];
}

extern "C" double params[3];

extern "C" float command_point(float* input){
    float a = input[0];
    return a;
}