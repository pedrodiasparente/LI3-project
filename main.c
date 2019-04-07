#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gmodule.h>
#include "vendas.h"
#include "clientNoBuy.h"
#include "leitura.h"
#include "query2.h"
#include "query3.h"
#include "query4.h"
#include "query5.h"
#include "query6.h"
#include "query7.h"
#include "query8.h"
#include "catProdutos.h"
#include "catClientes.h"
#include "gestaoFilial.h"

int main() {
	int i;
	FATGLOBAL fatGlobal;
	GESTAOFILIAL gestFilial[3];
	CAT_PRODUTOS produtos;
	CAT_CLIENTES clientes;

	char query2Letra;
	char query4Prod[6];
	int query4Mes;
	int query4Filial;

	fatGlobal = newFatGlobal();
	for(i = 0; i < 3; i++)
		gestFilial[i] = newGestaoFilial();
	clientes = new_Cat_cliente();
	produtos = new_Cat_prod();

    /*----------QUERY [1]-----------*/
	getClientes(clientes);
	getProdutos(produtos);
 	getVendas(fatGlobal, gestFilial, produtos, clientes);
    /*----------QUERY [2]-----------*/
    if(0) {
    	printf("QUERY 2: Forneça uma letra (maiúscula)\n");
		scanf("%c",&query2Letra);
    	printf("%d clientes QUERY1\n", num_Cat_prod(findProducts(produtos, query2Letra)));
    }
	/*----------QUERY [3]-----------*/
	if(0){
		printf("QUERY 3: Forneça um produto, um mês e uma filial\n");
		scanf("%s %d %d", query4Prod, &query4Mes, &query4Filial);
		printf("QUERY 3: VENDAS P: [%d]\n", totalVendasProdMesP(fatGlobal, query4Prod, query4Mes, query4Filial));
		printf("QUERY 3: VENDAS N: [%d]\n", totalVendasProdMesN(fatGlobal, query4Prod, query4Mes, query4Filial));
		printf("QUERY 3: FATURACAO P: [%f]\n", totalFatProdMesP(fatGlobal, query4Prod, query4Mes, query4Filial));
		printf("QUERY 3: FATURACAO N: [%f]\n", totalFatProdMesN(fatGlobal, query4Prod, query4Mes, query4Filial));
	}
	/*----------QUERY [4]-----------*/
	if(0){
		printf("QUERY 4:\n");
		print_Cat_prod(productNoBuy(fatGlobal));
		printf("QUERY 4: TOTAL [%d]\n", num_Cat_prod(productNoBuy(fatGlobal)));
		printf("QUERY 4: F1 [%d]\n", num_Cat_prod(productNoBuyFilial(fatGlobal, 1)));
		printf("QUERY 4: F2 [%d]\n", num_Cat_prod(productNoBuyFilial(fatGlobal, 2)));
		printf("QUERY 4: F3 [%d]\n", num_Cat_prod(productNoBuyFilial(fatGlobal, 3)));
	}
	/*----------QUERY [5]-----------*/
	if(0) {
		printf("QUERY 5:\n");
		print_Cat_client(clientAll(gestFilial));
	}
    /*----------QUERY [6]-----------*/
    if(0) {
    	printf("QUERY 6:\n");
    	printf("CLIENTES QUE NÃO COMPRARAM: %d\n", num_Cat_cliente(noClient(gestFilial,clientes)));
    	/*esta parte é feita pela funçao da query4, podemos?*/
		printf("PRODUTOS NÃO COMPRADOS: %d\n", num_Cat_prod(productNoBuy(fatGlobal)));
	}
	/*----------QUERY [7]-----------*/
	if(0) {
		printf("QUERY 7:\n");
		printQuery7(clientBoughtItems(gestFilial[0], "F2918"));
		printQuery7(clientBoughtItems(gestFilial[1], "F2918"));
		printQuery7(clientBoughtItems(gestFilial[2], "F2918"));
	}
	/*----------QUERY [8]-----------*/
	if(1) {
		printf("QUERY 8:\n");
		printf("NUMERO DE VENDAS: %d\n", nVendasIntervalo(fatGlobal,1,3));
		printf("TOTAL FATURADO: %f\n", totFatIntervalo(fatGlobal,1,3));
	}
	/*----------QUERY [9]-----------*/
	if(1) {
		printf("QUERY 9:\n");
	}
	/*----------QUERY [10]----------*/
	if(1) {
		printf("QUERY 10:\n");
	}
	/*----------QUERY [11]----------*/
	if(1) {
		printf("QUERY 11:\n");
	}
	/*----------QUERY [12]----------*/
	if(1) {
		printf("QUERY 12:\n");
	}
	/*------------------------------*/
	printf("Número de clientes:%d\nNúmero de Produtos:%d\nNúmero de Faturações:%d\nNúmero de gestFilial1:%d\nNúmero de gestFilial2:%d\nNúmero de gestFilial3:%d\n",
			num_Cat_cliente(clientes), num_Cat_prod(produtos), numFatGlobal(fatGlobal), numGestaoFilial(gestFilial[0]), numGestaoFilial(gestFilial[1]), numGestaoFilial(gestFilial[2]));

	destroyFatGlobal(fatGlobal);
	for(i = 0; i < 3; i++)
		destroyGestaoFilial(gestFilial[i]);
	destroy_Cat_prod(produtos);
    destroy_Cat_cliente(clientes);

	return 0;
}
