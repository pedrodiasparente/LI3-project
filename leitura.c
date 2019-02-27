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
 	numVendas = getFile(&vendas, fp);
	fclose(fp);

	printAVL(clientes);
	printAVL(produtos);
	printAVL(vendas);

	printf("Número de clientes:%d\nNúmero de Produtos:%d\nNúmero de vendas:%d\n",
			numClientesReal, numProdutosReal, numVendas);

	return 0;
}
