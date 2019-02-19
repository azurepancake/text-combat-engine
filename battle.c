#include "player.h"
#include "enemy.h"
#include "helpers.h"
#include "battle.h"

int battle()
{
    // Weapons
	struct Weapon *dagger;
	dagger = malloc(sizeof(struct Weapon));
	dagger->mindmg = 1;
	dagger->maxdmg = 3;
	dagger->owned = 1;
	strcpy(dagger->name, "Dagger");

    struct Weapon *broadsword;
    broadsword = malloc(sizeof(struct Weapon));
	broadsword->mindmg = 3;
	broadsword->maxdmg = 8;
	broadsword->owned = 1;
    strcpy(broadsword->name, "Broadsword");

	struct Weapon *longsword;
	longsword = malloc(sizeof(struct Weapon));
	longsword->mindmg = 10;
	longsword->maxdmg = 20;
	longsword->owned = 1;
	strcpy(longsword->name, "Longsword");

	// Create an array of all weapons
	struct Weapon *weapons[] = { dagger, broadsword, longsword };

    // Head armor
    struct Armor *skullcap;
    skullcap = malloc(sizeof(struct Armor));
    skullcap->def = 3;
	skullcap->owned = 1;
    strcpy(skullcap->name, "Skull Cap");

	struct Armor *leathercap;
	leathercap = malloc(sizeof(struct Armor));
	leathercap->def = 1;
	leathercap->owned = 1;
	strcpy(leathercap->name, "Leather Cap");

	// Create an array of all head armor
	struct Armor *headarmor[] = { skullcap, leathercap };

    // Chest armor
    struct Armor *breastplate;
    breastplate = malloc(sizeof(struct Armor));
    breastplate->def = 5;
	breastplate->owned = 1;
    strcpy(breastplate->name, "Breastplate");

	struct Armor *leathercuirass;
	leathercuirass = malloc(sizeof(struct Armor));
	leathercuirass->def = 3;
	leathercuirass->owned = 1;
	strcpy(leathercuirass->name, "Leather Cuirass");

	struct Armor *chestarmor[] = { breastplate, leathercuirass };

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
    struct Spell *spells[] = { fire, ice, heal, barrier };

	// Items
	struct Item *potion;
	potion = malloc(sizeof(struct Item));
	potion->dmg = -10;
	potion->quantity = 1;
	potion->index = 0;
	strcpy(potion->name, "Potion");

	struct Item *ether;
	ether = malloc(sizeof(struct Item));
	ether->dmg = -10;
	ether->quantity = 1;
	ether->index = 1;
	strcpy(ether->name, "Ether");

	struct Item *bomb;
	bomb = malloc(sizeof(struct Item));
	bomb->dmg = 25;
	bomb->quantity = 4;
	bomb->index = 2;
	strcpy(bomb->name, "Bomb");

	// Create array of all items
	struct Item *items[] = { potion, ether, bomb };

    // Create player character
    struct Player *player;
    player = setupPlayer(player, broadsword, skullcap, breastplate, spells, items, weapons, headarmor, chestarmor);

    // Create enemy non-player character
	struct Spell *enemySpells[] = { fire, ice };
	//struct Spell *enemySpells[] = { NULL };
    struct Enemy *enemy;
    enemy = setupEnemy(enemy, broadsword, enemySpells);

	// Setup spell pointers
	fire->playerAffects = &enemy->hp;
	fire->enemyAffects = &player->hp;
	ice->playerAffects = &enemy->hp;
	ice->enemyAffects = &player->hp;
	heal->playerAffects = &player->hp;
	heal->enemyAffects = &enemy->hp;

	// Setup item pointers
	potion->playerAffects = &player->hp;
	ether->playerAffects = &player->mp;
	bomb->playerAffects = &enemy->hp;

	printf("\n//// F I G H T ////");

    // Enter main loop
    int state = 0;
    while(state == 0) {
		printf("\n"); // without this, enemy loops over and over.. weird..
        state = playersTurn(player, enemy);
		if(state == 0) {
			state = enemysTurn(player, enemy);
		}
    }

	// Maintain arrays of malloc'd objects to free
    struct Weapon *weaponList[] = { broadsword };
    struct Armor *armorList[] = { skullcap, breastplate };
    struct Spell *spellList[] = { fire, ice };

	// Free up malloc'd memory
    cleanUpMemory(weaponList, armorList, spellList, player, enemy);

    return state;
}

