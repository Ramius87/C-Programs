#include <stdio.h>
#include <stdlib.h>                    /* wg. exit() */
#include <conio.h>                     /* wg. getch() */

#define  MAXZ 13             /* max. Zeilenzahl des Pascalschen Dreiecks*/
#define  PAUSE {printf("\nRETURN!\n");fflush(stdin); getchar();}

void compute_pd_zeile(int i, int max);

unsigned int pd_zeile[MAXZ+1];

int main(void)
{
    /* lokale Variablen */
    int maxzeilen, i;

    /* Anweisungen */

    /* Information */
    printf("\n\tProgramm berechnet PASCALsches Dreieck - d.h. die "
           "\n\tBinomialkoeffizienten n ueber i := n!/((n-i)!*i!) "
           "\n\tfuer i = 0,...,n, wobei n = 0,...,maxzeilen - 1"
           "\n=======================================================================");

    /* Eingabe */
    printf("\nBitte gewuenschte Zeilenanzahl (1 <= maxzeilen <= 13) angeben: ");
    scanf("%d",&maxzeilen);

    if (maxzeilen < 1 || maxzeilen > MAXZ)
    {
		printf("\nUnzulaessige Zeilenzahl"); exit(1);
	}

    printf("\n--------------- Pascalsches Dreieck mit %2d Zeile(n) -------------------",
           maxzeilen);

    printf("\n     i=");
    for (i = 0; i <= maxzeilen - 1; i++)
         i == 0 ? printf("%4d",i) : printf("%5d",i);

    /* Berechnung und Ausgabe durch Aufruf rekursiver Funktion */
    compute_pd_zeile(0, maxzeilen-1);

    printf("\n-----------------------------------------------------------------------");
    PAUSE;
    return 0;
}

/* Funktion berechnet n-te Zeile des Pascalschen Dreiecks */
void compute_pd_zeile(int n, int max)
{
    /* lokale Variablen */
    int i, oben_links, oben_rechts;

    /* Anweisungen */
    /* neue Zeile berechnen und ausgeben */
    printf("\nn=%2d ->", n);
    oben_links = 0;                      /* Koeff. oben-links init. */
    for (i = 0; i <= n; i++)             /* fuer alle i ab 0 bis n */
    {
       if (i < n)                      /* nicht letzter Koeff. */
       {
           oben_rechts = pd_zeile[i];  /* Koeff. oben-rechts sichern */
                                       /* neuen Koeff. n ueber i ermitteln */
           pd_zeile[i] = oben_links + oben_rechts;
           oben_links = oben_rechts;   /* Koeff. oben-links aktual. */
       }
       else pd_zeile[i] = 1;           /* letzter Koeff. n ueber n = 1 */
           printf(" %3d ", pd_zeile[i]);
    }

    /* ggf. naechste Zeile berechnen */
    if (n < max)                         /* wenn noch eine Zeile zu berechnen*/
        compute_pd_zeile(n+1,max);       /* rekursiver Aufruf */
}
