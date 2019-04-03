#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include <stdlib.h>
#include "catClientes.h"

struct cat_clientes {
	GTree * clientes;
};

CAT_CLIENTES new_Cat_cliente(){

    CAT_CLIENTES c = malloc(sizeof(CAT_CLIENTES));

    GTree * clientes = g_tree_new((GCompareFunc) strcmp);

    c->clientes = clientes;

    return c;
}

void destroy_Cat_cliente(CAT_CLIENTES c){
    g_tree_destroy(c->clientes);
	free(c);
}

void insert_Cat_cliente(CAT_CLIENTES c, char *cliente){
	g_tree_insert(c->clientes, cliente, cliente);
}

int lookup_Cat_cliente(CAT_CLIENTES c, char *cliente){
	return ((g_tree_lookup (c->clientes, cliente)) != NULL);
}

void foreach_Cat_cliente(CAT_CLIENTES c, GTraverseFunc func, gpointer user_data){
	g_tree_foreach(c->clientes, func, user_data);
}

int num_Cat_cliente(CAT_CLIENTES c) {
	return g_tree_nnodes(c->clientes);
}
