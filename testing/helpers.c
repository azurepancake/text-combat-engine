void cleanUpMemory(struct Weapon **weaponList, struct Armor **armorList, struct Spell **spellList, struct Player *player, struct Enemy *enemy)
{
    int i;
    int length;

    // Free up weapon memory
    length = sizeof(weaponList) / sizeof(*weaponList);
    for(i = 0; i <= length; i++) {
        free(weaponList[i]);
    }

    // Free up armor memory
    length = sizeof(armorList) / sizeof(*armorList);
    for(i = 0; i <= length; i++) {
        free(armorList[i]);
    }

    // Free up spell memory
    length = sizeof(spellList) / sizeof(*spellList);
    for(i = 0; i <= length; i++) {
        free(spellList[i]);
    }

    free(player);
    free(enemy);
}

int randRange(int low, int high)
{
    srand(time(NULL));
    int num = rand() % (high + 1 - low) + low;

    return num;
}
