#ifndef __ENEMY_H
#define __ENEMY_H

#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include "player.h"

struct Enemy {
    char name[20];
    int hp;
    int mp;
    int dmg;
};

struct Enemy *setupEnemy(struct Enemy *enemy);
void enemysAttack(struct Player *player, struct Enemy *enemy);
void enemysTurn(struct Player *player, struct Enemy *enemy);

#endif
