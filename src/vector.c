// Copyright 2023 <Seres67>

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <vector.h>

vector_t *vector_new(size_t size, void *data) {
    vector_t *vector = malloc(sizeof(vector_t));
    if (!vector)
        return NULL;
    vector->size = 1;
    vector->capacity = size;
    vector->data = malloc(sizeof(void *) * (size + 1));
    if (!vector->data) {
        free(vector);
        return NULL;
    }
    vector->data[0] = data;
    return vector;
}

void vector_delete(vector_t *vector) {
    free(vector->data);
    free(vector);
}

vector_t *vector_push(vector_t *vector, void *data) {
    if (vector->size + 1 >= vector->capacity) {
        vector->data = realloc(vector->data, vector->capacity + 1);
        if (!vector->data)
            return NULL;
        vector->capacity += 1;
    }
    vector->data[vector->size] = data;
    vector->size += 1;
    return vector;
}

void *vector_pop(vector_t *vector) {
    void *data = vector->data[vector->size - 1];
    vector->data[vector->size - 1] = NULL;
    vector->size -= 1;
    return data;
}

size_t vector_find(vector_t *vector, const void *data) {
    for (size_t i = 0; i < vector->size; ++i) {
        if (vector->data[i] == data) {
            return i;
        }
    }
    return -1;
}

void *vector_remove(vector_t *vector, size_t index) {
    void *data = vector->data[index];
    for (size_t i = index; i < vector->size - 1; ++i) {
        vector->data[i] = vector->data[i + 1];
    }
    vector->data[vector->size - 1] = NULL;
    vector->size -= 1;
    return data;
}
