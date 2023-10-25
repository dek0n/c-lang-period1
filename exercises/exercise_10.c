#include <stdio.h>
#include <string.h>

int is_string_stop()
{
    char string_input[64];
    printf("Enter a string: \n");
    fgets(string_input, sizeof(string_input), stdin);
    size_t len = strlen(string_input);
    if (string_input[len - 1] == '\n')
    {
        string_input[len - 1] = '\0';
    }
    len = strlen(string_input); //updating length after removing '\n' mark

    char stop_string[5] = "stop";
    int comparison = strcmp(string_input, stop_string);
    if (comparison == 0)
    {
        return -1;
    }
    else
    {
        printf("The length of this string is %zu\n", len);
        return 0;
    }
}
int main()
{
    int response;
    do
    {
        response = is_string_stop();
    } while (response != -1);
    return 0;
}