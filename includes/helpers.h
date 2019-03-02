#ifndef __HELPERS_H
#define __HELPERS_H
#define MAX_INPUT_SZ 256

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "player.h"

struct Inventory {
	struct Weapon **weapons;
	struct Armor **headarmor;
	struct Armor **chestarmor;
	struct Spell **spells;
	struct Item **items;
};

enum Weapons {
	Dagger,
	Stick,
	Broadsword,
	Longsword
};

enum HeadArmor {
	SkullCap,
	LeatherCap
};

enum ChestArmor {
	LeatherCuirass,
	BreastPlate
};

enum Spells {
	Fire,
	Ice,
	Heal,
	Earth
};

enum Items {
	Potion,
	Ether,
	Bomb
};

char *scanner(const char **keywords, int amount);
int reverseNegative(int x);
int randRange(int low, int high);
void cleanUpMemory(struct Weapon **weaponList, struct Armor **armorList, struct Spell **spellList, struct Player *player, struct Enemy *enemy);
void typeout(char *text);
void help(char *hint);

#endif
