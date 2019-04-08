/**
 * @file catClientes.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas para gerir o catálogo de produtos.
 */
#ifndef FATURACAO_H
#define FATURACAO_H

/**
 * @brief Estrutura que cria a Faturação Global (contém produtos em que cada um tem uma Faturação).
 */
typedef struct fatGlobal *FATGLOBAL;

/**
 * @brief Estrutura que cria a Faturação.
 */
typedef struct faturacao *FATURACAO;

/**
 * @brief Função que cria uma nova Faturação.

 * @return Uma Faturação vazia.
 */
FATURACAO newFaturacao();

/**
 * @brief Função que destrói uma Faturação.
 */
void destroyFaturacao(FATURACAO f);

/**
 * @brief Função que vai buscar o número de vendas feitas em promoção, num certo mês e filial.

 * @return O número de vendas.
 */
int getNVendasP(int mes, FATURACAO f, int filial);

/**
 * @brief Função que vai buscar o número de vendas feitas sem promoção, num certo mês e filial.

 * @return O número de vendas.
 */
int getNVendasN(int mes, FATURACAO f, int filial);

/**
 * @brief Função que vai buscar o preço de o produto vendido em promoção, num certo mês e filial.

 * @return O preço do produto.
 */
float getPrecoP(int mes, FATURACAO f, int filial);

/**
 * @brief Função que vai buscar o preço de o produto vendido sem promoção, num certo mês e filial.

 * @return O preço do produto.
 */
float getPrecoN(int mes, FATURACAO f, int filial);

/**
 * @brief Função que incrementa o número de vendas num certo mês, promoção e filial.
 */
void incNVendas(FATURACAO f, int mes, int filial, char promo);

/**
 * @brief Função que soma a faturação das vendas num certo mês, promoção e filial.
 */
void somaPrecoTotal(FATURACAO f, int mes, int filial, float preco, char promo, int quantidade);

/**
 * @brief Função que cria uma nova Faturação Global.

 * @return Uma Faturação Global vazia.
 */
FATGLOBAL newFatGlobal();

/**
 * @brief Função que "inicia" uma Faturação Global (vai ser usada para inserir todas as faturações de todos os produtos nesta faturação global).
 */
gint initFatGlobal(gpointer key, gpointer value, gpointer data);

/**
 * @brief Função que destrói a Faturação Global.
 */
void destroyFatGlobal(FATGLOBAL f);

/**
 * @brief Função usada pela initFatGlobal para inserir as faturações na Faturação Global.
 */
void insertFatGlobal(FATGLOBAL f, char *produto, FATURACAO fat);

/**
 * @brief Função que procura um certo produto numa Faturação Global.

 * @return A fatura correspondente ao produto procurado.
 */
gpointer lookupFatGlobal(FATGLOBAL f, char *produto);

/**
 * @brief Função que percorre a Faturação Global, aplicando uma função auxiliar (passada em argumento) a todos os produtos.
 */
void traverseFatGlobal(FATGLOBAL f, GTraverseFunc func, gpointer user_data);

/**
 * @brief Função que conta o número de produtos numa Faturação Global.

 * @return O número de produtos na Faturação Global.
 */
int numFatGlobal(FATGLOBAL f);

#endif
