#ifndef __PLAYER_H
#define __PLAYER_H

// The amount of things
#define WEAPONS 2
#define HEADARMOR 1
#define CHESTARMOR 1
#define SPELLS 3
#define ITEMS 2

// Player start stats
#define STARTHP 100
#define STARTMP 100
#define STARTAP 3
#define STARTDEF 3

#include <stdio.h>
#include <string.h>
#include "character-types.h"
#include "helpers.h"

struct Weapon {
	char name[20];
	int mindmg;
	int maxdmg;
	int owned;
	int index;
};

struct Armor {
	char name[20];
	int def;
	int owned;
	int index;
};

struct Spell {
	char name[20];
	int *playerAffects;
	int *enemyAffects;
	int dmg;
	int mp;
	int learned;
	int index;
};

struct Item {
	char name[20];
	int *playerAffects;
	int *enemyAffects;
	int dmg;
	int quantity;
	int index;
};

struct Player *setupPlayer(struct Player *player, struct Weapon *weapon, struct Armor *head, struct Armor *chest, struct Spell **spells, struct Item **items, struct Weapon **weapons, struct Armor **headarmor, struct Armor **chestarmor);
int playersTurn(struct Player *player, struct Enemy *enemy);
int playerAttack(struct Player *player, struct Enemy *enemy);
int playerSpell(struct Player *player, struct Enemy *enemy);
int playerItem(struct Player *player, struct Enemy *enemy);
int playerEquip(struct Player *player);
void changeWeapon(struct Player *player);
void changeHead(struct Player *player);
void changeChest(struct Player *player);

#endif
