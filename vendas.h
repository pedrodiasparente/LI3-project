/**
 * @file vendas.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas para gerir as vendas.
 */
#ifndef STRUCTVENDAS_H
#define STRUCTVENDAS_H

/**
 * @brief Estrutura das vendas.
 */
typedef struct venda *VENDA;

/**
 * @brief Função que transforma uma string numa venda.
 *
 * @return Uma VENDA
 */
VENDA strToVenda(char * str);

/**
 * @brief Função que imprime uma dada venda.
 */
void printVenda(VENDA v);

/**
 * @brief Função que destrói uma dada venda.
 */
void destroyVenda(VENDA v);

/**
 * @brief Função que retorna os produto de uma venda.
 *
 * @return produto da venda.
 */
char * getProduto(VENDA v);

/**
 * @brief Função que retorna o cliente de uma venda.
 *
 * @return cliente da venda.
 */
char * getCliente(VENDA v);

/**
 * @brief Função que retorna os preço de uma venda.
 *
 * @return preço da venda.
 */
float getPreco(VENDA v);

/**
 * @brief Função que retorna a quantidade de uma venda.
 *
 * @return quantidade da venda.
 */
int getQuantidade(VENDA v);

/**
 * @brief Função que os estado de promoção ou não promoção de uma venda.
 *
 * @return N ou P (não promoção ou promoção respetivamente).
 */
char getPromo(VENDA v);

/**
 * @brief Função que retorna o mês de uma venda.
 *
 * @return mês da venda.
 */
int getMes(VENDA v);

/**
 * @brief Função que retorna a filial onde ocorreu a venda.
 *
 * @return filial onde ocorreu a venda.
 */
int getFilial(VENDA v);

#endif
