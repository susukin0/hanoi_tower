// GRAPH_SEARCH.h
#ifndef GRAPH_SEARCH_H
#define GRAPH_SEARCH_H

#include "data_types.h"

typedef struct NodeList {
    Node *node;
    struct NodeList *next;
} NodeList;

NodeList* insert_to_open(NodeList* list, Node* node);
NodeList* pop_from_open(NodeList* list, Node** out_node);
void free_node_list(NodeList* list);

#endif

