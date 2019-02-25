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
		typeout("\nYou've defeated the beast formed of ice. You open the treasure chest and find an ancient scroll. You feel the power of ice flow through you..\n\nYou learn the spell 'Ice'.");
		return;
	} else {
		return;
	}
}

void westCaverns(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	if(! caverns->phaseone) {
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
			const char *keywords[] = { "open", "return", "help", "locate" };
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

			} else {
				printf("\nPlease try again.. Type 'help' for options..");
			}
		}
	}	
}

void fireBoss(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	typeout("\nYou attempt to open the treasure chest, however a beast of fire forms before you. Prepare for battle.\n");

    // Create enemy non-player character
    struct Spell *enemySpells[] = { inventory->spells[Fire] };
    struct Enemy *enemy;
    enemy = setupEnemy(enemy, inventory->weapons[Broadsword], enemySpells, inventory, player);

    if(battle(player, enemy)) {
        getchar();
        caverns->phasefive = 1;
        caverns->hint = "Opposites attract..";
        inventory->spells[Fire]->learned = 1;
        typeout("\nYou've defeated the beast formed of fire. You open the treasure chest and find an ancient scroll. You feel the power of fire flow through you..\n\nYou learn the spell 'Fire'.");
        return;
    } else {
        return;
    }
}

void northCaverns(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	bool locate = 1;
	for(;;) {
		if(locate) {
			typeout("\nYou now stand inside of a chamber of flames. ");
			if(! caverns->phasefive) {
				typeout("In the center of the room sits a large treasure chest.");
			} else if(caverns->phasefive) {
				typeout("In the center of the room sits the empty treasure chest.");
			}
		}
		locate = 0;

		char *word;
		const char *keywords[] = { "open", "return", "locate" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "open") == 0) {
			fireBoss(player, inventory, caverns);

		} else if(strcmp(word, "return") == 0) {
			return;

		} else if(strcmp(word, "locate") == 0) {
			locate = 1;
		}
	}
}

void northCavernsEntrance(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	bool locate = 1;
	for(;;) {
		if(locate) {
			if(! caverns->phasefour) {
				typeout("\nYou stand before the bellowing flames of the cavern's Northern opening. You feel the scortching heat upon your skin. It is impossible to pass.");
			} else {
				typeout("\nYou stand before the cavern's Northern opening. The flames that once bellowed here have been extinguished. Only embers and smoke remain.");
			}
			locate = 0;
		}

		char *word;
		const char *keywords[] = { "enter", "return", "stick", "fire", "light", "help", "locate", "cast", "ice" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "enter") == 0) {
			if(! caverns->phasefour) {
				typeout("\nYou do not dare near any closer to the flames..");
			} else {
				typeout("\nYou enter the Northern cavern passageway. The air becomes more hot and arid as you approach the caverns core.\n");
				northCaverns(player, inventory, caverns);
				locate = 1;
			}

		} else if(strcmp(word, "return") == 0) {
			return;

		} else if(strcmp(word, "light") == 0 && caverns->phaseone && strcmp(player->weapon->name, "Wooden Stick") == 0) {
			caverns->phasetwo = 1;
			strcpy(player->weapon->name, "Flaming Wooden Stick");
			typeout("\nYou light the wooden stick aflame..");

		} else if(strcmp(word, "ice") == 0 && caverns->phasethree && ! caverns->phasefour) {
			caverns->phasefour = 1;
			typeout("\nYou channel your power into a spell of ice, extinguishing the flames.");

		} else if(strcmp(word, "help") == 0) {
			help(caverns->hint);

		} else if(strcmp(word, "locate") == 0) {
			locate = 1;

		} else {
			// segmentation fault
			printf("\nPlease try again.. Type 'help' for options..");
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
		const char *keywords[] = { "enter", "return", "help", "locate" };
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

		} else {
			printf("\nPlease try again.. Type 'help' for options..");
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
	caverns->hint = "The darkness calls you..";

	printf("\nLoading caverns binary");
	typeout("........ ");
	printf("OK!\n\n\n");
	printf("//// T H E  C A V E R N S ////\n");

	bool locate = 1;
	for(;;) {
		if(locate) {
			printf("\nYou now stand at the southern end of a large cavern.. Around the outskirts of the main area which you stand are passage ways:\n\n");
			printf("The passage to the East appears to be closed off by large, thick vines.\n\n");

			if(! caverns->phasefour) {
				printf("The passage to the North is blocked by raging flames.\n\n");
			} else {
				printf("The passage to the North is no longer guarded by flames.\n\n");
			}

			printf("The passage to the West is gaping wide open, however is full of darkness.");
			locate = 0;
		}
		char *word;
		const char *keywords[] = { "north", "east", "south", "west", "help", "locate", "equip" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "east") == 0) {
			;; //eastCaverns();

		} else if(strcmp(word, "west") == 0) {
			westCavernsEntrace(player, inventory, caverns);
			locate = 1;

		} else if(strcmp(word, "north") == 0) {
			northCavernsEntrance(player, inventory, caverns);
			locate = 1;

		} else if(strcmp(word, "south") == 0) {
			;; //southCaverns();

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
