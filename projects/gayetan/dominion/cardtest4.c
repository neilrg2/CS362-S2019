#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Card test for outpost function
void testForOutpost()
{
    struct gameState test;
    
    int k[10] = {outpost, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int bonus = 0;
    
    test.whoseTurn = 1;
    
    initializeGame(2, k, 1, &test);
    
    if (!test.outpostPlayed)
        printf("outpost: PASS\n");
    else
        printf("outpost: FAIL\n");
    
    cardEffect(outpost, 1, 2, 3, &test, 1, &bonus);
    if (test.outpostPlayed == 1)
        printf("outpost: PASS\n");
    else
        printf("outpost: FAIL\n");
    
    cardEffect(outpost, 1, 2, 3, &test, 1, &bonus);
    if (test.outpostPlayed != 1)
        printf("outpost: PASS\n");
    else
        printf("outpost: FAIL\n");
    
    cardEffect(outpost, 1, 2, 3, &test, 1, &bonus);
    if (test.outpostPlayed == 3)
        printf("outpost: PASS\n");
    else
        printf("outpost: FAIL\n");
    
    cardEffect(outpost, 1, 2, 3, &test, 1, &bonus);
    if (test.numBuys != 3)
        printf("outpost: PASS\n");
    else
        printf("outpost: FAIL\n");
    
}


int main()
{
    testForOutpost();
    
    return 0;
}


