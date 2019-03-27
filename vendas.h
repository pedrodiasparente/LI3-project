#ifndef STRUCTVENDAS_H
#define STRUCTVENDAS_H

typedef struct venda *VENDA;

VENDA strToVenda(char * str);

void printVenda(VENDA v);

char * getProduto(VENDA v);

char * getCliente(VENDA v);

float getPreco(VENDA v);

int getQuantidade(VENDA v);

char getPromo(VENDA v);

int getMes(VENDA v);

int getFilial(VENDA v);

#endif
