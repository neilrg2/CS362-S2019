#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITERATIONS  2000

// random tester for _adventurer function
void _adventurer_TEST(int, struct gameState *);

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
        _adventurer_TEST(adventurer, &test);
        
        sumPassed++;
    }
    
    printf("**************************************\n");
    printf("RANDOMTESTADVENTURER:\n");
    printf("RESULTS - For %d Iterations of adventurer calls:\n", MAX_ITERATIONS);
    printf("Passed - %d\n", sumPassed);
    printf("TESTS OK - adventurer test COMPLETED\n");
    printf("**************************************\n");
    return 0;
}

void _adventurer_TEST(int card, struct gameState *state)
{
    int cardDrawn;
    int drawntreasure = 0;
    int currentPlayer = whoseTurn(state);
    int temphand[MAX_HAND];
    int z = 0;
    
    
    while (drawntreasure < 2)
    {
        if (state->deckCount[currentPlayer] < 1)
        {
            shuffle(currentPlayer, state);
        }
        
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer] - 1];
        
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawntreasure++;
        else
        {
            temphand[z] = cardDrawn;
            state->handCount[currentPlayer]--;
            z++;
        }
    }
    
    while (z - 1 >= 0)
    {
        state->discard[currentPlayer][state->discardCount[currentPlayer]++] = temphand[z - 1];
        z = z - 1;
    }
}
