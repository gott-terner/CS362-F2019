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
	int cardsInHand, prePlayedCards, postPlayedCards, preCount, postCount;

	int seed = 4;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, minion, great_hall };

	struct gameState G;
	struct gameState GTwo;
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing minionCardEffect():\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game

	prePlayedCards = G.playedCardCount;

	minionCardEffect(1, 0, 0, &G, 0);

	postPlayedCards = G.playedCardCount;

	cardsInHand = G.handCount[0];

	printf("Trash flag test ");
	checkTwo((prePlayedCards + 1), postPlayedCards);

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &GTwo); // initialize a new game

	preCount = GTwo.handCount[1];

	minionCardEffect(0, 1, 0, &GTwo, 1);

	postCount = GTwo.handCount[1];

	printf("Drawn Cards Count for choice2 test ");
	checkTwo(preCount, postCount-1);

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
