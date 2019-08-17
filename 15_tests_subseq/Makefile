all: maxSeq.o test-subseq.o
	gcc -o subseq -pedantic -Wall -Werror -std=gnu99 maxSeq.o test-subseq.o
test-subseq.0: test-subseq.c
	gcc -c test-subseq -pedantic -Wall -Werror -std=gnu99 test-subseq.c
maxSeq.o: maxSeq.c
	gcc -c maxSeq -pedantic -Wall -Werror -std=gnu99 maxSeq.c
