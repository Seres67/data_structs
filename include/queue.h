// Copyright 2023 <Seres67>

#ifndef MYSTD_QUEUE_H
#define MYSTD_QUEUE_H

#include <mystd.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct fifo {
    void **data;
    size_t size;
    size_t capacity;
} fifo_t;

MYSTD_PUBLIC fifo_t *stack_new(size_t capacity, void *data);
MYSTD_PUBLIC void stack_delete(fifo_t *stack);
MYSTD_PUBLIC fifo_t *stack_push(fifo_t *stack, void *data);
MYSTD_PUBLIC void *stack_peek(fifo_t *stack);
MYSTD_PUBLIC void *stack_pop(fifo_t *stack);

#endif  // MYSTD_QUEUE_H
