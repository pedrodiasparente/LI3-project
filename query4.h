/**
 * @file query4.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas pela query4.
 */
#ifndef QUERY4_H
#define QUERY4_H

/**
 * @brief Função que retorna a lista de produtos que ninguém comprou numa dada filial.
 *
 * @return Catálogo de produtos não comprados numa filial.
 */
CAT_PRODUTOS productNoBuyFilial(FATGLOBAL fg, int filial);

/**
 * @brief Função que retorna a lista de produtos que ninguém comprou.
 *
 * @return Catálogo de produtos não comprados.
 */
CAT_PRODUTOS productNoBuy(FATGLOBAL fg);

#endif
