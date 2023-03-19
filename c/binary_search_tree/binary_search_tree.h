#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H
#include <stddef.h>

typedef struct node node_t;

struct node {
   node_t *right;
   node_t *left;
   int data;
};

node_t *build_tree(int *tree_data, size_t tree_data_len);

node_t *create_node(int data);

void free_tree(node_t *tree);

void inorder_traversal(node_t *tree, int *arr, int index);

int size_of_tree(node_t *tree);

int *sorted_data(node_t *tree);

#endif