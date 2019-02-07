#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

struct Enemy *setupEnemy(struct Enemy *enemy);
void enemysAttack(struct Player *player, struct Enemy *enemy);
void enemysTurn(struct Player *player, struct Enemy *enemy);

#endif
