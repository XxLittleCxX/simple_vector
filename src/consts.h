#ifndef SIMPLE_VECTOR_CONSTS_H
#define SIMPLE_VECTOR_CONSTS_H

#define SV_HEIGHT 800
#define SV_WIDTH 800

enum NodeType {
    Vector
};

struct Node {
    NodeType type;
    double x;
    double y;
};

#endif //SIMPLE_VECTOR_CONSTS_H
