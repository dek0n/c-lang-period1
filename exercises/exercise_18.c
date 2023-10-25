#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // Randomizer seed

    while (1)
    {
        int user_input;
        printf("Enter a number from 0 to 15 or a negative number to stop: ");
        if (scanf("%d", &user_input) == 1)
        {

            if (user_input < 0)
            {
                break; // Stop the program
            }

            if (user_input >= 0 && user_input <= 15)
            {
                int random_hex = rand() % 256; // Generate a random number between 0 and 255 (0xFF)
                printf("Random hexadecimal number: 0x%02X\n", random_hex);

                // Shift right by the user's input and clear all other bits except bits 0-5
                int shifted_hex = (random_hex >> user_input) & 0x3F;
                printf("Shifted hexadecimal number: 0x%02X\n", shifted_hex);
            }
            else
            {
                printf("Number is > 15.\n");
            }
        }
        else
        {
            printf("Wrong input. Input an integer.\n");

            while (getchar() != '\n')
                ; // Clear the input buffer
        }
    }

    return 0;
}
