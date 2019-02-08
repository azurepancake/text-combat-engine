#include "characters.h"
#include "helpers.h"

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

