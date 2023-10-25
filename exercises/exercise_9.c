#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void random_seed() // Initializing a random number generator for random_roll function, use it once in main()
{
    srand(time(NULL));
}

int random_roll(int max_value) // Random number function, set max_value in main()
{
    int number = rand() % max_value + 1;
    return number;
}

int find_first(const unsigned int *array, unsigned int what)
{
    for (int i = 0; *array != 0; i++)
    {
        if (*array == what)
        {
            printf("Found on  index [%d] \n", i);
            return 0;
        }
        array++;
    }
    printf("Not found\n");
    return 0;
}

void print_numbers(const int *array, int count)
/* Print values of an array one per row except last(here 0)
(set print filed size in printf()) arguments (array name, array size)*/
{
    for (int i = 0; i != count - 1; i++)
    {
        printf("%2d\n", *array);
        array++;
    }
}

unsigned int read_range()
{
    int user_input = 0;
    bool confirmation = false;
    do
    {
        printf("Enter the unsigned number to serach or 0 to stop: ");
        if (scanf("%d", &user_input) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input!\n");
        }
        else
        {
            confirmation = true;
        }
    } while (!(confirmation));
    return user_input;
};

int main()
{
    int user_input;
    random_seed();
    const int max_value = 20;
    const int array_size = 20;
    int the_array[array_size];
    for (int i = 0; i != array_size - 1; i++)
    {
        the_array[i] = random_roll(max_value);
    }
    the_array[array_size - 1] = 0;
    print_numbers(the_array, array_size);
    do
    {
        user_input = read_range();
        if (user_input == 0)
        {
            printf("Bye!\n");
            return 0;
        }
        else
        {
            find_first(the_array, user_input);
        }

    } while (user_input != 0);
}