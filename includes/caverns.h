#ifndef __CAVERNS_H
#define __CAVERNS_H
#define MAX_INPUT_SZ 256

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "battle.h"

struct Caverns {
	int phaseone;
	int phasetwo;
	int phasethree;
};

void startCaverns(struct Player *player, struct Inventory *inventory);
void westCavernsEntrace(struct Player *player, struct Inventory *inventory, struct Caverns *caverns);
void westCaverns(struct Player *player, struct Inventory *inventory, struct Caverns *caverns);
void northCavernsEntrance(struct Player *player, struct Inventory *inventory, struct Caverns *caverns);
void iceBoss(struct Player *player, struct Inventory *inventory, struct Caverns *caverns);

#endif
