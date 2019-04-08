#define _GNU_SOURCE 1

#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include <string.h>

int IOinit(int * query){
    printf("\n\n\nSelecionar query a utilizar:\n");
    printf("[1]-Query1:\n");
    printf("[2]-Query2:\n");
    printf("[3]-Query3:\n");
    printf("[4]-Query4:\n");
    printf("[5]-Query5:\n");
    printf("[6]-Query6:\n");
    printf("[7]-Query7:\n");
    printf("[8]-Query8:\n");
    printf("[9]-Query9:\n");
    printf("[10]-Query10:\n");
    printf("[11]-Query11 (not working):\n");
    printf("[12]-Query12:\n");
    printf("\n");

    scanf("%d", query);
    return *query;
}

static void inQuery1Aux(char * fich, char * itemName){
    char item[40];

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

void outQuery1(int numVendas, char * nomeFich){
    printf(">NÚMERO VENDAS = [%d]\n lidas do ficheiro: \"%s\"\n", numVendas, nomeFich);

}

int printCat(void * prodkey, void * prodval, void* data){
    printf("%s\n", (char *) prodval);
    return 0;
}

void inQuery2(char * c){
    printf("\n[QUERY 2] (<-)\n");
    printf("Qual a letra inicial a procurar?\n");
    scanf("\n%c", c);
    printf("\n");
}

void outQuery2(int numP){
    printf("\n>NÚMERO DE PRODUTOS: %d", numP);
    printf("\n[QUERY 2] (->)\n");
}

void inQuery3(char * query3Prod, int * query3Mes, int * query3Filial){
    printf("\n[QUERY 3] (<-)\n");
    printf("Forneça um produto, um mês e uma filial(Separados por um espaço)\n");
    scanf("\n%s",query3Prod);
    scanf(" %d", query3Mes);
    scanf(" %d", query3Filial);
}

void outQuery3(int vendasP, int vendasN, float fatP, float fatN){
    printf("\n[QUERY 3] (->)\n");
    printf("Vendas (promoção): [%d]\n", vendasP);
    printf("Vendas (sem promoção): [%d]\n", vendasN);
    printf("Faturação (promoção): [%f]\n", fatP);
    printf("Faturação (sem promoção): [%f]\n", fatN);
}

void inQuery4(int * modo){
    printf("\n[QUERY 4] (<-)\n");
    printf("Procurar por:\n Total-[0] (default)\nFilial-[1]\n");
    scanf("\n%d", modo);
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

void outQuery5(){
    printf("\n[QUERY 5] (->)\n");
}

void outQuery6(int client, int prod){
    printf("\n[QUERY 6] (->)\n");
    printf("CLIENTES QUE NÃO COMPRARAM: %d\n", client);
    printf("PRODUTOS NÃO COMPRADOS: %d\n", prod);
}

void inQuery7(char * cliente){
    printf("\n[QUERY 7] (<-)\n");
    printf("Insira cliente a procurar\n");
    scanf("\n%s", cliente);
}

void outQuery7(int * prodMes){
    int i;
    printf("\n[QUERY 7] (->)\n");

    for(i = 0; i < 12; i++)
        printf("|[Mes %d] = %d |", (i + 1), prodMes[i]);
    printf("\n");
}

void inQuery8(int * li, int * ls){
    printf("\n[QUERY 8] (<-)\n");
    printf("Forneça um limite iferior e superior (Separados por um espaço)\n");
    scanf("\n%d %d", li, ls);
}

void outQuery8(int vendas, float faturado){
    printf("\n[QUERY 8] (->)\n");
    printf("NUMERO DE VENDAS: %d\n", vendas);
    printf("TOTAL FATURADO: %f\n", faturado);
}

void inQuery9(char * produto, int * filial){
    printf("\n[QUERY 9] (<-)\n");
    printf("Forneça um produto e uma filial (Separados por um espaço)\n");
    scanf("\n%s %d", produto, filial);
}

void outQuery9(int num, char promo){
    printf("\n[QUERY 9] (->)\n");
    if (promo == 'P'){
        printf("NÚMERO DE CLIENTES P: %d\n", num);
    }
    if (promo == 'N'){
        printf("NÚMERO DE CLIENTES N: %d\n", num);
    }
}

void inQuery10(char * cliente, int * mes){
    printf("\n[QUERY 9] (<-)\n");
    printf("Forneça um Cliente e um mês (Separados por um espaço)\n");
    scanf("\n%s %d", cliente, mes);
}

void outQuery10(){
    printf("\n[QUERY 10] (->)\n");
}

void inQuery12(char * cliente){
    printf("\n[QUERY 12] (<-)\n");
    printf("Forneça um cliente\n");
    scanf("%s", cliente);
}

void outQuery12(){
    printf("\n[QUERY 12] (->)\n");
}
