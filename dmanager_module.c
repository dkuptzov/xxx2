#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

//#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

struct door {
        int id;
        int status;
};

void initialize_doors(struct door* doors);

int main()
{
	struct door doors[DOORS_COUNT];
	initialize_doors(doors);

	for (int i = 0; i < DOORS_COUNT - 1; i++)
	{
		for (int j = 0; j < DOORS_COUNT - 1 - i; j++)
		{
			if (doors[j].id > doors[j + 1].id)
			{
				struct door temp = doors[j];
				doors[j] = doors[j + 1];
				doors[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < DOORS_COUNT; i++)
		doors[i].status = 1;

	return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors)
{
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++)
    {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}
