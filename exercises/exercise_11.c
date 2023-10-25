/* Input string to modify and 2-character string to replace one character on another*/
#include <stdio.h>
#include <string.h>

struct Replaced
// Initializing structure for the result
{
    char string[50];
    int number;
};

struct Replaced replace_char(char *str, const char *repl)
// Modification function
{
    struct Replaced modification;
    modification.number = 0;

    size_t len = strlen(str);

    for (int i = 0; i != len - 1; i++)
    {
        if (str[i] == repl[0])
        {
            str[i] = repl[1];
            modification.number++;
        }
        modification.string[i] = str[i];
    }
    return modification;
}

int main()
{
    // Initializing and input
    char string_to_modify[64];
    char string_modificator[3];
    printf("Enter the first string TO modify: \n");
    fgets(string_to_modify, sizeof(string_to_modify), stdin);

    printf("Enter the modificator string (2 characters): \n");
    fgets(string_modificator, sizeof(string_modificator), stdin);

    // Initializing struct using function
    struct Replaced result = replace_char(string_to_modify, string_modificator);

    // Conditions
    if (result.number == 0)
    {
        printf("The string was NOT modified.\n");
    }
    else
    {
        printf("The string was modified with %d characters:\n", result.number);
        printf("%s\n", result.string);
    }
    return 0;
}