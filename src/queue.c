// Copyright 2023 <Seres67>

#include "include/queue.h"
#include <stdio.h>

/**
 * allocates a new queue
 * @param capacity preallocates <capacity> elements
 * @param data element to add to queue, can be NULL
 * @returns new queue
 */
fifo_t *queue_new(size_t capacity, void *data) {
    fifo_t *queue;
    queue = malloc(sizeof(fifo_t));
    if (!queue)
        return NULL;
    queue->size = 1;
    queue->capacity = capacity + 1;
    queue->data = malloc(sizeof(void *) * (capacity + 1));
    if (!queue->data) {
        free(queue);
        return NULL;
    }
    queue->data[0] = data;
    for (int i = 1; i <= capacity; ++i) {
        queue->data[i] = NULL;
    }
    return queue;
}

/**
 * frees queue memory
 * @attention does NOT delete each element
 * @param queue queue to free
 */
void queue_delete(fifo_t *queue) {
    free(queue->data);
    free(queue);
}

/**
 * pushes an element to the queue
 * @param queue queue to push to
 * @param data element to push
 * @return modified queue or NULL if realloc failed
 */
fifo_t *queue_push(fifo_t *queue, void *data) {
    if (queue->size + 1 >= queue->capacity) {
        queue->data =
            realloc(queue->data, sizeof(void *) * (queue->capacity + 1));
        if (!queue->data) {
            free(queue);
            return NULL;
        }
        queue->capacity += 1;
    }
    queue->data[queue->size] = data;
    queue->size += 1;
    return queue;
}

/**
 * returns a pointer to the first element
 * @param queue queue to get the pointer from
 * @return pointer to the first element
 */
void *queue_peek(fifo_t *queue) { return queue->data[0]; }

/**
 * pops first element of the queue
 * @param queue the queue to pop from
 * @return the popped element
 */
void *queue_pop(fifo_t *queue) {
    void *tmp = queue->data[0];
    for (int i = 1; i < queue->size; ++i) {
        queue->data[i - 1] = queue->data[i];
    }
    queue->data[queue->size] = NULL;
    queue->size -= 1;
    return tmp;
}
