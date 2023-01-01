CC = gcc
FLAGS = -Wall -g

.PHONY: clean all

all: isort txtfind

isort: isort.o
	$(CC) $(FLAGS) -o isort isort.c

txtfind: txtfind.o
	$(CC) $(FLAGS) -o txtfind txtfind.c

clean:
	rm -f *.o isort txtfind
