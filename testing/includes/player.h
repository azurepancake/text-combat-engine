#ifndef __PLAYER_H
#define __PLAYER_H

#include <stdio.h>
#include <string.h>
#include "helpers.h"
#include "enemy.h"

struct Weapon {
    char name[20];
    int dmg;
};

struct Armor {
    char name[20];
    int def;
};

struct Spell {
    char name[20];
    int dmg;
    int mp;
};

struct Player {
    struct Weapon *weapon;
    struct Armor *head;
    struct Armor *chest;
    struct Spell *spells[10];
    char name[20];
    int level;
    int hp;
    int mp;
    int ap;
    int def;
    int totalDef;
};

struct Player *setupPlayer(struct Player *player, struct Weapon *weapon, struct Armor *head, struct Armor *chest, struct Spell **spells);
int playersTurn(struct Player *player, struct Enemy *enemy);
void playerAttack(struct Player *player, struct Enemy *enemy);
void playerSpell(struct Player *player, struct Enemy *enemy);

#endif
