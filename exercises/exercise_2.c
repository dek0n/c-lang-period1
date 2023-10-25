#include <stdio.h>
int main()
{
    float income_array[12];
    float tax_array[12];
    float tax_below;
    float tax_above;
    float income_limit;
    float income_total = 0.0;
    char headers[][10] = {
        "month",
        "income",
        "tax"};
    printf("Enter tax:\n");
    scanf("%f", &tax_below);
    printf("Enter limit:\n");
    scanf("%f", &income_limit);
    printf("Enter tax above limit\n");
    scanf("%f", &tax_above);
    for (int i = 0; i <= 11; i++)
    {
        printf("Enter income for month %d :", i + 1);
        scanf("%f", &income_array[i]);
        income_total += income_array[i];
        if (income_total <= income_limit)
        {
            tax_array[i] = income_array[i] / 100 * tax_below;
        }
        else
        {
            tax_array[i] = (income_total - income_limit) / 100 * tax_above + (income_array[i] - (income_total - income_limit)) / 100 * tax_below;
            income_limit = income_total;
        }
    }
    printf("%5s%10s%10s\n", headers[0], headers[1], headers[2]);
    for (int i = 0; i <= 11; i++)
    {
        printf("%5d%10.2f%10.2f\n", i + 1, income_array[i], tax_array[i]);
    }

    return 0;
}
