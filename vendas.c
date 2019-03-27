#define _GNU_SOURCE 1

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "vendas.h"

struct venda {
    char * cliente;
    char * produto;
    char promo;
    float preco;
    int quantidade;
    int mes;
    int filial;
};

VENDA strToVenda(char * str){
	char* currentTok;
    char* prod;
    VENDA v;
    v = malloc(sizeof(VENDA)*8);

	currentTok = strtok(str, " ");
    prod = strdup(currentTok);
    v -> produto = strdup(prod);

	currentTok = strtok(NULL, " ");
	v -> preco = atof(currentTok);

	currentTok = strtok(NULL, " ");
	v -> quantidade = atoi(currentTok);

	currentTok = strtok(NULL, " ");
	v -> promo = currentTok[0];

	currentTok = strtok(NULL, " ");
	v -> cliente = strdup(currentTok);

	currentTok = strtok(NULL, " ");
	v -> mes = atoi(currentTok);

	currentTok = strtok(NULL, " ");
	v -> filial = atoi(currentTok);


	return v;
}

void printVenda(VENDA v){
    if(v != NULL)
        printf("%s %f %d %c %s %d %d\n", v -> produto,
                                         v -> preco,
                                         v -> quantidade,
                                         v -> promo,
                                         v -> cliente,
                                         v -> mes,
                                         v -> filial);
    else
        printf("NULL\n");
}

void destroyVenda(VENDA v){
    free(v -> produto);
    free(v -> cliente);
}

char * getProduto(VENDA v){
    return (v -> produto);
}
char * getCliente(VENDA v){
    return (v -> cliente);
}

float getPreco(VENDA v){
    return (v -> preco);
}

int getQuantidade(VENDA v){
    return (v -> quantidade);
}

char getPromo(VENDA v){
    return (v -> promo);
}

int getMes(VENDA v){
    return (v -> mes);
}

int getFilial(VENDA v){
    return (v -> filial);
}
