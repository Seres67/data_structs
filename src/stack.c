// Copyright 2023 <Seres67>

#include "include/stack.h"

/**
 * allocates a new stack
 * @param capacity preallocates <capacity> elements
 * @param data element to add to stack, can be NULL
 * @returns new stack
 */
lifo_t *stack_new(size_t capacity, void *data) {
    lifo_t *stack;
    stack = malloc(sizeof(lifo_t));
    if (!stack)
        return NULL;
    stack->size = 1;
    stack->capacity = capacity + 1;
    stack->data = malloc(sizeof(void *) * (capacity + 1));
    if (!stack->data) {
        free(stack);
        return NULL;
    }
    stack->data[0] = data;
    for (int i = 1; i <= capacity; ++i) {
        stack->data[i] = NULL;
    }
    return stack;
}

/**
 * frees stack memory
 * @attention does NOT delete each element
 * @param stack stack to free
 */
void stack_delete(lifo_t *stack) {
    free(stack->data);
    free(stack);
}

/**
 * pushes an element to the stack
 * @param stack stack to push to
 * @param data element to push
 * @return modified stack or NULL if realloc failed
 */
lifo_t *stack_push(lifo_t *stack, void *data) {
    if (stack->size + 1 >= stack->capacity) {
        stack->data =
            realloc(stack->data, sizeof(void *) * (stack->capacity + 1));
        if (!stack->data) {
            free(stack);
            return NULL;
        }
        stack->capacity += 1;
    }
    stack->data[stack->size] = data;
    stack->size += 1;
    return stack;
}

/**
 * returns a pointer to the last element
 * @param stack stack to get the pointer from
 * @return pointer to the last element
 */
void *stack_peek(lifo_t *stack) { return stack->data[stack->size - 1]; }

/**
 * pops last element of the stack
 * @param stack the stack to pop from
 * @return the popped element
 */
void *stack_pop(lifo_t *stack) {
    void *tmp = stack->data[stack->size - 1];
    stack->data[stack->size - 1] = NULL;
    stack->size -= 1;
    return tmp;
}
