#include <stdio.h>
#include <stdlib.h>

// Benannte Konstanten
#define PI 3.14

// Prototypen
float berechneFlaeche(float radius);
float berechneUmfang(float radius);

int main()
{
    int auswahl;
    float r;

    printf("Programm zur Kreisberechnung\n\n");
    printf("1 - Kreisflaeche\n");
    printf("2 - Kreisumfang\n\n");

    printf("Bitte Berechnungsart durch Eingabe der Nummer: ");
    scanf("%d", &auswahl);

    printf("\nBitte gewuenschten Radius eingeben: ");
    scanf("%f",&r);

    if (auswahl == 1)
        printf("Kreisflaeche = %02.2f",berechneFlaeche(r));
    else
        printf("Kreisumfang = %02.2f",berechneUmfang(r));

}

float berechneUmfang(float radius)
{
    return PI * 2 * radius;
}

float berechneFlaeche(float radius)
{
    return PI * radius * radius;
}
