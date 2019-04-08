#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "catClientes.h"
#include "catProdutos.h"
#include "gestaoFilial.h"
#include "faturacao.h"
#include "userData.h"

static int isComprado(void * prod, void * faturacao, void * naoComprado){
    int mes, filial, comprado;

    comprado = 0;

    for(mes = 1; mes < 13; mes++){
        if(comprado == 1) break;
        for(filial = 1; filial < 4; filial++){
            if(comprado == 1) break;
            if(getNVendasN(mes, faturacao, filial) != 0) comprado = 1;
            if(getNVendasP(mes, faturacao, filial) != 0) comprado = 1;
        }
    }

    if(!comprado){
        insert_Cat_prod(naoComprado, prod);
    }

    return FALSE;
}

CAT_PRODUTOS productNotBought(FATGLOBAL fg){
    CAT_PRODUTOS naoComprado;

    naoComprado = new_Cat_prod();

    traverseFatGlobal(fg, isComprado, naoComprado);

    return naoComprado;
}

static int exists(void * client, void * cat_client, void * data){
	GESTAOFILIAL *gfs;
    GESTAOFILIAL gf1, gf2, gf3;
	CAT_CLIENTES clientNone;
	clientNone = getData1(data);
	gfs = getData2(data);
	gf1 = gfs[0];
    gf2 = gfs[1];
    gf3 = gfs[2];

	if(numProdutosCliente(lookupGestaoFilial(gf1, client)) == 0 && numProdutosCliente(lookupGestaoFilial(gf2, client)) == 0 && numProdutosCliente(lookupGestaoFilial(gf3, client)) == 0){
       	insert_Cat_cliente(clientNone, client);
    }

    return FALSE;
}

CAT_CLIENTES noClient(GESTAOFILIAL * gf, CAT_CLIENTES c){
    CAT_CLIENTES clientNone;
    DATA d;

    clientNone = new_Cat_cliente();

    d = data(clientNone,gf);

    foreach_Cat_cliente(c, exists, d);

    return clientNone;
}
