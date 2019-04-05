#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gmodule.h>
#include "vendas.h"
#include "clientNoBuy.h"
#include "leitura.h"
#include "findProduct.h"
#include "vendasProdMes.h"
#include "catProdutos.h"
#include "catClientes.h"
#include "gestaoFilial.h"

int main() {
	int i;
	FATGLOBAL fatGlobal;
	GESTAOFILIAL gestFilial[3];
	CAT_PRODUTOS produtos;
	CAT_CLIENTES clientes;

	fatGlobal = newFatGlobal();
	for(i = 0; i < 3; i++)
		gestFilial[i] = newGestaoFilial();
	clientes = new_Cat_cliente();
	produtos = new_Cat_prod();

    /*----------QUERY [3]-----------*/
	getClientes(clientes);
	getProdutos(produtos);
 	getVendas(fatGlobal, gestFilial, produtos, clientes);
    /*----------QUERY [2]-----------*/
    if(0) printArray(findProducts(produtos, 'A'));
	/*----------QUERY [3]-----------*/
	if(0){
		printf("VENDAS P: [%d]\n", totalVendasProdMesP(fatGlobal, "AA1409", 6, 1));
		printf("VENDAS N: [%d]\n", totalVendasProdMesN(fatGlobal, "AA1409", 8, 2));
		printf("FATURACAO P: [%f]\n", totalFatProdMesP(fatGlobal, "AA1409", 6, 1));
		printf("FATURACAO N: [%f]\n", totalFatProdMesN(fatGlobal, "AA1409", 8, 2));
	}
    /*----------QUERY [6]-----------*/
    /*printf("\nYes?%d\n", didNotBuy(vendas,produtos,clientes));*/

	/*printf("Vendas Escritas: %d\n", vWrite);*/
	printf("Número de clientes:%d\nNúmero de Produtos:%d\nNúmero de Faturações:%d\nNúmero de gestFilial1:%d\nNúmero de gestFilial2:%d\nNúmero de gestFilial3:%d\n",
			num_Cat_cliente(clientes), num_Cat_prod(produtos), numFatGlobal(fatGlobal), numGestaoFilial(gestFilial[0]), numGestaoFilial(gestFilial[1]), numGestaoFilial(gestFilial[2]));

	destroyFatGlobal(fatGlobal);
	for(i = 0; i < 3; i++)
		destroyGestaoFilial(gestFilial[i]);
	destroy_Cat_prod(produtos);
    destroy_Cat_cliente(clientes);

	return 0;
}
