#include "functions.h"

int clear_input_buffer()
// Clearing input buffer
{
    while ((getchar() != '\n' && getchar() != EOF))
        ;
}

void input_name(char *name, int max_length)
// Name input function
{
    bool confirmation = false;
    do
    {

        printf("Please, enter the room name (case-insensitive): ");

        if (fgets(name, max_length, stdin) != NULL)
        {
            size_t len = strlen(name);

            if (len > 0 && name[len - 1] == '\n') // Remove the newline character if present.
            {
                name[len - 1] = '\0';
            }
            else
            {
                clear_input_buffer();
            }

            confirmation = true;
        }
        else
        {
            printf("Invalid input! No input!\n");
            clear_input_buffer();
        }
    } while (!(confirmation));
}

void remove_trailing_spaces(char *str)
{
    int len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1]))
    {
        str[len - 1] = '\0';
        len--;
    }
}

int reading_csv_header(int size_of_line, FILE *file_name)
// Reading CSV header, parameters: (maximum size of line to read, name of target CSV file)
{
    char header[size_of_line];
    if (fgets(header, size_of_line, file_name) == NULL)
    {
        printf("Error! .csv header.\n");
        return 1;
    }
    return 0;
}

int file_open_check_1(FILE *file_name)
{
    if (file_name == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }
    return 0;
}