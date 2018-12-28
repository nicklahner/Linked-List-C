all: List

List: List.o prog3.o
	gcc -Wall -g -o List List.o prog3.o

List.o: List.h List.c
	gcc -Wall -g -c List.c

prog3.o: prog3.c
	gcc -Wall -g -c prog3.c
