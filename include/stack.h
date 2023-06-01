// Copyright 2023 <Seres67>

#include <stddef.h>
#include <stdlib.h>

typedef struct lifo {
    void **data;
    size_t size;
    size_t capacity;
} lifo_t;

lifo_t *stack_new(size_t capacity, void *data);
void stack_delete(lifo_t *stack);
lifo_t *stack_push(lifo_t *stack, void *data);
void *stack_peek(lifo_t *stack);
void *stack_pop(lifo_t *stack);
