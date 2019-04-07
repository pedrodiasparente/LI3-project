#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "gestaoFilial.h"
#include "userData.h"

void printQuery7(GArray * array){
    int i;
    int currentQuant;

    currentQuant = g_array_index (array, int , 0);

    for(i = 1; currentQuant != 0; i++){
        printf("| %d | ", currentQuant);
        currentQuant = g_array_index (array, int , i);
    }
    printf("\n");
}

static gboolean addArray(void * prodKey, void * infoprod, void *data){
	int * soma;
	int mes;
	GArray * array;
	soma = (int *)getData2(data);
	array = (GArray *) getData1(data);
	for(mes = 1; mes < 13; mes++) {
		(* soma) = getQuant(infoprod, mes, 'P') + getQuant(infoprod, mes, 'N');
	}

	g_array_append_val(array, (* soma));

    return FALSE;
}

GArray * clientBoughtItems(GESTAOFILIAL gf, char *client){
    GArray * array = g_array_sized_new(TRUE, TRUE, sizeof(int), 200);
    int soma;
    DATA d;
    d = data(array, &soma);
    GESTAOCLIENTE gc = newGestaoCliente();
    gc = lookupGestaoFilial(gf, client);

    traverseGestClient(gc, addArray, d);

    return array;
}