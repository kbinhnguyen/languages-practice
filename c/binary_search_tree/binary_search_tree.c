// problem statement: https://exercism.org/tracks/c/exercises/binary-search-tree

#include "binary_search_tree.h"
#include <stdlib.h>

node_t *create_node(int data) {
    node_t *n = malloc(sizeof(node_t));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node_t *build_tree(int *tree_data, size_t tree_data_len) {
    node_t *root;

    if (tree_data_len > 0) {
        root = create_node(tree_data[0]);

        for (size_t i = 1; i < tree_data_len; i++) {
            node_t *curr = root;
            node_t *next = create_node(tree_data[i]);

            while (curr) {
                if (tree_data[i] <= curr->data) {
                    if (!curr->left) {
                        curr->left = next;
                        break;
                    } else curr = curr->left;
                } else {
                    if (!curr->right) {
                        curr->right = next;
                        break;
                    } else curr = curr->right;
                }
            }
        }
    } else root = NULL;
    return root;
}

void free_tree(node_t *tree) {
    if (!tree) return;
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}

int size_of_tree(node_t *tree) {
    if (!tree) return 0;

    int count = 1; // current node
    count += size_of_tree(tree->left) + size_of_tree(tree->right);
    return count;
}

void inorder_traversal(node_t *tree, int *arr, int index) {
    if (!tree) return;
    inorder_traversal(tree->left, arr, index);
    int left_size = size_of_tree(tree->left);
    arr[index + left_size] = tree->data;
    inorder_traversal(tree->right, arr, index + left_size + 1);
}

int *sorted_data(node_t *tree) {
    int *arr = malloc(sizeof(int) * size_of_tree(tree));
    inorder_traversal(tree, arr, 0);
    return arr;
}