#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <glib.h>
#include <gmodule.h>
#include "IO.h"
#include "leitura.h"
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

int main() {
	clock_t start, end;
	double cpu_time_used;

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
				start = clock();

				inQuery1(fichVendas, fichProdutos, fichClientes);
				getClientes(clientes, fichClientes);
				getProdutos(produtos, fichProdutos);
				numVendas = getVendas(fatGlobal, gestFilial, produtos, clientes, fichVendas);
				outQuery1(numVendas, fichVendas);

				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
				break;
			case 2:
				start = clock();

				inQuery2(&singleChar);
				foreach_Cat_prod(findProducts(produtos, singleChar), printCat, NULL);
				outQuery2(num_Cat_prod(findProducts(produtos, singleChar)));

				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
				break;
			case 3:
				start = clock();

				inQuery3(prod, &mes, &filial);
				outQuery3(totalVendasProdMesP(fatGlobal,prod,mes,filial),
						  totalVendasProdMesN(fatGlobal,prod,mes,filial),
					  	  totalFatProdMesP(fatGlobal,prod,mes,filial),
					  	  totalFatProdMesN(fatGlobal,prod,mes,filial));
				
				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
				break;
			case 4:
				start = clock();

				inQuery4(&modo);
				outQuery4(num_Cat_prod(productNoBuy(fatGlobal)),
						  num_Cat_prod(productNoBuyFilial(fatGlobal, 1)),
					  	  num_Cat_prod(productNoBuyFilial(fatGlobal, 2)),
					      num_Cat_prod(productNoBuyFilial(fatGlobal, 3)),
					  	  modo);

				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
				break;
			case 5:
				start = clock();

				foreach_Cat_cliente(clientAll(gestFilial, clientes), printCat, NULL);
				outQuery5();

				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
				break;
			case 6:
				start = clock();

				outQuery6(num_Cat_cliente(noClient(gestFilial,clientes)),num_Cat_prod(productNotBought(fatGlobal)));
				
				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
				break;
			case 7:
				start = clock();

				inQuery7(cliente);
				outQuery7(clientBoughtItems(gestFilial[0], cliente));
				outQuery7(clientBoughtItems(gestFilial[1], cliente));
				outQuery7(clientBoughtItems(gestFilial[2], cliente));
				
				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
				break;
			case 8:
				start = clock();

				inQuery8(&mes, &mes2);
				outQuery8(nVendasIntervalo(fatGlobal,mes,mes2), totFatIntervalo(fatGlobal,mes,mes2));
				
				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
				break;
			case 9:
				start = clock();

				inQuery9(prod, &filial);
				outQuery9(num_Cat_cliente(clientBuyProdFilial(gestFilial[filial-1], prod, 'P')), 'P');
				foreach_Cat_cliente(clientBuyProdFilial(gestFilial[filial], prod, 'P'),printCat, NULL);
				outQuery9(num_Cat_cliente(clientBuyProdFilial(gestFilial[filial-1], prod, 'N')), 'N');
				foreach_Cat_cliente(clientBuyProdFilial(gestFilial[filial], prod, 'N'),printCat, NULL);
				
				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
				break;
			case 10:
				start = clock();

				inQuery10(cliente, &mes);
				outQuery10();
				foreach_Cat_prod(prodsMaisComprados(gestFilial, cliente, mes),printCat, NULL);
				
				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
				break;
			case 12:
				start = clock();

				inQuery12(cliente);
				outQuery12();
				foreach_Cat_prod(prodsMaisDespesa(gestFilial, cliente),printCat,NULL);
				
				end = clock();
				cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
				printf("CPU Time:%f\n", cpu_time_used );
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
