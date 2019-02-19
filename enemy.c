#include "enemy.h"

struct Enemy *setupEnemy(struct Enemy *enemy, struct Weapon *weapon, struct Spell **spells)
{
    enemy = malloc(sizeof(struct Enemy)); // need error checking
    strcpy(enemy->name, "Grunt");
    enemy->hp = 100;
    enemy->mp = 100;
    enemy->dmg = 4;
	enemy->weapon = weapon;
	enemy->spells = spells;

    return enemy;
}

void enemyAttack(struct Player *player, struct Enemy *enemy)
{
    int dmg = randRange(enemy->weapon->mindmg, enemy->weapon->maxdmg);
    printf("-> %s attacks for %d!\n", enemy->name, dmg);
    player->hp -= dmg;
}

void enemySpell(struct Player *player, struct Enemy *enemy)
{
	int length = sizeof(enemy->spells) / sizeof(*enemy->spells);
	int choice;
	choice = randRange(0, length);
	printf("-> %s casts %s for %d!\n", enemy->name, enemy->spells[choice]->name, enemy->spells[choice]->dmg);
	*enemy->spells[choice]->enemyAffects -= player->spells[choice]->dmg;
}

int enemysTurn(struct Player *player, struct Enemy *enemy)
{
	// if no spells, just attack
	if(enemy->spells[0] == NULL) {
		enemyAttack(player, enemy);
		return 0;
	}

	// choose between attack or spell
	int choice;
	choice = randRange(1, 10);
	if(choice < 8) {
    	enemyAttack(player, enemy);
	} else {
		enemySpell(player, enemy);
	}

	if(player->hp <= 0) {
		printf("\n//// Y O U  L O S E ////\n\n");
		return 2;
	}

	return 0;
}
