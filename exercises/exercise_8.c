#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void random_seed() // Initializing a random number generator for random_roll function
{
    srand(time(NULL));
}

int random_roll(int max_value)
{
    int number = rand() % max_value + 1;
    return number;
}

void print_numbers(const int *array, int count)
{
    for (int i = 0; i != count; i++)
    {
        printf("%8d\n", *array);
        array++;
    }
}
int main()
{
    random_seed();
    const int max_value = 99999999;
    const int array_size = 15;
    int the_array[array_size];
    for (int i = 0; i != array_size; i++)
    {
        the_array[i] = random_roll(max_value);
    }
    print_numbers(the_array, array_size);
    return 0;
}