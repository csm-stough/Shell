CC=gcc
CFLAGS= -O -Wall
EXE_NAME='shell'

all: main

main: main.c Shell.h Shell.c
	$(CC) $(CFLAGS) -c -o Shell.o Shell.c
	$(CC) $(CFLAGS) -c -o main.o main.c
	$(CC) $(CFLAGS) -o $(EXE_NAME) main.o Shell.o

clean:
	rm -f Shell.o main.c $(EXE_NAME)
