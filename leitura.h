#ifndef LEITURA_H
#define LEITURA_H

#include "catProdutos.h"
#include "catClientes.h"
#include "faturacao.h"
#include "gestaoFilial.h"

void getProdutos(CAT_PRODUTOS p);

void getClientes(CAT_CLIENTES c);

void getVendas(FATGLOBAL fatGlobal, GESTAOFILIAL * gestFilial, CAT_PRODUTOS prod, CAT_CLIENTES client);

#endif
