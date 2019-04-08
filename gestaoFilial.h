/**
 * @file gestaoFilial.h
 * @author Grupo LI3 nº33
 * @date 8 Abril 2019
 * @brief Funções utilizadas para gerir a gestão de filial.
 */
#ifndef GESTAOFILIAL_H
#define GESTAOFILIAL_H

/**
 * @brief Estrutura da gestão de filial.
 */
typedef struct gestaoFilial *GESTAOFILIAL;

/**
 * @brief Estrutura da gestão de cliente.
 */
typedef struct gestaoCliente *GESTAOCLIENTE;

/**
 * @brief Estrutura da gestão de informação do produto.
 */
typedef struct infoProduto *INFOPROD;

/**
 * @brief Função que cria uma nova gestão de filial.
 *
 * @return Uma nova gestão de filial vazia.
 */
GESTAOFILIAL newGestaoFilial();

/**
 * @brief Preenche uma gestão de filial com todos os clientes.
 */
gint initGestaoFilial(gpointer key, gpointer value, gpointer data);

/**
 * @brief Função que destrói uma dada gestão de filial.
 */
void destroyGestaoFilial(GESTAOFILIAL gf);

/**
 * @brief Função auxiliar usada pela initGestaoFilial para inserir as GESTAOCLIENTE na GESTAOFILIAL.
 */
void insertGestaoFilial(GESTAOFILIAL gf, char *cliente, GESTAOCLIENTE gc);

/**
 * @brief Procura um dado cliente numa gestão de filial passada por referência.
 *
 * @return Retorna a GESTAOCLIENTE correspondente ao cliente procurado.
 */
gpointer lookupGestaoFilial(GESTAOFILIAL gf, char *cliente);

/**
 * @brief Função que percorre uma dada gestão de filial e aplica uma dada função a todos os seus elementos.
 */
void traverseGestFilial(GESTAOFILIAL gf, GTraverseFunc func, gpointer user_data);

/**
 * @brief Função que calcula o número de clientes guardado numa dada gestão de filial.
 *
 * @return Número de clientes presentes na gestão de filial.
 */
int numGestaoFilial(GESTAOFILIAL gf);

/**
 * @brief Função que cria uma nova gestão de clientes.
 *
 * @return Uma gestão de clientes vazia.
 */
GESTAOCLIENTE newGestaoCliente();

/**
 * @brief Funçaõ que adiciona uma informação de um produto numa dada gestão de clientes.
 */
void addProdutoCliente(GESTAOCLIENTE g, char * prod, INFOPROD newProduto);

/**
 * @brief Função que procura um dado produto numa gestão de clientes.
 *
 * @return Retorna a informação correspondente ao produto.
 */
gpointer lookupProdutoCliente(GESTAOCLIENTE g, char * prod);

/**
 * @brief Função que calcula o número de produtos numa dada gestão de clientes.
 *
 * @return Número de produtos numa gestão de clientes.
 */
int numProdutosCliente(GESTAOCLIENTE g);

/**
 * @brief Função que percorre uma dada gestão de clientes e aplica uma dada função a todos os seus elementos.
 */
void traverseGestClient(GESTAOCLIENTE g, GTraverseFunc func, gpointer user_data);

/**
 * @brief Função que destrói uma dada gestão de clientes.
 */
void destroyGestaoCliente(GESTAOCLIENTE gc);

/**
 * @brief Função que cria uma nova estrutura de informação de produtos.
 *
 * @return uma INFOPROD vazia.
 */
INFOPROD newInfoProd();

/**
 * @brief Função que destrói uma INFOPROD.
 */
void destroyInfoProd(INFOPROD i);

/**
 * @brief Função que calcula a quantidade de um produto num dado mês com ou sem promoção.
 *
 * @return Número de produtos num dado mês com ou sem promoção.
 */
int getQuant(INFOPROD i, int mes, char promo);

/**
 * @brief Função que altera a quantidade de um produto num dado mês com ou sem promoção
 */
void setQuant(INFOPROD i, int mes, int quant, char promo);

/**
 * @brief Função que calcula o preço de um produto num dado mês com ou sem promoção.
 *
 * @return Preço de um produto num mês com ou sem promoção.
 */
float getPrecoGF(INFOPROD i, int mes, char promo);

/**
 * @brief Função que altera o preço de um produto num dado mês com ou sem promoção
 */
void setPrecoGF(INFOPROD i, int mes, float preco, char promo);

#endif
