#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> // For toupper() function

#define SIZE_ARRAY_MAX_ITEMS 40
#define SIZE_NAME_LENGTH 60
#define SIZE_LINE_LENGTH 80

typedef struct menu_item_
{
    char name[SIZE_NAME_LENGTH];
    double price;
} menu_item;

int main()
{
    char filename[20];
    FILE *file;
    menu_item menu_array[SIZE_ARRAY_MAX_ITEMS]; // Array
    int count_items = 0;
    char line[SIZE_LINE_LENGTH]; // For reading lines

    printf("Enter filename: ");
    if (scanf("%s", filename) != 1)
    {
        fprintf(stderr, "Failed to open '%s' .\n", filename);
        return 1;
    }

    file = fopen(filename, "r"); // Read
    if (file == NULL)
    {
        fprintf(stderr, "Failed to open '%s' .\n", filename);
        return 1;
    }

    while (count_items < SIZE_ARRAY_MAX_ITEMS && fgets(line, sizeof(line), file) != NULL)
    {
        char *delimeter_semicolon = strchr(line, ';');
        if (delimeter_semicolon != NULL)
        {
            *delimeter_semicolon = '\0';
            delimeter_semicolon++; // Move to the price part
            char *endptr;
            double price = strtod(delimeter_semicolon, &endptr);
            if (*endptr == '\n' || *endptr == '\0')
            {
                // Successfully read name and price
                strncpy(menu_array[count_items].name, line, SIZE_NAME_LENGTH);
                menu_array[count_items].name[SIZE_NAME_LENGTH - 1] = '\0'; // Adding null terminator
                menu_array[count_items].price = price;
                count_items++;
            }
        }
    }

    fclose(file);

    for (int i = 0; i < count_items; i++)
    {
        printf("%-8.2lf %s\n", menu_array[i].price, menu_array[i].name);
    }

    return 0;
}
