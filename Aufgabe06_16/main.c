#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, max, summe=0;

    printf("Bitte Maximum eingeben: ");
    scanf("%d", &max);

    for (i=2; i<=max; i++)
    {
        if (i%2 == 1)
            continue;
        summe += i;
    }

    printf("Summe aller geraden Zahlen von 2 bis %d: %d", max,summe);
}
