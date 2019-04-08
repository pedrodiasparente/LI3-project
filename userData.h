/**
 * @file userData.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas para gerir a data.
 */
#ifndef USERDATA_H
#define USERDATA_H

/**
 * @brief Estrutura do userData.
 */
typedef struct userData *DATA;

/**
 * @brief Função que junta dois apontadores num par para ser passado como data.
 *
 * @return Uma DATA.
 */
DATA data(void* data1, void * data2);

/**
 * @brief Função que utiliza o primeiro parâmetro de um par de uma DATA.
 */
void * getData1(DATA d);

/**
 * @brief Função que utiliza o segundo parâmetro de um par de uma DATA.
 */
void * getData2(DATA d);

#endif
