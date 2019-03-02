#include "caverns.h"

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
		typeout("\nYou've defeated the beast formed of fire. You open the treasure chest and find an ancient scroll. You feel the power of fire flow through you..\n\nYou learn the spell 'Fire'.");		return;
	} else {
		return;
	}
}

void northCaverns(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)
{	 bool locate = 1;
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
		const char *keywords[] = { "open", "return", "locate", "help", "equip" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "open") == 0) {
			fireBoss(player, inventory, caverns);

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

void northCavernsEntrance(struct Player *player, struct Inventory *inventory, struct Caverns *caverns)																							{
	bool locate = 1;
	for(;;) {
		if(locate) {
			if(! caverns->phasefour) {				  typeout("\nYou stand before the bellowing flames of the cavern's Northern opening. You feel the scortching heat upon your skin. It is impossible to pass.");								  } else {				  typeout("\nYou stand before the cavern's Northern opening. The flames that once bellowed here have been extinguished. Only embers and smoke remain.");									  }
			locate = 0;
		}

		char *word;		   const char *keywords[] = { "enter", "return", "stick", "fire", "light", "help", "locate", "cast", "ice", "equip" };		  int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "enter") == 0) {
			if(! caverns->phasefour) {
				typeout("\nYou do not dare near any closer to the flames..");
			} else {				typeout("\nYou enter the Northern cavern passageway. The air becomes more hot and arid as you approach the caverns core.\n");				 northCaverns(player, inventory, caverns);
				locate = 1;
			}

		} else if(strcmp(word, "return") == 0) {
			return;
				} else if(strcmp(word, "light") == 0 && caverns->phaseone && strcmp(player->weapon->name, "Wooden Stick") == 0) {			 caverns->phasetwo = 1;
			strcpy(player->weapon->name, "Flaming Wooden Stick");
			typeout("\nYou light the wooden stick aflame..");

		} else if(strcmp(word, "ice") == 0 && caverns->phasethree && ! caverns->phasefour) {
			caverns->phasefour = 1;
			typeout("\nYou channel your power into a spell of ice, extinguishing the flames.");

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
