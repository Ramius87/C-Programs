#include <stdio.h>
#include <stdlib.h>

#define GROESSE 4

int pruefeAnzahl(int quadrat[GROESSE][GROESSE])
{
    // Laufvariablen
    int index, i, j;
    // Anzahl der jeweiligen Zahl
    int anzahl;

    for (index = 1; index <= GROESSE*GROESSE; index++)
    {
        //Re-/initialisiere Anzahl der der Zahl index
        anzahl = 0;
        for (i = 0; i < GROESSE; i++)
        {
            for (j = 0; j < GROESSE; j++)
            {
                if (index == quadrat[i][j])
                {
                    anzahl++;
                }
            }
        }
        // Zahl kommt nicht oder mehrfach vor
        if (anzahl != 1)
            return 0;
    }
    // Alle Zahlen kommen genau einmal vor
    return 1;
}

int pruefeSummen(int quadrat[GROESSE][GROESSE])
{
    // Laufvariablen
    int i, j;
    int zeilensumme[GROESSE], spaltensumme[GROESSE];
    int diagonale1 = 0, diagonale2 = 0;

    // Berechnung Zeilen-/Spaltensummen
    for (i = 0; i < GROESSE; i++)
    {
        zeilensumme[i] = 0;
        spaltensumme[i] = 0;
        for (j = 0; j < GROESSE; j++)
        {
            zeilensumme[i] += quadrat[i][j];
            spaltensumme[i] += quadrat[j][i];
            if (i == j) diagonale1 += quadrat[i][j];
            if ((i+j)==3) diagonale2 += quadrat[i][j];
        }
    }

    if (diagonale1 != diagonale2)
        return 0;

    for (i = 0; i < GROESSE; i++)
    {
        if (zeilensumme[i] != diagonale1 ||
            spaltensumme[i] != diagonale1)
            return 0;
    }

    return 1;
}

int main()
{
    int summenOk, anzahlOk;
    // magisches Quadrat
    int quadrat[GROESSE][GROESSE] =
    {
        {16,3,2,13},{5,10,11,8},{9,6,7,12},{4,15,14,1}
    };

    printf("Test auf magisches Quadrat\n\n");

    summenOk = pruefeSummen(quadrat);
    anzahlOk = pruefeAnzahl(quadrat);

    if (summenOk && anzahlOk)
        printf("Das Quadrat ist ein magisches Quadrat.");
    else
        printf("Das Quadrat ist kein magisches Quadrat.");
    return 0;
}
