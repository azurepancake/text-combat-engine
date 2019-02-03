#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Weapon {
    char name[20];
    int dmg;
} weapon;

struct Player {
	struct Weapon weapon;
	char name[20];
	int level;
	int hp;
	int mp;
	int ap;
	int defense;
} player;

struct Enemy {
	char name[20];
	int hp;
	int mp;
	int dmg;
} enemy;

struct Player *setupPlayer(struct Player *player);
struct Enemy *setupEnemy(struct Enemy *enemy);
void playerAttack(struct Player *player, struct Enemy *enemy);
void playersTurn(struct Player *player, struct Enemy *enemy);
void enemysTurn(struct Player *player, struct Enemy *enemy);

int main()
{
	struct Player *player;
	player = setupPlayer(player);

	struct Enemy *enemy;
	enemy = setupEnemy(enemy);

	for(;;) {
		playersTurn(player, enemy);
		enemysTurn(player, enemy);
	}

	return 0;
}

struct Player *setupPlayer(struct Player *player)
{
	player = malloc(sizeof(struct Player)); // need error checking
	strcpy(player->name, "Player");
	player->hp = 30;
	player->mp = 25;
	player->ap = 3;

	strcpy(player->weapon.name, "Broadsword");
	player->weapon.dmg = 3;

	return player;
}

struct Enemy *setupEnemy(struct Enemy *enemy)
{
	enemy = malloc(sizeof(struct Enemy)); // need error checking
	strcpy(enemy->name, "Grunt");
	enemy->hp = 100;
	enemy->mp = 100;
	enemy->dmg = 2;

	return enemy;
}

void playerAttack(struct Player *player, struct Enemy *enemy)
{
	int dmg = player->ap * player->weapon.dmg;
	printf("\n-> %s attacks for %d!\n", player->name, dmg);
}

void playersTurn(struct Player *player, struct Enemy *enemy)
{
	int choice;
	printf("\n%s\n", player->name);
	printf("----------\n");
	printf("HP: %d\n", player->hp);
	printf("MP: %d\n", player->mp);
	printf("----------\n");
	printf("1) Attack\n");
	printf("2) Magic\n");
	printf("3) Item\n");
	printf("> ");
	scanf("%d", &choice);

	if(choice == 1) {
		playerAttack(player, enemy);
	}
	else if(choice == 2) {
		printf("\n-> %s casts spell!\n", player->name);
	}
	else if(choice == 3) {
		printf("\n-> %s uses item!\n", player->name);
	}
	else {
		printf("\nInvalid entry..\n");
	}
}

void enemysTurn(struct Player *player, struct Enemy *enemy)
{
	printf("-> %s attacks for %d!\n", enemy->name, enemy->dmg);
	player->hp -= enemy->dmg;
}
