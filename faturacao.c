#define _GNU_SOURCE 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"

struct faturacao {
    int nVendasP[][];
    int nVendasN[][];
    int precoTotalP[][];
    int precoTotalN[][];
};

//---------
int getNVendasP(int mes, faturacao f, int filial) {
	return f->nVendasP[mes-1];
}

int getNVendasN(int mes, faturacao f, int filial) {
	return f->nVendasN[mes-1];
}

int getPrecoP(int mes, faturacao f, int filial) {
	return f->precoTotalP[mes-1];
}

int getPrecoN(int mes, faturacao f, int filial) {
	return f->precoTotalN[mes-1];
}
//---------
int getNVendasPTotal(int mes, faturacao f)  {
	return (getNVendasP(mes,f,0) + getNVendasP(mes,f,1) + getNVendasP(mes,f,2));
}

int getNVendasNTotal(int mes, faturacao f)  {
	return (getNVendasN(mes,f,0) + getNVendasN(mes,f,1) + getNVendasN(mes,f,2));
}

int getPrecoPTotal(int mes, faturacao f)  {
	return (getPrecoP(mes,f,0) + getPrecoP(mes,f,1) + getPrecoP(mes,f,2));
}

int getPrecoNTotal(int mes, faturacao f)  {
	return (getPrecoN(mes,f,0) + getPrecoN(mes,f,1) + getPrecoN(mes,f,2));
}
//---------
void incNVendasP(int mes, faturacao f, int filial){
	f->nVendasP[mes-1]++;
}

int incNVendasN(int mes, faturacao f, int filial) {
	f->nVendasN[mes-1]++;
}

int setPrecoTotalP(int mes, faturacao f,int filial, int preco) {
	f->precoTotalP[mes-1] += preco;
}

int setPrecoTotalN(int mes, faturacao f,int filial, int preco) {
	f->precoTotalN[mes-1] = preco;
}