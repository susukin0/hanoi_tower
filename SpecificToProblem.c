// SpecificToProblem.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data_types.h"

void print_state(State* s) {
    printf("State:\n");
    for (int p = 0; p < 3; p++) {
        printf(" Peg %d:", p);
        for (int d = 0; d < s->heights[p]; d++) {
            printf(" %d", s->pegs[p][d]);
        }
        printf("\n");
    }
}

State initial_state(int num_disks) {
    State s = { .heights = { num_disks, 0, 0 } };
    for (int i = 0; i < num_disks; i++) {
        s.pegs[0][i] = num_disks - i;
    }
    return s;
}

int is_goal(State* s, int num_disks) {
    return s->heights[2] == num_disks;
}

int valid_move(State* s, int from, int to) {
    if (s->heights[from] == 0) return 0;
    if (s->heights[to] == 0) return 1;
    int disk_from = s->pegs[from][s->heights[from] - 1];
    int disk_to = s->pegs[to][s->heights[to] - 1];
    return disk_from < disk_to;
}

void move_disk(State* src, State* dest, int from, int to) {
    *dest = *src;
    int disk = src->pegs[from][src->heights[from] - 1];
    dest->heights[from]--;
    dest->pegs[to][dest->heights[to]] = disk;
    dest->heights[to]++;
}

Node** successors(Node* node, int* out_count) {
    *out_count = 0;
    Node** succs = malloc(6 * sizeof(Node*)); // 6 possible moves
    for (int from = 0; from < 3; from++) {
        for (int to = 0; to < 3; to++) {
            if (from != to && valid_move(&node->state, from, to)) {
                Node* new_node = malloc(sizeof(Node));
                move_disk(&node->state, &new_node->state, from, to);
                new_node->parent = node;
                new_node->depth = node->depth + 1;
                succs[(*out_count)++] = new_node;
            }
        }
    }
    return succs;
}

