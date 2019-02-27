CC = gcc
CFLAGS = -Wall
EXECUTAVEL = leitura

program: $(EXECUTAVEL)
	$(CC) $(CFLAGS) leitura.c -o $(EXECUTAVEL)

read:
	$(CC) $(CFLAGS) -c leitura.c

clean:
	rm $(EXECUTAVEL) leitura.o
