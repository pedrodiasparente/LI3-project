#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gmodule.h>
#include "vendas.h"
#include "clientNoBuy.h"
#include "leitura.h"
#include "findProduct.h"
#include "catProdutos.h"

gint printVendaTree(gpointer key, gpointer value, gpointer data){
    printVenda((VENDA) value);
    return FALSE;
}

int main() {
	GTree * vendas;
	CAT_PRODUTOS produtos;
	GTree * clientes;
	vendas = g_tree_new_full((GCompareDataFunc) strcmp,NULL,(GDestroyNotify) free,(GDestroyNotify) destroyVenda);
	clientes = g_tree_new_full((GCompareDataFunc) strcmp,NULL, NULL, (GDestroyNotify) free);
	produtos = new_Cat_prod();

    /*QUERY1*/
	getClientes(clientes);
	getProdutos(produtos);
 	getVendas(vendas, produtos, clientes);
    /*QUERY2*/
    printArray(findProducts(produtos, 'A'));
    /*QUERY6*/
    /*printf("\nYes?%d\n", didNotBuy(vendas,produtos,clientes));*/


	/*printAVL(clientes);
	//printAVL(produtos);
	//printAVL(vendas);
	//g_tree_foreach(vendas, printVendaTree, NULL);*/

	/*printf("Vendas Escritas: %d\n", vWrite);*/
	printf("Número de clientes:%d\nNúmero de Produtos:%d\nNúmero de vendas:%d\n",
			g_tree_nnodes(clientes), num_Cat_prod(produtos), g_tree_nnodes(vendas));

	g_tree_destroy(vendas);
	g_tree_destroy(clientes);
	destroy_Cat_prod(produtos);

	return 0;
}
