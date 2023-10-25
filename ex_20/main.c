#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "debug.h"

int main()
{

    srand(time(NULL)); // Random seed

    int input_debug_level;
    printf("Enter debug level (0 - 4): ");
    scanf("%d", &input_debug_level);
    set_debug_level(input_debug_level);

    for (int i = 1; i <= 5; i++)
    {
        int random_level = rand() % 5; // Generate a random debug level (0 - 4)
        dprintf(random_level, "Message %d: BUG! \n", i);
    }

    return 0;
}
