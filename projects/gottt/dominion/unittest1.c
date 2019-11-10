#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
//#include "dominion.c"
#include "rngs.h"
//#include "rngs.c"

void checkTwo( int one , int two );

int main() {
	int originalNumBuys, postNumBuys, supply,  postSupply1, postSupply2;

	int seed = 4;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, baron, great_hall };
	
	struct gameState G, newG;
	
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing baronCardEffect():\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game

	originalNumBuys = G.numBuys;
	baronCardEffect(1, &G, 0);

	postNumBuys = G.numBuys;

	G.handCount[0] = 1;
	baronCardEffect(1, &G, 0);

	printf("Num Buys Test ");
	checkTwo(postNumBuys, (originalNumBuys + 1));

	G.handCount[0] = 1;
	baronCardEffect(1, &G, 0);

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &newG); // initialize a new game

	newG.supplyCount[estate] = 2;
	newG.hand[0][0] = estate;
	supply = newG.supplyCount[estate];

	baronCardEffect(0, &newG, 0);
	postSupply1 = newG.supplyCount[estate];

	printf("Estate Supply Test 1 ");
	checkTwo(postSupply1, (supply - 1));

	newG.supplyCount[estate] = 1;
	supply = newG.supplyCount[estate];
	baronCardEffect(0, &newG, 0);
	postSupply2 = newG.supplyCount[estate];

	printf("Estate Supply Test 2 ");
	checkTwo(postSupply2, (supply - 1));

	printf("\n***ALL TESTS COMPLETE\n\n");

	return 0;
}

void checkTwo(int one , int two)
{
	if (one < two )
	{
		printf("Passed \n");
	}
	else if(one > two)
	{
		printf("Failed \n");
	}
	else
	{
		printf("Passed \n");
	}

	return;
}
