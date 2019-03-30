#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "vendas.h"



gboolean checkIfClient(gpointer key, gpointer value, gpointer data){
    if (1) ((gint*) data++);
    return FALSE;
}

int didNotBuy(GTree * vendas, GTree *produtos, GTree *clientes) {
	int client;
	/*int prod;*/
	g_tree_foreach(clientes, checkIfClient, &client);
	/*g_tree_foreach(a, checkIfProd, &prod);
*/


	
	return client;
}