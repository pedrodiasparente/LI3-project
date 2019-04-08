#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "gestaoFilial.h"

static int somaProdsCliente(void * prod, void * infoProd, void * infoProdReturn){
    int i;

    for(i = 0; i < 12; i++){
        setQuant(infoProdReturn, i, getQuant(infoProd, i, 'N'), 'N');
        setQuant(infoProdReturn, i, getQuant(infoProd, i, 'P'), 'N');
    }

    return FALSE;
}


int * clientBoughtItems(GESTAOFILIAL gf, char *client){
    GESTAOCLIENTE gc;
    INFOPROD p;

    p = newInfoProd();

    gc = lookupGestaoFilial(gf, client);

    traverseGestClient(gc, somaProdsCliente, p);

    return getMesN(p);
}
