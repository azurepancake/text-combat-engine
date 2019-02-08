#include "helpers.h"

int randRange(int low, int high)
{
    srand(time(NULL));
    int num = rand() % (high + 1 - low) + low;

    return num;
}
