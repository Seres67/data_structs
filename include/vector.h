// Copyright 2023 <Seres67>

#ifndef MYSTD_VECTOR_H
#define MYSTD_VECTOR_H

#include <mystd.h>
#include <stddef.h>

typedef struct vector {
    void **data;
    size_t size;
    size_t capacity;
} vector_t;

MYSTD_PUBLIC vector_t *vector_new(size_t size, void *data);
MYSTD_PUBLIC void vector_delete(vector_t *vector);
MYSTD_PUBLIC vector_t *vector_push(vector_t *vector, void *data);
MYSTD_PUBLIC void *vector_pop(vector_t *vector);
MYSTD_PUBLIC size_t vector_find(vector_t *vector, const void *data);
MYSTD_PUBLIC void *vector_remove(vector_t *vector, size_t index);

#endif // MYSTD_VECTOR_H
