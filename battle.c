#include "player.h"
#include "enemy.h"
#include "helpers.h"
#include "battle.h"

int battle(struct Player *player, struct Enemy *enemy)
{
	printf("\n//// F I G H T ////");

    // Enter main loop
    int state = 0;

    while(state == 0) {
	printf("\n"); // without this, enemy loops over and over.. weird..
	state = playersTurn(player, enemy);
  
		if(state == 0) {
			state = enemysTurn(player, enemy);
		}
	}

	return state;
}

