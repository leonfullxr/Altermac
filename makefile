opt=-O3 -Wall -std=c2x

all: clean altermac

altermac: altermac.o
	cc ${opt} $^ -o $@

altermac.o: altermac.c
	cc ${opt} -c $^

clean:
	rm -f altermac *.o
