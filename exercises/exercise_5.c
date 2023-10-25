#include <stdio.h>
int read_range(int low, int high)
{
    int user_input = 0;
    do
    {
        printf("Roll a die and enter your result.\n");
        printf("Enter a number between %d and %d: ", low, high);
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

int main()
{
    printf("Let's play!\n");
    int range_low = 1;
    int range_high = 6;
    int user_roll;
    do
    {
        user_roll = read_range(range_low, range_high);
        if (user_roll != range_high)
        {
            printf("I got %d. I win!\n", user_roll + 1);
        }
    } while (user_roll != range_high);

    printf("I got %d. It's a tie!\n", user_roll);
    printf("Better luck nex time. Bye!\n");

    return 0;
}