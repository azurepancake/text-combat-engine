#ifndef __CHARACTERTYPES_H
#define __CHARACTERTYPES_H

struct Player {
    struct Weapon *weapon;
    struct Armor *head;
    struct Armor *chest;
    struct Spell *spells[10];
	struct Item *items[10];
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

#endif
