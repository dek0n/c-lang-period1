#include <stdio.h>
#include <string.h>

int main()
{
    char filename[100];
    FILE *file;

    printf("Enter the file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Failed to open the file.\n"); // Error if failed to open file
        return 1;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        if (line[0] == '$')
        {
            int checksum = 0;
            int i;

            for (i = 1; line[i] != '*' && line[i] != '\0'; i++) // while i is not '*' AND i is not '\0'
            {
                checksum ^= line[i]; // bitwise XOR (^=) operation
            }

            int expected_checksum;
            if (sscanf(&line[i + 1], "%2X", &expected_checksum) == 1)
            {
                if (checksum == expected_checksum)
                {
                    printf("[ OK ] %s", line);
                }
                else
                {
                    printf("[FAIL] %s", line);
                }
            }
            else
            {
                printf("[FAIL] %s", line);
            }
        }
    }

    fclose(file);
    printf("\n");
    return 0;
}
