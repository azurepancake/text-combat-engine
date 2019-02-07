#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "helpers.h"
#include "player.h"
#include "enemy.h"

int main()
{
    // Setup weapons
    struct Weapon *broadsword;
    broadsword = malloc(sizeof(struct Weapon));
    broadsword->dmg = 3;
    strcpy(broadsword->name, "Broadsword");

    // Setup head armor
    struct Armor *skullcap;
    skullcap = malloc(sizeof(struct Armor));
    skullcap->def = 3;
    strcpy(skullcap->name, "Skull Cap");

    // Setup chest armor
    struct Armor *breastplate;
    breastplate = malloc(sizeof(struct Armor));
    breastplate->def = 5;
    strcpy(breastplate->name, "Breastplate");

    // Setup spells
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

    struct Spell *spells[10] = { 0 };
    spells[0] = fire;
    spells[1] = ice;

    // Create player
    struct Player *player;
    player = setupPlayer(player, broadsword, skullcap, breastplate, spells);

    // Create enemy
    struct Enemy *enemy;
    enemy = setupEnemy(enemy);

    // Main loop
    int state;
    while(state != 1) {
        state = playersTurn(player, enemy);
        if(state == 0) {
            enemysTurn(player, enemy);
        }
    }

    struct Weapon *weaponList[] = { broadsword };
    struct Armor *armorList[] = { skullcap, breastplate };
    struct Spell *spellList[] = { fire, ice };

    cleanUpMemory(weaponList, armorList, spellList, player, enemy);

    return 0;
}
