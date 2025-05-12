// main.c
#include <stdio.h>
#include "data_types.h"

extern State initial_state(int num_disks);
extern void BFS(State start, int num_disks);

int main() {
    int num_disks = 3; // You can increase this if desired
    State start = initial_state(num_disks);
    BFS(start, num_disks);
    return 0;
}

