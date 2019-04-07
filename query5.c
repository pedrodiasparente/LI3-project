#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "catClientes.h"
#include "gestaoFilial.h"
#include "userData.h"

static int exists(void * client, void * gf1, void * data){
	GESTAOFILIAL gf2, gf3;
	CAT_CLIENTES clientsTodas;
	clientsTodas = getData1(data);
	gf2 = getData1(getData2(data));
	gf3 = getData2(getData2(data));

	if(lookupGestaoFilial(gf2, client) != NULL && lookupGestaoFilial(gf3, client) != NULL){
       	insert_Cat_cliente(clientsTodas, client);
    }

    return FALSE;
}

CAT_CLIENTES clientAll(GESTAOFILIAL gf[]){
    CAT_CLIENTES clientsTodas;
    DATA gfs, gfNcat;

    clientsTodas = new_Cat_cliente();

    gfs = data(gf[1], gf[2]);
    gfNcat = data(clientsTodas, gfs);

    traverseGestFilial(gf[0], exists, gfNcat);

    return clientsTodas;
}
