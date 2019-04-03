#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gmodule.h>
#include "gestaoFilial.h"

#define _GNU_SOURCE 1
#define N 0
#define P 1


struct gestaoFilial{
    GTree * clientes;
};

struct gestaoCliente{
    GTree * produtos;
};

struct infoProduto{
    int *quantP;
    int *quantN;
}

/*GESTAO DE FILIAL (FUNCOES DE GESTAO DA TREE DE CLIENTES PARA CADA FILIAL)*/

GESTAOFILIAL newGestaoFilial(){
    GESTAOFILIAL gf;

    gf = malloc(sizeof(GESTAOFILIAL));

    (gf -> clientes) = g_tree_new((GCompareFunc) strcmp);

    return gf;
}

void destroy_gestao_filial(GESTAOFILIAL gf){
    g_tree_destroy (gf->clientes);
    free(gf);
}

void insert_gestao_filial(GESTAOFILIAL gf, char *cliente){
    g_tree_insert(gf->clientes, cliente, cliente);
}

gpointer lookup_gestao_filial(GESTAOFILIAL gf, char *cliente){
    return (g_tree_lookup (gf->clientes, cliente));
}

/*this one not sure if necessary*/
void traverseGestFilial(GESTAOFILIAL gf, GTraverseFunc func, gpointer user_data){
    g_tree_foreach(gf->clientes, func, user_data);
}

int num_gestao_filial(GESTAOFILIAL gf) {
    return g_tree_nnodes(gf->clientes);
}

/*GESTAO DE CLIENTE (FUNCOES DE GESTAO DA TREE DE PRODUTOS PARA CADA CLIENTE)*/

GESTAOCLIENTE newGestaoCliente(){
    GESTAOCLIENTE gc;

    gc = malloc(sizeof(GESTAOCLIENTE));

    (gc-> produtos) = g_tree_new((GCompareFunc) strcmp);

    return gc;
}

static void somaMat(int produtoData[][],int newProduto[][]){
    int i,j;

    for(i=0;i<2;i++)
        for(j=0;j<12;j++)
            produtoData[i][j] =  (produtoData[i][j] + newProduto[i][j]);
}

void addProdutoCliente(GESTAOCLIENTE g, char * prod, int quant, int mes, char promo){
    int * * newProduto;
    int * * produtoData;
    int i, j;

    for(i=0;i<2;i++)
        for(j=0;j<12;j++)
            newProduto[i][j] = 0;

    if(promo == 'N')
        newProduto[mes-1][N] = quant;
    else
        newProduto[mes-1][P] = quant;

    produtoData = g_tree_lookup((g->produtos), prod);

    if(produtoData == NULL)
        g_tree_insert((g -> produtos), prod, newProduto);
    else{
        somaMat(produtoData, newProduto);
    }
}

gpointer lookupProdutoCliente(GESTAOCLIENTE g, char * prod){
    return (g_tree_lookup(g -> produtos, prod));
}

/*this one not sure if necessary*/
int numProdutosCliente(GESTAOCLIENTE g){
    return (g_tree_nnodes(g -> produtos));
}
