#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define SIZE_ARRAY_MAX_ITEMS 40
#define SIZE_NAME_LENGTH 60
#define SIZE_LINE_LENGTH 80

typedef struct menu_item_
{
    char name[SIZE_NAME_LENGTH];
    double price;
} menu_item;

int compare_name(const void *a, const void *b)
{
    const menu_item *item1 = (const menu_item *)a;
    const menu_item *item2 = (const menu_item *)b;
    return strcmp(item1->name, item2->name);
}

int compare_price(const void *a, const void *b)
{
    const menu_item *item1 = (const menu_item *)a;
    const menu_item *item2 = (const menu_item *)b;
    if (item1->price < item2->price)
        return -1;
    else if (item1->price > item2->price)
        return 1;
    else
        return 0;
}

int main()
{
    char filename[20];
    FILE *file;
    menu_item menu_array[SIZE_ARRAY_MAX_ITEMS];
    int count_items = 0;
    char line[SIZE_LINE_LENGTH];

    printf("Enter filename: ");
    if (scanf("%s", filename) != 1)
    {
        fprintf(stderr, "Failed to open '%s'.\n", filename);
        return 1;
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Failed to open '%s'.\n", filename);
        return 1;
    }

    while (count_items < SIZE_ARRAY_MAX_ITEMS && fgets(line, sizeof(line), file) != NULL)
    {
        char *delimiter_semicolon = strchr(line, ';');
        if (delimiter_semicolon != NULL)
        {
            *delimiter_semicolon = '\0';
            delimiter_semicolon++;
            char *endptr;
            double price = strtod(delimiter_semicolon, &endptr);
            if (*endptr == '\n' || *endptr == '\0')
            {
                strncpy(menu_array[count_items].name, line, SIZE_NAME_LENGTH);
                menu_array[count_items].name[SIZE_NAME_LENGTH - 1] = '\0';
                menu_array[count_items].price = price;
                count_items++;
            }
        }
    }

    fclose(file);

    int choice;
    do
    {
        printf("Choose sorting order:\n");
        printf("1. Sort by name\n");
        printf("2. Sort by price\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2))
        {
            fprintf(stderr, "Invalid input. Please enter 1 or 2.\n");
            while (getchar() != '\n')
                ; // Clear input buffer
        }
    } while (choice != 1 && choice != 2);

    if (choice == 1)
    {
        qsort(menu_array, count_items, sizeof(menu_item), compare_name);
    }
    else if (choice == 2)
    {
        qsort(menu_array, count_items, sizeof(menu_item), compare_price);
    }

    printf("\nSorted Menu:\n");
    for (int i = 0; i < count_items; i++)
    {
        printf("%-8.2lf %s\n", menu_array[i].price, menu_array[i].name);
    }

    return 0;
}
