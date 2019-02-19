#ifndef __ENEMY_H
#define __ENEMY_H

#include <stdio.h>
#include <string.h>
#include "character-types.h"
#include "helpers.h"

struct Enemy *setupEnemy(struct Enemy *enemy, struct Weapon *weapon, struct Spell **spells);
void enemysAttack(struct Player *player, struct Enemy *enemy);
int enemysTurn(struct Player *player, struct Enemy *enemy);

#endif
