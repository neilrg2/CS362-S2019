#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Unit test for _village function
void testForVillage()
{
    struct gameState test;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    test.whoseTurn = 1;
    test.numActions = 0;
    
    initializeGame(2, k, 1, &test);
    

    _village(1, &test);
    if (test.numActions == 3)
        printf("_village(): PASS numActions must be 3\n");
    else
        printf("_village(): FAIL numActions must be 3\n");
    
    _village(1, &test);
    if (test.numActions == 5)
        printf("_village(): PASS numActions must be 5\n");
    else
        printf("_village(): FAIL numActions must be 5\n");
    
    _village(1, &test);
    if (test.numActions == 7)
        printf("_village(): PASS numActions must be 7\n");
    else
        printf("_village(): FAIL numActions must be 7\n");
    
    _village(1, &test);
    if (test.numActions == 9)
        printf("_village(): PASS numActions must be 9\n");
    else
        printf("_village(): FAIL numActions must be 9\n");
    
    _village(1, &test);
    if (test.numActions == 11)
        printf("_village(): PASS numActions must be 11\n");
    else
        printf("_village(): FAIL numActions must be 11\n");
    
}


int main()
{
    testForVillage();
    
    return 0;
}
