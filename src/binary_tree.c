// Copyright 2023 <Seres67>

#include <binary_tree.h>
#include <stdio.h>
#include <stdlib.h>

binary_tree_t *binary_tree_new(void *data) {
    binary_tree_t *tree = malloc(sizeof(binary_tree_t));
    if (!tree)
        return NULL;
    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

binary_tree_t *binary_tree_insert(binary_tree_t *tree, void *data) {
    if (!tree) {
        tree = binary_tree_new(data);
        if (!tree)
            return NULL;
        return tree;
    }
    if (data < tree->data)
        tree->left = binary_tree_insert(tree->left, data);
    else
        tree->right = binary_tree_insert(tree->right, data);
    return tree;
}
