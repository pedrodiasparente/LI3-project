/**
 * @file query3.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas pela query3.
 */
#ifndef QUERY3_H
#define QUERY3_H

/**
 * @brief Função que calcula o total de vendas de um dado produto em promoção, num dado mês e numa dada filial, de uma FATGLOBAL.
 *
 * @return Número de vendas.
 */
int totalVendasProdMesP(FATGLOBAL fg, char * prod, int mes, int filial);

/**
 * @brief Função que calcula o total de vendas de um dado produto sem promoção, num dado mês e numa dada filial, de uma FATGLOBAL.
 *
 * @return Número de vendas.
 */
int totalVendasProdMesN(FATGLOBAL fg, char * prod, int mes, int filial);

/**
 * @brief Função que calcula a faturação total de um dado produto em promoção, num dado mês e numa dada filial, de uma FATGLOBAL.
 *
 * @return Faturação total.
 */
float totalFatProdMesP(FATGLOBAL fg, char * prod, int mes, int filial);

/**
 * @brief Função que calcula a faturação total de um dado produto sem promoção, num dado mês e numa dada filial, de uma FATGLOBAL.
 *
 * @return Faturação total.
 */
float totalFatProdMesN(FATGLOBAL fg, char * prod, int mes, int filial);

#endif
