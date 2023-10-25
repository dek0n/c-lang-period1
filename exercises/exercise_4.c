#include <stdio.h>
int read_integer(void)
{
    int input_int = 0;
    do
    {
        printf("Enter a positive integer or any negative number to stop: ");
        if (scanf("%d", &input_int) != 1)
        {
            while (getchar() != '\n')
                ;
            printf("Invalid input!\n");
        }
    } while (input_int == 0);
    return input_int;
}

int main()
{
    int number;
    int counter = 0;
    float average = 0.0;
    do
    {
        number = read_integer();
        if (number > 0)
        {
            average += number;
            counter++;
        }
    } while (number > 0);
    average = average / counter;
    printf("You entered %d positive numbers. The average is: %.3f\n", counter, average);
    return 0;
}