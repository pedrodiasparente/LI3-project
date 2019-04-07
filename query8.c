#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "faturacao.h"
#include "userData.h"

static int nVendasIntervaloAux(void * prod, void * faturacao, void * data) {
	int * a;
	int * b;
	int * vendas;
	int i,j;
	vendas = (int*) getData1(data);
	a = (int*) getData1(getData2(data));
	b = (int*) getData2(getData2(data));
	
	for(i=*a; i<=*b; i++)
		for(j=1; j<4;j++)
			*vendas += getNVendasP(i, faturacao, j) + getNVendasN(i, faturacao, j);

	return FALSE;
}

int nVendasIntervalo(FATGLOBAL fg, int a , int b){
	int vendas = 0;
	DATA d, intervalo;
	intervalo = data(&a,&b);
	d = data(&vendas,intervalo);
	traverseFatGlobal(fg, nVendasIntervaloAux, d);
	return vendas;
}

static int totFatIntervaloAux(void * prod, void * faturacao, void * data) {
	int * a;
	int * b;
	float * fat;
	int i,j;
	fat = getData1(data);
	a = getData1(getData2(data));
	b = getData2(getData2(data));
	
	for(i=*a; i<=*b; i++)
		for(j=1; j<4;j++)
			*fat += getPrecoP(i, faturacao, j) + getPrecoN(i, faturacao, j);

	return FALSE;
}

float totFatIntervalo(FATGLOBAL fg, int a , int b){
	float fatura = 0;
	DATA d, intervalo;
	intervalo = data(&a,&b);
	d = data(&fatura,intervalo);
	traverseFatGlobal(fg, totFatIntervaloAux, d);
	return fatura;
}