#ifndef FATURACAO_H
#define FATURACAO_H

typedef struct faturacao *FATURACAO;

typedef struct fatGlobal *FATGLOBAL;

FATURACAO newFaturacao();

void destroyFacturacao(FATURACAO f);

int getNVendasP(int mes, FATURACAO f, int filial);

int getNVendasN(int mes, FATURACAO f, int filial);

int getPrecoP(int mes, FATURACAO f, int filial);

int getPrecoN(int mes, FATURACAO f, int filial);

void incNVendasP(int mes, FATURACAO f, int filial);

void incNVendasN(int mes, FATURACAO f, int filial);

void setPrecoTotalP(int mes, FATURACAO f,int filial, int preco);

void setPrecoTotalN(int mes, FATURACAO f,int filial, int preco);



/*int getNVendasPTotal(int mes, FATURACAO f);

int getNVendasNTotal(int mes, FATURACAO f);

int getPrecoPTotal(int mes, FATURACAO f);

int getPrecoNTotal(int mes, FATURACAO f);*/

#endif
