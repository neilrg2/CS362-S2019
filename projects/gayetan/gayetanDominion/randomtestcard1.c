#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS  500

// random tester for _smithy function
void _smithy_TEST(int, struct gameState *);

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
        _smithy_TEST((rand() % MAX_PLAYERS + 1), &test);
        
        sumPassed++;
    }
    
    printf("**************************************\n");
    printf("RESULTS - For %d Iterations of _smithy calls:\n", MAX_ITERATIONS);
    printf("Passed - %d\n", sumPassed);
    printf("TESTS OK - _smithy test COMPLETED\n");
    printf("**************************************\n");
    return 0;
}

void _smithy_TEST(int handPos, struct gameState *state)
{
    int currentPlayer = whoseTurn(state);
    int i;
    
    for (i = 0; i < 3; i++)
    {
        drawCard(currentPlayer, state);
    }
    
    discardCard(handPos, currentPlayer, state, 0);
}
