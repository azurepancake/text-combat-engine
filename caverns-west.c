#include "caverns.h"

void iceBoss(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	typeout("\nYou attempt to open the chest, however a large beast of ice forms before your very eyes. Prepare for battle.\n");

	// Create enemy non-player character
	struct Spell *enemySpells[] = { inventory->spells[Ice] };
	struct Enemy *enemy;
	enemy = setupEnemy(enemy, inventory->weapons[Broadsword], enemySpells, inventory, player);
	if(battle(player, enemy)) {
		getchar();
		caverns->phasethree = 1;
		caverns->hint = "Opposites attract..";
		inventory->spells[Ice]->learned = 1;
		typeout("\nYou've defeated the beast formed of ice. You open the treasure chest and find an ancient scroll. You feel the power of ice flow through you..\n\nYou learn the spell 'Ice'.");		 return;
	} else {
		return;
	}
}

void westCaverns(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{	 if(! caverns->phaseone) {
		typeout("\nYou enter the darkness. Suddenly, a wooden club clumsily swings through the dark which you barely dodge. Prepare for battle.\n");

		// Create enemy non-player character
		struct Spell *enemySpells[1];
		memset(enemySpells, 0, sizeof(enemySpells));
		struct Enemy *enemy;
		enemy = setupEnemy(enemy, inventory->weapons[Stick], enemySpells, inventory, player);

		// Enter battle		   
		if(battle(player, enemy)) {
			caverns->phaseone = 1;
			caverns->hint = "Bring the fire into the darkness..";
			typeout("\nYou've defeated the beast that emerged from the cloak of darkness. You retrieve a stick of rough wood which the monster used as a weapon.\n");
			inventory->weapons[Stick]->owned = 1; // you get a stick!
			getchar();
			return;
		} else {
			return;
		}

	} else if (caverns->phasetwo) {
		bool locate = 1;
		for(;;) {
			if(locate) {
				typeout("\n\nYou now stand inside of an icy chamber. ");
				if(! caverns->phasethree) {
					typeout("In the center of the room sits a large treasure chest.");
				} else if(caverns->phasethree) {
					typeout("In the center of the room sits the empty treasure chest.");
				}
			}
			locate = 0;

			char *word;
			const char *keywords[] = { "open", "return", "help", "locate", "equip" };
			int length = (sizeof(keywords) / sizeof(*keywords));
			word = scanner(keywords, length);

			if((strcmp(word, "open") == 0) && ! caverns->phasethree) {
				iceBoss(player, inventory, caverns);

			} else if(strcmp(word, "return") == 0) {
				return;

			} else if(strcmp(word, "help") == 0) {
				help(caverns->hint);

			} else if(strcmp(word, "locate") == 0) {
				locate = 1;

			} else if(strcmp(word, "equip") == 0) {
				playerEquip(player);
				getchar();

			} else {
				printf("\nPlease try again.. Type 'help' for options..");
			}
		}
	}
}

void westCavernsEntrace(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	bool locate = 1;
	for(;;) {
		if(locate) {
			locate = 0;
			typeout("\nYou stand before the large opening of the cavern's Western wall. ");
			if(! caverns->phaseone) {
				typeout("You hear the sound of whispers come from deep within the darkness.");
			}
		}

		char *word;
		const char *keywords[] = { "enter", "return", "help", "locate", "equip" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "enter") == 0) {
			if(! caverns->phasetwo && caverns->phaseone) {
				typeout("\nYou do not dare enter that darkness again without a torch..");
			} else {
				if(caverns->phasetwo) {
					typeout("\nUsing your torch, you navigate through the passage way. The air begins to feel chill and you notice ice forming upon the walls.");
				}
				westCaverns(player, inventory, caverns);
				locate = 1;
			}

		} else if(strcmp(word, "return") == 0) {
			return;

		} else if(strcmp(word, "help") == 0) {
			help(caverns->hint);

		} else if(strcmp(word, "locate") == 0) {
			locate = 1;

		} else if(strcmp(word, "equip") == 0) {
			playerEquip(player);
			getchar();

		} else {
			printf("\nPlease try again.. Type 'help' for options..");
		}
	}
}
