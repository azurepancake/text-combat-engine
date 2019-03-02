#include "caverns.h"

void earthBoss(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	typeout("\nYou attempt to open the treasure chest, however a beast of earth forms before you. Prepare for battle.\n");

	// Create enemy non-player character
	struct Spell *enemySpells[] = { inventory->spells[Earth] };
	struct Enemy *enemy;
	enemy = setupEnemy(enemy, inventory->weapons[Broadsword], enemySpells, inventory, player);
	if(battle(player, enemy)) {
		getchar();
		caverns->phaseseven = 1;
		caverns->hint = "Opposites attract..";
		inventory->spells[Fire]->learned = 1;
		typeout("\nYou've defeated the beast formed of earth. You open the treasure chest and find an ancient scroll. You feel the power of the earth flow through you..\n\nYou learn the spell 'Earth'.");		  

		return;
	} else {
		return;
	}
}

void eastCaverns(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{	 bool locate = 1;
	for(;;) {
		if(locate) {
			typeout("\nYou now stand inside a chamber of trees. ");
			if(! caverns->phasefive) {
				typeout("In the center of the room sits a large treasure chest.");
			} else if(caverns->phasefive) {
				typeout("In the center of the room sits the empty treasure chest.");
			}
		}
		locate = 0;

		char *word;
		const char *keywords[] = { "open", "return", "locate", "help", "equip" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "open") == 0 && ! caverns->phaseseven) {
			earthBoss(player, inventory, caverns);

		} else if(strcmp(word, "return") == 0) {
			return;

		} else if(strcmp(word, "locate") == 0) {
			locate = 1;

		} else if(strcmp(word, "equip") == 0) {
			playerEquip(player);
			getchar();

		} else if(strcmp(word, "help") == 0) {
			help(caverns->hint);
		}
	}
}

void eastCavernsEntrance(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{
	bool locate = 1;
	for(;;) {
		if(locate) {
			if(! caverns->phasesix) {
				typeout("\nYou stand before the tangled weeds of the cavern's Eastern opening. ");
			} else {
				typeout("\nYou stand before the cavern's Northern opening. The smell of burnt plant life hangs in the air.");
			}
			locate = 0;
		}

		char *word;
		const char *keywords[] = { "enter", "return", "help", "locate", "fire", "equip" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "enter") == 0) {
			if(! caverns->phasesix) {
				typeout("\nThe weeds are barbed and too dense to pass.");
			} else {
				typeout("\nYou enter the Eastern cavern passageway. Suddenly, you feel as if you've entered a tropical rainforest.\n");
				eastCaverns(player, inventory, caverns);
				locate = 1;
			}

		} else if(strcmp(word, "return") == 0) {
			return;

		} else if(strcmp(word, "fire") == 0 && caverns->phasefive && ! caverns->phasesix) {
			caverns->phasesix = 1;
			typeout("\nYou channel your power into a spell of fire, burning the tangled plant matter away.");

		} else if(strcmp(word, "help") == 0) {
			help(caverns->hint);

		} else if(strcmp(word, "locate") == 0) {
			locate = 1;

		} else if(strcmp(word, "equip") == 0) {
			playerEquip(player);
			getchar();

		} else {
			// segmentation fault
			printf("\nPlease try again.. Type 'help' for options..");
		}
	}
}
