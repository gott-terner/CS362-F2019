#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
//#include "dominion.c"
#include "rngs.h"
//#include "rngs.c"

void checkNow( int one , int two );

int main() {
	int postNumBuys;
	int val;
	int iter = 0;

	srand(time(NULL));

	int state = 0;
	int loop = 1;

	int seed = 4;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, baron, great_hall };
	
	struct gameState G, newG;
	
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing baronCardEffect():\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game
	
	G.hand[0][0] = estate;
	
	while(loop)
	{
		iter++;
		val = (rand() % 3);
		G.supplyCount[estate] = (rand() % 3);
		G.handCount[0] = (rand() % 5 + 1);

		baronCardEffect(val, &G, 0);

		if (state == 0 && val == 0) state = 1;
		if (state == 1 && G.supplyCount[estate] == 0) state = 2;
		if (state == 2 && G.supplyCount[estate] == 1) loop = 0;
	}

	postNumBuys = G.numBuys;

	printf("NumBuys test ");
	checkNow(iter+1, postNumBuys);

	memset(&newG, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &newG); // initialize a new game

	loop = 1;
	int state2 = 0;
	int j;

	for (j = 0; j < newG.handCount[0]; j++)
	{
		newG.hand[0][j] = copper;
	}

	while (loop)
	{
		val = (rand() % 3);
		newG.supplyCount[estate] = (rand() % 3 + 1);
		newG.handCount[0] = (rand() % 5);

		if (state2 == 0 && newG.handCount[0] == 0 && val > 0)
		{
			state2 = 1;
			baronCardEffect(val, &newG, 0);
		}
		if (state2 == 1 && val == 0 && newG.supplyCount[estate] == 2)
		{
			baronCardEffect(val, &newG, 0);
			loop = 0;
		}

	}


	printf("\n***ALL TESTS COMPLETE\n\n");

	return 0;
}

void checkNow(int one , int two)
{
	if (one == two)
	{
		printf("passed \n");
	}
	else
	{
		printf("failed \n");
	}

	return;
}
