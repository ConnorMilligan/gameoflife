SHELL = /bin/sh

CC=gcc
CFLAGS=-Wall
LDFLAGS =-lncurses
SRC = ${wildcard *.c}
OBJ  = ${SRC:.c=.o}

.PHONY: all clean

all: main

%.o: %.c
	${CC} -c -o $@ $< ${CFLAGS}

main: ${OBJ}
	${CC} -o $@ $^ ${CFLAGS} $(LDFLAGS)

clean:
	-rm -f main main.exe $(OBJ)