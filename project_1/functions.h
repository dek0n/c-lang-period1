#include <stdio.h>  // 'f'open', 'fclose': Open and close files. 'fgets', 'fprintf': Read and write text data.
#include <stdlib.h> // 'malloc', 'free': Allocate and free memory, which can be useful for dynamic data storage when working with CSV data.
#include <string.h> // string manipulation when parsing CSV lines 'strtok': Tokenize strings, splitting CSV lines into individual values.
#include <stdbool.h>
#include <ctype.h>

#define SIZE_LINE 60
#define SIZE_ROWS 100 // maybe change to dynamic memory allocation

#define SIZE_TEMPERATURE 4
#define SIZE_ROOMNAME 30
#define FORMAT_STRING "%f,%30[^\n]" // for reading string of csv file formatted "00.0,Abcdef.."

#define SIZE_FILE_NAME 60
#define FILE_NAME "temperatures.csv"

#define TEMPERATURE_MIN 0.0
#define TEMPERATURE_MAX 30.0
#define TEMPERATURE_STEP 0.5

#define WIDTH_REPORT (int)(TEMPERATURE_MAX / TEMPERATURE_STEP)

typedef struct
{
    float column_1;
    char column_2[SIZE_ROOMNAME];
} CsvRow;

void input_name(char *name, int max_length);

void remove_trailing_spaces(char *str);

int reading_csv_header(int size_of_line, FILE *file_name);

int file_open_check_1(FILE *file_name);