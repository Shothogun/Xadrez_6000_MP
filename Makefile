main: main.o peca.o peca.h
	g++ -std=c++11 $^ -o $@ -g

main.o: main.cpp peca.h
	g++ -std=c++11 $< -c -g

peca.o: peca.cpp peca.h
	g++ -std=c++11	$<	-c	-g	

all: main

clean:
	rm -rf *.o

mrproper: clean
	rm -rf main