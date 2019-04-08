#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "gestaoFilial.h"
#include "catClientes.h"
#include "userData.h"

static int clientBuyProdFilialNAux(void * client, void * gestClient, void * data) {
	INFOPROD info;
	char* prod = getData2(data);;
	int mes, exists = 0;

	info = lookupProdutoCliente((GESTAOCLIENTE) gestClient, prod);
	
	if (info != NULL) {
		for(mes = 0; mes < 12; mes++)
			if(getQuant(info, mes, 'N') != 0)
				exists = 1;

		if(exists) insert_Cat_cliente(getData1(data), client);

	}
	return FALSE;
}

static int clientBuyProdFilialPAux(void * client, void * gestClient, void * data) {
	INFOPROD info;
	char* prod = getData2(data);
	int mes, exists = 0;

	info = lookupProdutoCliente((GESTAOCLIENTE) gestClient, prod);

	if (info != NULL) {
		for(mes = 0; mes < 12; mes++)
			if(getQuant(info, mes, 'P') != 0)
				exists = 1;

		if(exists) insert_Cat_cliente(getData1(data), client);

	}
	return FALSE;
}

CAT_CLIENTES clientBuyProdFilial(GESTAOFILIAL gf, char* prod, char promo) {
	CAT_CLIENTES clients;
	clients = new_Cat_cliente();
	DATA d;
	d = data(clients, prod);

	if (promo == 'N')
		traverseGestFilial(gf, clientBuyProdFilialNAux, d);
	else 
		traverseGestFilial(gf, clientBuyProdFilialPAux, d);

	return clients;
}