#ifndef __ENEMY_H
#define __ENEMY_H

#include <stdio.h>
#include <string.h>
#include "character-types.h"
#include "helpers.h"

struct Enemy *setupEnemy(struct Enemy *enemy);
void enemysAttack(struct Player *player, struct Enemy *enemy);
void enemysTurn(struct Player *player, struct Enemy *enemy);

#endif
