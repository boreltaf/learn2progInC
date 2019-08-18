all: read-matrix.o rotate.o
	gcc -o rotate-matrix -Wall -Werror -pedantic -std=gnu99 read-matrix.o rotate.o
rotate.o: rotate.c
	gcc -c -Wall -Werror -pedantic -std=gnu99 rotate.c
