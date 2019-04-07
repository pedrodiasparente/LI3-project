#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "gestaoFilial.h"
#include "catClientes.h"
#include "userData.h"


static int clientBuyProdFilialAux(void * client, void * gestClient, void * data) {
	INFOPROD info;
	char* prod = getData1(getData2(data));
	char* aux = getData2(getData2(data));
	int mes, exists = 0;
	char promo = aux[0];

	info = lookupProdutoCliente((GESTAOCLIENTE) gestClient, prod);
	if (info != NULL) {
	
		for(mes = 0; mes < 12; mes++)
			if(getQuant(info, mes, promo) != 0)
				exists = 1;

		if(exists) insert_Cat_cliente(getData1(data), client);

	}
	return FALSE;
}

CAT_CLIENTES clientBuyProdFilial(GESTAOFILIAL gf, char* prod, char promo) {
	CAT_CLIENTES clients;
	clients = new_Cat_cliente();
	DATA d, prodPromo;
	prodPromo = data(prod,&promo);
	d = data(clients, prodPromo);

	traverseGestFilial(gf, clientBuyProdFilialAux, d);

	return clients;
}