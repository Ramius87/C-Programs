#include <stdio.h>
#include <stdlib.h>

int main()
{
    float kapital = 1000.0;
    float zinssatz = 0.1;
    int jahr = 1;

    printf("-------- Zinseszinstabelle --------\n\n");

    printf("Anfangskapital: %.2f\n",kapital);
    printf("Zinssatz: %.1f Prozent\n\n",zinssatz*100);

    printf("Jahr      Gesamtbetrag\n");
    printf("----------------------\n");

    while (jahr <= 10)
    {
        kapital *= (1+zinssatz);
        printf("%3d %15.2f\n",jahr,kapital);
        jahr++;
    }

    return 0;
}
