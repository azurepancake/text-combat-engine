#include "caverns.h"
#include "enemy.h"

void westCaverns(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	if(caverns->phaseone == 0) {
		typeout("\nYou enter the darkness. Suddenly, a wooden club clumsily swings through the dark which you barely dodge. Prepare for battle.\n");

	    // Create enemy non-player character
	    struct Spell *enemySpells[] = { inventory->spells[0], inventory->spells[1] };
	    struct Enemy *enemy;
	    enemy = setupEnemy(enemy, inventory->weapons[0], enemySpells, inventory, player);
	
		// Enter battle
		if(battle(player, enemy)) {
			caverns->phaseone = 1;
			typeout("\nYou've defeated the beast that emerged from the cloak of darkness. You retrieve a stick of rough wood which the monster used as a weapon.\n\n");
			inventory->weapons[1]->owned = 1; // you get a stick!
			printf("What do you do?\n> ");

			char *input = malloc(MAX_INPUT_SZ);
			char *word;
			const char *keywords[2] = { "enter", "return" };
			int length = (sizeof(keywords) / sizeof(*keywords)) - 1;
			getchar();
			scanf("%*[^\n]%*c");
			fgets(input, MAX_INPUT_SZ, stdin);
			word = scanner(input, keywords, length);
		} else {
			return;
		}
	} else {
		typeout("\nNo way you are entering that darkness again..\n\n");
	}
}

void westCavernsEntrace(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{	
	typeout("\nYou head towards the West, where you approach the large opening upon the outer wall. You hear the sound of whispers come from deep within the darkness.\n\n");
	for(;;) {
		printf("What do you do?\n> ");

		char *input = malloc(MAX_INPUT_SZ);
		char *word;
		const char *keywords[2] = { "enter", "return" };
		int length = (sizeof(keywords) / sizeof(*keywords)) - 1;
		fgets(input, MAX_INPUT_SZ, stdin);
		word = scanner(input, keywords, length);

		if(strcmp(word, "enter") == 0) {
			westCaverns(player, inventory, caverns);
		} else if(strcmp(word, "return") == 0) {
			return;
		} else {
			printf("\nPlease try again..\n\n");
		}
	}
}

void startCaverns(struct Player *player, struct Inventory *inventory)
{
	struct Caverns *caverns;
	caverns = malloc(sizeof(struct Caverns));
	caverns->phaseone = 0;
	caverns->phasetwo = 0;
	caverns->phasethree = 0;

	printf("\nLoading caverns binary");
	typeout("........ ");
	printf("OK!\n\n\n");
	printf("//// T H E  C A V E R N S ////\n\n");

	char *input = malloc(MAX_INPUT_SZ);
	char *word;
	const char *keywords[4] = { "north", "east", "south", "west" };
	int length = (sizeof(keywords) / sizeof(*keywords)) - 1;

	printf("You now stand at the southern end of a large cavern. There is nothing, but a solid wall of stone behind you. The area is softly lit with small torches attached to the walls.\n\nAround the outskirts of the main area which you stand are passage ways:\n\nThe passage to the East appears to be closed off by a large block of ice.\n\nThe passage to the North is blocked by raging flames.\n\nThe passage to the West is gaping wide open, however is full of darkness.\n\n");

	for(;;) {
		printf("What do you do?\n> ");
		fgets(input, MAX_INPUT_SZ, stdin);
		word = scanner(input, keywords, length);

		if(strcmp(word, "east") == 0) {
			//eastCaverns();
			;;
		} else if (strcmp(word, "west") == 0) {
			westCavernsEntrace(player, inventory, caverns);
		} else if (strcmp(word, "north") == 0) {
			//northCaverns();
			;;
		} else if (strcmp(word, "south") == 0) {
			//southCaverns();
			;;
		} else {
			printf("\nPlease try again..\n\n");
		}
	}
}
