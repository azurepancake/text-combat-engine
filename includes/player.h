#ifndef __PLAYER_H
#define __PLAYER_H
#define SPELLS 3
#define ITEMS 2

#include <stdio.h>
#include <string.h>
#include "character-types.h"
#include "helpers.h"

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
	int learned;
	int index;
};

struct Item {
	char name[20];
	int dmg;
	int quantity;
};

struct Player *setupPlayer(struct Player *player, struct Weapon *weapon, struct Armor *head, struct Armor *chest, struct Spell **spells, struct Item **items);
int playersTurn(struct Player *player, struct Enemy *enemy);
void playerAttack(struct Player *player, struct Enemy *enemy);
void playerSpell(struct Player *player, struct Enemy *enemy);
void playerItem(struct Player *player, struct Enemy *enemy);

#endif
