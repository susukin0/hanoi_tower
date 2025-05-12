// GRAPH_SEARCH.c
#include <stdlib.h>
#include "GRAPH_SEARCH.h"

NodeList* insert_to_open(NodeList* list, Node* node) {
    NodeList* new_elem = (NodeList*) malloc(sizeof(NodeList));
    new_elem->node = node;
    new_elem->next = list;
    return new_elem;
}

NodeList* pop_from_open(NodeList* list, Node** out_node) {
    if (!list) return NULL;
    NodeList* next = list->next;
    *out_node = list->node;
    free(list);
    return next;
}

void free_node_list(NodeList* list) {
    while (list) {
        NodeList* temp = list;
        list = list->next;
        free(temp->node);
        free(temp);
    }
}

