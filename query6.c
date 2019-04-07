#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "catClientes.h"
#include "gestaoFilial.h"
#include "userData.h"

static int exists(void * client, void * cat_client, void * data){
	GESTAOFILIAL gf1, gf2, gf3;
	CAT_CLIENTES clientNone;
	clientNone = getData1(getData2(data));
	gf1 = getData2(getData2(data));
	gf2 = getData1(getData1(data));
	gf3 = getData2(getData1(data));

	if(lookupGestaoFilial(gf1, client) == NULL && lookupGestaoFilial(gf2, client) == NULL && lookupGestaoFilial(gf3, client) == NULL){
       	insert_Cat_cliente(clientNone, client);
    }

    return FALSE;
}

CAT_CLIENTES noClient(GESTAOFILIAL * gf, CAT_CLIENTES c){
    CAT_CLIENTES clientNone;
    DATA gfs, gfNcat, d;

    clientNone = new_Cat_cliente();

    gfs = data(gf[1], gf[2]);
    gfNcat = data(clientNone, gf[0]);
    d = data(gfs,gfNcat);

    foreach_Cat_cliente(c, exists, d);

    return clientNone;
}
