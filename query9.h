/**
 * @file query9.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas pela query9.
 */
#ifndef QUERY9_H
#define QUERY9_H

/**
 * @brief Função que determina os códigos dos clientes que compraram uma dado produto numa filial.
 *
 * @return Catálogo de clientes com os códigos dos clientes.
 */
CAT_CLIENTES clientBuyProdFilial(GESTAOFILIAL gf, char* prod, char promo);

#endif
