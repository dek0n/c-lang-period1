#include "functions.h"

int main()
{
    /*User input*/
    char room_selected[SIZE_ROOMNAME];        // Declaration of the array for room name
    input_name(room_selected, SIZE_ROOMNAME); // Input name to the array

    /*CSV file processing*/
    FILE *file_temperatures;                          // Declaring file
    file_temperatures = fopen(FILE_NAME, "r");        // Opening file
    file_open_check_1(file_temperatures);             // Checking for opening errors
    reading_csv_header(SIZE_LINE, file_temperatures); // Reading CSV file header with checking syntax
    CsvRow data_rows[SIZE_ROWS];                      // Initializingrray of row structures
    int data_tokens_read = 0;
    int data_row_number = 0;
    do
    {
        data_tokens_read = fscanf(file_temperatures, FORMAT_STRING, &data_rows[data_row_number].column_1, data_rows[data_row_number].column_2);
        if (data_tokens_read == 2)
            data_row_number++;
        if (ferror(file_temperatures))
        {
            printf("Error reading file!\n");
            ;
            return 1;
        }
        if (data_row_number>=SIZE_ROWS)
        {
            printf("Error! File is too large, increase SIZE_ROWS.\n"); // Or add dynamic mameory allocation.
            ;
            return 1;
        }
    } while (!feof(file_temperatures));
    fclose(file_temperatures); // Close the file

    /*Output*/
    int scale_temperature_size = -1;
    int room_not_found = 0;
    for (int i = 0; i < data_row_number; i++)
    {
        remove_trailing_spaces(data_rows[i].column_2);
        if (strcasecmp(room_selected, data_rows[i].column_2) == 0) // Comparing case-insensitive
        {
            scale_temperature_size = (int)(data_rows[i].column_1 / TEMPERATURE_STEP);
            printf("%.1f ", data_rows[i].column_1);
            if (scale_temperature_size < 0 || scale_temperature_size > ((int)(TEMPERATURE_MAX / TEMPERATURE_STEP)))
            {
                printf("X");
            }
            else
            {
                for (int i = 0; i != scale_temperature_size; i++)
                {
                    printf("-");
                }
            }
            printf("\n");
            scale_temperature_size = -1;
            room_not_found = 1;
        }
    }
    if (room_not_found == 0)
    {
        printf("Room '%s' was not found in '%s'.\n", room_selected, FILE_NAME);
    }

    return 0;
}
