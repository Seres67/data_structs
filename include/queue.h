// Copyright 2023 <Seres67>

#include <stddef.h>
#include <stdlib.h>

typedef struct fifo {
    void **data;
    size_t size;
    size_t capacity;
} fifo_t;

fifo_t *stack_new(size_t capacity, void *data);
void stack_delete(fifo_t *stack);
fifo_t *stack_push(fifo_t *stack, void *data);
void *stack_peek(fifo_t *stack);
void *stack_pop(fifo_t *stack);
