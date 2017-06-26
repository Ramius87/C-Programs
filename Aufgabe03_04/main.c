#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int MAX = 100;
    const float PI = 3.14159;
    const float Durchmesser = 20.7;
    const float Radius = Durchmesser/2;
    const float MwSt = 16;
    const float Temperatur = 37.0;
    const char Satz[] = "Hallo da bin ich.\n";

    printf("Kreisumfang: %.2f\n",PI*Durchmesser);
    printf("Kreisflaeche: %.2f\n", PI*Radius*Radius);
    printf("Mehrwertsteuer: %.2f\n", 100*100/MwSt);
    printf("Temperatur: %.1f Grad Celsius\n", Temperatur);
    printf(Satz);

    return 0;
}
