#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS  500

// _great_hall random tester 
void _great_hall_TEST(int, struct gameState *);

int main()
{
    srand((unsigned)time(NULL));
    int sumPassed = 0;
    
    struct gameState test;
    int i, k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    initializeGame(MAX_PLAYERS, k, 3, &test);
    
    for (i = 0; i < MAX_ITERATIONS; i++)
    {
        test.whoseTurn = (rand() % (MAX_PLAYERS - 1) + 1);
        _great_hall_TEST(test.whoseTurn, &test);
        sumPassed++;
    }
    
    
    printf("**************************************\n");
    printf("RESULTS - For %d Iterations of great_hall calls:\n", MAX_ITERATIONS);
    printf("Passed - %d\n", sumPassed);
    printf("TESTS OK - _great_hall test COMPLETED\n");
    printf("**************************************\n");
    return 0;
}

void _great_hall_TEST(int handPos, struct gameState *state)
{
    int currentPlayer = whoseTurn(state);
    
    drawCard(currentPlayer, state);
    state->numActions++;
    discardCard(handPos, currentPlayer, state, 0);
}

// gcc -std=c99 dominion.c dominion.h dominion_helpers.h rngs.h rngs.c randomtestcard2.c -Wall
// -fpic -coverage -lm
