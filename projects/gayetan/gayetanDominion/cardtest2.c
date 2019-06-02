#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Card test for _adventurer function
void testForAdventurer()
{
    struct gameState test;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int bonus = 0;
    
    test.whoseTurn = 1;
    
    initializeGame(2, k, 1, &test);
    if (test.handCount[whoseTurn(&test)] == 5)
        printf("_adventurer(): PASS\n");
    else
        printf("_adventurer(): FAIL\n");
    
    cardEffect(adventurer, 1, 2, 3, &test, 1, &bonus);
    if (test.handCount[whoseTurn(&test)] == 7)
        printf("_adventurer(): PASS\n");
    else
        printf("_adventurer(): FAIL\n");
    
    cardEffect(adventurer, 1, 2, 3, &test, 1, &bonus);
    if (test.handCount[whoseTurn(&test)] != 7)
        printf("_adventurer(): PASS\n");
    else
        printf("_adventurer(): FAIL\n");
    
    cardEffect(adventurer, 1, 2, 3, &test, 1, &bonus);
    if (test.handCount[whoseTurn(&test)] == 8)
        printf("_adventurer(): PASS\n");
    else
        printf("_adventurer(): FAIL\n");
    
    cardEffect(adventurer, 1, 2, 3, &test, 1, &bonus);
    if (test.handCount[whoseTurn(&test)] == 8)
        printf("_adventurer(): PASS\n");
    else
        printf("_adventurer(): FAIL\n");
    
}


int main()
{
    testForAdventurer();
    
    return 0;
}
