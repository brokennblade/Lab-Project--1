#include <stdio.h>
#include <string.h>
void decoration();
void idn_stock_condtion(int arr[][8]);
void Points(int p[][8]);
void priority_level(int p[][8]);
void shortage_expiry(int p[][8]);
int main()

{
    int search, Add, amount, amount1, issue;
    int med[6][8] = {{0, 120, 35, 80, 45, 3}, {1, 300, 40, 100, 120, 2}, {2, 60, 12, 50, 30, 3}, {3, 200, 25, 80, 20, 3}, {4, 250, 18, 60, 15, 1}, {5, 180, 15, 50, 90, 1}};
    // Medicine Covergae
    for (int i = 0; i < 6; i++)
    {
        med[i][6] = (med[i][1]) / (med[i][2]);
    }
    // // Essential point condition Ends Here;
    decoration();
    printf("\n");

    printf("Code| Available Stock| Avg Daily Requirment| Minimum Stock |DR to Exp |    ES Level |     Coverage Days| Priority Points\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d\t\t", med[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 120; i++)
    {
        printf("_");
    }
    printf("\n");
    idn_stock_condtion(med);
    printf(
        "\n\n");
    printf("stock and Expiry Status:\n");
    shortage_expiry(med);

    printf(
        "\n\n");
    printf("List of Medicine :-\n\n");
    printf("0.Oral Saline\n1.Paracetamol\n2.Insulin\n3.Amoxicillin\n4.Antacid\n5.Cetirizine\n\n");
    printf("Enter Medicine Code: ");
    scanf("%d", &search);
    if (search == 0)
    {
        printf("Oral Saline - \n");
        printf("Code| Available Stock| Avg Daily Requirment| Minimum Stock |DR to Exp |    ES Level |     Coverage Days| Priority Points\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d\t\t", med[0][i]);
        }
    }
    if (search == 1)
    {
        printf("Paracetaml - \n");
        printf("Code| Available Stock| Avg Daily Requirment| Minimum Stock |DR to Exp |    ES Level |     Coverage Days| Priority Points\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d\t\t", med[1][i]);
        }
    }
    if (search == 2)
    {
        printf("Insulin - \n");
        printf("Code| Available Stock| Avg Daily Requirment| Minimum Stock |DR to Exp |    ES Level |     Coverage Days| Priority Points\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d\t\t", med[2][i]);
        }
    }
    if (search == 3)
    {
        printf("Amoxicillin - \n");
        printf("Code| Available Stock| Avg Daily Requirment| Minimum Stock |DR to Exp |    ES Level |     Coverage Days| Priority Points\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d\t\t", med[3][i]);
        }
    }
    if (search == 4)
    {
        printf("Antacid - \n");
        printf("Code| Available Stock| Avg Daily Requirment| Minimum Stock |DR to Exp |    ES Level |     Coverage Days| Priority Points\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d\t\t", med[4][i]);
        }
    }
    if (search == 5)
    {
        printf("Cetirizine - \n");
        printf("Code| Available Stock| Avg Daily Requirment| Minimum Stock |DR to Exp |    ES Level |     Coverage Days| Priority Points\n");
        for (int i = 0; i < 8; i++)
        {
            printf("%d\t\t", med[5][i]);
        }
    }
    printf("\n");
    printf("Do u want to Add any Stocks?\n 'Y' for yes and 'N' for no -- ");
    getchar();
    char input = getchar();
    // printf("Do you wish to Add medicine to stocks?\nYes or No\n");

    if (input == 'Y' || input == 'y')
    {
        printf("Enter for Medicine Code you want to Add Stock At -- ");
        scanf("%d", &Add);
        printf("Add stock amount -- ");
        scanf("%d", &amount);
        med[Add][1] += amount;
    }
    else
    {
        printf("\n");
    }
    printf("Any medicine Being Issued?\n Y for Yes and N for No --");
    getchar();
    char input1 = getchar();
    // printf("Do you wish to Add medicine to stocks?\nYes or No\n");

    if (input1 == 'Y' || input1 == 'y')
    {
        printf("Enter for Medicine Code thats being Issued -- ");
        scanf("%d", &issue);
        printf("Add stock amount -- ");
        scanf("%d", &amount1);
        med[issue][1] -= amount1;
    }
    else
    {
        printf("\n");
    }
    for (int i = 0; i < 6; i++)
    {
        med[i][6] = (med[i][1]) / (med[i][2]);
    }
    Points(med);
    // now sorting whole table;

    printf("Stock Update after addition/issue\n");

    printf("\n");
    for (int i = 0; i < 120; i++)
    {
        printf("_");
    }
    printf("\n");
    printf("Code| Available Stock| Avg Daily Requirment| Minimum Stock |DR to Exp |    ES Level |     Coverage Days| Priority Points\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d\t\t", med[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 120; i++)
    {
        printf("_");
    }
    printf("\n\n");
    idn_stock_condtion(med);
    printf("stock and Expiry Status:\n");
    shortage_expiry(med);

    printf("final Stock Update\n");

    //sorting
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {

            
            if (med[j][7] < med[j + 1][7])
            {

                
                for (int k = 0; k < 8; k++)
                {
                    int x = med[j][k];
                    med[j][k] = med[j + 1][k];
                    med[j + 1][k] = x;
                }
            }
        }
    }
    printf("\n");
    printf("Code| Available Stock| Avg Daily Requirment| Minimum Stock |DR to Exp |    ES Level |     Coverage Days| Priority Points\n");
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d\t\t", med[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 120; i++)
    {
        printf("_");
    }
    printf("\n");
    idn_stock_condtion(med);
    printf("\n");
    priority_level(med);
    printf("\n");
    printf("stock and Expiry Status:\n");
    shortage_expiry(med);

    return 0;
    // }
}

void idn_stock_condtion(int arr[][8])
{

    for (int i = 0; i < 6; i++)
    {
        if (arr[i][1] > arr[i][3])
        {
            if (arr[i][4] <= 30)
            {
                printf("medicine%d : Expiery Risk!\n", i);
            }
            else
            {
                printf("medicine%d : Sufficient Stock\n", i);
            }
        }
        else
        {
            if (arr[i][4] < 15)
            {
                if (arr[i][5] == 3)
                {
                    printf("medicine%d : Critical Condition.\n", i);
                }
                else
                {
                    printf("medicine%d : Urgent Order.\n", i);
                }
            }
            else
            {
                printf("medicine%d : Reorder Required\n", i);
            }
        }
    }
}

void Points(int p[][8])
{
    // Reset priority points before recalculating
    for (int i = 0; i < 6; i++)
        p[i][7] = 0;

    for (int i = 0; i < 6; i++)
    {
        if (p[i][1] == p[i][3]) p[i][7] += 1;
        else if (p[i][1] < p[i][3]) p[i][7] += 2;

        if (p[i][5] == 3) p[i][7] += 3;
        else if (p[i][5] == 2) p[i][7] += 2;
        else p[i][7] += 1;

        if (p[i][6] <= 3) p[i][7] += 2;
        else if (p[i][6] <= 7) p[i][7] += 1;

        if (p[i][4] <= 15) p[i][7] += 3;
        else if (p[i][4] < 30) p[i][7] += 2;
    }
}

void priority_level(int p[][8])
{
    for (int i = 0; i < 6; i++)
    {
        printf("Priority Level %d = medCode%d (Points: %d)\n",
               i + 1, p[i][0], p[i][7]);
    }
}

void decoration()
{
    printf("Current Medicine Stock Status:\n");
    for (int i = 0; i < 120; i++)
    {
        printf("_");
    }
}
void shortage_expiry(int p[][8])
{
    for (int i = 0; i < 6; i++)
    {
        int low_exp_date = 30;
        if (p[i][1] > p[i][3])
        {
            if (p[i][4] <= low_exp_date)
            {

                printf("medCode%d = Expiry Risk!\n", p[i][0]);
            }
            else
            {
                printf("medCode%d = No Shortage & expiry Risk!\n", p[i][0]);
            }
        }
        else
        {
            if (p[i][4] < low_exp_date)
            {
                printf("MedCode%d = Shortage & Expiery Risk\n", p[i][0]);
            }
            else
            {
                printf("MedCode%d = Shortage Risk\n", p[i][0]);
            }
        }
    }
}