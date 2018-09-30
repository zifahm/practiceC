#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "vector.h"

void vector_init(vector *v)
{
    v->capacity = 1;
    v->total = 0;
    v->items = malloc(sizeof(void *) * v->capacity);
}

void vector_add(vector *v, void *item)
{
    if (v->capacity == v->total)
    {

        vector_resize(v, v->capacity + 1);
    }
    v->items[v->total++] = item;
}

int vector_total(vector *v)
{
    return v->total;
}

void *vector_get(vector *v, int index)
{
    return v->items[index];
}

void vector_resize(vector *v, int size)
{
    void **items = realloc(v->items, sizeof(void *) * size);
    if (items)
    {
        v->items = items;
        v->capacity = size;
    }
}

void *vector_at(vector *v, int index)
{
    return v->items[index];
}

void vector_insert(vector *v, int index, void *item)
{
    if (index == 0 || index > v->total)
    {
        return;
    }
    for (int i = v->total - 1; i >= index - 1; i--)
    {
        if (v->capacity == v->total)
        {

            vector_resize(v, v->capacity + 1);
        }
        v->items[i + 1] = v->items[i];
    }
    v->items[index - 1] = item;
    v->total++;
}

void vector_delete(vector *v, int index)
{

    for (int i = index - 1; i < v->total - 1; i++)
    {
        if (v->total < v->capacity)
        {
            vector_resize(v, v->capacity - 2);
        }
        v->items[i] = v->items[i + 1];
    }
    v->total--;
}

void vector_remove(vector *v, void *item)
{
    for (int i = 0; i < v->total; i++)
    {
        if (strcmp(v->items[i], (char *)item) == 0)
        {
            vector_delete(v, i + 1);
        }
    }
}
int vector_find(vector *v, void *item)
{
    for (int i = 0; i < v->total; i++)
    {
        if (strcmp(v->items[i], (char *)item) == 0)
        {
            return i + 1;
        }
    }
    return -1;
}