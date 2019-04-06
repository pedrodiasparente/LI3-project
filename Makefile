CC = gcc
LDLIBS = `pkg-config --libs glib-2.0` `pkg-config --cflags --libs gmodule-2.0`
CFLAGS = -O3 -Wall -ansi `pkg-config --cflags glib-2.0` `pkg-config --cflags --libs gmodule-2.0`

sgv: leitura.o clientNoBuy.o vendas.o userData.o main.o findProduct.o faturacao.o gestaoFilial.o catProdutos.o catClientes.o vendasProdMes.o query4.o
	$(CC) $(CFLAGS) main.o leitura.o clientNoBuy.o vendas.o userData.o findProduct.o faturacao.o gestaoFilial.o catProdutos.o catClientes.o vendasProdMes.o query4.o -o sgv $(LDLIBS)

main.o: clientNoBuy.h vendas.h leitura.h catProdutos.h catClientes.h faturacao.h gestaoFilial.h vendasProdMes.h query4.h
	$(CC) $(CFLAGS) -c main.c $(LDLIBS)

leitura.o: leitura.c leitura.h vendas.h faturacao.h catProdutos.h catClientes.h gestaoFilial.h
	$(CC) $(CFLAGS) -c leitura.c $(LDLIBS)

findProduct.o: findProduct.c findProduct.h userData.h catProdutos.h
	$(CC) $(CFLAGS) -c findProduct.c $(LDLIBS)

vendasProdMes.o: vendasProdMes.c vendasProdMes.h faturacao.h
	$(CC) $(CFLAGS) -c vendasProdMes.c $(LDLIBS)

query4.o: query4.c query4.h faturacao.h catProdutos.h userData.h
	$(CC) $(CFLAGS) -c query4.c $(LDLIBS)

clientNoBuy.o: userData.h clientNoBuy.h clientNoBuy.c
	$(CC) $(CFLAGS) -c clientNoBuy.c $(LDLIBS)

userData.o: userData.c userData.h
	$(CC) $(CFLAGS) -c userData.c

faturacao.o: faturacao.c faturacao.h
	$(CC) $(CFLAGS) -c faturacao.c $(LDLIBS)

gestaoFilial.o: gestaoFilial.c gestaoFilial.h
	$(CC) $(CFLAGS) -c gestaoFilial.c $(LDLIBS)

catProdutos.o: catProdutos.c catProdutos.h
	$(CC) $(CFLAGS) -c catProdutos.c $(LDLIBS)

catClientes.o: catClientes.c catClientes.h
	$(CC) $(CFLAGS) -c catClientes.c $(LDLIBS)

vendas.o: vendas.c vendas.h
	$(CC) $(CFLAGS) -c vendas.c

clean:
	rm *.o sgv
