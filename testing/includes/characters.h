#ifndef __CHARACTERS_H
#define __CHARACTERS_H

#include <stdio.h>
#include <helpers.h>

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

struct Enemy {
    char name[20];
    int hp;
    int mp;
    int dmg;
};

int playersTurn(struct Player *player, struct Enemy *enemy);
void playerAttack(struct Player *player, struct Enemy *enemy);
void playerSpell(struct Player *player, struct Enemy *enemy);
void enemysAttack(struct Player *player, struct Enemy *enemy);
void enemysTurn(struct Player *player, struct Enemy *enemy);

#endif
