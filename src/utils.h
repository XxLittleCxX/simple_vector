#ifndef SIMPLE_VECTOR_UTILS_H
#define SIMPLE_VECTOR_UTILS_H
// maybe big endian
// https://stackoverflow.com/a/14375308/8308032
int createRGBA(int r, int g, int b, int a) {
    return ((r & 0xff)) + ((g & 0xff) << 8) + ((b & 0xff) << 16)
           + ((a & 0xff) << 24);
}

#endif //SIMPLE_VECTOR_UTILS_H
