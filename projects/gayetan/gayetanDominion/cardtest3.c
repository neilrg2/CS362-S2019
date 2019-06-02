#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Card test for council_room function
void testForCouncilRoom()
{
    struct gameState test;
    
    int k[10] = {council_room, gardens, embargo, village, minion, mine, cutpurse,
        sea_hag, tribute, smithy};
    int bonus = 0;
    
    test.whoseTurn = 1;
    
    initializeGame(2, k, 1, &test);

    cardEffect(council_room, 1, 2, 3, &test, 1, &bonus);
    if (test.numBuys == 2)
        printf("council_room: PASS\n");
    else
        printf("council_room: FAIL\n");
    
    cardEffect(council_room, 1, 2, 3, &test, 1, &bonus);
    if (test.numBuys != 2)
        printf("council_room: PASS\n");
    else
        printf("council_room: FAIL\n");
    
    cardEffect(council_room, 1, 2, 3, &test, 1, &bonus);
    if (test.numBuys == 4)
        printf("council_room: PASS\n");
    else
        printf("council_room: FAIL\n");
    
    cardEffect(council_room, 1, 2, 3, &test, 1, &bonus);
    if (test.numBuys == 5)
        printf("council_room: PASS\n");
    else
        printf("council_room: FAIL\n");
    
    cardEffect(council_room, 1, 2, 3, &test, 1, &bonus);
    if (test.numBuys != 5)
        printf("council_room: PASS\n");
    else
        printf("council_room: FAIL\n");
    
}


int main()
{
    testForCouncilRoom();
    
    return 0;
}
