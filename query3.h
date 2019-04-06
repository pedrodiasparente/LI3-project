#ifndef QUERY3_H
#define QUERY3_H

#include "faturacao.h"

int totalVendasProdMesP(FATGLOBAL fg, char * prod, int mes, int filial);

int totalVendasProdMesN(FATGLOBAL fg, char * prod, int mes, int filial);

float totalFatProdMesP(FATGLOBAL fg, char * prod, int mes, int filial);

float totalFatProdMesN(FATGLOBAL fg, char * prod, int mes, int filial);

#endif
