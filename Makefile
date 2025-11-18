CC = gcc
CFLAGS = -Wall -Iinclude

SRC = src/lista.c main.c
OBJ = $(SRC:.c=.o)

main: $(OBJ)
	$(CC) $(OBJ) -o main

clean:
	rm -f $(OBJ) main
