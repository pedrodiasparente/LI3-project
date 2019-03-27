CC = gcc
LDLIBS = `pkg-config --libs glib-2.0` `pkg-config --cflags --libs gmodule-2.0`
CFLAGS = -Wall -ansi `pkg-config --cflags glib-2.0` `pkg-config --cflags --libs gmodule-2.0`

leitura: avltree vendas export
	$(CC) $(CFLAGS) leitura.c -o leitura avltree.o vendas.o $(LDLIBS)

avltree:
	$(CC) $(CFLAGS) -c avltree.c

vendas:
	$(CC) $(CFLAGS) -c vendas.c

export:
	export G_SLICE=always-malloc

clean:
	rm leitura avltree.o vendas.o ./Ficheiros/Venda_1MValidas.txt
