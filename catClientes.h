#ifndef CATCLIENTES_H
#define CATCLIENTES_H

typedef struct cat_clientes *CAT_CLIENTES;

CAT_CLIENTES new_Cat_cliente();

void destroy_Cat_cliente(CAT_CLIENTES p);

void insert_Cat_cliente(CAT_CLIENTES p, char *cliente);

int lookup_Cat_cliente(CAT_CLIENTES p, char* cliente);

void foreach_Cat_cliente(CAT_CLIENTES p, GTraverseFunc func, gpointer user_data);

int num_Cat_cliente(CAT_CLIENTES p);

#endif
