#ifndef __CHARACTERTYPES_H
#define __CHARACTERTYPES_H

struct Player {
    struct Weapon *weapon;
    struct Armor *head;
    struct Armor *chest;
	struct Weapon **weapons;
	struct Armor **headarmor;
	struct Armor **chestarmor;
    struct Spell **spells;
	struct Item **items;
    char name[20];
    int level;
    int hp;
    int mp;
	int totalhp;
	int totalmp;
    int ap;
    int def;
    int totalDef;
	int spellCount;
};

struct Enemy {
	struct Weapon *weapon;
	struct Spell **spells;
    char name[20];
    int hp;
    int mp;
    int dmg;
};

#endif
