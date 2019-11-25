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
	int preSilverHand, postSilverHand, preCopper, postCopper = 0, preGold, postGold = 0, preMine, postMine = 0, preSmithy, postSmithy = 0;

	int seed = 4;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, tribute, great_hall };

	struct gameState G, G2;
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing mineCardEffect():\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game

	G.hand[0][0] = silver; //set silver for silver bug
	//G.hand[0][1] = copper;
	G.hand[0][4] = mine;
	preSilverHand = G.handCount[0];

	cardEffectMine(0, silver, &G, 4, 0);

	postSilverHand = G.handCount[0];

	printf("Treasure range base case test ");
	checkTwo(postSilverHand, (preSilverHand - 1));

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G2); // initialize a new game

	G2.hand[0][0] = copper;
	G2.hand[0][1] = gold;
	G2.hand[0][2] = gold;
	G2.hand[0][3] = mine;
	G2.hand[0][4] = smithy;

	preCopper = 1;
	preGold = 2;
	preMine = 1;
	preSmithy = 1;

	cardEffectMine(0, silver, &G2, 3, 0);

	int i;
	for (i = 0; i < G2.handCount[0]; i++)
	{
		if (G2.hand[0][i] == copper)
		{
			postCopper++;
		}
		else if (G2.hand[0][i] == gold)
		{
			postGold++;
		}
		else if (G2.hand[0][i] == mine)
		{
			postMine++;
		}
		else if (G2.hand[0][i] == smithy)
		{
			postSmithy++;
		}
	}
	
	printf("Copper handPos test ");
	checkTwo(postCopper, (preCopper - 1));

	printf("Gold handPos test ");
	checkTwo(postGold, preGold);

	printf("Mine handPos test ");
	checkTwo(postMine, (preMine - 1));

	printf("Smithy handPos test ");
	checkTwo(preSmithy , postSmithy);

	printf(" ");

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
