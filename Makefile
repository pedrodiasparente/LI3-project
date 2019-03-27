CC = gcc
LDLIBS = `pkg-config --libs glib-2.0` `pkg-config --cflags --libs gmodule-2.0`
CFLAGS = -Wall -ansi -O2 `pkg-config --cflags glib-2.0` `pkg-config --cflags --libs gmodule-2.0`

leitura: avltree vendas
	$(CC) $(CFLAGS) leitura.c -o leitura avltree.o vendas.o $(LDLIBS)

avltree:
	$(CC) $(CFLAGS) -c avltree.c

vendas: avltree
	$(CC) $(CFLAGS) -c vendas.c

clean:
	rm leitura avltree.o
