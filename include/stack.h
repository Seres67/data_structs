// Copyright 2023 <Seres67>

#ifndef MYSTD_STACK_H
#define MYSTD_STACK_H

#include <mystd.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct lifo {
    void **data;
    size_t size;
    size_t capacity;
} lifo_t;

MYSTD_PUBLIC lifo_t *stack_new(size_t capacity, void *data);
MYSTD_PUBLIC void stack_delete(lifo_t *stack);
MYSTD_PUBLIC lifo_t *stack_push(lifo_t *stack, void *data);
MYSTD_PUBLIC void *stack_peek(lifo_t *stack);
MYSTD_PUBLIC void *stack_pop(lifo_t *stack);

#endif  // MYSTD_STACK_H
