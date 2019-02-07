struct Enemy {
    char name[20];
    int hp;
    int mp;
    int dmg;
};

struct Enemy *setupEnemy(struct Enemy *enemy)
{    enemy = malloc(sizeof(struct Enemy)); // need error checking
    strcpy(enemy->name, "Grunt");
    enemy->hp = 100;
    enemy->mp = 100;
    enemy->dmg = 4;

    return enemy;
}

void enemyAttack(struct Player *player, struct Enemy *enemy)
{
    int dmg = enemy->dmg - (randRange(1, 2));
    printf("\n-> %s attacks for %d!\n", enemy->name, dmg);
    player->hp -= dmg;
}

void enemysTurn(struct Player *player, struct Enemy *enemy)
{
    enemyAttack(player, enemy);
}
