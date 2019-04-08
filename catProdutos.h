#ifndef CATPRODUTOS_H
#define CATPRODUTOS_H

typedef struct cat_produtos *CAT_PRODUTOS;

CAT_PRODUTOS new_Cat_prod();

CAT_PRODUTOS new_Cat_prod_ord();

void destroy_Cat_prod(CAT_PRODUTOS p);

void insert_Cat_prod(CAT_PRODUTOS p, char *produto);

void insert_Cat_prod_ord(CAT_PRODUTOS p, char *produto, int * quant);

void remove_Cat_prod(CAT_PRODUTOS p, char * prod);

void remove_Cat_prod_ord(CAT_PRODUTOS p, int * key);

int lookup_Cat_prod(CAT_PRODUTOS p, char* produto);

void foreach_Cat_prod(CAT_PRODUTOS p, GTraverseFunc func, gpointer user_data);

int num_Cat_prod(CAT_PRODUTOS p);

void print_Cat_prod(CAT_PRODUTOS p);

#endif
