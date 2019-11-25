#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
//#include "dominion.c"
#include "rngs.h"
//#include "rngs.c"

void checkThis(int one, int two);

int main() {
	srand(time(NULL));

	int originalDeck, originalDiscard;

	int state = 0;
	int loop = 1;
	int i;
	int iterator = 0;

	int seed = 4;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, tribute, great_hall };

	int tributeRevealedCards[2] = { -1, -1 };

	struct gameState G;
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing tributeCardEffect():\n");

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G); // initialize a new game

	cardEffectTribute(&G, tributeRevealedCards, 1);
	
	while (loop)
	{
		for (i = 0; i < G.deckCount[1]; i++)
		{
			if ((i % 2) == 0)
			{
				G.deck[0][i] = estate;
			}
			else
			{
				G.deck[0][i] = copper;
			}
		}
		
		G.discardCount[1] = (rand() % 3);
		G.deckCount[1] = (rand() % 6);

		if (state == 0 && G.discardCount[1] == 0 && G.deckCount[1] == 0) state = 1;
		if (state == 1 && G.discardCount[1] == 1 && G.deckCount[1] == 0) state = 2;
		if (state == 2 && G.discardCount[1] == 2 && G.deckCount[1] == 0) state = 3;
		if (state == 3 && G.discardCount[1] == 0 && G.deckCount[1] == 1) state = 4;
		if (state == 4 && G.discardCount[1] == 1 && G.deckCount[1] == 1) state = 5;
		if (state == 5 && G.discardCount[1] == 2 && G.deckCount[1] == 1) state = 6;
		if (state == 6 && G.discardCount[1] == 0 && G.deckCount[1] == 2) state = 7;
		if (state == 7 && G.discardCount[1] == 1 && G.deckCount[1] == 2) state = 8;
		if (state == 8 && G.discardCount[1] == 2 && G.deckCount[1] == 2) state = 9;
		if (state == 9 && G.discardCount[1] == 0 && G.deckCount[1] == 3) state = 10;
		if (state == 10 && G.discardCount[1] == 1 && G.deckCount[1] == 3) state = 11;
		if (state == 11 && G.discardCount[1] == 2 && G.deckCount[1] == 3) state = 12;
		if (state == 12)
		{
			loop = 0;
		}

		iterator++;
		cardEffectTribute(&G, tributeRevealedCards, 1);

	}

	printf("Reveal card match test ");
	checkThis((iterator + 1), G.playedCardCount);


	printf("\n***ALL TESTS COMPLETE\n\n");

	return 0;
}

void checkThis(int one, int two)
{
	if (one == two)
	{
		printf("Failed \n");
	}
	else
	{
		printf("Passed \n");
	}

	return;
}
