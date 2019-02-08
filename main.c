#include <battle.h>

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

    struct Spell *spells[10] = { 0 };
    spells[0] = fire;
    spells[1] = ice;

    // CREATE PLAYER
    struct Player *player;
    player = setupPlayer(player, broadsword, skullcap, breastplate, spells);

	// CREATE ENEMY
    struct Enemy *enemy;
    enemy = setupEnemy(enemy);

    // MAIN LOOP
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

