#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "gestaoFilial.h"

static int print7Aux(void * prod, void * infoProd, void * infoProdReturn){
    int i;

    for(i = 0; i < 12; i++){
        setQuant(infoProdReturn, i, getQuant(infoProd, i, 'N'), 'N');
        setQuant(infoProdReturn, i, getQuant(infoProd, i, 'P'), 'N');
    }

    return FALSE;
}

void printQuery7(GESTAOCLIENTE gc){
    INFOPROD p;
    int i;

    p = newInfoProd();

    traverseGestClient(gc, print7Aux, p);
    for(i = 0; i < 12; i++)
        printf("|#%d = %d |", (i + 1), getQuant(p, i, 'N'));
    printf("\n");
}


GESTAOCLIENTE clientBoughtItems(GESTAOFILIAL gf, char *client){
    GESTAOCLIENTE gc;

    gc = lookupGestaoFilial(gf, client);

    return gc;
}
