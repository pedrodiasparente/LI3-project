#define _GNU_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmodule.h>
#include <glib.h>
#include "avltree.h"
#include "vendas.h"

int getFile(AVL *avl, FILE *fp){
	char* niceBuffer;
	char buffer[35];
	int strcount = 0;

	while(fgets(buffer, 35, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		insertAVL(avl, niceBuffer);
		strcount++;
	}
	return strcount;
}

gint printVendaTree(gpointer key, gpointer value, gpointer data){
    printVenda((VENDA) value);
    return FALSE;
}

int valVendas(VENDA v, AVL *prod, AVL *client){
	int val;
	val = 1;

    if (!(searchAVL(*prod, getProduto(v)))) val = 0;

	if (getPreco(v) < 0 || getPreco(v) >= 1000.0) val = 0;

	if (getQuantidade(v) < 1 || getQuantidade(v) > 200) val = 0;

	if (getPromo(v) != 'N' && getPromo(v) != 'P') val = 0;

	if (!(searchAVL(*client, getCliente(v)))) val = 0;

	if (getMes(v) < 1 || getMes(v) > 12) val = 0;

	if (getFilial(v) < 1 || getFilial(v) > 3) val = 0;

	return val;
}

int getVendas(GTree * vendas, AVL *prod, AVL *client, FILE *fp){
	char* lnBuffer;
	char buffer[35];
	int strcount = 0;
	int val;
	VENDA v;

	while(fgets(buffer, 35, fp)) {
		lnBuffer = strdup(buffer);
		lnBuffer = strtok(lnBuffer, "\r\n");

		v = strToVenda(buffer);

		val = valVendas(v, prod, client);

		if (val) {
			strcount++;
			g_tree_insert(vendas, lnBuffer, v);
		}
	}
	return strcount;
}

int main() {
	FILE *fp;
	AVL clientes, produtos;
	GTree * vendas;
	vendas = g_tree_new((GCompareFunc)g_ascii_strcasecmp);
	clientes = produtos = NULL;
	int numClientesReal, numProdutosReal, numVendas;
	numClientesReal = numProdutosReal = numVendas = 0;

	fp = fopen("./Ficheiros/Clientes.txt", "r");
	numClientesReal = getFile(&clientes, fp);
	fclose(fp);

	fp = fopen("./Ficheiros/Produtos.txt", "r");
	numProdutosReal = getFile(&produtos, fp);
	fclose(fp);

	fp = fopen("./Ficheiros/Vendas_1M.txt", "r");
 	numVendas = getVendas(vendas, &produtos, &clientes, fp);
	fclose(fp);

	/*fp = fopen("./Ficheiros/Venda_1MValidas.txt", "w");
	vWrite = writeFile(vendas, fp);
	fclose(fp);*/

	/*printAVL(clientes);
	//printAVL(produtos);
	//printAVL(vendas);*/
	g_tree_foreach(vendas, printVendaTree, NULL);

	/*printf("Vendas Escritas: %d\n", vWrite);*/
	printf("Número de clientes:%d\nNúmero de Produtos:%d\nNúmero de vendas:%d\n",
			numClientesReal, numProdutosReal, g_tree_nnodes(vendas));

	g_tree_destroy(vendas);

	return 0;
}
