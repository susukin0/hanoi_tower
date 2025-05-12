// Standart_Search.c
#include <stdio.h>
#include <stdlib.h>
#include "data_types.h"
#include "GRAPH_SEARCH.h"
#include "HashTable.h"

extern int is_goal(State* s, int num_disks);
extern Node** successors(Node* node, int* out_count);
extern void print_state(State* s);

void reconstruct_path(Node* node) {
    if (!node) return;
    reconstruct_path(node->parent);
    print_state(&node->state);
}

void BFS(State start, int num_disks) {
    init_hash_table();

    Node* root = malloc(sizeof(Node));
    root->state = start;
    root->parent = NULL;
    root->depth = 0;

    NodeList* open = NULL;
    open = insert_to_open(open, root);

    while (open) {
        Node* node;
        open = pop_from_open(open, &node);

        if (is_visited(&node->state)) {
            free(node);
            continue;
        }

        add_to_hash_table(&node->state);

        if (is_goal(&node->state, num_disks)) {
            printf("\n--- Solution ---\n");
            reconstruct_path(node);
            free_hash_table();
            free_node_list(open);
            return;
        }

        int succ_count;
        Node** succs = successors(node, &succ_count);
        for (int i = 0; i < succ_count; i++) {
            open = insert_to_open(open, succs[i]);
        }
        free(succs);
    }

    printf("No solution found.\n");
    free_hash_table();
}

