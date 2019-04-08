/**
 * @file leitura.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas pela leitura.
 */
#ifndef LEITURA_H
#define LEITURA_H

#include "catProdutos.h"
#include "catClientes.h"
#include "faturacao.h"
#include "gestaoFilial.h"

/**
 * @brief Função que saca os produtos de um ficheiro.
 */
void getProdutos(CAT_PRODUTOS p, char * fich);

/**
 * @brief Função que saca os clientes de um ficheiro.
 */
void getClientes(CAT_CLIENTES c, char * fich);

/**
 * @brief Função que saca as vendas de um ficheiro.
 *
 * @return Número de vendas
 */
int getVendas(FATGLOBAL fatGlobal, GESTAOFILIAL * gestFilial, CAT_PRODUTOS prod, CAT_CLIENTES client, char * fich);

#endif
