
fibonacci: main.o fibonacci.o
	gcc -o fibonacci main.o fibonacci.o

main.o: main.c fibonacci.h
	gcc -c main.c

fibonacci.o: fibonacci.c fibonacci.h
	gcc -c fibonacci.c

