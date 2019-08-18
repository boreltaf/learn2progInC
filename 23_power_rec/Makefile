CFLAGS = -Wall -Werror -pedantic -std=gnu99
all: test-power.o power.o
	gcc -o power $(CFLAGS) test-power.o power.o
power.o: power.c
	gcc -c $(CFLAGS) power.c
test-power.o: test-power.c
	gcc -c $(CFLAGS) test-power.c
