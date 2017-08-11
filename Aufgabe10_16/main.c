#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,vektor[20];

    printf("Vektorzugriff mittels Zeigern\n\n");

    printf("Vektor fuellen!\n");
    for (i=0;i<20;i++)
    {
        printf("%d. Zahl: ",i+1);
        scanf("%d",(vektor+i));
    }

    printf("\nVektor ausgeben!\n");
    for (i=0;i<20;i++)
    {
        printf("-%d-",*(vektor+i));
    }

    return 0;
}
