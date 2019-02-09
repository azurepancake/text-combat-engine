#ifndef __HELPERS_H
#define __HELPERS_H

#include <stdlib.h>
#include <time.h>
#include "player.h"

int randRange(int low, int high);
void cleanUpMemory(struct Weapon **weaponList, struct Armor **armorList, struct Spell **spellList, struct Player *player, struct Enemy *enemy);

#endif
