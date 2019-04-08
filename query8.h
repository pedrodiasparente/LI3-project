/**
 * @file query8.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas pela query8.
 */
#ifndef QUERY8_H
#define QUERY8_H

/**
 * @brief Função calcula o total de vendas num intervalo de tempo fechado.
 *
 * @return Número total de vendas nesse intervalo.
 */
int nVendasIntervalo(FATGLOBAL fg, int a , int b);

/**
 * @brief Função calcula o total faturado num intervalo de tempo fechado.
 *
 * @return Total faturado nesse intervalo.
 */
float totFatIntervalo(FATGLOBAL fg, int a , int b);

#endif
