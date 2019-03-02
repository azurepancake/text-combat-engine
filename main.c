#include "intro.h"
#include "caverns.h"
#include "enemy.h"
#include "player.h"
#include "helpers.h"

int main()
{
	// Weapons
	struct Weapon *dagger;
	dagger = malloc(sizeof(struct Weapon));
	dagger->mindmg = 1;
	dagger->maxdmg = 3;
	dagger->owned = 1;
	strcpy(dagger->name, "Dagger");

	struct Weapon *stick;
	stick = malloc(sizeof(struct Weapon));
	stick->mindmg = 3;
	stick->maxdmg = 4;
	stick->owned = 0;
	strcpy(stick->name, "Wooden Stick");

	struct Weapon *broadsword;
	broadsword = malloc(sizeof(struct Weapon));
	broadsword->mindmg = 3;
	broadsword->maxdmg = 8;
	broadsword->owned = 0;
	strcpy(broadsword->name, "Broadsword");

	struct Weapon *longsword;
	longsword = malloc(sizeof(struct Weapon));
	longsword->mindmg = 10;
	longsword->maxdmg = 20;
	longsword->owned = 0;
	strcpy(longsword->name, "Longsword");

	// Create an array of all weapons
	struct Weapon *weapons[] = { dagger, stick, broadsword, longsword };

	// Head armor
	struct Armor *skullcap;
	skullcap = malloc(sizeof(struct Armor));
	skullcap->def = 3;
	skullcap->owned = 1;
	strcpy(skullcap->name, "Skull Cap");

	struct Armor *leathercap;
	leathercap = malloc(sizeof(struct Armor));
	leathercap->def = 1;
	leathercap->owned = 1;
	strcpy(leathercap->name, "Leather Cap");

	// Create an array of all head armor
	struct Armor *headarmor[] = { skullcap, leathercap };

	// Chest armor
	struct Armor *breastplate;
	breastplate = malloc(sizeof(struct Armor));
	breastplate->def = 5;
	breastplate->owned = 1;
	strcpy(breastplate->name, "Breastplate");

	struct Armor *leathercuirass;
	leathercuirass = malloc(sizeof(struct Armor));
	leathercuirass->def = 3;
	leathercuirass->owned = 1;
	strcpy(leathercuirass->name, "Leather Cuirass");

	struct Armor *chestarmor[] = { breastplate, leathercuirass };

	// Spells
	struct Spell *fire;
	fire = malloc(sizeof(struct Spell));
	fire->dmg = 10;
	fire->mp = 5;
	fire->learned = 0;
	strcpy(fire->name, "Fire");

	struct Spell *ice;
	ice = malloc(sizeof(struct Spell));
	ice->dmg = 5;
	ice->mp = 5;
	ice->learned = 0;
	strcpy(ice->name, "Ice");

	struct Spell *heal;
	heal = malloc(sizeof(struct Spell));
	heal->dmg = -10;
	heal->mp = 5;
	heal->learned = 0;
	strcpy(heal->name, "Heal");

	struct Spell *earth;
	earth = malloc(sizeof(struct Spell));
	earth->dmg = 10;
	earth->mp = 8;
	earth->learned = 0;
	strcpy(earth->name, "Earth");

	// Create array of all spells
	struct Spell *spells[] = { fire, ice, heal, earth };

	// Items
	struct Item *potion;
	potion = malloc(sizeof(struct Item));
	potion->dmg = -10;
	potion->quantity = 1;
	potion->index = 0;
	strcpy(potion->name, "Potion");

	struct Item *ether;
	ether = malloc(sizeof(struct Item));
	ether->dmg = -10;
	ether->quantity = 1;
	ether->index = 1;
	strcpy(ether->name, "Ether");

	struct Item *bomb;
	bomb = malloc(sizeof(struct Item));
	bomb->dmg = 25;
	bomb->quantity = 25;
	bomb->index = 2;
	strcpy(bomb->name, "Bomb");

	// Create array of all items
	struct Item *items[] = { potion, ether, bomb };

	// Create player character
	struct Player *player;
	player = setupPlayer(player, dagger, skullcap, breastplate, spells, items, weapons, headarmor, chestarmor);

	// Setup inventory structure
	struct Inventory *inventory;
	inventory = malloc(sizeof(struct Inventory));
	inventory->weapons = weapons;
	inventory->headarmor = headarmor;
	inventory->chestarmor = chestarmor;
	inventory->items = items;
	inventory->spells = spells;

	//startIntro();
	startCaverns(player, inventory);

	return 0;
}
