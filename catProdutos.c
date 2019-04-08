#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include <stdlib.h>
#include "catProdutos.h"

struct cat_produtos {
	GTree * produtos;
};

static int compInt(void * a, void * b){
	int * ca, * cb;
	ca = a;
	cb = b;
	if(*ca < *cb) return 1;
	if(*ca > *cb) return -1;
	else return 0;
}

CAT_PRODUTOS new_Cat_prod_ord(){

    CAT_PRODUTOS p = malloc(sizeof(CAT_PRODUTOS));

    GTree * produtos = g_tree_new_full((GCompareDataFunc) compInt,NULL, (GDestroyNotify) free, (GDestroyNotify) free);

    p->produtos = produtos;

    return p;
}

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

void insert_Cat_prod_ord(CAT_PRODUTOS p, char *produto, int * quant){
	g_tree_insert(p->produtos, quant, produto);
}

void remove_Cat_prod(CAT_PRODUTOS p, char * prod){
	g_tree_remove(p->produtos, prod);
}

void remove_Cat_prod_ord(CAT_PRODUTOS p, int * key){
	g_tree_remove(p->produtos, key);
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

static gboolean print_GTree(gpointer key, gpointer value, gpointer data) {
    printf("%s\n", (char *) value);
    return FALSE;
}

void print_Cat_prod(CAT_PRODUTOS p) {
    foreach_Cat_prod(p, print_GTree, NULL);
}
