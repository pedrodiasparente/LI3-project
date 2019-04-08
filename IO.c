#include <stdio.h>
#include <glib.h>
#include <gmodule.h>
#include "vendas.h"
#include "leitura.h"
#include "catProdutos.h"
#include "catClientes.h"
#include "gestaoFilial.h"

static int checkNVendas(void * prod, void * fat, void* numVendas){
    int i, filial;
	int * res = numVendas;
    for(i = 1; i < 13; i++){
        for(filial = 1; filial < 4; filial++){
            *res += getNVendasP(i, fat, filial);
            *res += getNVendasN(i, fat, filial);
		}
    }

    return FALSE;
}

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

static int printProdutos(void * prodkey, void * prodval, void* data){
    printf("%s\n", prodVal)
    return FALSE;
}

void inQuery2(char * c){
    printf("\n[QUERY 2] (<-)\n");
    printf("Qual a letra inicial a procurar?\n");
    scanf("%c\n", c);
}

void outQuery2(CAT_PRODUTOS catProdutos){
    printf("\n[QUERY 2] (->)\n");
    foreach_Cat_prod(catProdutos, printProdutos, NULL);
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
    printf("Faturação (promoção): [%f]\n", fatP
    printf("Faturação (sem promoção): [%f]\n", fatN);
}

void outQuery4(int vendasP, int vendasN, int fatP, int fatN){
    printf("QUERY 4: TOTAL [%d]\n", total);
    printf("QUERY 4: F1 [%d]\n", fat);
    printf("QUERY 4: F2 [%d]\n", num_Cat_prod(productNoBuyFilial(fatGlobal, 2)));
    printf("QUERY 4: F3 [%d]\n", num_Cat_prod(productNoBuyFilial(fatGlobal, 3)));
}
