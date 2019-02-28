#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"

int getFile(AVL *avl, FILE *fp){
	char* niceBuffer;
	char buffer[64];
	int strcount = 0;

	while(fgets(buffer, 64, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		insertAVL(avl, niceBuffer);
		strcount++;
	}
	return strcount;
}

int getVendas(AVL *avl, AVL *prod, AVL *client, FILE *fp){
	char* LnBuffer;
	char buffer[64];
	int strcount = 0;
	char* tokenProd;
	char* tokenCost;
	char* tokenQuant;
	char* tokenPN;
	char* tokenClient;
	char* tokenMes;
	char* tokenFilial;
	int triggerProdut;
	int triggerCost;
	int triggerQuant;
	int triggerPN;
	int triggerClient;
	int triggerMes;
	int triggerFilial;

	while(fgets(buffer, 64, fp)) {
		LnBuffer = strdup(buffer);
		LnBuffer = strtok(LnBuffer, "\r\n");
		
		triggerProdut = 0;
		triggerCost = 0;
		triggerQuant = 0;
		triggerPN = 0;
		triggerClient = 0;
		triggerMes = 0;
		triggerFilial = 0;

		tokenProd = strtok(buffer, " ");
		tokenCost = strtok(NULL, " ");
		tokenQuant = strtok(NULL, " ");
		tokenPN = strtok(NULL, " ");
		tokenClient = strtok(NULL, " ");
		tokenMes = strtok(NULL, " ");
		tokenFilial = strtok(NULL, " ");

		
		if (searchAVL(*prod, tokenProd)) triggerProdut = 1;

		if (atof(tokenCost) >= 0.0 && atof(tokenCost) < 1000.0) triggerCost = 1;
		
		if (atoi(tokenQuant) >= 1 && atoi(tokenQuant) <= 200) triggerQuant = 1;
		
		if (strcmp(tokenPN,"P") == 0 || strcmp(tokenPN,"N") == 0) triggerPN = 1;
		
		if (searchAVL(*client, tokenClient)) triggerClient = 1;

		if (atoi(tokenMes) >= 1 && atoi(tokenMes) <= 12) triggerMes = 1;
		
		if (atoi(tokenFilial) >= 1 && atoi(tokenFilial) <= 3) triggerFilial = 1;
		
		if (triggerProdut && triggerCost && triggerQuant && triggerPN && triggerClient && triggerMes && triggerFilial) {
			strcount++;
			printf("%d %s %s\n", strcount, tokenProd, tokenClient);
			insertAVL(avl, LnBuffer);
		}
	}
	return strcount;
}

int main() {
	FILE *fp;
	AVL clientes, produtos, vendas;
	clientes = produtos = vendas = NULL;
	int numClientesReal, numProdutosReal, numVendas;
	numClientesReal = numProdutosReal = numVendas = 0;

	fp = fopen("./Ficheiros/Clientes.txt", "r");
	numClientesReal = getFile(&clientes, fp);
	fclose(fp);

	fp = fopen("./Ficheiros/Produtos.txt", "r");
	numProdutosReal = getFile(&produtos, fp);
	fclose(fp);

	fp = fopen("./Ficheiros/Vendas_1M.txt", "r");
 	numVendas = getVendas(&vendas, &produtos, &clientes, fp);
	fclose(fp);

	//printAVL(clientes);
	//printAVL(produtos);
	printAVL(vendas);

	printf("Número de clientes:%d\nNúmero de Produtos:%d\nNúmero de vendas:%d\n",
			numClientesReal, numProdutosReal, numVendas);



	return 0;
}
