#include "caverns.h"
#include "enemy.h"

void iceBoss(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	typeout("\nYou attempt to open the chest, however a large beast of ice forms before your very eyes. Prepare for battle.\n");
	
	// Create enemy non-player character
	struct Spell *enemySpells[] = { inventory->spells[1] };
	struct Enemy *enemy;
	enemy = setupEnemy(enemy, inventory->weapons[0], enemySpells, inventory, player);

	if(battle(player, enemy) == 0) {
		typeout("\nYou've defeated the beast formed of ice. You open the treasure chest and find an ancient scroll. You feel the power of ice flow through you..\n\nYou learn the spell 'Ice'.");
		inventory->spells[1]->learned = 1;
		caverns->phasethree = 1;
		return;
	} else {
		return;
	}
}

void westCaverns(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	if(caverns->phaseone == 0) {
		typeout("\nYou enter the darkness. Suddenly, a wooden club clumsily swings through the dark which you barely dodge. Prepare for battle.\n");

		// Create enemy non-player character
		struct Spell *enemySpells[0];
		struct Enemy *enemy;
		enemy = setupEnemy(enemy, inventory->weapons[0], enemySpells, inventory, player);
	
		// Enter battle
		if(battle(player, enemy)) {
			caverns->phaseone = 1;
			typeout("\nYou've defeated the beast that emerged from the cloak of darkness. You retrieve a stick of rough wood which the monster used as a weapon.");
			inventory->weapons[1]->owned = 1; // you get a stick!
			getchar();
			return;
		} else {
			return;
		}

	} else if (caverns->phasetwo == 1) {
		typeout("\nUsing your torch, you navigate through the passage way. The air begins to feel chill and you notice ice forming upon the walls.\n\nYou enter an icy chamber, in the center of the room sits a large treasure chest.");
		for(;;) {
			char *word;
			const char *keywords[2] = { "open", "return" };
			int length = (sizeof(keywords) / sizeof(*keywords));
			word = scanner(keywords, length);

			if(strcmp(word, "open") == 0) {
				iceBoss(player, inventory, caverns);
			} else if(strcmp(word, "return") == 0) {
				return;
			} else {
				printf("\nPlease try again..");
			}
		}
	}	
}

void northCavernsEntrance(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	typeout("\nYou head towards the Northern area of the cavern. Standing before the bellowing flames of the opening, you feel the scortching heat upon your skin. It is impossible to pass.");
	for(;;) {
		char *word;
		const char *keywords[5] = { "enter", "return", "stick", "fire", "light" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "enter") == 0) {
			typeout("\nYou do not dare near any closer to the flames..");
		} else if(strcmp(word, "return") == 0) {
			return;
		} else if(strcmp(word, "light") == 0 && caverns->phaseone == 1) {
			caverns->phasetwo = 1;
			typeout("\nYou light the wooden stick aflame..");
		} else {
			printf("\nPlease try again..");
		}
	}
}

void westCavernsEntrace(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{	
	typeout("\nYou head towards the West, where you approach the large opening upon the outer wall. You hear the sound of whispers come from deep within the darkness.");
	for(;;) {
		char *word;
		const char *keywords[2] = { "enter", "return" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "enter") == 0) {
			westCaverns(player, inventory, caverns);
		} else if(strcmp(word, "return") == 0) {
			return;
		} else {
			printf("\nPlease try again..");
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
	printf("//// T H E  C A V E R N S ////\n");

	for(;;) {
		printf("\nYou now stand at the southern end of a large cavern.. Around the outskirts of the main area which you stand are passage ways:\n\nThe passage to the East appears to be closed off by large, thick vines.\n\nThe passage to the North is blocked by raging flames.\n\nThe passage to the West is gaping wide open, however is full of darkness.");

		char *word;
		const char *keywords[4] = { "north", "east", "south", "west" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "east") == 0) {
			;; //eastCaverns();
		} else if (strcmp(word, "west") == 0) {
			westCavernsEntrace(player, inventory, caverns);
		} else if (strcmp(word, "north") == 0) {
			northCavernsEntrance(player, inventory, caverns);
		} else if (strcmp(word, "south") == 0) {
			;; //southCaverns();
		} else {
			printf("\nPlease try again..\n");
		}
	}
}
