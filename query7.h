/**
 * @file query7.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas pela query7.
 */
#ifndef QUERY7_H
#define QUERY7_H


void printQuery7(GESTAOCLIENTE gc);

/**
 * @brief Função que uma GESTAOCLIENTE com os produtos comprados por um dado cliente.
 *
 * @return GESTAOCLIENTE com produtos comprados
 */
GESTAOCLIENTE clientBoughtItems(GESTAOFILIAL gf, char *client);

#endif
