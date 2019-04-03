#ifndef FATURACAO_H
#define FATURACAO_H

typedef struct faturacao *FATURACAO;

typedef struct fatGlobal *FATGLOBAL;

FATURACAO newFaturacao();

void destroyFaturacao(FATURACAO f);

int getNVendasP(int mes, FATURACAO f, int filial);

int getNVendasN(int mes, FATURACAO f, int filial);

float getPrecoP(int mes, FATURACAO f, int filial);

float getPrecoN(int mes, FATURACAO f, int filial);

void incNVendas(FATURACAO f, int mes, int filial, char promo);

void somaPrecoTotal(FATURACAO f, int mes, int filial, float preco, char promo);

FATGLOBAL newFatGlobal();

gint initFatGlobal(gpointer key, gpointer value, gpointer data);

void destroyFatGlobal(FATGLOBAL f);

void insertFatGlobal(FATGLOBAL f, char *produto, FATURACAO fat);

gpointer lookupFatGlobal(FATGLOBAL f, char *produto);

void traverseFatGlobal(FATGLOBAL f, GTraverseFunc func, gpointer user_data);

int numFatGlobal(FATGLOBAL f);

#endif
