CC=gcc
CFLAGS= -Wall -Werror -g 
RM=rm -rf
OUT=vector

all: build

build: main.o vector.o
	$(CC) $(CFLAGS) -o $(OUT) main.c vector.c
	$(RM) *.o

main.o: main.c vector.h
	$(CC) $(CFLAGS) -c main.c

vector.o: vector.c vector.h
	$(CC) $(CFLAGS) -c vector.c

clean:
	$(RM) *.o $(OUT)