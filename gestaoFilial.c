#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gmodule.h>
#include "gestaoFilial.h"

#define _GNU_SOURCE 1

struct gestaoFilial{
    GTree * clientes;
};

struct gestaoCliente{
    GTree * produtos;
};

struct infoProduto{
    int *quantP;
    int *quantN;
};

/*GESTAO DE FILIAL (FUNCOES DE GESTAO DA TREE DE CLIENTES PARA CADA FILIAL)*/

GESTAOFILIAL newGestaoFilial(){
    GESTAOFILIAL gf;

    gf = malloc(sizeof(GESTAOFILIAL));

    (gf -> clientes) = g_tree_new_full((GCompareDataFunc) strcmp, NULL, (GDestroyNotify)  free, (GDestroyNotify) destroyGestaoCliente);

    return gf;
}

gint initGestaoFilial(gpointer key, gpointer value, gpointer data){
    GESTAOCLIENTE g;

    g = newGestaoCliente();

    insertGestaoFilial(data, value, g);

    return FALSE;
}

void destroyGestaoFilial(GESTAOFILIAL gf){
    g_tree_destroy (gf->clientes);
    free(gf);
}

gpointer lookupGestaoFilial(GESTAOFILIAL gf, char *cliente){
    return (g_tree_lookup (gf->clientes, cliente));
}

void insertGestaoFilial(GESTAOFILIAL gf, char *cliente, GESTAOCLIENTE gc){
    g_tree_insert(gf -> clientes, cliente, gc);
}

/*this one not sure if necessary*/
void traverseGestFilial(GESTAOFILIAL gf, GTraverseFunc func, gpointer user_data){
    g_tree_foreach(gf -> clientes, func, user_data);
}

int numGestaoFilial(GESTAOFILIAL gf) {
    return g_tree_nnodes(gf -> clientes);
}
/*GESTAO DE CLIENTE (FUNCOES DE GESTAO DA TREE DE PRODUTOS PARA CADA CLIENTE)*/

GESTAOCLIENTE newGestaoCliente(){
    GESTAOCLIENTE gc;

    gc = malloc(sizeof(GESTAOCLIENTE));

    (gc -> produtos) = g_tree_new_full((GCompareDataFunc) strcmp, NULL, (GDestroyNotify)  free, (GDestroyNotify) destroyInfoProd);

    return gc;
}

static void somaProdInfo(INFOPROD produtoData, INFOPROD newProduto){
    int i;

    for(i = 0; i < 12; i++)
        setQuant(produtoData, i, getQuant(newProduto, i, 'N'), 'N');
    for(i = 0; i < 12; i++)
        setQuant(produtoData, i, getQuant(newProduto, i, 'P'), 'P');

}

void addProdutoCliente(GESTAOCLIENTE g, char * prod, INFOPROD newProduto){
    INFOPROD produtoData;

    produtoData = lookupProdutoCliente(g, prod);
    if(produtoData == NULL){
        g_tree_insert((g -> produtos), prod, newProduto);
    }
    else{
        somaProdInfo(produtoData, newProduto);
    }
}

gpointer lookupProdutoCliente(GESTAOCLIENTE g, char * prod){
    return (g_tree_lookup(g -> produtos, prod));
}

/*this one not sure if necessary*/
int numProdutosCliente(GESTAOCLIENTE g){
    return (g_tree_nnodes(g -> produtos));
}

void destroyGestaoCliente(GESTAOCLIENTE gc){
    g_tree_destroy (gc -> produtos);
    free(gc);
}


/*infoProduto------------------------------------------*/

INFOPROD newInfoProd(){
    INFOPROD infoProduto;
    int i;

    infoProduto = malloc(sizeof(INFOPROD));

    (infoProduto -> quantN) = malloc(sizeof(int)*12);
    (infoProduto -> quantP) = malloc(sizeof(int)*12);

    for(i = 0; i < 12; i++){
        (infoProduto -> quantN)[i] = 0;
        (infoProduto -> quantP)[i] = 0;
    }

    return infoProduto;
}

void destroyInfoProd(INFOPROD i){
    free(i -> quantN);
    free(i -> quantP);
    free(i);
}

int getQuant(INFOPROD i, int mes, char promo){
    if(promo == 'N')
        return ((i -> quantN)[mes]);
    else
        return ((i -> quantP)[mes]);
}

void setQuant(INFOPROD i, int mes, int quant, char promo){
    if(promo == 'N')
        (i -> quantN)[mes] += quant;
    else
        (i -> quantN)[mes] += quant;
}
