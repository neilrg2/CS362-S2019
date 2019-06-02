#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Unit test for _smithy function
void testForSmithy()
{
    struct gameState test;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    test.whoseTurn = 1;
    
    initializeGame(2, k, 1, &test);
    _smithy(1, &test);
    if (test.handCount[test.whoseTurn] == 7)
        printf("_smithy(): PASS test should be 7\n");
    else
        printf("_smithy(): FAIL test should be 7\n");
    
    _smithy(1, &test);
    if (test.handCount[test.whoseTurn] == 8)
        printf("_smithy(): PASS test should be 8\n");
    else
        printf("_smithy(): FAIL test should be 8\n");
    
    _smithy(1, &test);
    if (test.handCount[test.whoseTurn] == 7)
        printf("_smithy(): PASS test should be 7\n");
    else
        printf("_smithy(): FAIL test should be 7\n");
    
    _smithy(1, &test);
    if (test.handCount[test.whoseTurn] == 6)
        printf("_smithy(): PASS test should be 6\n");
    else
        printf("_smithy(): FAIL test should be 6\n");
    
    _smithy(1, &test);
    if (test.handCount[test.whoseTurn] == 5)
        printf("_smithy(): PASS test should be 5\n");
    else
        printf("_smithy(): FAIL test should be 5\n");
    
}


int main()
{
    testForSmithy();
    
    return 0;
}
