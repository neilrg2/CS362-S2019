#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Unit test for _great_hall function
void testForGreatHall()
{
    struct gameState test;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    
    test.whoseTurn = 1;
    test.numActions = 0;
    
    initializeGame(2, k, 1, &test);
    
    
    _great_hall(1, &test);
    if (test.numActions == 2)
        printf("_great_hall(): PASS numActions must be 2\n");
    else
        printf("_great_hall(): FAIL numActions must be 2\n");
    
    _great_hall(1, &test);
    if (test.numActions == 3)
        printf("_great_hall(): PASS numActions must be 3\n");
    else
        printf("_great_hall(): FAIL numActions must be 3\n");
    
    _great_hall(1, &test);
    if (test.numActions == 4)
        printf("_great_hall(): PASS numActions must be 4\n");
    else
        printf("_great_hall(): FAIL numActions must be 4\n");
    
    _great_hall(1, &test);
    if (test.numActions == 5)
        printf("_great_hall(): PASS numActions must be 5\n");
    else
        printf("_great_hall(): FAIL numActions must be 5\n");
    
    _great_hall(1, &test);
    if (test.numActions == 6)
        printf("_great_hall(): PASS numActions must be 6\n");
    else
        printf("_great_hall(): FAIL numActions must be 6\n");
    
}


int main()
{
    testForGreatHall();
    
    return 0;
}

