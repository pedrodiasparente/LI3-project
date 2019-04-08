#include <stdio.h>
#include <glib.h>
#include <gmodule.h>


static void inQuery1Aux(char * fich, char * itemName){
    int findFicheiro, scanned ;
    char item[40];

    scanned = 0;

    printf("\nPor favor insira a localização do ficheiro de %s: (0 para default)\n", itemName);
    scanf("%s", item);

    if(fopen(item, "r")){
        fich = strdup(item);
		printf("\n(->) Ficheiro %s recebido! = %s\n", itemName, fich);
	}
    else{
        printf("Ficheiro inexistente! Revertendo para default...\n");
		fich = NULL;
	}

	return;
}

void inQuery1(char * fichVendas, char * fichProdutos, char * fichClientes){
    inQuery1Aux(fichVendas, "Vendas");
    inQuery1Aux(fichProdutos, "Produtos");
    inQuery1Aux(fichProdutos, "Clientes");
	printf("\nFicheiros de input escolhidos\n");
}

void outQuery1(FATGLOBAL fg, char * nomeFich){
    int numVendas, numProds, numClientes;

    traverseFatGlobal(fg, checkNVendas, &numVendas);
    printf(">NÚMERO VENDAS = [%d]\n lidas do ficheiro: \"%s\"\n", numVendas, nomeFich);

}

int printProdutos(void * prodkey, void * prodval, void* data){
    printf("%s\n", prodVal)
    return 0;
}

void inQuery2(char * c){
    printf("\n[QUERY 2] (<-)\n");
    printf("Qual a letra inicial a procurar?\n");
    scanf("%c\n", c);
}

void outQuery2(int numP){
    printf("\n[QUERY 2] (->)\n");
    printf("\n>NÚMERO DE PRODUTOS: %d", numP)
}

void inQuery3(char * query3Prod, int * query3Prod, int * query3Prod){
    printf("\n[QUERY 3] (<-)\n");
    printf("Forneça um produto, um mês e uma filial(Separados por um espaço)\n");
    scanf("%s %d %d",query3Prod, query3Mes, query3Filial);
}

void outQuery3(int vendasP, int vendasN, int fatP, int fatN){
    printf("\n[QUERY 3] (->)\n");
    printf("Vendas (promoção): [%d]\n", vendasP);
    printf("Vendas (sem promoção): [%d]\n", vendasN);
    printf("Faturação (promoção): [%f]\n", fatP);
    printf("Faturação (sem promoção): [%f]\n", fatN);
}

void inQuery4(int * modo){
    printf("\n[QUERY 4] (<-)\n");
    printf("Procurar por:\n Total[0] (default)\nFilial[1]\n");
    scanf("%d", modo);
}


void outQuery4(int total, int f1, int f2, int f3, int modo){
    printf("\n[QUERY 4] (->)\n");
    if(modo == 0)
        printf("TOTAL [%d]\n", total);
    else{
        printf("Filial 1 [%d]\n", f1);
        printf("Filial 2 [%d]\n", f2);
        printf("Filial 3 [%d]\n", f3);
    }
}

void outQuery6(){

}
