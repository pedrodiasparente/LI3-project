#define _GNU_SOURCE 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmodule.h>
#include <unistd.h>
#include <glib.h>
#include "avltree.h"
#include "vendas.h"

gint compareStrings(gconstpointer s1, gconstpointer s2){
	return (strcmp(s1,s2));
}

void getFile(GTree * tree, FILE *fp){
	char * niceBuffer, * actualBuffer;
	char buffer[35];

	while(fgets(buffer, 35, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		actualBuffer = strdup(niceBuffer);
		g_tree_insert(tree, actualBuffer, actualBuffer);
	}
}

gint printVendaTree(gpointer key, gpointer value, gpointer data){
    printVenda((VENDA) value);
    return FALSE;
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

void getVendas(GTree * vendas, GTree * prod, GTree * client, FILE * fp){
	char* lnBuffer;
	char buffer[35];
	int val,i = 0;
	VENDA v;

	while(fgets(buffer, 35, fp)) {
		lnBuffer = strdup(buffer);
		lnBuffer = strtok(lnBuffer, "\r\n");

		v = strToVenda(buffer);

		val = valVendas(v, prod, client);

		if (val){
			printf("Venda nº%d: ", i++);
			printVenda(v);
			g_tree_insert(vendas, lnBuffer, v);
		}
	}
}

int main() {
	FILE *fp;
	GTree * vendas;
	GTree * produtos;
	GTree * clientes;
	vendas = g_tree_new_full((GCompareDataFunc) compareStrings,NULL,(GDestroyNotify) free,(GDestroyNotify) destroyVenda);
	clientes = g_tree_new_full((GCompareDataFunc) compareStrings,NULL, NULL, (GDestroyNotify) free);
	produtos = g_tree_new_full((GCompareDataFunc) compareStrings,NULL, NULL, (GDestroyNotify) free);

	fp = fopen("./Ficheiros/Clientes.txt", "r");
	getFile(clientes, fp);
	fclose(fp);

	fp = fopen("./Ficheiros/Produtos.txt", "r");
	getFile(produtos, fp);
	fclose(fp);

	fp = fopen("./Ficheiros/Vendas_1M.txt", "r");
 	getVendas(vendas, produtos, clientes, fp);
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
			g_tree_nnodes(clientes), g_tree_nnodes(produtos), g_tree_nnodes(vendas));

	g_tree_destroy(vendas);
	g_tree_destroy(clientes);
	g_tree_destroy(produtos);

	return 0;
}
