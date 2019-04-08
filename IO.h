#ifndef IO_H
#define IO_H

int IOinit(int * query);

void inQuery1(char * fichVendas, char * fichProdutos, char * fichClientes);

void outQuery1(int numVendas, char * nomeFich);

int printCat(void * prodkey, void * prodval, void* data);

void inQuery2(char * c);

void outQuery2(int numP);

void inQuery3(char * query3Prod, int * query3Mes, int * query3Filial);

void outQuery3(int vendasP, int vendasN, int fatP, int fatN);

void inQuery4(int * modo);

void outQuery4(int total, int f1, int f2, int f3, int modo);

void outQuery5();

void outQuery6(int client, int prod);

void inQuery7(char * cliente);

void outQuery7(int * prodMes);

void inQuery8(int * li, int * ls);

void outQuery8(int vendas, float faturado);

void inQuery9(char * produto, int * filial);

void outQuery9(int num, char promo);

void inQuery10(char * produto, int * filial);

void outQuery10();

void inQuery12(char * cliente);

void outQuery12();


#endif
