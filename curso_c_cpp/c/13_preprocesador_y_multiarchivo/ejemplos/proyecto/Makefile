# Makefile del proyecto de ejemplo.
# OJO: las lineas de comando empiezan con TAB, no con espacios.

CC = gcc
CFLAGS = -std=c11 -Wall -Wextra

programa: main.c mathutils.c mathutils.h
	$(CC) $(CFLAGS) main.c mathutils.c -o programa

clean:
	rm -f programa
