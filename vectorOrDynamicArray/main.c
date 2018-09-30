#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"
int main()
{
    vector v;
    vector_init(&v);

    vector_add(&v, "Bonjour");
    vector_add(&v, "tout");
    vector_add(&v, "le");
    vector_add(&v, "monde");

    for (int i = 0; i < vector_total(&v); i++)
        printf("%s ", (char *)vector_get(&v, i));
    printf("\n");

    vector_delete(&v, 3);
    vector_delete(&v, 2);
    vector_delete(&v, 1);

    vector_insert(&v, 1, "Hello");

    vector_add(&v, "World");

    for (int i = 0; i < vector_total(&v); i++)
        printf("%s ", (char *)vector_get(&v, i));
    printf("\n");

    free(v.items);
}
