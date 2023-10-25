#include <stdio.h>

int main()
{
    int students;
    int condition_number = 1;
    printf("How many students:\n");
    scanf("%d", &students);
    int students_array[students];
    for (int i = 0; i < students; i++)
    {
        students_array[i] = -1;
    }

    while (condition_number)
    {
        printf("Enter student number (1 - %d) or 0 to stop:\n", students);
        scanf("%d", &condition_number);
        if (condition_number == 0)
        {
            break;
        }
        else if (condition_number > students || condition_number < 0)
        {
            printf("Invalid student number!\n");
            condition_number = 1;
        }
        else
        {
            int grade = 0;
            while (!(grade == -1))
            {
                printf("Enter grade (0 - 5) for student %d or -1 to cancel:\n",condition_number);
                scanf("%d", &grade);
                if (grade >= 0 && grade <= 5)
                {
                    students_array[condition_number-1] = grade;
                    break;
                }
                else if (grade < 0 || grade > 5)
                {
                    if (grade == -1)
                    {
                        break;
                    }
                    else
                    {
                        printf("Invalid grade!\n");
                    }
                }
            }
        }
    }
    char headers[][10] = {
        "Student",
        "Grade"};
    printf("%-10s%-10s\n", headers[1], headers[2]);
    char text_na[] = "N/A";
    for (int i = 0; i < students; i++)
    {
        if (students_array[i] == -1)
        {
            printf("%-10d%-10s\n", i + 1, text_na);
        }
        else
        {
            printf("%-10d%-10d\n", i + 1, students_array[i]);
        }
    }

    return 0;
}