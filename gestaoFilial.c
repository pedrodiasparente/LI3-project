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
    float *precoP;
    float *precoN;
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
    for(i = 0; i < 12; i++)
        setPrecoGF(produtoData, i, getPrecoGF(newProduto, i, 'N'), 'N');
    for(i = 0; i < 12; i++)
        setPrecoGF(produtoData, i, getPrecoGF(newProduto, i, 'P'), 'P');

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

void traverseGestClient(GESTAOCLIENTE g, GTraverseFunc func, gpointer user_data){
    g_tree_foreach(g -> produtos, func, user_data);
}

void destroyGestaoCliente(GESTAOCLIENTE gc){
    g_tree_destroy (gc -> produtos);
    free(gc);
}


/*infoProduto------------------------------------------*/

INFOPROD newInfoProd(){
    INFOPROD infoProduto;
    int i;

    infoProduto = malloc(sizeof(INFOPROD)*4);

    (infoProduto -> quantN) = malloc(sizeof(int)*12);
    (infoProduto -> quantP) = malloc(sizeof(int)*12);
    (infoProduto -> precoN) = malloc(sizeof(float)*12);
    (infoProduto -> precoP) = malloc(sizeof(float)*12);

    for(i = 0; i < 12; i++){
        (infoProduto -> quantN)[i] = 0;
        (infoProduto -> quantP)[i] = 0;
        (infoProduto -> precoN)[i] = 0;
        (infoProduto -> precoP)[i] = 0;
    }

    return infoProduto;
}

void destroyInfoProd(INFOPROD i){
    free(i -> quantN);
    free(i -> quantP);
    free(i -> precoN);
    free(i -> precoP);
    free(i);
}

int getQuant(INFOPROD i, int mes, char promo){
    if(promo == 'N')
        return ((i -> quantN)[mes]);
    else if (promo == 'P')
        return ((i -> quantP)[mes]);
    else return 0;
}

void setQuant(INFOPROD i, int mes, int quant, char promo){
    if(promo == 'N')
        (i -> quantN)[mes] += quant;
    else if (promo == 'P')
        (i -> quantN)[mes] += quant;
    else;
}

float getPrecoGF(INFOPROD i, int mes, char promo){
    if(promo == 'N')
        return ((i -> precoN)[mes]);
    else if (promo == 'P')
        return ((i -> precoP)[mes]);
    else return 0;
}

void setPrecoGF(INFOPROD i, int mes, float preco, char promo){
    if(promo == 'N')
        (i -> precoN)[mes] += preco;
    else if (promo == 'P')
        (i -> precoN)[mes] += preco;
    else;
}
