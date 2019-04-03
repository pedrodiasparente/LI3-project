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

    CAT_CLIENTES p = malloc(sizeof(CAT_CLIENTES));

    GTree * clientes = g_tree_new_full((GCompareDataFunc) strcmp,NULL, NULL, (GDestroyNotify) free);

    p->clientes = clientes;

    return p;
}

void destroy_Cat_cliente(CAT_CLIENTES p){
    g_tree_destroy (p->clientes);
    free(p);
}

void insert_Cat_cliente(CAT_CLIENTES p, char *cliente){
	g_tree_insert(p->clientes, cliente, cliente);
}

int lookup_Cat_cliente(CAT_CLIENTES p, char *cliente){
	return ((g_tree_lookup (p->clientes, cliente)) != NULL);
}

void foreach_Cat_cliente(CAT_CLIENTES p, GTraverseFunc func, gpointer user_data){
	g_tree_foreach(p->clientes, func, user_data);
}

int num_Cat_cliente(CAT_CLIENTES p) {
	return g_tree_nnodes(p->clientes);
}
