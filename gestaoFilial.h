#ifndef GESTAOFILIAL_H
#define GESTAOFILIAL_H

typedef struct gestaoFilial *GESTAOFILIAL;

typedef struct gestaoCliente *GESTAOCLIENTE;

GESTAOFILIAL newGestaoFilial();

void destroy_gestao_filial(GESTAOFILIAL gf);

void insert_gestao_filial(GESTAOFILIAL gf, char *cliente);

gpointer lookup_gestao_filial(GESTAOFILIAL gf, char *cliente);

void traverseGestFilial(GESTAOFILIAL gf, GTraverseFunc func, gpointer user_data);

int num_gestao_filial(GESTAOFILIAL gf);

GESTAOCLIENTE newGestaoCliente();

void addProdutoCliente(GESTAOCLIENTE g, char * prod, int quant, int mes, char promo);

gpointer lookupProdutoCliente(GESTAOCLIENTE g, char * prod);

int numProdutosCliente(GESTAOCLIENTE g);

#endif
