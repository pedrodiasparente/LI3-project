/**
 * @file catProdutos.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas para gerir o catálogo de produtos.
 */
#ifndef CATPRODUTOS_H
#define CATPRODUTOS_H

/**
 * @brief Estrutura do catálogo de produtos.
 */
typedef struct cat_produtos *CAT_PRODUTOS;

/**
 * @brief Função que cria um novo catálogo de produtos.
 *
 * @return Um catálogo de produtos vazio.
 */
CAT_PRODUTOS new_Cat_prod();

/**
 * @brief Função que cria um catálogo de produtos ordenado por um valor.
 *
 * @return Um catálogo de produtos ordenado por um valor.
 */
CAT_PRODUTOS new_Cat_prod_ord(char type);

/**
 * @brief Função que destroi um catálogo de produtos.
 */
void destroy_Cat_prod(CAT_PRODUTOS p);

/**
 * @brief Função que insere um produto num dado catálogo de produtos.
 */
void insert_Cat_prod(CAT_PRODUTOS p, char *produto);

/**
 * @brief Função que insere um produto num catálogo de produtos ordenado por quantidade.
 */
void insert_Cat_prod_ord_quant(CAT_PRODUTOS p, char *produto, int * quant);

/**
 * @brief Função que insere um produto num catálogo de produtos ordenado por preço.
 */
void insert_Cat_prod_ord_preco(CAT_PRODUTOS p, char *produto, float * preco);

/**
 * @brief Função remove um dado produto de um catálogo de produtos.
 */
void remove_Cat_prod(CAT_PRODUTOS p, char * prod);

/**
 * @brief Função remove um dado produto de um catálogo de produtos ordenado.
 */
void remove_Cat_prod_ord(CAT_PRODUTOS p, int * key);

/**
 * @brief Função que verifica se um dado produto está guardado num catálogo de produtos passado por referência.
 *
 * @return 1 se o produto está guardado no catálogo de produtos 0 caso contrário.
 */
int lookup_Cat_prod(CAT_PRODUTOS p, char* produto);

/**
 * @brief Função que percorre uma dado catálogo de produtos e aplica uma dada função a todos os produtos nele presentes.
 */
void foreach_Cat_prod(CAT_PRODUTOS p, GTraverseFunc func, gpointer user_data);

/**
 * @brief Função calcula o número de produtos presentes num catálogo de produtos passado por referência.
 *
 * @return Número de produtos presentes no catálogo de produtos.
 */
int num_Cat_prod(CAT_PRODUTOS p);

void print_Cat_prod(CAT_PRODUTOS p);

#endif
