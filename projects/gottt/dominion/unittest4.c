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
	int prePlayedCards, postPlayedCards, preCoins, postCoins, nextDeckCount;

	int tributeRevealedCards[2] = { -1, -1 };

	int seed = 4;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, tribute, great_hall };

	struct gameState G, GTwo;
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing tributeCardEffect():\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game

	prePlayedCards = G.playedCardCount;
	preCoins = G.coins;

	tributeCardEffect(&G, 0, 1, tributeRevealedCards);

	if (G.deck[1][G.deckCount[1] - 1] == G.deck[1][G.deckCount[1] - 2])
	{
		printf("equal \n");
	}

	postPlayedCards = G.playedCardCount;
	postCoins = G.coins;

	printf("Duplicate revealed card test ");
	checkTwo(postPlayedCards, prePlayedCards);

	printf("Coins increase test ");
	checkTwo(postCoins, (preCoins + 2));

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed+1, &GTwo); // initialize a new game

	GTwo.deckCount[1] = 1; // set flag for if deckcount and discard count <= 1 for next player

	tributeCardEffect(&GTwo, 0, 1, tributeRevealedCards);  // gaining coverage

	GTwo.discardCount[1] = 1;
	GTwo.deckCount[1] = 0;

	tributeCardEffect(&GTwo, 0, 1, tributeRevealedCards);

	GTwo.discardCount[1] = 2;
	GTwo.deckCount[1] = 0;

	tributeCardEffect(&GTwo, 0, 1, tributeRevealedCards);


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
