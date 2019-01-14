
all: velha main
	g++ -oJogo.exe velha.o main.o
velha:
	g++ -o velha.o -c velha.c -W -Wall -ansi -pedantic

main:
	g++ -o main.o -c main.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o