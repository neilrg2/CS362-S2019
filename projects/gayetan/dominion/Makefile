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

unittestresults: unittest1.c unittest2.c unittest3.c unittest4.c cardtest1.c cardtest2.c cardtest3.c cardtest4.c dominion.c rngs.c rngs.h dominion.h dominion_helpers.h
	echo "Result for running unittestresults:" > unittestresults.out
	echo "unittest1.c:" >> unittestresults.out
	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h unittest1.c $(CFLAGS)
	mv a.out unittest1
	./unittest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest2.c:" >> unittestresults.out
	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h unittest2.c $(CFLAGS)
	mv a.out unittest2
	./unittest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest3.c:" >> unittestresults.out
	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h unittest3.c $(CFLAGS)
	mv a.out unittest3
	./unittest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "unittest4.c:" >> unittestresults.out
	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h unittest4.c $(CFLAGS)
	mv a.out unittest4
	./unittest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest1.c:" >> unittestresults.out
	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h cardtest1.c $(CFLAGS)
	mv a.out cardtest1
	./cardtest1 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest2.c:" >> unittestresults.out
	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h cardtest2.c $(CFLAGS)
	mv a.out cardtest2
	./cardtest2 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest3.c:" >> unittestresults.out
	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h cardtest3.c $(CFLAGS)
	mv a.out cardtest3
	./cardtest3 >> unittestresults.out
	gcov dominion.c >> unittestresults.out

	echo "cardtest4.c:" >> unittestresults.out
	gcc dominion.h dominion.c dominion_helpers.h rngs.c rngs.h cardtest4.c $(CFLAGS)
	mv a.out cardtest4
	./cardtest4 >> unittestresults.out
	gcov dominion.c >> unittestresults.out


player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

all: playdom player unittestresults

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so *.out testDrawCard testDrawCard.exe unittest1 unittest2 unittest3 unittest4 cardtest1 cardtest2 cardtest3 cardtest4
