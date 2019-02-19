#ifndef __HELPERS_H
#define __HELPERS_H
#define MAX_INPUT_SZ 256

#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "player.h"

struct Inventory {
	struct Weapons **weapons;
	struct Armor **armor;
};

char *scanner(char *input, const char **keywords, int amount);
int reverseNegative(int x);
int randRange(int low, int high);
void cleanUpMemory(struct Weapon **weaponList, struct Armor **armorList, struct Spell **spellList, struct Player *player, struct Enemy *enemy);
void typeout(char *text);

#endif
