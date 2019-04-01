#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gmodule.h>
#include "vendas.h"
#include "clientNoBuy.h"
#include "leitura.h"
#include "findProduct.h"

gint printVendaTree(gpointer key, gpointer value, gpointer data){
    printVenda((VENDA) value);
    return FALSE;
}

int main() {
	GTree * vendas;
	GTree * produtos;
	GTree * clientes;
	vendas = g_tree_new_full((GCompareDataFunc) strcmp,NULL,(GDestroyNotify) free,(GDestroyNotify) destroyVenda);
	clientes = g_tree_new_full((GCompareDataFunc) strcmp,NULL, NULL, (GDestroyNotify) free);
	produtos = g_tree_new_full((GCompareDataFunc) strcmp,NULL, NULL, (GDestroyNotify) free);

    /*QUERY1*/
	getClientes(clientes);
	getProdutos(produtos);
 	getVendas(vendas, produtos, clientes);
    /*QUERY2*/
    printArray(findProducts(produtos, 'C'));
    /*QUERY6*/
    /*printf("\nYes?%d\n", didNotBuy(vendas,produtos,clientes));*/


	/*printAVL(clientes);
	//printAVL(produtos);
	//printAVL(vendas);
	//g_tree_foreach(vendas, printVendaTree, NULL);*/

	/*printf("Vendas Escritas: %d\n", vWrite);*/
	printf("Número de clientes:%d\nNúmero de Produtos:%d\nNúmero de vendas:%d\n",
			g_tree_nnodes(clientes), g_tree_nnodes(produtos), g_tree_nnodes(vendas));

	g_tree_destroy(vendas);
	g_tree_destroy(clientes);
	g_tree_destroy(produtos);

	return 0;
}
