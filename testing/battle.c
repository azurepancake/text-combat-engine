#include "battle.h"

void cleanUpMemory(struct Weapon **weaponList, struct Armor **armorList, struct Spell **spellList, struct Player *player, struct Enemy *enemy)
{
	int i;
	int length;

	// Free up weapon memory	
	length = sizeof(weaponList) / sizeof(*weaponList);
	for(i = 0; i <= length; i++) {
		free(weaponList[i]);
	}

	// Free up armor memory
    length = sizeof(armorList) / sizeof(*armorList);
    for(i = 0; i <= length; i++) {
        free(armorList[i]);
    }

	// Free up spell memory
    length = sizeof(spellList) / sizeof(*spellList);
    for(i = 0; i <= length; i++) {
        free(spellList[i]);
    }

	free(player);
	free(enemy);
}

struct Player *setupPlayer(struct Player *player, struct Weapon *weapon, struct Armor *head, struct Armor *chest, struct Spell **spells)
{
	player = malloc(sizeof(struct Player)); // need error checking
	strcpy(player->name, "Player");
	player->hp = 30;
	player->mp = 25;
	player->ap = 3;
	player->def = 5;
	player->weapon = weapon;
	player->head = head;
	player->chest = chest;
	player->totalDef = player->def + player->head->def + player->chest->def;

	int length = sizeof(player->spells) / sizeof(*player->spells);
	for(int i = 0; i < length; i++) {
		player->spells[i] = 0;
	}

	player->spells[0] = spells[0]; // 0 = fire
	player->spells[1] = spells[1]; // 1 = ice

	return player;
}

struct Enemy *setupEnemy(struct Enemy *enemy)
{
	enemy = malloc(sizeof(struct Enemy)); // need error checking
	strcpy(enemy->name, "Grunt");
	enemy->hp = 100;
	enemy->mp = 100;
	enemy->dmg = 4;

	return enemy;
}
