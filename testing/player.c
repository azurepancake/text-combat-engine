#include "player.h"

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

    int length = sizeof(player->spells) / sizeof(*player->spells);
    for(int i = 0; i < length; i++) {
        player->spells[i] = 0;
    }

    player->spells[0] = spells[0]; // 0 = fire
    player->spells[1] = spells[1]; // 1 = ice

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
        case 3: printf("\n-> %s uses item!\n", player->name);
            break;
        default: printf("\nInvalid entry..\n");
            break;
    }

    return 0;
}
