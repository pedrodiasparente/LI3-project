#ifndef CATPRODUTOS_H
#define CATPRODUTOS_H

typedef struct cat_produtos *CAT_PRODUTOS;

CAT_PRODUTOS new_Cat_prod();

void destroy_Cat_prod(CAT_PRODUTOS p);

void insert_Cat_prod(CAT_PRODUTOS p, char *produto);

int lookup_Cat_prod(CAT_PRODUTOS p, char* produto);

void foreach_Cat_prod(CAT_PRODUTOS p, GTraverseFunc func, gpointer user_data);

int num_Cat_prod(CAT_PRODUTOS p);

#endif
