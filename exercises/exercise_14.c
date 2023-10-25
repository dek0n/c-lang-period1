#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> // For toupper() function

#define SIZE_ARRAY_MAX 100
#define SIZE_LINE_MAX 2
#define SIZE_COLUMN_MAX 100

int main()
{
    char lines_array[SIZE_ARRAY_MAX][SIZE_LINE_MAX][SIZE_COLUMN_MAX + 1]; // Array to store values +1 for \0
    char filename[20];
    FILE *file;
    int count_lines = 0;

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

    while (count_lines < SIZE_ARRAY_MAX && fgets(lines_array[count_lines], sizeof(lines_array[count_lines]), file) != NULL)
    {

        lines_array[count_lines][strcspn(lines_array[count_lines], "\n")] = '\0'; // Remove newline character

        for (int i = 0; lines_array[count_lines][i]; i++)
        {
            lines_array[count_lines][i] = toupper(lines_array[count_lines][i]); // Convert to uppercase
        }

        count_lines++;
    }

    fclose(file);

    file = fopen(filename, "w"); // Write
    if (file == NULL)
    {
        fprintf(stderr, "Failed to open '%s' for writing.\n", filename);
        return 1;
    }

    for (int i = 0; i < count_lines; i++)
    {
        fprintf(file, "%s\n", lines_array[i]);
    }
    fclose(file);

    return 0;
}
