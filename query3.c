#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include "faturacao.h"

int totalVendasProdMesP(FATGLOBAL fg, char * prod, int mes, int filial){
    FATURACAO f;

    f = lookupFatGlobal(fg, prod);

    if(f != NULL)
        return getNVendasP(mes, f, filial);
    else{
        printf("Prod [%s] = NULL\n", prod);
        return 0;
    }
}

int totalVendasProdMesN(FATGLOBAL fg, char * prod, int mes, int filial){
    FATURACAO f;

    f = lookupFatGlobal(fg, prod);
    if(f != NULL)
        return getNVendasN(mes, f, filial);
    else
        return 0;
}

float totalFatProdMesP(FATGLOBAL fg, char * prod, int mes, int filial){
    FATURACAO f;

    f = lookupFatGlobal(fg, prod);
    if(f != NULL)
        return getPrecoP(mes, f, filial);
    else
        return 0;
}

float totalFatProdMesN(FATGLOBAL fg, char * prod, int mes, int filial){
    FATURACAO f;

    f = lookupFatGlobal(fg, prod);
    if(f != NULL)
        return getPrecoN(mes, f, filial);
    else
        return 0;
}
