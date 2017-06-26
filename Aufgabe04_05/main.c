#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("-------- Formatierungen mit printf --------\n\n");

    int n = 12345;
    // linksbuendig mit Vorzeichen
    printf("<%+-07d>\n",n);
    // linksbuendig ohne Vorzeichen
    printf("<%-07d>\n",n);
    // rechtsbuendig mit Vorzeichen
    printf("<%+07d>\n",n);
    // rechtsbuendig ohne Vorzeichen
    printf("<%07d>\n\n",n);

    const float PI = 3.14159;
    // linksbuendig mit Vorzeichen
    printf("<%+-07.2f>\n",PI);
    // linksbuendig ohne Vorzeichen
    printf("<%-07.2f>\n",PI);
    // rechtsbuendig mit Vorzeichen
    printf("<%+07.2f>\n",PI);
    // rechtsbuendig ohne Vorzeichen
    printf("<%07.2f>\n\n",PI);

    float round = 5.9999999;
    printf("Rundungsfehler? : %.2f\n\n", round);

    char zk[] = "FernUni Hagen";
    // mindestens 10 Zeichen
    printf("%10s\n",zk);
    // mindestens 20 Zeichen rechtsbuendig
    printf("%20s\n",zk);
    // mindestens 20 Zeichen linkssbuendig
    printf("%-20s\n",zk);
    // maximal 10 Zeichen
    printf("%.10s\n",zk);
    // maximal 10 Zeichen in einem 20 Zeichen Bereich linkssbuendig
    printf("%-20.10s\n",zk);
    // maximal 10 Zeichen in einem 20 Zeichen Bereich rechtsbuendig
    printf("%20.10s\n\n",zk);

    char star = '*';
    printf("<%-7c>\n",star);
    printf("<%7c>\n\n",star);

    n = 123;
    printf("<%d>\n",n);
    printf("<%u>\n",n);
    printf("<%f>\n",n);
    printf("<%o>\n",n);
    printf("<%x>\n",n);
    printf("<%X>\n\n",n);

    // Steuer- und Sonderzeichen
    // horizontaler Tabulator
    printf("\t\n");
    // Wagenruecklauf
    printf("\r\n");
    // Klingelzeichen
    printf("\a\n");
    // Einfaches Hochkomma
    printf("\'\n");
    // Doppeltes Hochkomma
    printf("\"\n");
    // Backslash
    printf("\\\n");
    // Prozentzeichen
    printf("\%\n");
    // Zeilenvorlauf
    printf("\n\n");

    char string[] = "ist";
    char zeichen[] = ":";
    printf("Dies %s die Zahl Pi%s %.5f\n",string,zeichen,PI);

    return 0;
}
