CFLAGS= -Wall -fpic -coverage -lm -std=c99

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: testDrawCard 
	./testDrawCard &> unittestresult.out
	gcov dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

randomtestresults: randomtestcard2.c randomtestcard1.c randomtestadventurer.c dominion.c dominion.h dominion_helpers.h rngs.h rngs.c
	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h randomtestadventurer.c ${CFLAGS}
	mv a.out randomtestadventurer
	echo "#!/bin/bash" > adventurerTestScript
	echo "echo \"****************\"" >> adventurerTestScript
	echo "./randomtestadventurer > randomtestresults.out" >> adventurerTestScript
	echo "gcov randomtestadventurer.c -b >> randomtestresults.out" >> adventurerTestScript
	chmod u+x adventurerTestScript

	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h randomtestcard1.c ${CFLAGS}
	mv a.out randomtestcard1 
	echo "#!/bin/bash" > randomTestCardOneScript
	echo "echo \"****************\"" >> randomTestCardOneScript
	echo "./randomtestcard1 >> randomtestresults.out" >> randomTestCardOneScript
	echo "gcov randomtestcard1.c -b >> randomtestresults.out" >> randomTestCardOneScript
	chmod u+x randomTestCardOneScript

	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h randomtestcard2.c ${CFLAGS}
	mv a.out randomtestcard2
	echo "#!/bin/bash" > randomTestCardTwoScript
	echo "echo \"****************\"" >> randomTestCardTwoScript
	echo "./randomtestcard2 >> randomtestresults.out" >> randomTestCardTwoScript
	echo "gcov randomtestcard2.c -b >> randomtestresults.out" >> randomTestCardTwoScript
	echo "echo -e \"\nResults stored in 'randomtestresults.out'\"" >> randomTestCardTwoScript
	chmod u+x randomTestCardTwoScript
	echo "\n\n"

	./adventurerTestScript
	./randomTestCardOneScript
	./randomTestCardTwoScript

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player randomtestresults

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe randomtestadventurer adventurerTestScript randomTestCardOneScript randomTestCardTwoScript randomtestcard1 randomtestcard2
