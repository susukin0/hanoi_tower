// HashTable.h
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "data_types.h"

void init_hash_table();
int is_visited(State* state);
void add_to_hash_table(State* state);
void free_hash_table();

#endif

