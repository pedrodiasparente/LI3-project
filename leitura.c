#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *fp;
	char* *clientes = NULL;
	char* *produtos = NULL;
	char* * vendas = NULL;
	char buffer[64];
	int i;
	char* token;
	char* niceBuffer;
	int r=1;
	int strcount = 0;
	int numClientesReal;
	int numProdutosReal;
	int numVendas;

	fp = fopen("./Ficheiros/Clientes.txt", "r");
	while(fgets(buffer, 64, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		clientes = (char**)realloc(clientes, (strcount + 1) * sizeof(char*));
		clientes[strcount++] = strdup(niceBuffer);
	}
	fclose(fp);
	numClientesReal = strcount;
	strcount = 0;

	fp = fopen("./Ficheiros/Produtos.txt", "r");
	while(fgets(buffer, 64, fp)) {
		niceBuffer = strtok(buffer, "\r\n");
		produtos = (char**)realloc(produtos, (strcount + 1) * sizeof(char*));
		produtos[strcount++] = strdup(niceBuffer);
	}
	fclose(fp);
	numProdutosReal = strcount;
	strcount = 0;


	fp = fopen("./Ficheiros/Vendas_1M.txt", "r");
	while(fgets(buffer, 64, fp)) { 
		niceBuffer = strtok(buffer, "\r\n");
		vendas = (char**)realloc(vendas, (strcount + 1) * sizeof(char*));
		vendas[strcount++] = strdup(niceBuffer);
		
		token = strtok(niceBuffer, " ");
		for(i=0;i<numProdutosReal;i++) {
			if (strcmp(token,produtos[i]) == 0) {
				r=0;
				break;
			} 
		}
		
		token = strtok(NULL, " ");

		//vendas[i] = strdup(token);
		//i++;
		//printf( "%s\n", token );
	}
	numVendas = strcount;

	for(i=0;i<numVendas;i++)
		printf("%s\n", vendas[i]);

	for(i=0;i<numProdutosReal;i++)
		printf("%s\n", produtos[i]);
	
	for(i=0;i<numClientesReal;i++)
		printf("%s\n", clientes[i]);		
	return 0;
}
