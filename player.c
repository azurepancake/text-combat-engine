#include "player.h"

struct Player *setupPlayer(struct Player *player, struct Weapon *weapon, struct Armor *head, struct Armor *chest, struct Spell **spells, struct Item **items)
{
    player = malloc(sizeof(struct Player)); // need error checking
    strcpy(player->name, "Player");
    player->hp = 30;
    player->mp = 25;
    player->ap = 3;
    player->def = 5;
    player->weapon = weapon;
    player->head = head;
    player->chest = chest;
    player->totalDef = player->def + player->head->def + player->chest->def;
    player->spells = spells;
    player->items = items;

    return player;
}

void playerAttack(struct Player *player, struct Enemy *enemy)
{
    int dmg = (player->ap * player->weapon->dmg) - (randRange(1, 3));
    printf("\n-> %s attacks for %d!\n", player->name, dmg);
    enemy->hp -= dmg;
}

void playerSpell(struct Player *player, struct Enemy *enemy)
{
    printf("\n----------\n");
    printf("SPELLS:\n");
    printf("----------\n");
    
	int count = 0; 
	for(int i = 0; i <= SPELLS; i++) {
        if(player->spells[i]->learned == 0) {
            continue;
        }

		count++;
		player->spells[i]->index = count;
        printf("%d) %s\n", count, player->spells[i]->name);
    }

    int choice;
    printf("> ");
    scanf("%d", &choice);

	for(int i = 0; i <= SPELLS; i++) {
		if(player->spells[i]->index == choice) {
			printf("\n-> %s casts %s for %d!\n", player->name, player->spells[i]->name, player->spells[i]->dmg);
    		player->mp -= player->spells[i]->mp;
    		enemy->hp -= player->spells[i]->dmg;
		}
	}
}

void playerItem(struct Player *player, struct Enemy *enemy)
{
	printf("\n----------\n");
	printf("ITEMS:\n");
	printf("----------\n");

	for(int i = 0; i <= ITEMS; i++) {
		if(player->items[i]->quantity == 0) {
			continue;
		}

		printf("%d) %s\n", i + 1, player->items[i]->name);
	}

	int choice;
	printf("> ");
	scanf("%d", &choice);
	choice = choice - 1;

	// prevent player from accessing items not owned
	if(player->items[choice]->quantity == 0) {
		printf("\n-> Invalid choice!\n");

		return;
	}

	printf("\n-> %s uses %s for %d!\n", player->name, player->items[choice]->name, player->items[choice]->dmg);
}

int playersTurn(struct Player *player, struct Enemy *enemy)
{
    int choice;
    printf("\n----------\n");
    printf("%s\n", player->name);
    printf("----------\n");
    printf("HP: %d\n", player->hp);
    printf("MP: %d\n", player->mp);
    printf("DF: %d\n", player->totalDef);
    printf("AP: %d\n", player->ap);
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
        case 1: playerAttack(player, enemy);
            break;
        case 2: playerSpell(player, enemy);
            break;
        case 3: playerItem(player, enemy);
            break;
        default: printf("\nInvalid entry..\n");
            break;
    }

    return 0;
}
