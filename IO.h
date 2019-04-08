#ifndef IO_H
#define IO_H

void inQuery1(char * fichVendas, char * fichProdutos, char * fichClientes);

/*void outQuery1(FATGLOBAL fg, char * nomeFich);
*/
int printProdutos(void * prodkey, void * prodval, void* data);

void inQuery2(char * c);

void outQuery2(int numP);

void inQuery3(char * query3Prod, int * query3Mes, int * query3Filial);

void outQuery3(int vendasP, int vendasN, int fatP, int fatN);

void inQuery4(int * modo);

void outQuery4(int total, int f1, int f2, int f3, int modo);

void outQuery6();

void outQuery10();

#endif
