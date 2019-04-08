#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "gestaoFilial.h"
#include "catProdutos.h"
#include "userData.h"

static int checkProd(void * quant, void * prodActual, void * prodExists){
    int * exists;
    char * prod;
    int * prodQuant;

    prodQuant = quant;

    exists = getData1(prodExists);
    prod = getData2(prodExists);

    if(strcmp(prodActual, prod) == 0){
        printf("Found prod %s with quant %d!\n", prod, *prodQuant);
        *exists = *prodQuant;
        return TRUE;
    }
    else{
        *exists = 0;
        return FALSE;
    }
}

static int addProdOrd(void * prod, void * infoProd, void * userdata){
    int * quantMes;
    int * mes;
    int exists;
    CAT_PRODUTOS catProds;
    DATA d;

    exists = 0;
    d = data(&exists, prod);

    quantMes = malloc(sizeof(int));

    catProds = getData1(userdata);
    mes = getData2(userdata);

    *quantMes = getQuant(infoProd, *mes, 'P') + getQuant(infoProd, *mes, 'N');

    foreach_Cat_prod(catProds, checkProd, d);

    if(*quantMes != 0){
        remove_Cat_prod_ord(catProds, &exists);
        *quantMes += exists;
        insert_Cat_prod_ord(catProds, prod, quantMes);
    }

    return FALSE;
}

CAT_PRODUTOS prodsMaisComprados(GESTAOFILIAL * gf, char * cliente, int mes){
    GESTAOCLIENTE gc;
    CAT_PRODUTOS catProd;
    DATA d;

    catProd = new_Cat_prod_ord();

    d = data(catProd, &mes);

    gc = lookupGestaoFilial(gf[0], cliente);
    traverseGestClient(gc, addProdOrd, d);

    gc = lookupGestaoFilial(gf[1], cliente);
    traverseGestClient(gc, addProdOrd, d);

    gc = lookupGestaoFilial(gf[2], cliente);
    traverseGestClient(gc, addProdOrd, d);

    return catProd;
}
