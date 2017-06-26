#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("----- Roemische Zahlen -------------------\n");

    printf("\nDas Programm stellt einen Aufzaehlungstyp fuer roemische Zahlen vor.\n\n");

    // Variante 1
    enum roem_zahlen {I = 1, II, III, IV, V, VI, VII, VIII, IX, X};
    enum roem_zahlen rom1, rom2;

    /* Variante 2
    * enum roem_zahlen {I = 1, II, III, IV, V, VI, VII, VIII, IX, X} rom1, rom2;
    */

    /* Variante 3
    * typedef enum roem_zahlen {I = 1, II, III, IV, V, VI, VII, VIII, IX, X} ROMZAHLEN;
    * ROMZAHLEN rom1, rom2;
    */

    rom1 = II;
    rom2 = VI;

    // Arithmetische Operationen
    printf("II + VI = %d\n", rom1 + rom2);
    printf("VI - II = %d\n", rom2 - rom1);
    printf("II * VI = %d\n", rom1 * rom2);
    printf("VI / II = %d\n\n", rom2 / rom1);

    // Vergleiche
    if (rom1 == II)
        printf("rom1 = II\n");
    if (rom2 == VI)
        printf("rom2 = VI");

    /* Zuweisung einer Zahl, die nicht in enum aufgefuehrt ist */
    printf("\n\nZuweisungen an Variable des Aufzaehltyps.");
    printf("\nZuweisung der Zahl 20, die keine Aufzaehlungskonstante ist.");
    rom1 = 20;
    printf("\n  Ist der Compiler nachsichtig? rom1 = %d\n", rom1);

    /* Zuweisung eines falschen Datentyps */
    printf("\nZuweisung einer float-Zahl.");
    rom1 = 1.111F;
    printf("\n  Ist der Compiler nachsichtig? rom1 = %f", rom1);
    printf("\n  Bei Zuweisung von float-Konstanten Wert-Verfaelschung!");

    return 0;
}
