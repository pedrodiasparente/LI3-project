#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gmodule.h>
#include "vendas.h"
#include "clientNoBuy.h"
#include "leitura.h"
#include "IO.h"
#include "query2.h"
#include "query3.h"
#include "query4.h"
#include "query5.h"
#include "query6.h"
#include "query7.h"
#include "query8.h"
#include "query9.h"
#include "query10.h"
#include "query12.h"
#include "catProdutos.h"
#include "catClientes.h"
#include "gestaoFilial.h"

int main() {
	int i, done, query, numVendas;
	FATGLOBAL fatGlobal;
	GESTAOFILIAL gestFilial[3];
	CAT_PRODUTOS produtos;
	CAT_CLIENTES clientes;

	done = 0;
	char singleChar;
	char prod[6], fichVendas[30], fichClientes[30], fichProdutos[30];
	int mes, filial;
	CAT_PRODUTOS catprodQuery10;
	CAT_PRODUTOS catprodQuery12;

	fatGlobal = newFatGlobal();
	for(i = 0; i < 3; i++)
		gestFilial[i] = newGestaoFilial();
	clientes = new_Cat_cliente();
	produtos = new_Cat_prod();

    while(done == 0){
		IOinit(&query);
		switch (query) {
			case 0:
				done = 1;
				break;
			case 1:
				inQuery1(fichVendas, fichProdutos, fichClientes);
				getClientes(clientes, fichClientes);
				getProdutos(produtos, fichProdutos);
				numVendas = getVendas(fatGlobal, gestFilial, produtos, clientes, fichVendas);
				outQuery1(numVendas, fichVendas);
				break;
			case 2:
				inQuery2(&singleChar);
				foreach_Cat_prod(findProducts(produtos, singleChar), printCat, NULL);
				outQuery2(num_Cat_prod(findProducts(produtos, singleChar)));
				break;
			case 3:
				inQuery3(prod, &mes, &filial);
				outQuery3(totalVendasProdMesP(fatGlobal,prod,mes,filial),
						  totalVendasProdMesN(fatGlobal,prod,mes,filial),
					  	  totalFatProdMesP(fatGlobal,prod,mes,filial),
					  	  totalFatProdMesN(fatGlobal,prod,mes,filial));
				break;
			default:
				done = 1;
				break;
		}
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
		print_Cat_client(clientAll(gestFilial, clientes));
	}
    /*----------QUERY [6]-----------*/
    if(1) {
    	printf("QUERY 6:\n");
    	printf("CLIENTES QUE NÃO COMPRARAM: %d\n", num_Cat_cliente(noClient(gestFilial,clientes)));
		printf("PRODUTOS NÃO COMPRADOS: %d\n", num_Cat_prod(productNotBought(fatGlobal)));
	}
	/*----------QUERY [7]-----------*/
	if(0) {
		printf("QUERY 7:\n");
		printQuery7(clientBoughtItems(gestFilial[0], "F2918"));
		printQuery7(clientBoughtItems(gestFilial[1], "F2918"));
		printQuery7(clientBoughtItems(gestFilial[2], "F2918"));
	}
	/*----------QUERY [8]-----------*/
	if(0) {
		printf("QUERY 8:\n");
		printf("NUMERO DE VENDAS: %d\n", nVendasIntervalo(fatGlobal,1,3));
		printf("TOTAL FATURADO: %f\n", totFatIntervalo(fatGlobal,1,3));
	}
	/*----------QUERY [9]-----------*/
	if(0) {
		printf("QUERY 9:\n");
		printf("LISTA DE CLIENTES:\n");
		if(/*promo is N*/1){
			print_Cat_client(clientBuyProdFilial(gestFilial[0], "GQ1432", 'N'));
			printf("NÚMERO DE CLIENTES: %d\n", num_Cat_cliente(clientBuyProdFilial(gestFilial[0], "GQ1432", 'N')));
		}
		else if (/*promo is P*/0) {
			print_Cat_client(clientBuyProdFilial(gestFilial[0], "GQ1432", 'P'));
			printf("NÚMERO DE CLIENTES: %d\n", num_Cat_cliente(clientBuyProdFilial(gestFilial[0], "GQ1432", 'P')));
		}
		else printf("Introduza uma promoçao válida\n");
	}
	/*----------QUERY [10]----------*/
	if(0) {
		outQuery10();
		catprodQuery10 = (prodsMaisComprados(gestFilial, "Y1444", 10));
		foreach_Cat_prod(catprodQuery10, printCat, NULL);
	}
	/*----------QUERY [11]----------*/
	if(0) {
		printf("QUERY 11:\n");
	}
	/*----------QUERY [12]----------*/
	if(1) {
		printf("QUERY 12:\n");
		catprodQuery12 = (prodsMaisDespesa(gestFilial, "A1444"));
		foreach_Cat_prod(catprodQuery12, printCat, NULL);
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
