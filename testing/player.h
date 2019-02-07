#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

struct Player *setupPlayer(struct Player *player, struct Weapon *weapon, struct Armor *head, struct Armor *chest, struct Spell **spells);
int setupArmor();
int playersTurn(struct Player *player, struct Enemy *enemy);
void playerAttack(struct Player *player, struct Enemy *enemy);
void playerSpell(struct Player *player, struct Enemy *enemy);

#endif
