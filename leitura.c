#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *fp;
	char* clientes[20000];
	char* produtos[200000];
	char* vendas[1000000];
	char buffer[64];
	int i = 0;
	int j;
	char* token;

	/*fp = fopen("./Ficheiros/Clientes.txt", "r");
	while(fgets(buffer, 64, fp)) {
		clientes[i] = strdup(buffer);
		i++;
	}
	fclose(fp);

	fp = fopen("./Ficheiros/Produtos.txt", "r");
	while(fgets(buffer, 64, fp)) {
		produtos[i] = strdup(buffer);
		i++;
	}
	fclose(fp);
	*/
	fp = fopen("./Ficheiros/Vendas_1M.txt", "r");
	while(fgets(buffer, 64, fp)) {
		vendas[i] = strdup(buffer);
		i++;
		token = strtok(buffer, " ");
		printf( " %s\n", token );
	}

	for(j=0;j<1000000;j++)
		printf("%s", vendas[j]);
		
	return 0;
}
