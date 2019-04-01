CC = gcc
LDLIBS = `pkg-config --libs glib-2.0` `pkg-config --cflags --libs gmodule-2.0`
CFLAGS = -Wall -ansi `pkg-config --cflags glib-2.0` `pkg-config --cflags --libs gmodule-2.0`

sgv: leitura.o clientNoBuy.o vendas.o userData.o main.o findProduct.o
	$(CC) $(CFLAGS) main.o leitura.o clientNoBuy.o vendas.o userData.o findProduct.o -o sgv $(LDLIBS)

main.o: clientNoBuy.h vendas.h leitura.h
	$(CC) $(CFLAGS) -c main.c $(LDLIBS)

leitura.o: vendas.h
	$(CC) $(CFLAGS) -c leitura.c $(LDLIBS)

clientNoBuy.o: userData.h clientNoBuy.h clientNoBuy.c
	$(CC) $(CFLAGS) -c clientNoBuy.c $(LDLIBS)

vendas.o: vendas.c vendas.h
	$(CC) $(CFLAGS) -c vendas.c

findProduct.o: findProduct.c findProduct.h userData.h
	$(CC) $(CFLAGS) -c findProduct.c $(LDLIBS)

userData.o: userData.c userData.h
	$(CC) $(CFLAGS) -c userData.c

clean:
	rm *.o sgv ./Ficheiros/Venda_1MValidas.txt
