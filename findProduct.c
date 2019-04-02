#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "userData.h"
#include "catProdutos.h"

void printArray(GArray * productArray){
    int i;
    char * currentProd;

    currentProd = g_array_index (productArray, char * , 0);

    for(i = 1; currentProd != 0; i++){
        printf("%s\n", currentProd);
        currentProd = g_array_index (productArray, char * , i);
    }
    printf("\nQUERIE 2:Número de produtos: %d\n",i-1);
}

gboolean addArray(gpointer key, gpointer value, gpointer Array){
    GArray * productArray;
    char * c, * currentProd;

    currentProd = (char *) value;
    productArray = (GArray *) getData1(Array);
    c = (char *) getData2(Array);

    if(currentProd[0] == (* c)){
        g_array_append_val(productArray, currentProd);
    }

    return FALSE;
}

GArray * findProducts(CAT_PRODUTOS p, char a){
    GArray * productArray = g_array_sized_new(TRUE, TRUE, sizeof(char *), 200);
    DATA d;

    d = data(productArray, &a);

    foreach_Cat_prod(p, addArray, d);

    return productArray;
}
