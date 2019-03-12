#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avltree.h"

int getFile(AVL *avl, FILE *fp){
	char* niceBuffer;
	char buffer[35];
	int strcount = 0;

	while(fgets(buffer, 35, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		insertAVL(avl, niceBuffer);
		strcount++;
	}
	return strcount;
}

int writeFile(AVL a, FILE *fp){
	int vWrite;

	vWrite = 0;
	if(a != NULL){
		vWrite += writeFile(a -> esq, fp);
		if(fwrite(a -> cont, 1, strlen(a -> cont), fp)){
			vWrite++;
			fwrite("\n", 1, 1, fp);
		}
		vWrite += writeFile(a -> dir, fp);
	}
	return vWrite;
}

int valVendas(char *buffer, AVL *prod, AVL *client){
	int val;
	char* currentTok;

	val = 1;

	currentTok = strtok(buffer, " ");
	if (!(searchAVL(*prod, currentTok))) val = 0;

	currentTok = strtok(NULL, " ");
	if (atoi(currentTok) < 0 || atof(currentTok) >= 1000.0) val = 0;

	currentTok = strtok(NULL, " ");
	if (atoi(currentTok) < 1 || atoi(currentTok) > 200) val = 0;

	currentTok = strtok(NULL, " ");
	if (strcmp(currentTok,"P") != 0 && strcmp(currentTok,"N") != 0) val = 0;

	currentTok = strtok(NULL, " ");
	if (!(searchAVL(*client, currentTok))) val = 0;

	currentTok = strtok(NULL, " ");
	if (atoi(currentTok) < 1 || atoi(currentTok) > 12) val = 0;

	currentTok = strtok(NULL, " ");
	if (atoi(currentTok) < 1 || atoi(currentTok) > 3) val = 0;

	return val;
}

int getVendas(AVL *avl, AVL *prod, AVL *client, FILE *fp){
	char* lnBuffer;
	char buffer[35];
	int strcount = 0;
	int val;

	while(fgets(buffer, 35, fp)) {
		lnBuffer = strdup(buffer);
		lnBuffer = strtok(lnBuffer, "\r\n");

		val = valVendas(buffer, prod, client);

		if (val) {
			strcount++;
			insertAVL(avl, lnBuffer);
		}
	}
	return strcount;
}

int main() {
	FILE *fp;
	AVL clientes, produtos, vendas;
	clientes = produtos = vendas = NULL;
	int numClientesReal, numProdutosReal, numVendas, vWrite;
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

	fp = fopen("./Ficheiros/Venda_1MValidas.txt", "w");
	vWrite = writeFile(vendas, fp);
	fclose(fp);

	//printAVL(clientes);
	//printAVL(produtos);
	printAVL(vendas);

	printf("Vendas Escritas: %d\n", vWrite);
	printf("Número de clientes:%d\nNúmero de Produtos:%d\nNúmero de vendas:%d\n",
			numClientesReal, numProdutosReal, numVendas);

	return 0;
}
