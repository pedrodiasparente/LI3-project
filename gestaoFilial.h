#ifndef GESTAOFILIAL_H
#define GESTAOFILIAL_H

typedef struct gestaoFilial *GESTAOFILIAL;

typedef struct gestaoCliente *GESTAOCLIENTE;

typedef struct infoProduto *INFOPROD;

GESTAOFILIAL newGestaoFilial();

gint initGestaoFilial(gpointer key, gpointer value, gpointer data);

void destroyGestaoFilial(GESTAOFILIAL gf);

void insertGestaoFilial(GESTAOFILIAL gf, char *cliente, GESTAOCLIENTE gc);

gpointer lookupGestaoFilial(GESTAOFILIAL gf, char *cliente);

void traverseGestFilial(GESTAOFILIAL gf, GTraverseFunc func, gpointer user_data);

int numGestaoFilial(GESTAOFILIAL gf);

GESTAOCLIENTE newGestaoCliente();

void addProdutoCliente(GESTAOCLIENTE g, char * prod, INFOPROD newProduto);

gpointer lookupProdutoCliente(GESTAOCLIENTE g, char * prod);

int numProdutosCliente(GESTAOCLIENTE g);

void destroyGestaoCliente(GESTAOCLIENTE gc);

INFOPROD newInfoProd();

void destroyInfoProd(INFOPROD i);

int getQuant(INFOPROD i, int mes, char promo);

void setQuant(INFOPROD i, int mes, int quant, char promo);

#endif
