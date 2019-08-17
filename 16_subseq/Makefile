CFLAGS= -Wall -Werror -pedantic -std=gnu99
subseq: test-subseq.o maxSeq.o
	gcc -o subseq test-subseq.o maxSeq.o
maxSeq.o: maxSeq.c
	gcc $(CFLAGS) -c maxSeq.c
test-subseq.o: test-subseq.c
	gcc -c -pedantic -Wall -std=gnu99 test-subseq.c
