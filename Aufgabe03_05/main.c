#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define PI 3.14159
#define Durchmesser 20.7
#define Radius (Durchmesser/2)
#define MwSt 16
#define Temperatur 37.0
#define Satz "Hallo da bin ich."

int main()
{
    printf("Kreisumfang: %.2f\n",PI*Durchmesser);
    printf("Kreisflaeche: %.2f\n", PI*Radius*Radius);
    printf("Mehrwertsteuer: %d\n", 100*100/MwSt);
    printf("Temperatur: %.1f Grad Celsius\n", Temperatur);
    printf(Satz);

    return 0;
}
