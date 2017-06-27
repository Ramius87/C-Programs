#include <stdio.h>
#include <stdlib.h>

int main()
{
    // lokale Variablen
    unsigned int index = 0;
    float fahrenheit = 0.0;
    float celsius = 0.0;

    printf("------- Celsius-Fahrenheit-Rechner -------\n");

    while (index != 3)
    {
        printf("1. Von Celsius zu Fahrenheit berechnen\n");
        printf("2. Von Fahrenheit zu Celsius berechnen\n");
        printf("3. Programm beenden\n\n");

        printf("Auswahl: ");
        scanf("%u",&index);

        if (index == 1)
        {
            printf("\nFahrenheit: ");
            scanf("%f",&fahrenheit);
            celsius = (fahrenheit/1.8) - (160.0/9.0);
            printf("\n%.2f Fahrenheit entsprechen %.2f Grad Celsius\n\n",
                   fahrenheit,celsius);
        } else if (index == 2)
        {
            printf("\nCelsius: ");
            scanf("%f",&celsius);
            celsius = (1.8*celsius) + 32;
            printf("\n%.2f Grad Celsius entsprechen %.2f Fahrenheit\n\n",
                   celsius, fahrenheit);
        }
    }


    return 0;
}
