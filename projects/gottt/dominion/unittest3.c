#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
//#include "dominion.c"
#include "rngs.h"
//#include "rngs.c"

void checkTwo(int one, int two);

int main() {
	int pTwoPreCount, pTwoPostCount, pThreePreCount, pThreePostCount, playerPreDiscard, playerPostDiscard;

	int seed = 4;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, ambassador, great_hall };

	struct gameState G, GTwo;
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing ambassadorCardEffect():\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(3, k, seed, &G); // initialize a new game

	pTwoPreCount = G.handCount[1];
	pThreePreCount = G.handCount[2];

	ambassadorCardEffect(1, 1, 0, &G, 0);
	
	pTwoPostCount = G.handCount[1];
	pThreePostCount = G.handCount[2];

	printf("Player 2 gain card test ");
	checkTwo(pTwoPreCount+1, pTwoPostCount);

	printf("Player 3 gain card test ");
	checkTwo(pThreePreCount + 1, pThreePostCount);

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(3, k, seed, &GTwo); // initialize a new game

	playerPreDiscard = GTwo.handCount[2];

	ambassadorCardEffect(1, 0, 2, &GTwo, 0);

	playerPostDiscard = GTwo.handCount[2];

	printf("Correct Player Discard Test ");
	checkTwo(playerPreDiscard, playerPostDiscard);

	printf("\n***ALL TESTS COMPLETE\n\n");

	return 0;
}

void checkTwo(int one, int two)
{
	if (one < two)
	{
		printf("Passed \n");
	}
	else if (one > two)
	{
		printf("Failed \n");
	}
	else
	{
		printf("Passed \n");
	}

	return;
}
