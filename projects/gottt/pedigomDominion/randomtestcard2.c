#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"

void checkIt( int one , int two );

int main() {
	srand(time(NULL));
	int choiceOne, choiceTwo, preHandCount2, postHandCount2;
	int state = 0;
	int i;

	int loop = 1;

	int seed = 5;
	int k[10] = { adventurer, council_room, feast, gardens, mine
			   , remodel, smithy, village, minion, great_hall };

	struct gameState G1;
	printf("----------------------------------------------------------------------------\n");
	printf("Begin Testing minionCardEffect():\n");

	memset(&G1, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(2, k, seed, &G1); // initialize a new game

	G1.deckCount[0] = (rand() % 6 + 6);
	for (i = 0; i < G1.deckCount[0]; i++)
	{
		G1.deck[0][i] = copper;
	}

	while (loop)
	{
		choiceOne = (rand() % 4);
		if (choiceOne > 0)
		{
			choiceTwo = 0;
		}
		else
		{
			choiceTwo = 1;
		}

		preHandCount2 = G1.handCount[0];

		cardEffectMinion(0, 1, &G1, 0, 0);

		postHandCount2 = G1.handCount[0];

		if (choiceOne == 0 && choiceTwo == 1)
		{
			loop = 0;
		}
		
		loop = 0;

	}

	printf("Draw Card Current player test ");
	checkIt(preHandCount2 - 1, postHandCount2);


	printf("\n***ALL TESTS COMPLETE\n\n");

	return 0;
}

void checkIt(int one , int two)
{
	if(one == two)
	{
		printf("Passed \n");
	}
	else
	{
		printf("Failed \n");
	}

	return;
}
