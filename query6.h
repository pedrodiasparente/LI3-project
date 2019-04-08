/**
 * @file query6.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas pela query6.
 */
#ifndef QUERY6_H
#define QUERY6_H

/**
 * @brief Função que determina a lista de produtos que ninguém comprou.
 *
 * @return Catálogo de produtos com produtos que ninguém comprou.
 */
CAT_PRODUTOS productNotBought(FATGLOBAL fg);

/**
 * @brief Função que determina a lista de clientes que não realizaram compras.
 *
 * @return Catálogo de clientes com clientes que não compraram.
 */
CAT_CLIENTES noClient(GESTAOFILIAL * gf, CAT_CLIENTES c);

#endif
