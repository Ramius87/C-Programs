#include <stdio.h>
#include <stdlib.h>

// Typdefinitionen
typedef enum {sieben, acht, neun, zehn, Bube, Dame, Koenig, As} WERT;
typedef enum {karo, herz, pik, kreuz} FARBE;


int main()
{
    // lokale Variablen
    WERT wert;
    FARBE farbe;

    printf("Alle Karten eines Skatblattes:\n\n");

    for (farbe=karo; farbe<=kreuz; farbe++)
    {
        for (wert=sieben; wert<=As; wert++)
        {
            switch (farbe)
            {
                case karo: printf("Karo");
                break;
                case herz: printf("Herz");
                break;
                case pik: printf("Pik");
                break;
                case kreuz: printf("Kreuz");
                break;
            }
            switch (wert)
            {
                case sieben: printf("-Sieben\n");
                break;
                case acht: printf("-Acht\n");
                break;
                case neun: printf("-Neun\n");
                break;
                case zehn: printf("-Zehn\n");
                break;
                case Bube: printf("-Bube\n");
                break;
                case Dame: printf("-Dame\n");
                break;
                case Koenig: printf("-Koenig\n");
                break;
                case As: printf("-As\n");
            }
        }
    }
}
