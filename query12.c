#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "gestaoFilial.h"
#include "catProdutos.h"
#include "userData.h"

static int checkProd(void * preco, void * prodActual, void * prodExists){
    int * exists;
    char * prod;
    float * prodPreco;

    prodPreco = preco;

    exists = getData1(prodExists);
    prod = getData2(prodExists);

    if(strcmp(prodActual, prod) == 0){
        *exists = *prodPreco;
        return TRUE;
    }
    else{
        *exists = 0;
        return FALSE;
    }
}

static int addProdOrd(void * prod, void * infoProd, void * userdata){
    float * preco;
    int mes;
    int exists;
    CAT_PRODUTOS catProds = userdata;
    DATA d;

    exists = 0;
    d = data(&exists, prod);

    preco = malloc(sizeof(float));

    for(mes = 0; mes < 12; mes++)
        *preco += (getPrecoGF(infoProd, mes, 'P') * getQuant(infoProd, mes, 'P')) + (getPrecoGF(infoProd, mes, 'N') * getQuant(infoProd, mes, 'N'));

    foreach_Cat_prod(catProds, checkProd, d);

    if(*preco != 0){
        remove_Cat_prod_ord(catProds, &exists);
        *preco += exists;
        insert_Cat_prod_ord_preco(catProds, prod, preco);
    }

    return FALSE;
}

static int getFirstThree(void * preco, void * prod, void * data){
    int * num = getData2(data);
    if(*num == 3)
        return TRUE;

    insert_Cat_prod_ord_preco(getData1(data), prod, preco);
    (*num)++;
    return FALSE;
}

CAT_PRODUTOS prodsMaisDespesa(GESTAOFILIAL * gf, char * cliente){
    GESTAOCLIENTE gc;
    CAT_PRODUTOS catProd;
    CAT_PRODUTOS catProdFinal;
    int num = 0;
    DATA d;

    catProd = new_Cat_prod_ord('f');
    catProdFinal = new_Cat_prod_ord('f');
    d = data(catProdFinal, &num);

    gc = lookupGestaoFilial(gf[0], cliente);
    traverseGestClient(gc, addProdOrd, catProd);

    gc = lookupGestaoFilial(gf[1], cliente);
    traverseGestClient(gc, addProdOrd, catProd);

    gc = lookupGestaoFilial(gf[2], cliente);
    traverseGestClient(gc, addProdOrd, catProd);

    foreach_Cat_prod(catProd, getFirstThree, d);

    return catProdFinal;
}
