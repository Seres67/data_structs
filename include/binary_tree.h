// Copyright 2023 <Seres67>

#ifndef MYSTD_BINARY_TREE_H
#define MYSTD_BINARY_TREE_H

#include <mystd.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct binary_tree {
    void *data;
    struct binary_tree *left;
    struct binary_tree *right;
} binary_tree_t;

MYSTD_PUBLIC binary_tree_t *binary_tree_new(void *data);
MYSTD_PUBLIC binary_tree_t *binary_tree_insert(binary_tree_t *tree, void *data);

#endif  // MYSTD_BINARY_TREE_H
