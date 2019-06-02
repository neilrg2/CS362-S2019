#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Card test for _smithy function
void testForSmithy()
{
    struct gameState test;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int bonus = 0;
    
    test.whoseTurn = 1;
    
    initializeGame(2, k, 1, &test);
    cardEffect(smithy, 1, 2, 3, &test, 1, &bonus);
    if (test.handCount[test.whoseTurn] == 7)
        printf("_smithy(): PASS smithy should be 7\n");
    else
        printf("_smithy(): FAIL smithy should be 7\n");
    
    cardEffect(smithy, 1, 2, 3, &test, 1, &bonus);
    if (test.handCount[test.whoseTurn] == 8)
        printf("_smithy(): PASS smithy should be 8\n");
    else
        printf("_smithy(): FAIL smithy should be 8\n");
    
    cardEffect(smithy, 1, 2, 3, &test, 1, &bonus);
    if (test.handCount[test.whoseTurn] == 7)
        printf("_smithy(): PASS smithy should be 7\n");
    else
        printf("_smithy(): FAIL smithy should be 7\n");
    
    cardEffect(smithy, 1, 2, 3, &test, 1, &bonus);
    if (test.handCount[test.whoseTurn] == 6)
        printf("_smithy(): PASS smithy should be 6\n");
    else
        printf("_smithy(): FAIL smithy should be 6\n");
    
    cardEffect(smithy, 1, 2, 3, &test, 1, &bonus);
    if (test.handCount[test.whoseTurn] == 5)
        printf("_smithy(): PASS smithy should be 5\n");
    else
        printf("_smithy(): FAIL smithy should be 5\n");
    
}


int main()
{
    testForSmithy();
    
    return 0;
}
