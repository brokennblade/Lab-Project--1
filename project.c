#include <stdio.h>

#define ZONE 6

void decoration();
void points(float arr[][8]);
void zone_condition(float arr[][8]);
void priority_level(float arr[][8]);
void supply_status(float arr[][8]);

int main()
{
    int i, j, k;
    int search;
    int found = 0;
    
    float zone[ZONE][8] =
    {
        {1, 4000, 3000, 2, 0, 0, 0, 0},
        {2, 3500, 2500, 4, 1, 0, 0, 0},
        {3, 4500, 2000, 8, 2, 0, 0, 0},
        {4, 3800, 1800, 12, 3, 0, 0, 0},
        {5, 2600, 1600, 5, 1, 0, 0, 0},
        {6, 2000, 1500, 1, 0, 0, 0, 0}
    };

    float shortage[ZONE];
    float available = 13500;


    /*
    Current Zone Data
    */

    decoration();

    printf("\n");

    printf("Zone | Requested | Minimum | Loss%% | Waiting | Points\n");

    for(i = 0; i < ZONE; i++)
    {
        printf("%.0f\t%.0f\t\t%.0f\t\t%.0f\t%.0f\t\t%.0f\n",
               zone[i][0],
               zone[i][1],
               zone[i][2],
               zone[i][3],
               zone[i][4],
               zone[i][5]);
    }


    /*
    Calculate Points
    */

    points(zone);

    printf("\nPriority Points:\n\n");

    printf("Zone | Waiting Days | Points\n");

    for(i = 0; i < ZONE; i++)
    {
        printf("%.0f\t%.0f\t\t%.0f\n",
               zone[i][0],
               zone[i][4],
               zone[i][5]);
    }


    /*
    Sorting Whole Table
    */

    for(i = 0; i < ZONE; i++)
    {
        for(j = 0; j < ZONE - 1; j++)
        {
            if(zone[j][5] < zone[j + 1][5])
            {
                for(k = 0; k < 8; k++)
                {
                    float temp;

                    temp = zone[j][k];

                    zone[j][k] = zone[j + 1][k];

                    zone[j + 1][k] = temp;
                }
            }
        }
    }


    printf("\n");

    for(i = 0; i < 90; i++)
    {
        printf("_");
    }

    printf("\n");

    printf("ZONE PRIORITY DATA\n\n");

    printf("Zone | Requested | Minimum | Waiting | Points\n");

    for(i = 0; i < ZONE; i++)
    {
        printf("%.0f\t%.0f\t\t%.0f\t\t%.0f\t\t%.0f\n",
               zone[i][0],
               zone[i][1],
               zone[i][2],
               zone[i][4],
               zone[i][5]);
    }


    /*
    Minimum Allocation
    */

    printf("\nMINIMUM WATER ALLOCATION\n");

    for(i = 0; i < 90; i++)
    {
        printf("_");
    }

    printf("\n");

    for(i = 0; i < ZONE; i++)
    {
        if(available >= zone[i][2])
        {
            zone[i][6] = zone[i][2];

            available = available - zone[i][2];
        }
        else
        {
            zone[i][6] = available;

            available = 0;

            break;
        }
    }


    printf("Zone | Minimum | Allocated\n");

    for(i = 0; i < ZONE; i++)
    {
        printf("%.0f\t%.0f\t\t%.0f\n",
               zone[i][0],
               zone[i][2],
               zone[i][6]);
    }

    printf("\nWater Remaining = %.2f\n", available);


    /*
    Extra Allocation
    */

    printf("\nREMAINING WATER ALLOCATION\n");

    for(i = 0; i < 90; i++)
    {
        printf("_");
    }

    printf("\n");

    for(i = 0; i < ZONE; i++)
    {
        float extra;

        extra = zone[i][1] - zone[i][6];

        if(available >= extra)
        {
            zone[i][6] = zone[i][6] + extra;

            available = available - extra;
        }
        else if(available > 0)
        {
            zone[i][6] = zone[i][6] + available;

            available = 0;

            break;
        }
    }


    printf("Zone | Requested | Allocated\n");

    for(i = 0; i < ZONE; i++)
    {
        printf("%.0f\t%.0f\t\t%.2f\n",
               zone[i][0],
               zone[i][1],
               zone[i][6]);
    }


    /*
    Delivery Calculation
    */

    printf("\nWATER DELIVERY AFTER LOSS\n");

    for(i = 0; i < 90; i++)
    {
        printf("_");
    }

    printf("\n");

    for(i = 0; i < ZONE; i++)
    {
        float loss;

        loss = zone[i][6] * zone[i][3] / 100;

        zone[i][7] = zone[i][6] - loss;
    }


    printf("Zone | Allocated | Loss%% | Delivered\n");

    for(i = 0; i < ZONE; i++)
    {
        printf("%.0f\t%.2f\t\t%.0f\t%.2f\n",
               zone[i][0],
               zone[i][6],
               zone[i][3],
               zone[i][7]);
    }


    /*
    Shortage
    */

    printf("\nFINAL WATER STATUS\n");

    for(i = 0; i < 90; i++)
    {
        printf("_");
    }

    printf("\n");

    printf("Zone | Requested | Delivered | Shortage\n");

    for(i = 0; i < ZONE; i++)
    {
        shortage[i] = zone[i][1] - zone[i][7];

        printf("%.0f\t%.0f\t\t%.2f\t\t%.2f\n",
               zone[i][0],
               zone[i][1],
               zone[i][7],
               shortage[i]);
    }


    /*
    Zone Condition
    */

    printf("\nZONE CONDITION\n");

    zone_condition(zone);


    /*
    Total Summary
    */

    {
        float total_request = 0;
        float total_allocate = 0;
        float total_delivery = 0;
        float total_shortage = 0;

        for(i = 0; i < ZONE; i++)
        {
            total_request = total_request + zone[i][1];

            total_allocate = total_allocate + zone[i][6];

            total_delivery = total_delivery + zone[i][7];

            total_shortage = total_shortage + shortage[i];
        }

        printf("\nTOTAL SUMMARY\n");

        for(i = 0; i < 90; i++)
        {
            printf("_");
        }

        printf("\n");

        printf("Total Requested = %.2f\n", total_request);
        printf("Total Allocated = %.2f\n", total_allocate);
        printf("Total Delivered = %.2f\n", total_delivery);
        printf("Total Shortage = %.2f\n", total_shortage);
    }


    /*
    Search Zone
    */

    printf("\nZONE LIST\n\n");

    for(i = 0; i < ZONE; i++)
    {
        printf("%.0f = Zone %.0f\n",
               zone[i][0],
               zone[i][0]);
    }

    printf("\nEnter Zone Code: ");

    scanf("%d", &search);


    for(i = 0; i < ZONE; i++)
    {
        if(search == (int)zone[i][0])
        {
            printf("\nZONE INFORMATION\n");

            printf("Zone Code : %.0f\n", zone[i][0]);
            printf("Requested : %.2f\n", zone[i][1]);
            printf("Minimum   : %.2f\n", zone[i][2]);
            printf("Allocated : %.2f\n", zone[i][6]);
            printf("Delivered : %.2f\n", zone[i][7]);
            printf("Shortage  : %.2f\n", shortage[i]);

            found = 1;
        }
    }

    if(found == 0)
    {
        printf("\nZone Not Found!\n");
    }


    /*
    Highest Shortage
    */

    {
        float highest = shortage[0];
        int position = 0;

        for(i = 1; i < ZONE; i++)
        {
            if(shortage[i] > highest)
            {
                highest = shortage[i];

                position = i;
            }
        }

        printf("\nHIGHEST SHORTAGE\n");

        printf("Zone %.0f has highest shortage.\n",
               zone[position][0]);

        printf("Shortage Amount = %.2f\n",
               highest);
    }


    /*
    Final Priority
    */

    printf("\nFINAL PRIORITY LIST\n");

    priority_level(zone);


    /*
    Water Supply Status
    */

    printf("\nWATER SUPPLY CONDITION\n");

    supply_status(zone);

    return 0;
}


/*
Priority Point Function
*/

void points(float arr[][8])
{
    int i;

    for(i = 0; i < ZONE; i++)
    {
        arr[i][5] = 0;

        if(arr[i][4] == 1)
        {
            arr[i][5] = 3;
        }
        else if(arr[i][4] == 2)
        {
            arr[i][5] = 5;
        }
        else if(arr[i][4] >= 3)
        {
            arr[i][5] = 7;
        }
    }
}


/*
Zone Condition
*/

void zone_condition(float arr[][8])
{
    int i;

    for(i = 0; i < ZONE; i++)
    {
        if(arr[i][6] == 0)
        {
            printf("Zone %.0f : Unserved\n", arr[i][0]);
        }
        else if(arr[i][7] >= arr[i][1])
        {
            printf("Zone %.0f : Full Supply\n", arr[i][0]);
        }
        else if(arr[i][7] >= arr[i][2])
        {
            printf("Zone %.0f : Minimum Satisfied\n", arr[i][0]);
        }
        else
        {
            printf("Zone %.0f : Below Minimum\n", arr[i][0]);
        }
    }
}


/*
Priority Level
*/

void priority_level(float arr[][8])
{
    int i;

    for(i = 0; i < ZONE; i++)
    {
        printf("Priority %d = Zone %.0f (Points: %.0f)\n",
               i + 1,
               arr[i][0],
               arr[i][5]);
    }
}


/*
Supply Status
*/

void supply_status(float arr[][8])
{
    int i;

    for(i = 0; i < ZONE; i++)
    {
        if(arr[i][7] >= arr[i][1])
        {
            printf("Zone %.0f = Full Water Supplied\n",
                   arr[i][0]);
        }
        else if(arr[i][7] >= arr[i][2])
        {
            printf("Zone %.0f = Minimum Water Supplied\n",
                   arr[i][0]);
        }
        else if(arr[i][6] > 0)
        {
            printf("Zone %.0f = Partial Supply\n",
                   arr[i][0]);
        }
        else
        {
            printf("Zone %.0f = No Water Supplied\n",
                   arr[i][0]);
        }
    }
}


/*
Decoration
*/

void decoration()
{
    int i;

    printf("CURRENT WATER DISTRIBUTION DATA\n");

    for(i = 0; i < 90; i++)
    {
        printf("_");
    }
}