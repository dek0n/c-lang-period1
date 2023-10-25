#include <stdio.h>

int main()
{
    int price_bus;
    int price_taxi;
    int budget;
    int selection;

    printf("Enter price of bus ticket: ");
    scanf("%d\n", &price_bus);
    printf("Enter price of taxi ride: ");
    scanf("%d\n", &price_taxi);
    printf("How much money do you have: ");
    scanf("%d\n", &budget);
    while (budget >= price_bus || budget >= price_taxi)
    {

        printf("Do you want to take\n");
        printf("1) bus\n");
        printf("2) taxi\n");
        printf("Enter your selection: \n");
        scanf("%d", &selection);
        if (selection == 1)
        {
            printf("You chose bus\n");
            if (budget < price_bus)
            {
                printf("You don't have enough money for bus. Choose another variant.\n");
            }
            else
            {
                budget -= price_bus;
                printf("There is %d money left\n", budget);
            }
        }
        else if (selection == 2)
        {
            printf("You chose taxi\n");
            if (budget < price_taxi)
            {
                printf("You don't have enough money for taxi. Choose another variant.\n");
            }
            else
            {
                budget -= price_taxi;
                printf("There is %d money left\n", budget);
            }
        }
        else
        {
            printf("Invalid selection. Please choose 1 or 2.\n");
        }
    }
    printf("You have no budget to ride and need to walk. Bye\n");
    return 0;
}