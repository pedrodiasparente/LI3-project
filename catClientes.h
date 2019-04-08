/**
 * @file catClientes.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas para gerir o catálogo de clientes.
 */
#ifndef CATCLIENTES_H
#define CATCLIENTES_H

/**
 * @brief Estrutura do catálogo de clientes.
 */
typedef struct cat_clientes *CAT_CLIENTES;

/**
 * @brief Função que cria um novo catálogo de clientes.
 *
 * @return Um catálogo de clientes vazio.
 */
CAT_CLIENTES new_Cat_cliente();

/**
 * @brief Função que destroi um catálogo de clientes.
 */
void destroy_Cat_cliente(CAT_CLIENTES c);

/**
 * @brief Função que insere um cliente num dado catálogo de clientes.
 */
void insert_Cat_cliente(CAT_CLIENTES c, char *cliente);

/**
 * @brief Função que verifica se um dado cliente está num catálogo de clientes passado por referência.
 *
 * @return Retorna 1 se o cliente está guardado no catálogo de clientes e 0 caso contrário.
 */
int lookup_Cat_cliente(CAT_CLIENTES c, char* cliente);

/**
 * @brief Função que percorre um catálogo de clientes e aplica uma dada função passada por referência a todos os
 * elementos do catálogo.
 */
void foreach_Cat_cliente(CAT_CLIENTES c, GTraverseFunc func, gpointer user_data);

/**
 * @brief Função que calcula o número de clientes presentes num catálogo de clientes passado por referência.
 *
 * @return Número de clientes presentes num dado catálogo de clientes.
 */
int num_Cat_cliente(CAT_CLIENTES c);

void print_Cat_client(CAT_CLIENTES c);

#endif
