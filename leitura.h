#ifndef LEITURA_H
#define LEITURA_H

#include "catProdutos.h"
#include "catClientes.h"
#include "faturacao.h"

void getProdutos(CAT_PRODUTOS p);

void getClientes(CAT_CLIENTES c);

void getFaturacao(FATGLOBAL fatGlobal, CAT_PRODUTOS prod, CAT_CLIENTES client);

#endif
