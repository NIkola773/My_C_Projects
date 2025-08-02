#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LOG 100
#define PRICE_PER_KWH 0.15
#define LIMIT 50

// Global consumption log
float consumptionLog[MAX_LOG];
int measurementCount = 0;

// Generates random energy consumption
float readConsumption()
{
    return (float)(rand() % 1000) / 100.0;
}

// Calculates cost of consumption
float calculateCost(float kwh)
{
    return kwh * PRICE_PER_KWH;
}

// Saves data to file
void saveToFile(float kwh, float cost)
{
    FILE *f = fopen("consumption_log.txt", "a");
    if (f != NULL)
    {
        time_t t = time(NULL);
        fprintf(f, "Time: %sConsumption: %.2f kWh, Cost: %.2f RSD\n\n", ctime(&t), kwh, cost);
        fclose(f);
    }
    else
    {
        printf("Error writing to file.\n");
    }
}

// Displays history of all measurements
void showLog()
{
    printf("\n--- Consumption History ---\n");
    for (int i = 0; i < measurementCount; i++)
    {
        printf("Measurement #%d: %.2f kWh\n", i + 1, consumptionLog[i]);
    }
    printf("----------------------------\n");
}

// Calculates voltage and power based on current and resistance
void calculateVoltageAndPower()
{
    float I, R, U, P;
    printf("Enter current (A): ");
    scanf("%f", &I);
    printf("Enter resistance (Ω): ");
    scanf("%f", &R);
    U = I * R;
    P = U * I;
    printf("Voltage: %.2f V\n", U);
    printf("Power: %.2f W\n", P);
}

int main()
{
    srand(time(NULL));
    int choice;

    while (1)
    {
        printf("\n=== Energy Monitor ===\n");
        printf("1 - Measure consumption\n");
        printf("2 - Calculate voltage and power\n");
        printf("3 - Show measurement log\n");
        printf("0 - Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            printf("Exiting program.\n");
            break;
        }

        switch (choice)
        {
        case 1:
        {
            float kwh = readConsumption();
            float cost = calculateCost(kwh);
            printf("Consumption: %.2f kWh\n", kwh);
            printf("Cost: %.2f RSD\n", cost);

            if (kwh > LIMIT)
                printf("WARNING: Consumption exceeds the allowed limit (%.2f > %d)!\n", kwh, LIMIT);
            else
                printf("Consumption is within normal limits.\n");

            if (measurementCount < MAX_LOG)
            {
                consumptionLog[measurementCount++] = kwh;
            }

            saveToFile(kwh, cost);
            break;
        }
        case 2:
            calculateVoltageAndPower();
            break;

        case 3:
            showLog();
            break;

        default:
            printf("Unknown option! Please try again.\n");
            break;
        }
    }

    return 0;
}
