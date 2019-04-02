#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "gestaoFilial.h"

#define _GNU_SOURCE 1
#define N 0
#define P 1


struct gestaoCliente{
    GTree * produtos;
}

GESTAOCLIENTE newGestaoCliente(){
    GESTAOCLIENTE gf;

    gf = malloc(sizeof(GESTAOCLIENTE));

    (gf -> produtos) = g_tree_new((GCompareFunc) strcmp);

    return gf;
}

void somaMat(int produtoData[][],int newProduto[][]){
    int i,j;

    for(i=1;i<=3;i++)
        for(j=1;j<=12;j++)
            produtoData[i][j] =  (produtoData[i][j] + newProduto[i][j]);
}

void addProdutoCliente(GESTAOCLIENTE g, char * prod, int quant, int mes, char promo){
    int newProduto[12][2];
    int produtoData[12][2];
    int i, j;

    for(i=1;i<=3;i++)
        for(j=1;j<=12;j++)
                newProduto[i][j] = 0;

    if(promo = 'N')
        newProduto[mes][N] = quant;
    else
        newProduto[mes][P] = quant;

    produtoData = g_tree_lookup((g->produtos), prod);

    if(produtoData == NULL)
        g_tree_insert((g -> produtos), prod, newProduto);
    else{
        somaMat(produtoData, newProduto);
    }
}
