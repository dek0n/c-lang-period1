#include <stdio.h>
#include <stdlib.h> // Memory allocation functions here
#include <string.h>

typedef struct node
{
    int number;
    struct node *next;
} nnode;

nnode *create_node(int data)
{
    nnode *new_node = (nnode *)malloc(sizeof(nnode));
    if (new_node == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    new_node->number = data;
    new_node->next = NULL;
    return new_node;
}

int main()
{
    nnode *head = NULL;
    nnode *tail = NULL;

    while (1)
    {
        char input[100];
        printf("Enter a number or 'end' to stop: ");
        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            perror("Input error");
            exit(EXIT_FAILURE);
        }

        if (strcmp(input, "end\n") == 0)
        {
            break;
        }
        else
        {
            int num;
            char extra;
            if (sscanf(input, "%d%c", &num, &extra) == 2 && extra == '\n')
            {
                nnode *new_node = create_node(num);
                if (head == NULL)
                {
                    head = new_node;
                    tail = new_node;
                }
                else
                {
                    tail->next = new_node;
                    tail = new_node;
                }
            }
            else
            {
                printf("Invalid input.\n");
            }
        }
    }

    printf("Numbers: ");
    nnode *current = head;
    while (current != NULL)
    {
        printf("%d ", current->number);
        nnode *temp = current;
        current = current->next;
        free(temp);
    }
    printf("\n");

    return 0;
}
