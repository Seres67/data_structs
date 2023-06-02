// Copyright 2023 <Seres67>

#ifndef MYSTD_LINKED_LIST_H
#define MYSTD_LINKED_LIST_H

#include <mystd.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct linked_list {
    void *data;
    struct linked_list *next;
    struct linked_list *prev;
} linked_list_t;

MYSTD_PUBLIC linked_list_t *linked_list_new(void *data);
MYSTD_PUBLIC void linked_list_delete(linked_list_t *list);
MYSTD_PUBLIC linked_list_t *linked_list_push(linked_list_t *list, void *data);
MYSTD_PUBLIC void *linked_list_pop(linked_list_t *list);
MYSTD_PUBLIC void *linked_list_remove(linked_list_t *list, size_t index);

#endif  // MYSTD_LINKED_LIST_H
