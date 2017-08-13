#include <stdio.h>
#include <stdlib.h>

// Typdefinitionen
typedef struct
{
    int zaehler;
    int nenner;
} BRUCH;

// Prototypen
int  ggT(int a, int b);
int  kgV(int a, int b);
void erweitern(BRUCH *bruch, int hauptnenner);
void kuerzen(BRUCH *bruch);

int main()
{
    BRUCH bruch1, bruch2, summe;
    int hauptnenner;

    printf("Berechnung der Summe von 2 Bruechen\n");
    printf("\nBruch 1\n");
    printf("Zaehler: ");
    scanf("%d",&(bruch1.zaehler));
    printf("Nenner: ");
    scanf("%d",&(bruch1.nenner));
    printf("\nBruch 2\n");
    printf("Zaehler: ");
    scanf("%d",&(bruch2.zaehler));
    printf("Nenner: ");
    scanf("%d",&(bruch2.nenner));

    printf("\n%d/%d + %d/%d = ", bruch1.zaehler, bruch1.nenner, bruch2.zaehler, bruch2.nenner);
    hauptnenner = kgV(bruch1.nenner, bruch2.nenner);
    erweitern(&bruch1, hauptnenner);
    erweitern(&bruch2, hauptnenner);
    summe.zaehler = bruch1.zaehler + bruch2.zaehler;
    summe.nenner = hauptnenner;
    kuerzen(&summe);
    printf("%d/%d\n", summe.zaehler, summe.nenner);


    return 0;
}

int  ggT(int a, int b)
{
    int rest;

    do
    {
        rest = a % b;
        a = b;
        b = rest;
    }
    while (rest != 0);

    return a;
}
int  kgV(int a, int b)
{
    int kgV;

    kgV = a * b / ggT(a,b);

    return kgV;
}

void erweitern(BRUCH *bruch, int hauptnenner)
{
    bruch->zaehler *= (hauptnenner / bruch->nenner);
    bruch->nenner = hauptnenner;
}

void kuerzen(BRUCH *bruch)
{
    int divisor;

    divisor = ggT(bruch->zaehler, bruch->nenner);

    if (divisor != 1)
    {
        bruch->zaehler /= divisor;
        bruch->nenner /= divisor;
    }
}
