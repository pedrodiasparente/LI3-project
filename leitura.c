#define _GNU_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmodule.h>
#include <glib.h>
#include "leitura.h"
#include "vendas.h"
#include "faturacao.h"
#include "gestaoFilial.h"
#include "catProdutos.h"
#include "catClientes.h"

void getClientes(CAT_CLIENTES c){
	FILE * fp;
	char * niceBuffer, * actualBuffer;
	char buffer[10];

	fp = fopen("./Ficheiros/Clientes.txt", "r");

	while(fgets(buffer, 10, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		actualBuffer = strdup(niceBuffer);
		insert_Cat_cliente(c, actualBuffer);
	}

	fclose(fp);
}

void getProdutos(CAT_PRODUTOS p){
	FILE * fp;
	char * niceBuffer, * actualBuffer;
	char buffer[10];

	fp = fopen("./Ficheiros/Produtos.txt", "r");

	while(fgets(buffer, 10, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		actualBuffer = strdup(niceBuffer);
		insert_Cat_prod(p, actualBuffer);
	}

	fclose(fp);
}

static int valVendas(VENDA v, CAT_PRODUTOS produtos, CAT_CLIENTES clientes){
	int val;
	val = 1;

    if (!lookup_Cat_prod(produtos, getProduto(v))) val = 0;

	if (getPreco(v) < 0 || getPreco(v) >= 1000.0) val = 0;

	if (getQuantidade(v) < 1 || getQuantidade(v) > 200) val = 0;

	if (getPromo(v) != 'N' && getPromo(v) != 'P') val = 0;

	if (!lookup_Cat_cliente(clientes, getCliente(v))) val = 0;

	if (getMes(v) < 1 || getMes(v) > 12) val = 0;

	if (getFilial(v) < 1 || getFilial(v) > 3) val = 0;

	return val;
}

/*esta aqui está a servir de funçao auxiliar mas devia ser uma funçao mesmo*/
void getGestaoFilial(GESTAOFILIAL * gestFilial, VENDA v){
	GESTAOCLIENTE gestCliente;
	INFOPROD prodActual;
	char * prodAux;

	prodAux = strdup(getProduto(v));
	gestCliente = lookupGestaoFilial(gestFilial[getFilial(v)-1], getCliente(v));
	prodActual = newInfoProd();
	setQuant(prodActual, getMes(v), getQuantidade(v), getPromo(v));

	addProdutoCliente(gestCliente, prodAux, prodActual);
}

/*a getVendas acho que na verdade só está a servir de funçao que faz a getGestaoFilial e getFaturaçao lol*/
void getVendas(FATGLOBAL fatGlobal, GESTAOFILIAL * gestFilial, CAT_PRODUTOS prod, CAT_CLIENTES client){
	FILE * fp;
	char * lnBuffer;
	char buffer[35];
	int val, i;
	VENDA v;
	FATURACAO currentFat;

	foreach_Cat_prod(prod, initFatGlobal, fatGlobal);
	for(i = 0; i < 3; i++)
		foreach_Cat_cliente(client, initGestaoFilial, gestFilial[i]);

	fp = fopen("./Ficheiros/Vendas_1M.txt", "r");

	while(fgets(buffer, 35, fp)) {
		lnBuffer = strdup(buffer);
		lnBuffer = strtok(lnBuffer, "\r\n");

		v = strToVenda(buffer);
		val = valVendas(v, prod, client);
		currentFat = lookupFatGlobal(fatGlobal, getProduto(v));

		free(lnBuffer);

		if (val){
			getGestaoFilial(gestFilial, v);
			incNVendas(currentFat, getMes(v), getFilial(v), getPromo(v));
			somaPrecoTotal(currentFat, getMes(v), getFilial(v), getPreco(v), getPromo(v));
		}
		destroyVenda(v);
	}
}
