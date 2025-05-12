// HashTable.c
#include <stdlib.h>
#include <string.h>
#include "HashTable.h"

#define TABLE_SIZE 10007

typedef struct HashNode {
    State state;
    struct HashNode* next;
} HashNode;

static HashNode* table[TABLE_SIZE];

static unsigned long hash_state(State* state) {
    unsigned long hash = 5381;
    for (int p = 0; p < 3; p++) {
        for (int d = 0; d < state->heights[p]; d++) {
            hash = ((hash << 5) + hash) + state->pegs[p][d];
        }
    }
    return hash % TABLE_SIZE;
}

int states_equal(State* s1, State* s2) {
    return memcmp(s1, s2, sizeof(State)) == 0;
}

void init_hash_table() {
    memset(table, 0, sizeof(table));
}

int is_visited(State* state) {
    unsigned long h = hash_state(state);
    HashNode* node = table[h];
    while (node) {
        if (states_equal(&node->state, state))
            return 1;
        node = node->next;
    }
    return 0;
}

void add_to_hash_table(State* state) {
    unsigned long h = hash_state(state);
    HashNode* new_node = (HashNode*) malloc(sizeof(HashNode));
    new_node->state = *state;
    new_node->next = table[h];
    table[h] = new_node;
}

void free_hash_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* node = table[i];
        while (node) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
        table[i] = NULL;
    }
}

