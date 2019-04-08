#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "catClientes.h"
#include "gestaoFilial.h"
#include "userData.h"

static int exists(void * client, void * value, void * data){
	GESTAOFILIAL *gfs;
    GESTAOFILIAL gf1, gf2, gf3;
	CAT_CLIENTES clientsTodas;
	clientsTodas = getData1(data);
	gfs = getData2(data);
    gf1 = gfs[0];
    gf2 = gfs[1];
    gf3 = gfs[2];

	if(numProdutosCliente(lookupGestaoFilial(gf1, client)) > 0 && numProdutosCliente(lookupGestaoFilial(gf2, client)) > 0 && numProdutosCliente(lookupGestaoFilial(gf3, client)) > 0){
       	insert_Cat_cliente(clientsTodas, client);
    }

    return FALSE;
}

CAT_CLIENTES clientAll(GESTAOFILIAL gf[], CAT_CLIENTES clients){
    CAT_CLIENTES clientsTodas;
    DATA gfNcat;

    clientsTodas = new_Cat_cliente();

    gfNcat = data(clientsTodas, gf);

    foreach_Cat_cliente(clients, exists, gfNcat);

    return clientsTodas;
}
