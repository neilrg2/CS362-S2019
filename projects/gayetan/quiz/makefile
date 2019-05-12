
GFLAGS = -Wall -coverage -fpic -lm -std=c99

all: testme randomtest

testme: testme.c
	gcc -o testme testme.c ${GFLAGS}
	
randomtest: testme.c testme
	-./testme
	gcov testme.c -b > testme.out
	cat testme.out

clean:
	rm testme testme.gcno testme.gcda testme.c.gcov testme.out
