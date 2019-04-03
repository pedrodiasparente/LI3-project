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

int main() {
	FATGLOBAL fatGlobal;
	CAT_PRODUTOS produtos;
	CAT_CLIENTES clientes;
	
	fatGlobal = newFatGlobal();
	clientes = new_Cat_cliente();
	produtos = new_Cat_prod();

    /*QUERY1*/
	getClientes(clientes);
	getProdutos(produtos);
 	getFaturacao(fatGlobal, produtos, clientes);
    /*QUERY2*/
    printArray(findProducts(produtos, 'A'));
    /*QUERY6*/
    /*printf("\nYes?%d\n", didNotBuy(vendas,produtos,clientes));*/

	/*printf("Vendas Escritas: %d\n", vWrite);*/
	printf("Número de clientes:%d\nNúmero de Produtos:%d\nNúmero de Faturações:%d\n",
			num_Cat_cliente(clientes), num_Cat_prod(produtos), numFatGlobal(fatGlobal));

	destroyFatGlobal(fatGlobal);
	destroy_Cat_prod(produtos);
    destroy_Cat_cliente(clientes);

	return 0;
}
