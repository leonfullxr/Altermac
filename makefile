opt=-O3 -Wall -std=gnu11

all: clean altermac

altermac: altermac.o
	cc ${opt} $^ -o $@

altermac.o: altermac.c
	cc ${opt} -c $^

clean:
	rm -f altermac *.o
