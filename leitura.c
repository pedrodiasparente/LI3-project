#define _GNU_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmodule.h>
#include <glib.h>
#include "avltree.h"
#include "vendas.h"
#include "clientNoBuy.h"

void getClientes(GTree * tree){
	FILE * fp;
	char * niceBuffer, * actualBuffer;
	char buffer[35];

	fp = fopen("./Ficheiros/Clientes.txt", "r");

	while(fgets(buffer, 35, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		actualBuffer = strdup(niceBuffer);
		g_tree_insert(tree, actualBuffer, actualBuffer);
	}

	fclose(fp);
}

void getProdutos(GTree * tree){
	FILE * fp;
	char * niceBuffer, * actualBuffer;
	char buffer[35];

	fp = fopen("./Ficheiros/Produtos.txt", "r");

	while(fgets(buffer, 35, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		actualBuffer = strdup(niceBuffer);
		g_tree_insert(tree, actualBuffer, actualBuffer);
	}

	fclose(fp);
}

int valVendas(VENDA v, GTree * produtos, GTree * clientes){
	int val;
	val = 1;

    if ((g_tree_lookup(produtos, getProduto(v))) == NULL) val = 0;

	if (getPreco(v) < 0 || getPreco(v) >= 1000.0) val = 0;

	if (getQuantidade(v) < 1 || getQuantidade(v) > 200) val = 0;

	if (getPromo(v) != 'N' && getPromo(v) != 'P') val = 0;

	if ((g_tree_lookup(clientes, getCliente(v))) == NULL) val = 0;

	if (getMes(v) < 1 || getMes(v) > 12) val = 0;

	if (getFilial(v) < 1 || getFilial(v) > 3) val = 0;

	return val;
}

void getVendas(GTree * vendas, GTree * prod, GTree * client){
	FILE * fp;
	char* lnBuffer;
	char buffer[35];
	int val;
	VENDA v;

	fp = fopen("./Ficheiros/Vendas_1M.txt", "r");

	while(fgets(buffer, 35, fp)) {
		lnBuffer = strdup(buffer);
		lnBuffer = strtok(lnBuffer, "\r\n");

		v = strToVenda(buffer);

		val = valVendas(v, prod, client);

		if (val){
			g_tree_insert(vendas, lnBuffer, v);
		}
	}
}
