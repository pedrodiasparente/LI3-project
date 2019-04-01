#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "vendas.h"
#include "userData.h"

gboolean checkIfClientAux(gpointer key, gpointer value, gpointer cliente){
    int * i;
    char * s;
    VENDA v;

    s = (char *) getData1((DATA) cliente);
    v = (VENDA) value;
    i = (int *) getData2((DATA ) cliente);

    if(getCliente(v) == s)
        (* i)++;

    printf("vendasPorCLiente%d\n do cliente %s/%s  VENDA:", (*i), getCliente(v), s);
    printVenda(v);

    if(*i > 0)
        return TRUE;

    return FALSE;
}

gboolean checkIfClient(gpointer key, gpointer value, gpointer vendasTree){
    int * i;
    int j;
    GTree * vendas;
    DATA cliente;

    j = 0;
    vendas = (GTree *) getData1(vendasTree);
    i = (int *) getData2((DATA ) vendasTree);

    cliente = data(value, &j);

    g_tree_foreach(vendas, checkIfClientAux, cliente);

    if (j == 0){
        (* i)++;
        printf("numCLientes: %d\n", *i);
    }

    return FALSE;
}

int didNotBuy(GTree * vendas, GTree *produtos, GTree *clientes) {
	int numClientes;
    numClientes = 0;
	DATA d;
    d = data(vendas, &numClientes);

	g_tree_foreach(clientes, checkIfClient, d);
	/*g_tree_foreach(a, checkIfProd, &prod);
*/
	return numClientes;
}
