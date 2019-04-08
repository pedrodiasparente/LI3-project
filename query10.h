/**
 * @file query10.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas pela query10.
 */
#ifndef QUERY10_H
#define QUERY10_H

/**
 * @brief Função que determina os produtos mais comprados por um dado cliente num dado mês.
 *
 * @return Catálogo de produtos com produtos ordenados por quantidade (descendente).
 */
CAT_PRODUTOS prodsMaisComprados(GESTAOFILIAL * gf, char * cliente, int mes);

#endif
