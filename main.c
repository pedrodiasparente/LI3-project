#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <gmodule.h>
#include "vendas.h"
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
	char prod[6], cliente[5], fichVendas[30], fichClientes[30], fichProdutos[30];
	int mes, mes2, filial, modo;
	
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
			case 4:
				inQuery4(&modo);
				outQuery4(num_Cat_prod(productNoBuy(fatGlobal)),
						  num_Cat_prod(productNoBuyFilial(fatGlobal, 1)),
					  	  num_Cat_prod(productNoBuyFilial(fatGlobal, 2)),
					      num_Cat_prod(productNoBuyFilial(fatGlobal, 3)),
					  	  modo);
				break;
			case 5:
				foreach_Cat_cliente(clientAll(gestFilial, clientes), printCat, NULL);
				outQuery5();
				break;
			case 6:
				outQuery6(num_Cat_cliente(noClient(gestFilial,clientes)),num_Cat_prod(productNotBought(fatGlobal)));
				break;
			case 7:
				inQuery7(cliente);
				outQuery7(clientBoughtItems(gestFilial[0], cliente));
				outQuery7(clientBoughtItems(gestFilial[1], cliente));
				outQuery7(clientBoughtItems(gestFilial[2], cliente));
				break;
			case 8:
				inQuery8(&mes, &mes2);
				outQuery8(nVendasIntervalo(fatGlobal,mes,mes2), totFatIntervalo(fatGlobal,mes,mes2));
				break;
			case 9:
				inQuery9(prod, &filial);
				outQuery9(num_Cat_cliente(clientBuyProdFilial(gestFilial[filial-1], prod, 'P')), 'P');
				foreach_Cat_cliente(clientBuyProdFilial(gestFilial[filial], prod, 'P'),printCat, NULL);
				outQuery9(num_Cat_cliente(clientBuyProdFilial(gestFilial[filial-1], prod, 'N')), 'N');
				foreach_Cat_cliente(clientBuyProdFilial(gestFilial[filial], prod, 'N'),printCat, NULL);
				break;
			case 10:
				inQuery10(cliente, &mes);
				outQuery10();
				foreach_Cat_prod(prodsMaisComprados(gestFilial, cliente, mes),printCat, NULL);
				break;
			case 12:
				inQuery12(cliente);
				outQuery12();
				foreach_Cat_prod(prodsMaisDespesa(gestFilial, cliente),printCat,NULL);
				break;
			default:
				done = 1;
				break;
		}
	}

	destroyFatGlobal(fatGlobal);
	for(i = 0; i < 3; i++)
		destroyGestaoFilial(gestFilial[i]);
	destroy_Cat_prod(produtos);
    destroy_Cat_cliente(clientes);

	return 0;
}
