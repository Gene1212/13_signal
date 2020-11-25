all: main.o
	gcc -o test main.o

main.o: main.c
	gcc -c main.c

run:
	./test 