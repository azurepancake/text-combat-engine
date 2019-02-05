#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Weapon {
	char name[20];
	int dmg;
} weapon;

struct Armor {
	char name[20];
	int def;
} armor;

struct Spell {
	char name[20];
	int dmg;
	int healPower;
	int mp;
} spell;

struct Item {
	char name[20];
	int dmg;
	int healPower;
	int quantity;
} item;

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
} player;

struct Enemy {
	char name[20];
	int hp;
	int mp;
	int dmg;
} enemy;

struct Player *setupPlayer(struct Player *player, struct Weapon *weapon, struct Armor *head, struct Armor *chest, struct Spell **spells);
struct Enemy *setupEnemy(struct Enemy *enemy);
int setupArmor();
int randRange(int low, int high);
void playerAttack(struct Player *player, struct Enemy *enemy);
void playerSpell(struct Player *player, struct Enemy *enemy);
void playersTurn(struct Player *player, struct Enemy *enemy);
void enemysAttack(struct Player *player, struct Enemy *enemy);
void enemysTurn(struct Player *player, struct Enemy *enemy);

int main()
{
	// WEAPONS
	struct Weapon *broadsword;
	broadsword = malloc(sizeof(struct Weapon));
	broadsword->dmg = 3;
	strcpy(broadsword->name, "Broadsword");

	// HEAD ARMOR
	struct Armor *skullcap;
	skullcap = malloc(sizeof(struct Armor));
	skullcap->def = 3;
	strcpy(skullcap->name, "Skull Cap");

	// CHEST ARMOR
	struct Armor *breastplate;
	breastplate = malloc(sizeof(struct Armor));
	breastplate->def = 5;
	strcpy(breastplate->name, "Breastplate");

	// SPELLS
	struct Spell *fire;
	fire = malloc(sizeof(struct Spell));
	fire->dmg = 10;
	fire->mp = 5;
	strcpy(fire->name, "Fire");

	struct Spell *ice;
	ice = malloc(sizeof(struct Spell));
	ice->dmg = 5;
	ice->mp = 5;
	strcpy(ice->name, "Ice");

	struct Spell *spells[10] = { 0 }; // fill spells array with zeros
	spells[0] = fire;
	spells[1] = ice;

	// CREATE PLAYER
	struct Player *player;
	player = setupPlayer(player, broadsword, skullcap, breastplate, spells);

	// CREATE ENEMY
	struct Enemy *enemy;
	enemy = setupEnemy(enemy);

	// MAIN LOOP
	for(;;) {
		playersTurn(player, enemy);
		enemysTurn(player, enemy);
	}

	return 0;
}

struct Player *setupPlayer(struct Player *player, struct Weapon *weapon, struct Armor *head, struct Armor *chest, struct Spell **spells)
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

	// fill player->spells array with zeros
	int length = sizeof(player->spells) / sizeof(*player->spells);
	for(int i = 0; i < length; i++) {
		player->spells[i] = 0;
	}

	player->spells[0] = spells[0]; // 0 = fire
	player->spells[1] = spells[1]; // 1 = ice

	return player;
}

struct Enemy *setupEnemy(struct Enemy *enemy)
{
	enemy = malloc(sizeof(struct Enemy)); // need error checking
	strcpy(enemy->name, "Grunt");
	enemy->hp = 100;
	enemy->mp = 100;
	enemy->dmg = 4;

	return enemy;
}

int randRange(int low, int high)
{
	srand(time(NULL));
	int num = rand() % (high + 1 - low) + low;

	return num;
}

void playerAttack(struct Player *player, struct Enemy *enemy)
{
	int dmg = (player->ap * player->weapon->dmg) - (randRange(1, 3));
	printf("\n-> %s attacks for %d!\n", player->name, dmg);
	enemy->hp -= dmg;
}

void enemyAttack(struct Player *player, struct Enemy *enemy)
{
	int dmg = enemy->dmg - (randRange(1, 2));
	printf("\n-> %s attacks for %d!\n", enemy->name, dmg);
	player->hp -= dmg;
}

void playerSpell(struct Player *player, struct Enemy *enemy)
{

	printf("\n----------\n");
	printf("SPELLS:\n");
	printf("----------\n");
	int length = sizeof(player->spells) / sizeof(*player->spells);
	for(int i = 0; i <= length; i++) {
		if(player->spells[i] == 0) {
			break;
		}

		printf("%d) %s\n", i + 1, player->spells[i]->name);
	}

	int choice;
	printf("> ");
	scanf("%d", &choice);
	choice = choice - 1;
	printf("\n-> %s casts %s for %d!\n", player->name, player->spells[choice]->name, player->spells[choice]->dmg);
	player->mp -= player->spells[choice]->mp;
	enemy->hp -= player->spells[choice]->dmg;
}

void playersTurn(struct Player *player, struct Enemy *enemy)
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

	if(choice == 1) {
		playerAttack(player, enemy);
	}
	else if(choice == 2) {
		playerSpell(player, enemy);
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
	enemyAttack(player, enemy);
}
