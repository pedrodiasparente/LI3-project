/**
 * @file query12.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas pela query12.
 */
#ifndef QUERY12_H
#define QUERY12_H

/**
 * @brief Função que determina os 3 produtos em que um dado cliente mais gastou dinheiro num ano.
 *
 * @return Catálogo de produtos com os 3 produtos onde mais dinheiro foi gasto.
 */
CAT_PRODUTOS prodsMaisDespesa(GESTAOFILIAL * gf, char * cliente);

#endif
