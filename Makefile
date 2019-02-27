CC = gcc
CFLAGS = -Wall

leitura: avltree
	$(CC) $(CFLAGS) leitura.c -o leitura avltree.o

avltree:
	$(CC) $(CFLAGS) -c avltree.c

clean:
	rm program person.o
