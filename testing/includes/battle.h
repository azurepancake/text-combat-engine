#ifndef __BATTLE_H
#define __BATTLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

struct Item {
    char name[20];
    int dmg;
    int quantity;
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

struct Player *setupPlayer(struct Player *player, struct Weapon *weapon, struct Armor *head, struct Armor *chest, struct Spell **spells);
struct Enemy *setupEnemy(struct Enemy *enemy);
int setupArmor();
int randRange(int low, int high);
int playersTurn(struct Player *player, struct Enemy *enemy);
void playerAttack(struct Player *player, struct Enemy *enemy);
void playerSpell(struct Player *player, struct Enemy *enemy);
void enemysAttack(struct Player *player, struct Enemy *enemy);
void enemysTurn(struct Player *player, struct Enemy *enemy);
void cleanUpMemory(struct Weapon **weaponList, struct Armor **armorList, struct Spell **spellList, struct Player *player, struct Enemy *enemy);

#endif
