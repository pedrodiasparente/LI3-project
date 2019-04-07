#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "userData.h"
#include "catProdutos.h"

static gboolean addProdLetra(gpointer key, gpointer value, gpointer Array){
    CAT_PRODUTOS letraProds;
    char * c, * currentProd;

    currentProd = (char *) value;
    letraProds = (CAT_PRODUTOS) getData1(Array);
    c = (char *) getData2(Array);

    if(currentProd[0] == (* c)){
        insert_Cat_prod(letraProds, currentProd);
    }

    return FALSE;
}

CAT_PRODUTOS findProducts(CAT_PRODUTOS p, char a){
    CAT_PRODUTOS letraProds;
    DATA d;

    letraProds = new_Cat_prod();

    d = data(letraProds, &a);

    foreach_Cat_prod(p, addProdLetra, d);

    return letraProds;
}
