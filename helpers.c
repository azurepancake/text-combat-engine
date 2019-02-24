#include "helpers.h"

void help(char *hint)
{
	printf("\n----------\n");
	printf("Help:");
	printf("\n----------\n");
	printf("Enter words to describe what you want to do.\n\n");
	printf("Hint: %s\n\n", hint);
	printf("There are several keywords you can use anywhere:\n");
	printf("* return -> Return to previous area\n");
	printf("* equip -> Manage your equipment\n");
	printf("* items -> Manage your items\n");
	printf("* magic -> Manage your spells\n");
	printf("* locate -> Describe your immediate environment");
}

char *scanner(const char **keywords, int amount)
{
	printf("\n\nWhat do you do?\n> ");
	char *input = malloc(MAX_INPUT_SZ);
	fgets(input, MAX_INPUT_SZ, stdin);

	char word[MAX_INPUT_SZ];
	int count = 0;
	int i;

	// loop through input string
	for(i = 0; i <= strlen(input); i++) {

		// add characters into word array until we hit a space (indicating end of word)
		if(input[i] != ' ') {
			// if we hit a new line character, skip it
			if(input[i] == '\n') {
				continue;
			}
			word[count] = input[i];
			count++;
		}

		// if we hit space or \0, we have a full word
		if(input[i] == ' ' || input[i] == '\0') {
			word[count] = '\0';

			// iterate through keywords and find match
			for(int i = 0; i < amount; i++) {

				if(strcmp(word, keywords[i]) == 0) {
					free(input);
					return (char *)keywords[i];
				}
			}

			count = 0;
			memset(word, 0, MAX_INPUT_SZ);
		}
	}
	free(input);
	return "nomatch";
}

void typeout(char *text)
{
	int length;
	length = strlen(text);

	for(int i = 0; i < length; i++) {
		usleep(50000);
		putchar(text[i]);
		fflush(stdout);
	}
}

int reverseNegative(int x)
{
	if(x <= 0) {
		x = x * -1;
	}

	return x;
}

int randRange(int low, int high)
{
	srand(time(NULL));
	int num = rand() % (high + 1 - low) + low;

	return num;
}

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
