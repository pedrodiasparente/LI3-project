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
#include "querie4.h"
#include "catProdutos.h"
#include "catClientes.h"
#include "gestaoFilial.h"

int main() {
	int i;
	FATGLOBAL fatGlobal;
	GESTAOFILIAL gestFilial[3];
	CAT_PRODUTOS produtos;
	CAT_CLIENTES clientes;

	char querie4Prod[6];
	int querie4Mes;
	int querie4Filial;


	fatGlobal = newFatGlobal();
	for(i = 0; i < 3; i++)
		gestFilial[i] = newGestaoFilial();
	clientes = new_Cat_cliente();
	produtos = new_Cat_prod();

    /*----------QUERIE [1]-----------*/
	getClientes(clientes);
	getProdutos(produtos);
 	getVendas(fatGlobal, gestFilial, produtos, clientes);
    /*----------QUERIE [2]-----------*/
    /*if(1) printArray(findProducts(produtos, 'G'));*/
	/*----------QUERIE [3]-----------*/
	if(1){
		printf("QUERIE 3: Forneça um produto, um mês e uma filial (separados por um espaço)\n");
		scanf("%s %d %d",querie4Prod, &querie4Mes, &querie4Filial);
		printf("QUERIE 3: VENDAS P: [%d]\n", totalVendasProdMesP(fatGlobal, querie4Prod, querie4Mes, querie4Filial));
		printf("QUERIE 3: VENDAS N: [%d]\n", totalVendasProdMesN(fatGlobal, querie4Prod, querie4Mes, querie4Filial));
		printf("QUERIE 3: FATURACAO P: [%f]\n", totalFatProdMesP(fatGlobal, querie4Prod, querie4Mes, querie4Filial));
		printf("QUERIE 3: FATURACAO N: [%f]\n", totalFatProdMesN(fatGlobal, querie4Prod, querie4Mes, querie4Filial));
	}
	/*----------QUERIE [4]-----------*/
	if(1){
		printf("QUERIE 4: TOTAL [%d]\n", num_Cat_prod(productNoBuy(fatGlobal)));
		printf("QUERIE 4: F1 [%d]\n", num_Cat_prod(productNoBuyFilial(fatGlobal, 1)));
		printf("QUERIE 4: F2 [%d]\n", num_Cat_prod(productNoBuyFilial(fatGlobal, 2)));
		printf("QUERIE 4: F3 [%d]\n", num_Cat_prod(productNoBuyFilial(fatGlobal, 3)));
	}
	/*----------QUERIE [5]-----------*/

    /*----------QUERIE [6]-----------*/
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
