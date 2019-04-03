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
#include "catClientes.h"

gint printVendaTree(gpointer key, gpointer value, gpointer data){
    printVenda((VENDA) value);
    return FALSE;
}

int main() {
	FATGLOBAL fatGlobal;
    FATURACAO f = newFaturacao();
	CAT_PRODUTOS produtos;
	CAT_CLIENTES clientes;
	fatGlobal = newFatGlobal();
	clientes = new_Cat_cliente();
	produtos = new_Cat_prod();

    destroyFaturacao(f);

    /*QUERY1*/
	getClientes(clientes);
	getProdutos(produtos);
 	getFaturacao(fatGlobal, produtos, clientes);
    /*QUERY2*/
    printArray(findProducts(produtos, 'A'));
    /*QUERY6*/
    /*printf("\nYes?%d\n", didNotBuy(vendas,produtos,clientes));*/

	/*printf("Vendas Escritas: %d\n", vWrite);*/
	printf("Número de clientes:%d\nNúmero de Produtos:%d\nNúmero de faturações:%d\n",
			num_Cat_cliente(clientes), num_Cat_prod(produtos), numFatGlobal(fatGlobal));

	destroyFatGlobal(fatGlobal);
	destroy_Cat_prod(produtos);
    destroy_Cat_cliente(clientes);

	return 0;
}
