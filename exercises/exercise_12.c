/* Input string to modify and word to count occurrence*/
#include <stdio.h>
#include <string.h>

int count_words(const char *str, const char *word)
// Word counting function
{
    int counter = 0;
    const char *pos = str;
    char stop_word[5] = "stop";
    if (strcmp(word, stop_word) == 0)
    {
        counter = -1;
    }

    else
    {
        while ((pos = strstr(pos, word)) != NULL)
        {
            counter++;
            pos += strlen(word);
        }
        printf("The word '%s' occures in the string %d times.\n", word, counter);
    }
    return counter;
}

int main()
{
    // Initializing and input
    char string_input[64];
    char word_input[64];

    int result = 0;
    do
    {
        printf("Enter the string: \n");
        fgets(string_input, sizeof(string_input), stdin);

        printf("Enter the word to search: \n");
        fgets(word_input, sizeof(word_input), stdin);

        size_t len = strlen(word_input);
        if (word_input[len - 1] == '\n')
        {
            word_input[len - 1] = '\0';
        }

        result = count_words(string_input, word_input);
    } while (result >= 0);
    printf("Program stopped\n");
    return 0;
}