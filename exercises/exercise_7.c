#include <stdio.h>
#include <stdbool.h>

bool read_positive(int *value)
{
    printf("Enter a positive number: ");
    if (scanf("%d", value) != 1)
    {
        while (getchar() != '\n')
            ;
        printf("Invalid input!\n");
        return false;
    }
    else if (*value > 0)
    {

        return true;
    }
    else
    {
        printf("Invalid input!\n");
        return false;
    }
}
int main()
{
    int user_input;
    bool true_false;
    int counter = 0;
    do
    {
        printf("Guess how much I have!\n");
        true_false = read_positive(&user_input);
        if (true_false == true)
        {

            printf("You didn't get it right! I have %d e\n", (user_input * 2) + 20);
        }
        if (true_false == false)
        {
            counter++;
        }
    } while (counter != 3);
    printf("I give up! See you later!\n");
    return 0;
}