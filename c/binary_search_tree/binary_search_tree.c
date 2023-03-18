#include "binary_search_tree.h"
#include <stdlib.h>

node_t *build_tree(int *tree_data, size_t tree_data_len) {
    node_t *root;

    if (tree_data_len > 0) {
        root = malloc(sizeof(node_t));
        root->data = tree_data[0];
        root->left = NULL;
        root->right = NULL;

        for (size_t i = 1; i < tree_data_len; i++) {
            node_t *curr = root;
            node_t *next = malloc(sizeof(node_t));
            next->data = tree_data[i];
            next->left = NULL;
            next->right = NULL;

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
    node_t *left = tree->left;
    node_t *right = tree->right;
    free(tree);
    free_tree(left);
    free_tree(right);
}


int size_of_tree(node_t *tree, int curr_count) {
    if (!tree) return 0;

    int count = curr_count + 1; // current node
    count += size_of_tree(tree->left, curr_count) + size_of_tree(tree->right, curr_count);
    return count;
}


void inorder_traversal(node_t *tree, int *arr, int index) {
    if (!tree) return;
    inorder_traversal(tree->left, arr, index);
    int left_size = size_of_tree(tree->left, 0);
    arr[index + left_size] = tree->data;
    inorder_traversal(tree->right, arr, index + left_size + 1);
}


int *sorted_data(node_t *tree) {
    // in-order traversal
    int *arr = malloc(sizeof(int) * size_of_tree(tree, 0));
    inorder_traversal(tree, arr, 0);
    return arr;
}