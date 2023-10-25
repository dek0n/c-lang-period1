#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int read_range(int low, int high)
{
    int user_input = 0;
    do
    {
        printf("Enter a menu position between %d and %d: ", low, high);
        if (scanf("%d", &user_input) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input!\n");
        }
        else if (user_input >= low && user_input <= high)
        {
            return user_input;
        }
        else
        {
            printf("Invalid input!\n");
        }
    } while (user_input < low || user_input > high);
    return user_input;
};

int print_menu(void)
{
    printf("Select an operation from the menu. \n");
    printf("1. Roll D6\n");
    printf("2. Roll D10\n");
    printf("3. Quit.\n");
    return 0;
}

int random_roll(int max_value)
{
    srand(time(NULL));
    int number = rand() % max_value + 1;
    return number;
}
int main()
{
    int range_low = 1;
    int range_high = 3;
    int user_input = 0;
    int result;
    print_menu();
    do
    {
        user_input = read_range(range_low, range_high);
        if (user_input == 1)
        {
            result = random_roll(6);
            printf("You rolled %d\n", result);
        }
        else if (user_input == 2)
        {
            result = random_roll(10);
            printf("You rolled %d\n", result);
        }
        else
        {
            printf("Bye!");
            user_input = 3;
        }
    } while (user_input != 3);
    return 0;
}