#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include <stdlib.h>
#include "catProdutos.h"

struct cat_produtos {
	GTree * produtos;
};

CAT_PRODUTOS new_Cat_prod(){

    CAT_PRODUTOS p = malloc(sizeof(CAT_PRODUTOS));

    GTree * produtos = g_tree_new_full((GCompareDataFunc) strcmp,NULL, NULL, (GDestroyNotify) free);

    p->produtos = produtos;

    return p;
}

void destroy_Cat_prod(CAT_PRODUTOS p){
    g_tree_destroy (p->produtos);
    free(p);
}

void insert_Cat_prod(CAT_PRODUTOS p, char *produto){
	g_tree_insert(p->produtos, produto, produto);
}

int lookup_Cat_prod(CAT_PRODUTOS p, char *produto){
	return ((g_tree_lookup (p->produtos, produto)) != NULL);
}

void foreach_Cat_prod(CAT_PRODUTOS p, GTraverseFunc func, gpointer user_data){
	g_tree_foreach(p->produtos, func, user_data);
}

int num_Cat_prod(CAT_PRODUTOS p) {
	return g_tree_nnodes(p->produtos);
}
