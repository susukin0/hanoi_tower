// data_types.h
#ifndef DATA_TYPES_H
#define DATA_TYPES_H

#define MAX_DISKS 5

typedef struct {
    int pegs[3][MAX_DISKS];  // 3 pegs, each can hold MAX_DISKS disks
    int heights[3];          // Number of disks on each peg
} State;

typedef struct Node {
    State state;
    struct Node *parent;
    int depth;
} Node;

#endif

