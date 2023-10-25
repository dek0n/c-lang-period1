#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    char filename[20];
    FILE *file;
    int number = 0;
    int count = 0;
    int lowest;
    int highest;
    bool first = true;

    printf("Enter filename: ");
    if (scanf("%s", filename) != 1)
    {
        fprintf(stderr, "Failed to open '%s' .\n", filename);
        return 1;
    }

    file = fopen(filename, "r"); // Linux
    if (file == NULL)
    {
        fprintf(stderr, "Failed to open '%s' .\n", filename);
        return 1;
    }

    lowest = highest = 0; // Initialize lowest and highest

    // Read integers from the file
    while (fscanf(file, "%d", &number) == 1)
    {
        if (first)
        {
            lowest = highest = number;
            first = false;
        }
        else
        {
            if (number < lowest)
            {
                lowest = number;
            }
            if (number > highest)
            {
                highest = number;
            }
        }
        count++;
    }

    // Check for reading errors or end of file
    if (!feof(file))
    {
        fprintf(stderr, "Failed to read from '%s'.\n", filename);
        fclose(file);
        return 1;
    }

    // Print results
    printf("Total %d numbers \n", count);
    printf("The lowest number: %d\n", lowest);
    printf("The highest number: %d\n", highest);

    // Close the file
    fclose(file);

    return 0;
}
