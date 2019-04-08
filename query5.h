/**
 * @file query5.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas pela query5.
 */
#ifndef QUERY5_H
#define QUERY5_H

/**
 * @brief Função que determinar a lista ordenada de códigos de clientes que realizaram compras em todas as filiais.
 *
 * @return Catálogo de clientes com código de clientes que compraram em todas as filiais.
 */
CAT_CLIENTES clientAll(GESTAOFILIAL gf[], CAT_CLIENTES clients);

#endif
