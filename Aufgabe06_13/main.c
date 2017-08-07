#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,anz, booly = 1;

    printf("-------- Schachbrettmuster --------\n\n");

    printf("Geben Sie die Anzahl der Reihen ein: \n\n");
    scanf("%d", &anz);

    // Zeilen
    for (i = 0; i < anz; i++)
    {
        // Spalten
        for (j = 0; j < anz; j++)
        {
            if (booly)
            {
                putchar(32);
                putchar(32);
                booly = 0;
            } else {
                putchar(178);
                putchar(178);
                booly = 1;
            }
        }
        printf("\n");
        booly = !booly;
    }
    return 0;
}
