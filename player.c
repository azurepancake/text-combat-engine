#include "player.h"

struct Player *setupPlayer(struct Player *player, struct Weapon *weapon, struct Armor *head, struct Armor *chest, struct Spell **spells, struct Item **items, struct Weapon **weapons, struct Armor **headarmor, struct Armor **chestarmor)
{
	player = malloc(sizeof(struct Player)); // need error checking
	strcpy(player->name, "Player");
	player->totalhp = STARTHP;
	player->totalmp = STARTMP;
	player->hp = STARTHP;
	player->mp = STARTMP;
	player->ap = STARTAP;;
	player->def = STARTDEF;
	player->weapon = weapon;
	player->head = head;
	player->chest = chest;
	player->totalDef = player->def + player->head->def + player->chest->def;
	player->weapons = weapons;
	player->headarmor = headarmor;
	player->chestarmor = chestarmor;
	player->spells = spells;
	player->items = items;

	return player;
}

int playerAttack(struct Player *player, struct Enemy *enemy)
{
	int dmg = randRange(player->weapon->mindmg, player->weapon->maxdmg) + player->ap; 
	printf("\n-> %s attacks for %d!\n", player->name, dmg);
	enemy->hp -= dmg;

	return 1;
}

int playerSpell(struct Player *player, struct Enemy *enemy)
{
	printf("\n----------\n");
	printf("Spells");
	printf("\n----------\n");
	
	int count = 0; 
	for(int i = 0; i <= SPELLS; i++) {
		if(player->spells[i]->learned == 0) {
			continue;
		}

		count++;
		player->spells[i]->index = count; // map the actual array index to the menu number
		printf("%d) %s (%d MP)\n", count, player->spells[i]->name, player->spells[i]->mp);
	}

	int exit = count + 1;	
	printf("%d) Return\n", exit);

	int choice;
	printf("> ");
	scanf("%d", &choice);

	if(choice == exit) {
		return 0;
	}

	// check each spell index to find which one matches the choice
	for(int i = 0; i <= SPELLS; i++) {
		if(player->spells[i]->index == choice) {
			// return if spell is too expensive
			if((player->mp - player->spells[i]->mp) < 0) {
				printf("\n-> Not enough MP!\n");
				return 0;
			}
			int dmg = reverseNegative(player->spells[i]->dmg);
			printf("\n-> %s casts %s for %d!\n", player->name, player->spells[i]->name, dmg);
			player->mp -= player->spells[i]->mp;
			*player->spells[i]->playerAffects -= player->spells[i]->dmg;
		}
	}

	return 1;
}

int playerItem(struct Player *player, struct Enemy *enemy)
{
	printf("\n----------\n");
	printf("Items");
	printf("\n----------\n");

	/*
	1) Create map[] array
	2) For each iteration, index with "count" and define with player->items[i]->index
	3) Use "choice" to index map[] and get the item's "index" value
	4) Iterate through items and find matching index value
	5) Use item
	*/
	
	int map[ITEMS+2]; // I don't understand why I need to add 2..
	int count = 0;
	for(int i = 0; i <= ITEMS; i++) {
		if(player->items[i]->quantity == 0) {
			continue;
		}

		count++;
		map[count] = player->items[i]->index;
		printf("%d) %s (%d)\n", count, player->items[i]->name, player->items[i]->quantity);
	}

	int exit = count + 1;
	printf("%d) Return\n", exit);

	int choice;
	printf("> ");
	scanf("%d", &choice);

	if(choice == exit) {
		return 0;
	}

	// Can't pick out of range number
	if(choice > count) {
		printf("\n-> Invalid choice.\n");
		return 0;
	}

	for(int i = 0; i <= ITEMS; i++) {
		if(player->items[i]->index == map[choice]) {
			// Can't use an item that you don't have
			if(player->items[i]->quantity == 0) {
				printf("\n-> Invalid choice.\n");
				return 0;
			}
			int dmg = reverseNegative(player->items[i]->dmg);
			printf("\n-> You use a %s for %d!\n", player->items[i]->name, dmg);
			player->items[i]->quantity--;
			*player->items[i]->playerAffects -= player->items[i]->dmg;
		}
	}
	return 1;
}

void changeWeapon(struct Player *player)
{
	int choice;
	printf("\n----------\n");
	printf("Weapons");
	printf("\n----------\n");

	int count = 0;
	for(int i = 0; i <= WEAPONS; i++) {
		if(player->weapons[i]->name == player->weapon->name) {
			continue;
		}
		if(player->weapons[i]->owned == 1) {
			count++;
			player->weapons[i]->index = count;
			printf("%d) %s, Damage = %d - %d\n", count, player->weapons[i]->name, player->weapons[i]->mindmg, player->weapons[i]->maxdmg);
		}
	}

	int exit = count + 1;
	printf("%d) Return\n", exit);
	printf("> ");
	scanf("%d", &choice);

	if(choice == exit) {
		return;
	}

	for(int i = 0; i <= WEAPONS; i++) {
		if(player->weapons[i]->index == choice) {
			player->weapon = player->weapons[i];
			printf("\n-> You equip a %s.\n", player->weapon->name);
			return;
		}
	}
}

void changeHead(struct Player *player)
{
	int choice;
	printf("\n----------\n");
	printf("Head Armor");
	printf("\n----------\n");

	int count = 0;
	for(int i = 0; i <= HEADARMOR; i++) {
		if(player->headarmor[i]->name == player->head->name) {
			continue;
		}
		if(player->headarmor[i]->owned == 1) {
			count++;
			player->headarmor[i]->index = count;
			printf("%d) %s, Defense = %d\n", count, player->headarmor[i]->name, player->headarmor[i]->def);
		}
	}

	int exit = count + 1;
	printf("%d) Return\n", exit);
	printf("> ");
	scanf("%d", &choice);

	if(choice == exit) {
		return;
	}

	for(int i = 0; i <= HEADARMOR; i++) {
		if(player->headarmor[i]->index == choice) {
			player->head = player->headarmor[i];
			printf("\n-> You equip a %s.\n", player->head->name);
			return;
		}
	}
}

void changeChest(struct Player *player)
{
	int choice;
	printf("\n----------\n");
	printf("Chest Armor");
	printf("\n----------\n");

	int count = 0;
	for(int i = 0; i <= CHESTARMOR; i++) {
		if(player->chestarmor[i]->name == player->chest->name) {
			continue;
		}
		if(player->chestarmor[i]->owned == 1) {
			count++;
			player->chestarmor[i]->index = count;
			printf("%d) %s, Defense = %d\n", count, player->chestarmor[i]->name, player->chestarmor[i]->def);
		}
	}			

	int exit = count + 1;
	printf("%d) Return \n", exit);
	printf("> ");
	scanf("%d", &choice);

	if(choice == exit) {
		return;
	}

	for(int i = 0; i <= CHESTARMOR; i++) {
		if(player->chestarmor[i]->index == choice) {
			player->chest = player->chestarmor[i];
			printf("\n-> You equip a %s.\n", player->chest->name);
			return;
		}
	}
}

int playerEquip(struct Player *player)
{
	int state;
	for(;;) {
		int choice;
		printf("\n----------\n");
		printf("Statistics");
		printf("\n----------\n");
		printf("HP: %d / %d\n", player->hp, player->totalhp);
		printf("MP: %d / %d\n", player->mp, player->totalmp);
		printf("AP: %d\n", player->ap);
		printf("Defense: %d\n", player->def);
		printf("\n----------\n");
		printf("Equipment");
		printf("\n----------\n");
		printf("Weapon: %s, Damage = %d - %d\n", player->weapon->name, player->weapon->mindmg, player->weapon->maxdmg);
		printf("Head: %s, Defense = %d\n", player->head->name, player->head->def);
		printf("Chest: %s, Defense = %d", player->chest->name, player->chest->def);
		printf("\n----------\n");
		printf("1) Change weapon\n");
		printf("2) Change head armor\n");
		printf("3) Change chest armor\n");
		printf("4) Return\n");
		printf("> ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0: return 1;
				break;
			case 1: changeWeapon(player);
				break;
			case 2: changeHead(player);
				break;
			case 3: changeChest(player);
				break;
			case 4: return 0;
				break;
		}
	}
}

int playersTurn(struct Player *player, struct Enemy *enemy)
{
	// ensure hp and never goes above max
	if(player->hp > player->totalhp) {
		player->hp = player->totalhp;
	}
	if(player->mp > player->totalmp) {
		player->mp = player->totalmp;
	}

	int state;
	while(state != 1) {
		int choice;
		printf("\n----------\n");
		printf("%s", player->name);
		printf("\n----------\n");
		printf("HP: %d\n", player->hp);
		printf("MP: %d\n", player->mp);
		printf("----------\n");
		printf("1) Attack\n");
		printf("2) Magic\n");
		printf("3) Item\n");
		printf("4) Equip\n");
		printf("> ");
		scanf("%d", &choice);

		switch(choice)
		{
			case 0: return 1;
				break;
			case 1: state = playerAttack(player, enemy);
				break;
			case 2: state = playerSpell(player, enemy);
				break;
			case 3: state = playerItem(player, enemy);
				break;
			case 4: state = playerEquip(player);
				break;
			default: printf("\n-> Invalid choice.\n");
				break;
		}
	}

	if(enemy->hp <= 0) {
		printf("\n//// Y O U  W I N ////\n\n");
		return 1;
	}

	return 0;
}
