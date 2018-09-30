#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector
{
    void **items;
    int capacity;
    int total;
} vector;

void vector_init(vector *);
void vector_add(vector *, void *);
int vector_total(vector *);
void *vector_get(vector *, int);
void vector_resize(vector *, int);
void *vector_at(vector *, int);
void vector_insert(vector *, int, void *);
void vector_delete(vector *, int);
void vector_remove(vector *, void *);
int vector_find(vector *, void *);

#endif