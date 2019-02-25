#ifndef __CAVERNS_H
#define __CAVERNS_H
#define MAX_INPUT_SZ 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "helpers.h"
#include "battle.h"
#include "enemy.h"

struct Caverns {
	bool phaseone;
	bool phasetwo;
	bool phasethree;
	bool phasefour;
	char *hint;
};

void startCaverns(struct Player *player, struct Inventory *inventory);
void westCavernsEntrace(struct Player *player, struct Inventory *inventory, struct Caverns *caverns);
void westCaverns(struct Player *player, struct Inventory *inventory, struct Caverns *caverns);
void northCavernsEntrance(struct Player *player, struct Inventory *inventory, struct Caverns *caverns);
void northCaverns(struct Player *player, struct Inventory *inventory, struct Caverns *caverns);
void iceBoss(struct Player *player, struct Inventory *inventory, struct Caverns *caverns);
void fireBoss(struct Player *player, struct Inventory *inventory, struct Caverns *caverns);
#endif
