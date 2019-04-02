#include <string.h>
#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include <stdlib.h>
#include "faturacao.h"

struct faturacao {
    int * * nVendasP;
    int * * nVendasN;
    int * * precoTotalP;
    int * * precoTotalN;
};

struct fatGlobal {
    GTree * faturacaoGlobal;
};

FATURACAO newFaturacao(){
    int i, j;

    FATURACAO f = malloc(sizeof(FATURACAO));

    int * * nVendasP = malloc(sizeof(int *)*3);
    int * * nVendasN = malloc(sizeof(int *)*3);
    int * * precoTotalP = malloc(sizeof(int *)*3);
    int * * precoTotalN = malloc(sizeof(int *)*3);

    for(i = 0; i < 3; i++){
        nVendasP[i] = malloc(sizeof(int) * 12);
        nVendasN[i] = malloc(sizeof(int) * 12);
        precoTotalP[i] = malloc(sizeof(int) * 12);
        precoTotalN[i] = malloc(sizeof(int) * 12);
    }

    for(j = 0; j < 12; j++)
        for(i = 0; i < 3; i++){
            nVendasP[i][j] = 0;
            nVendasN[i][j] = 0;
            precoTotalP[i][j] = 0;
            precoTotalN[i][j] = 0;
    }

    (f -> nVendasN) = nVendasN;
    (f -> nVendasP) = nVendasP;
    (f -> precoTotalN) = precoTotalN;
    (f -> precoTotalP) = precoTotalP;

    return f;
}

void destroyFacturacao(FATURACAO f){
    int i;
    for(i = 0; i < 3; i++)
        free((f -> nVendasN)[i]);
    for(i = 0; i < 3; i++)
        free((f -> nVendasP)[i]);
    for(i = 0; i < 3; i++)
        free((f -> precoTotalN)[i]);
    for(i = 0; i < 3; i++)
        free((f -> precoTotalP)[i]);
}

/*------------------*/
int getNVendasP(int mes, FATURACAO f, int filial) {
	return (f->nVendasP)[filial][mes-1];
}

int getNVendasN(int mes, FATURACAO f, int filial) {
	return (f->nVendasN)[filial][mes-1];
}

int getPrecoP(int mes, FATURACAO f, int filial) {
	return (f->precoTotalP)[filial][mes-1];
}

int getPrecoN(int mes, FATURACAO f, int filial) {
	return (f->precoTotalN)[filial][mes-1];
}
/*------------------*/
void incNVendasP(int mes, FATURACAO f, int filial){
	(f->nVendasP)[filial][mes-1]++;
}

void ncNVendasN(int mes, FATURACAO f, int filial) {
	(f->nVendasN)[filial][mes-1]++;
}

void setPrecoTotalP(int mes, FATURACAO f,int filial, int preco) {
	(f->precoTotalP)[filial][mes-1] += preco;
}

void setPrecoTotalN(int mes, FATURACAO f,int filial, int preco) {
	(f->precoTotalN)[filial][mes-1] = preco;
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
