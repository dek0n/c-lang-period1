#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

char random_character()
{
    const char printable_characters[] = "!\"#$&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
    int len = strlen(printable_characters);
    return printable_characters[rand() % len];
}

bool random_password(char **ppword, const char *word)
{
    int word_len = strlen(word);
    if (word_len > 33)
    {
        printf("Error. The word should be max 32 characters.\n");
        return false;
    }

    int pword_len = (word_len - 1) * 2 + 1; // max 32*2 = 64 + 1 for /0 = max 65

    *ppword = (char *)malloc(pword_len * sizeof(char)); 

    if (*ppword == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    (*ppword)[0] = random_character();
    int pword_index = 1;

    for (int i = 0; i < word_len; i++)
    {
        (*ppword)[pword_index++] = word[i];
        (*ppword)[pword_index++] = random_character();
    }

    (*ppword)[pword_len - 1] = random_character();
    (*ppword)[pword_len] = '\0';

    return true;
}

int main()
{
    srand(time(NULL)); // randomizer seed

    char *word = NULL;
    char *pword = NULL;

    while (1)
    {
        printf("Enter a word to generate a password or 'stop' to quit: ");
        if (getline(&word, &(size_t){0}, stdin) == -1)
        {
            perror("Input error");
            exit(EXIT_FAILURE);
        }

        if (strcmp(word, "stop\n") == 0)
        {
            break;
        }
        else
        {
            if (random_password(&pword, word))
            {
                printf("Generated password: %s\n", pword);
                free(pword);
                pword = NULL;
            }
        }
    }

    free(word);
    word = NULL;

    return 0;
}
