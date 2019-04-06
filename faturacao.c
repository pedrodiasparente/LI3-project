#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gmodule.h>
#include "faturacao.h"

struct faturacao {
    int * * nVendasP;
    int * * nVendasN;
    float * * precoTotalP;
    float * * precoTotalN;
};

struct fatGlobal {
    GTree * faturacaoGlobal;
};

FATURACAO newFaturacao(){
    int i, j;

    FATURACAO f = malloc(sizeof(FATURACAO)*4);

    (f -> nVendasP) = malloc(sizeof(int *) * 3);
    (f -> nVendasN) = malloc(sizeof(int *) * 3);
    (f -> precoTotalP) = malloc(sizeof(float *) * 3);
    (f -> precoTotalN) = malloc(sizeof(float *) * 3);

    for(i = 0; i < 3; i++){
        (f -> nVendasP)[i] = malloc(sizeof(int) * 12);
        (f -> nVendasN)[i] = malloc(sizeof(int) * 12);
        (f -> precoTotalP)[i] = malloc(sizeof(float) * 12);
        (f -> precoTotalN)[i] = malloc(sizeof(float) * 12);
    }

    for(j = 0; j < 12; j++)
        for(i = 0; i < 3; i++){
            (f -> nVendasP)[i][j] = 0;
            (f -> nVendasN)[i][j] = 0;
            (f -> precoTotalP)[i][j] = 0;
            (f -> precoTotalN)[i][j] = 0;
    }

    return f;
}

void destroyFaturacao(FATURACAO f){
    int i;

    for(i = 0; i < 3; i++){
        free((f -> nVendasN)[i]);
        free((f -> nVendasP)[i]);
        free((f -> precoTotalN)[i]);
        free((f -> precoTotalP)[i]);
    }

    free(f -> nVendasN);
    free(f -> nVendasP);
    free(f -> precoTotalP);
    free(f -> precoTotalN);

    free(f);
}

/*------------------*/
int getNVendasP(int mes, FATURACAO f, int filial) {
	return (f->nVendasP)[filial-1][mes-1];
}

int getNVendasN(int mes, FATURACAO f, int filial) {
	return (f->nVendasN)[filial-1][mes-1];
}

float getPrecoP(int mes, FATURACAO f, int filial) {
	return (f->precoTotalP)[filial-1][mes-1];
}

float getPrecoN(int mes, FATURACAO f, int filial) {
	return (f->precoTotalN)[filial-1][mes-1];
}
/*------------------*/
void incNVendas(FATURACAO f, int mes, int filial, char promo){
    if(promo == 'P')
        ((f -> nVendasP)[filial-1][mes-1])++;
    else if (promo == 'N')
        ((f -> nVendasN)[filial-1][mes-1])++;
}

void somaPrecoTotal(FATURACAO f, int mes, int filial, float preco, char promo){
    if (promo == 'P')
        ((f -> precoTotalP)[filial-1][mes-1]) += preco;
    else if (promo == 'N')
        ((f -> precoTotalN)[filial-1][mes-1]) += preco;
}

/*FATGLOBAL-----------------------------------------*/


FATGLOBAL newFatGlobal(){
    FATGLOBAL f = malloc(sizeof(FATGLOBAL));

    GTree * faturacaoGlobal = g_tree_new_full((GCompareDataFunc) strcmp, NULL, (GDestroyNotify)  free, (GDestroyNotify) destroyFaturacao);

    f -> faturacaoGlobal = faturacaoGlobal;

    return f;
}

gint initFatGlobal(gpointer key, gpointer value, gpointer data){
    FATURACAO f;

    f = newFaturacao();

    insertFatGlobal(data, value, f);

    return FALSE;
}

void destroyFatGlobal(FATGLOBAL f){
    g_tree_destroy (f->faturacaoGlobal);
    free(f);
}

void insertFatGlobal(FATGLOBAL f, char *produto, FATURACAO fat){
	g_tree_insert(f->faturacaoGlobal, produto, fat);
}

gpointer lookupFatGlobal(FATGLOBAL f, char *produto){
	return (g_tree_lookup (f->faturacaoGlobal, produto));
}

/*this one not sure if necessary*/
void traverseFatGlobal(FATGLOBAL f, GTraverseFunc func, gpointer user_data){
	g_tree_foreach(f->faturacaoGlobal, func, user_data);
}

int numFatGlobal(FATGLOBAL f) {
	return g_tree_nnodes(f->faturacaoGlobal);
}

/*int getNVendasPTotal(int mes, FATURACAO f)  {
	return (getNVendasP(mes,f,0) + getNVendasP(mes,f,1) + getNVendasP(mes,f,2));
}

int getNVendasNTotal(int mes, FATURACAO f)  {
	return (getNVendasN(mes,f,0) + getNVendasN(mes,f,1) + getNVendasN(mes,f,2));
}

int getPrecoPTotal(int mes, FATURACAO f)  {
	return (getPrecoP(mes,f,0) + getPrecoP(mes,f,1) + getPrecoP(mes,f,2));
}

int getPrecoNTotal(int mes, FATURACAO f)  {
	return (getPrecoN(mes,f,0) + getPrecoN(mes,f,1) + getPrecoN(mes,f,2));
}
------------------*/
