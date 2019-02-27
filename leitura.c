#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * * getVendas(FILE *fp, int *strcount){
	char* niceBuffer;
	char buffer[64];
	char * * vendas = NULL;

	while(fgets(buffer, 64, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		vendas = (char**)realloc(vendas, ((*strcount) + 1) * sizeof(char*));
		vendas[(*strcount)++] = strdup(niceBuffer);
	}

	return vendas;
}

char * * getProdutos(FILE *fp, int *strcount){
	char* niceBuffer;
	char buffer[64];
	char * * produtos = NULL;

	while(fgets(buffer, 64, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		produtos = (char**)realloc(produtos, ((*strcount) + 1) * sizeof(char*));
		produtos[(*strcount)++] = strdup(niceBuffer);
	}

	return produtos;
}

char * * getClientes(FILE *fp, int *strcount){
	char* niceBuffer;
	char buffer[64];
	char * * clientes = NULL;

	while(fgets(buffer, 64, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		clientes = (char**)realloc(clientes, ((*strcount) + 1) * sizeof(char*));
		clientes[(*strcount)++] = strdup(niceBuffer);
	}

	return clientes;
}

int main() {
	FILE *fp;
	char* *clientes = NULL;
	char* *produtos = NULL;
	char* * vendas = NULL;
	int i;
	int numClientesReal = 0;
	int numProdutosReal = 0;
	int numVendas = 0;

	fp = fopen("./Ficheiros/Clientes.txt", "r");
	clientes = getClientes(fp, &numClientesReal);
	fclose(fp);

	fp = fopen("./Ficheiros/Produtos.txt", "r");
	produtos = getProdutos(fp, &numProdutosReal);
	fclose(fp);

	fp = fopen("./Ficheiros/Vendas_1M.txt", "r");
 	vendas = getVendas(fp, &numVendas);
	fclose(fp);

	for(i=0;i<numVendas;i++)
		printf("%s\n", vendas[i]);

	for(i=0;i<numProdutosReal;i++)
		printf("%s\n", produtos[i]);

	for(i=0;i<numClientesReal;i++)
		printf("%s\n", clientes[i]);

	return 0;
}
