#include "caverns.h"

void startCaverns(struct Player *player, struct Inventory *inventory)
{
	struct Caverns *caverns;
	caverns = malloc(sizeof(struct Caverns));
	caverns->hint = "The darkness calls you..";

	printf("\nLoading caverns binary");
	typeout("........ ");
	printf("OK!\n\n\n");
	printf("//// T H E  C A V E R N S ////\n");

	bool locate = 1;
	for(;;) {
		if(locate) {
			printf("\nYou now stand at the southern end of a large cavern.. Around the outskirts of the main area which you stand are passage ways:\n\n");
			printf("The passage to the East appears to be closed off by large, thick vines.\n\n");

			if(! caverns->phasefour) {
				printf("The passage to the North is blocked by raging flames.\n\n");
			} else {
				printf("The passage to the North is no longer guarded by flames.\n\n");
			}

			printf("The passage to the West is gaping wide open, however is full of darkness.");
			locate = 0;
		}
		char *word;
		const char *keywords[] = { "north", "east", "south", "west", "help", "locate", "equip" };
		int length = (sizeof(keywords) / sizeof(*keywords));
		word = scanner(keywords, length);

		if(strcmp(word, "east") == 0) {
			eastCavernsEntrance(player, inventory, caverns);
			locate = 1;

		} else if(strcmp(word, "west") == 0) {
			westCavernsEntrace(player, inventory, caverns);
			locate = 1;

		} else if(strcmp(word, "north") == 0) {
			northCavernsEntrance(player, inventory, caverns);
			locate = 1;

		} else if(strcmp(word, "help") == 0) {
			help(caverns->hint);

		} else if(strcmp(word, "locate") == 0) {
			locate = 1;

		} else if(strcmp(word, "equip") == 0) {
			playerEquip(player);
			getchar();

		} else {
			printf("\nPlease try again.. Type 'help' for options..");
		}
	}
}
