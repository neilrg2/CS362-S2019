#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Unit test for _embargo function
void testForEmbargo()
{
    struct gameState test;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    test.whoseTurn = 1;
    test.coins = 0;
    
    initializeGame(2, k, 1, &test);
    
    
    _embargo(1, &test, 0);
    printf("%d\n", test.coins);
    if (test.coins == 6)
        printf("_embargo(): PASS coins must be 6\n");
    else
        printf("_embargo(): FAIL coins must be 6\n");

    _embargo(1, &test);
    if (test.coins == 8)
        printf("_embargo(): PASS coins must be 8\n");
    else
        printf("_embargo(): FAIL coins must be 8\n");

    _embargo(1, &test);
    if (test.coins == 10)
        printf("_embargo(): PASS coins must be 10\n");
    else
        printf("_embargo(): FAIL coins must be 10\n");

    _embargo(1, &test);
    if (test.coins == 12)
        printf("_embargo(): PASS coins must be 12\n");
    else
        printf("_embargo(): FAIL coins must be 12\n");

    _embargo(1, &test);
    if (test.coins == 14)
        printf("_embargo(): PASS coins must be 14\n");
    else
        printf("_embargo(): FAIL coins must be 14\n");
    
}


int main()
{
    testForEmbargo();
    
    return 0;
}
