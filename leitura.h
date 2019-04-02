#ifndef LEITURA_H
#define LEITURA_H

#include "catProdutos.h"

void getProdutos(CAT_PRODUTOS p);

void getClientes(GTree * tree);

void getVendas(GTree * vendas, CAT_PRODUTOS prod, GTree * client);

#endif
