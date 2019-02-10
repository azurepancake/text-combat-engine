#include "player.h"
#include "enemy.h"
#include "helpers.h"

int main()
{
    // Weapons
    struct Weapon *broadsword;
    broadsword = malloc(sizeof(struct Weapon));
    broadsword->dmg = 3;
    strcpy(broadsword->name, "Broadsword");

    // Head armor
    struct Armor *skullcap;
    skullcap = malloc(sizeof(struct Armor));
    skullcap->def = 3;
    strcpy(skullcap->name, "Skull Cap");

    // Chest armor
    struct Armor *breastplate;
    breastplate = malloc(sizeof(struct Armor));
    breastplate->def = 5;
    strcpy(breastplate->name, "Breastplate");

    // Spells
    struct Spell *fire;
    fire = malloc(sizeof(struct Spell));
    fire->dmg = 10;
    fire->mp = 5;
	fire->learned = 1;
    strcpy(fire->name, "Fire");

    struct Spell *ice;
    ice = malloc(sizeof(struct Spell));
    ice->dmg = 5;
    ice->mp = 5;
	ice->learned = 1;
    strcpy(ice->name, "Ice");

	struct Spell *heal;
	heal = malloc(sizeof(struct Spell));
	heal->dmg = -10;
	heal->mp = 5;
	heal->learned = 1;
	strcpy(heal->name, "Heal");

	struct Spell *barrier;
	barrier = malloc(sizeof(struct Spell));
	barrier->dmg = -10;
	barrier->mp = 5;
	barrier->learned = 0;
	strcpy(barrier->name, "Barrier");

	// Create array of all spells
    struct Spell *spells[SPELLS] = { 0 };
    spells[0] = fire;
    spells[1] = ice;
	spells[2] = heal;
	spells[3] = barrier;

	// Items
	struct Item *potion;
	potion = malloc(sizeof(struct Item));
	potion->dmg = -10;
	potion->quantity = 1;
	strcpy(potion->name, "Potion");

	struct Item *ether;
	ether = malloc(sizeof(struct Item));
	ether->dmg = -10;
	ether->quantity = 1;
	strcpy(ether->name, "Ether");

	// Create array of all items
	//struct Item *items[10] = { 0 };
	//items[0] = potion;
	//items[1] = ether;

    // Create player character
    struct Player *player;
    player = setupPlayer(player, broadsword, skullcap, breastplate, spells);

	// Create enemy non-player character
    struct Enemy *enemy;
    enemy = setupEnemy(enemy);

    // Enter main loop
    int state;
    while(state != 1) {
        state = playersTurn(player, enemy);
        if(state == 0) {
            enemysTurn(player, enemy);
        }
    }

	// Maintain arrays of malloc'd objects to free
    struct Weapon *weaponList[] = { broadsword };
    struct Armor *armorList[] = { skullcap, breastplate };
    struct Spell *spellList[] = { fire, ice };

	// Free up malloc'd memory
    cleanUpMemory(weaponList, armorList, spellList, player, enemy);

    return 0;
}

