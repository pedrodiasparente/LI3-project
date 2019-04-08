#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "catProdutos.h"
#include "faturacao.h"
#include "userData.h"

static int isCompradoFilial(void * prod, void * faturacao, void * naoComprado){
    int mes, comprado;

    comprado = 0;

    for(mes = 1; mes < 13; mes++){
        if(comprado == 1) break;
        if(getNVendasN(mes, faturacao, *(int *)getData2(naoComprado)) != 0) comprado = 1;
        if(getNVendasP(mes, faturacao, *(int *)getData2(naoComprado)) != 0) comprado = 1;
    }

    if(!comprado){
        insert_Cat_prod(getData1(naoComprado), prod);
    }

    return FALSE;
}

CAT_PRODUTOS productNoBuyFilial(FATGLOBAL fg, int filial){
    CAT_PRODUTOS naoComprado;
    DATA d;

    naoComprado = new_Cat_prod();

    d = data(naoComprado, &filial);

    traverseFatGlobal(fg, isCompradoFilial, d);

    return naoComprado;
}

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

CAT_PRODUTOS productNoBuy(FATGLOBAL fg){
    CAT_PRODUTOS naoComprado;

    naoComprado = new_Cat_prod();

    traverseFatGlobal(fg, isComprado, naoComprado);

    return naoComprado;
}
