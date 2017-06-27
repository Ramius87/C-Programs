/*
** Programm: Verwaltung von Kunden und Lieferanten
** Einsendearbeit zum Kurs Programmieren in C, SoSe2017
** Autor: WURZLER, STEFFEN.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Loescht Bildschirmseite
void ClrScr(void)
{
// lokale Variable
    int i;
// Bildschirmseite loeschen
    for (i = 1; i <= 25; i++)
        printf("\n");
}


// Wartet auf Tastendruck
void Tastendruck(void)
{
    printf("\nBitte Return druecken.");
    getchar();
}

/* --- */
/* --- Aufgabenteil (a) --- Typenvereinbarung --- */
/* --- */

// Boolscher Typ
typedef enum {FALSE, TRUE} BOOL;

// Art des Partners festlegen
typedef enum {kunde,lieferant} ART;

// Typdefinition einer Adresse
typedef struct
{
    char strasse[20];
    char hausnummer[6];
    char ort[20];
    char plz[6];
} ADRESSE;

typedef struct
{
    int Nr; // Kunden- bzw. Lieferantennummer
    char firmenname[20];
    ADRESSE anschrift;
    char ansprechpartner[20];
    float wert; // Bestell- bzw. Lieferantenwert
} PARTNER;


// Zeigertyp auf den Partnerknoten
typedef struct partnernode* PPARTNER;

struct partnernode
{
    PARTNER partner;
    PPARTNER left;
    PPARTNER right;
};

typedef struct partnernode PARTNERNODE;


PPARTNER kundeRoot; // Kundenbaum
int LetzteKundenNr;

PPARTNER lieferantRoot; // Lieferantenbaum
int LetzteLieferantenNr;

int AnzZeilen; // Hilfsvariable fuer Listenausgabe

/* --- Prototypen --- */
void Initialisierung(void);
void Hauptmenue(void);
void MenuePartnerErfassen(ART partnerart);
void MenuePartnerAnzeigen(ART partnerart, PPARTNER ppos);
void MenueWertAktualisieren(ART partnertyp);
void Outputlistenzeile(ART partnerart, PPARTNER partner);
BOOL insertPartner(ART partnerart, PARTNER partner);
PPARTNER getPartner(PPARTNER ppos, int Nr, char* Firmenname, int Modus);
void DateienEinlesen(void);
void DateienSchreiben(void);
void ClrScr(void);
void Tastendruck(void);

/* --- */
/* --- Aufgabenteil (b) --- Funktion (1) --- Hauptmenue */
/* --- */
void Hauptmenue(void)
{
    // lokale Variablen
    unsigned int eingabe;

    // Menue immer wieder anzeigen, bis das Programm beendet wird

    do
    {
        printf("Programm zur Verwaltung von Kunden und Lieferanten\n");
        printf("\nHauptmenue\n");
        printf("\n1. Kunde erfassen");
        printf("\n2. Lieferant erfassen");
        printf("\n3. Kundenliste anzeigen");
        printf("\n4. Lieferantenliste anzeigen");
        printf("\n5. Bestellwert aktualisieren");
        printf("\n6. Lieferwert aktualisieren");
        printf("\n7. Programm beenden\n");
        printf("\nBitte waehlen Sie die gewuenschte Funktion durch Eingabe der Nummer!");
        printf("\nBestaetigen Sie Ihre Eingabe mit RETURN:\n");

        scanf(" %u",&eingabe);
        switch (eingabe)
        {
        case 1:
            MenuePartnerErfassen(kunde);
            break;
        case 2:
            MenuePartnerErfassen(lieferant);
            break;
        case 3:
            AnzZeilen = 0;
            MenuePartnerAnzeigen(kunde, kundeRoot);
            break;
        case 4:
            MenuePartnerAnzeigen(lieferant, lieferantRoot);
            break;
        case 5:
            MenueWertAktualisieren(kunde);
            break;
        case 6:
            MenueWertAktualisieren(lieferant);
            break;
        case 7:
            printf("Programm wird beendet.");
            break;
        default:
            printf("Keine gueltige Eingabe");
            Tastendruck();
            break;
        }
    } while (eingabe != 7);

}
/* --- */
/* --- Aufgabenteil (b) --- Funktion (2) --- MenuePartnerErfassen */
/* --- */
void MenuePartnerErfassen(ART partnerart)
{
    // lokale Variablen
    PARTNER partner;
    BOOL erfolg;

    // Bildschirm leeren
    ClrScr();

    // ID des Partners festlegen
    if (partnerart == kunde)
    {
        partner.Nr = LetzteKundenNr + 1;
        printf("\nMenue Kunde erfassen");
        printf("\n--------------------\n");
        printf("\nKundenNr.: %u", partner.Nr);
    }
    else
    {
        partner.Nr = LetzteLieferantenNr + 1;
        printf("\nMenue Lieferant erfassen");
        printf("\n------------------------\n");
        printf("\nLieferantenNr.: %u", partner.Nr);
    }

    // Bestell- bzw. Lieferantenwert des Partners initialisieren
    partner.wert = 0.0;

    // Firmennamen einlesen
    printf("\nFirmenname:");
    scanf("%s", &partner.firmenname);

    // Anschrift einlesen
    // Strasse einlesen
    printf("\nStrasse:");
    scanf("%s", &partner.anschrift.strasse);
    // Hausnummer einlesen
    printf("\nHausnummer:");
    scanf("%s", &partner.anschrift.hausnummer);
    // PLZ einlesen
    printf("\nPLZ:");
    scanf("%s", &partner.anschrift.plz);
    // Ort einlesen
    printf("\nOrt:");
    scanf("%s", &partner.anschrift.ort);

    // Ansprechpartner einlesen
    printf("\nAnsprechpartner:");
    scanf("%s", &partner.ansprechpartner);

    // Partner in Binaerbaum einfuegen
    erfolg = insertPartner(partnerart, partner);

    if (!erfolg)
    {
        printf("\nFirmenname bereits vorhanden - Erfassen nicht moeglich!");
        Tastendruck();
        return;
    } else
    {
        if (partnerart == kunde)
            LetzteKundenNr++;
        else
            LetzteLieferantenNr++;
    }
}

/* --- */
/* --- Aufgabenteil (b) --- Funktion (3) --- MenuePartnerAnzeigen */
/* --- */
void MenuePartnerAnzeigen(ART partnerart, PPARTNER ppos)
{
    // symmetrische Traversierung des passenden Binaerbaumes
    // Anzeige aller Partner in alphabetischer Reihenfolge
    if (ppos != NULL)
    {
        MenuePartnerAnzeigen(partnerart,ppos->left);
        Outputlistenzeile(partnerart,ppos);
        MenuePartnerAnzeigen(partnerart,ppos->right);
    }

    // Meldung wenn Liste leer
    if (partnerart == kunde && kundeRoot == NULL ||
        partnerart == lieferant && lieferantRoot == NULL)
    {
        printf("\nKeine Partner vorhanden.");
        Tastendruck();
    }
    // am Listenende auf Tastendruck warten
    else if ((partnerart == kunde && kundeRoot == ppos) ||
             (partnerart == lieferant && lieferantRoot == ppos))
             {
                 Tastendruck();
             }
}


/* --- */
/* --- Aufgabenteil (b) --- Funktion (4) --- MenueWertAktualisieren */
/* --- */
void MenueWertAktualisieren(ART partnerart)
{
    // lokale Variablen
    PPARTNER curr = NULL, root = NULL;
    char firmenname[20];
    float wert = 0.0;;

    // Bildschirm leeren
    ClrScr();

    if (partnerart == kunde)
    {
        printf("\n5. Bestellwert aktualisieren");
        printf("\n----------------------------\n");
    }
    else
    {
        printf("\n6. Lieferwert aktualisieren");
        printf("\n---------------------------\n");
    }
    // zu aktualisierenden Partner bestimmen
    do
    {
        printf("\nFirmenname:");
        scanf("%s", &firmenname);
        // Wurzel des passenden Binaerbaums ermitteln
        root = partnerart == kunde ? kundeRoot : lieferantRoot;
        curr = getPartner(root, 0, firmenname, 1);
        if (curr == NULL)
        {
            if (partnerart == kunde)
                printf("\nKunde nicht vorhanden.");
            else
                printf("\Lieferant nicht vorhanden.");
            Tastendruck();
        }
    } while (curr == NULL);

    // Werterhoehung einlesen
    printf("\nWerterhoehung: ");
    scanf("%f",wert);
    // Wert des Partners updaten
    curr->partner.wert += wert;

}

/* --- */
/* --- Aufgabenteil (b) --- Funktion (5) --- Outputlistenzeile */
/* --- */
void Outputlistenzeile(ART partnerart, PPARTNER curr)
{
    // lokale Variablen
    // Nach 15 ausgegebenen Zeilen neueen Listenkopf ausgeben
    if (AnzZeilen % 15 == 0)
    {
    // Eventuell auf Tastendruck warten
    if (AnzZeilen != 0)
        Tastendruck();
        ClrScr();
    if (partnerart == kunde)
    {
        printf("\n3. Kundenliste anzeigen");
        printf("\n-----------------------\n");
        printf("\nNr. Firmenname Anrede/Name Wohnort");
        printf(" Bestellwert (Euro)\n");
    }
    else // Lieferanten
    {
        printf("\n4. Lieferantenliste anzeigen");
        printf("\n----------------------------\n");
        printf("\nNr. Firmenname Anrede/Name Wohnort");
        printf(" Lieferwert (Euro)\n");
    }
    }

    // Listenzeile mit Daten des Partners ausgeben
    printf("\n%-6u", curr->partner.Nr);
    printf("%-18s", curr->partner.firmenname);
    printf("%-20s", curr->partner.ansprechpartner);
    printf("%-15s", curr->partner.anschrift.ort);
    printf(" %.2f ", curr->partner.wert);
    // Ausgegebene Zeilen zaehlen
    AnzZeilen++;

}

/* --- */
/* --- Aufgabenteil (b) --- Funktion (6) --- insertPartner */
/* --- */
BOOL insertPartner(ART partnerart, PARTNER partner)
{
    // lokale Variablen
    PPARTNER root, curr, prev;
    int res;

    // Wurzel bestimmen
    root = partnerart == kunde ? kundeRoot : lieferantRoot;
    prev = curr = root;

    // Einfuegestelle suchen
    while (curr != NULL)
    {
        prev = curr;
        res = strcmp(curr->partner.firmenname, partner.firmenname);
        if (res > 0) // vorhander Name nach neuem Namen
            curr = curr->left;
        else if (res < 0)
            curr = curr->right;
        else
            return FALSE;
    }

    // neuen Baumknoten erzeugen
    curr = (PPARTNER)malloc(sizeof(PARTNERNODE));
    if (curr == NULL)
    {
        printf("\n Kein Speicher verfuegbar - Abbruch!");
        exit(99);
    }
    curr->partner = partner;
    curr->left = curr->right = NULL;

    // Baum ist leer
    if (root == NULL )
    {
        if (partnerart == kunde)
            kundeRoot = curr;
        else
            lieferantRoot = curr;
    } else
    {
        if (res > 0)
            prev->left = curr;
        else
            prev->right = curr;
    }
    return TRUE;
}

/* --- */
/* --- Aufgabenteil (b) --- Funktion (7) --- getPartner */
/* --- */
PPARTNER getPartner(PPARTNER ppos, int Nr, char* firmenname, int modus)
{
    // lokale Variablen
    PPARTNER next = NULL;

    // Teilbaum leer
    if (ppos == NULL)
        return NULL;

    // Wurzelelement des Teilbaums ist das gesuchte Element
    if ((modus == 0 && ppos->partner.Nr == Nr) ||
        (modus == 1 && !strcmp(ppos->partner.firmenname, firmenname)))
            return ppos;

    // im linken Teilbaum suchen
    if (modus == 0)
        next = getPartner(ppos->left, Nr, "", 0);
    else
        next = getPartner(ppos->left, 0, firmenname, 1);
    if (next != NULL)
        return next;

    // im rechten Teilbaum suchen
    if (modus == 0)
        next = getPartner(ppos->right, Nr, "", 0);
    else
        next = getPartner(ppos->right, 0, firmenname, 1);
    return next;
}

/* --- */
/* --- Aufgabenteil (b) --- Funktion (8) --- DateienEinlesen */
/* --- */
void DateienEinlesen(void)
{
    // lokale Variablen
    FILE* fp;
    int index;
    char c; // fuer \n-Zeichen!
    PARTNER Partner; // Kunde oder Lieferant
    BOOL erfolg;
    ART partnerart;

    // Bildschirm loeschen
    ClrScr();
    for (partnerart = kunde; partnerart <= lieferant; partnerart++)
    {
        // Dateien KUNDEN.DAT, LIEFERANTEN.DAT einlesen
        fp = partnerart == kunde ? fopen("KUNDEN.DAT", "r") : fopen("LIEFERANTEN.DAT", "r");
        if (fp == NULL)
        {
            if (partnerart == kunde)
            printf("\nDatei KUNDEN.DAT nicht lesbar!");
            else printf("\nDatei LIEFERANTEN.DAT nicht lesbar!");
        }
        else
        {
            // Datensaetze in jeweiligen Binaerbaum einlesen
            index = 0;
            while (fscanf(fp, "%6u %20s %20s %6s %20s %6s %20s %f%c",
                    Partner.Nr,
                    Partner.firmenname,
                    Partner.anschrift.strasse,
                    Partner.anschrift.hausnummer,
                    Partner.anschrift.ort,
                    Partner.anschrift.plz,
                    Partner.ansprechpartner,
                    Partner.wert,
                    c) != EOF)
            {
                index++;
                erfolg = insertPartner(partnerart, Partner);
                if (! erfolg)
                {
                    printf("\nFirmenname erscheint mehrfach!");
                    exit(99);
                }
            }
            fclose(fp);
            if (partnerart == kunde)
            {
                printf("\nDatei KUNDEN.DAT enthielt - %u - Saetze", index);
                LetzteKundenNr = index;
            }
            else
            {
                printf("\nDatei LIEFERANTEN.DAT enthielt - %u - Saetze", index);
                LetzteLieferantenNr = index;
            }
        }
    }
    Tastendruck();
}

/* --- */
/* --- Aufgabenteil (b) --- Funktion (9) --- DateienSchreiben */
/* --- */
void DateienSchreiben(void)
{
    // lokale Variablen
    FILE *fp;
    int index, maxindex;
    PPARTNER pPartner = NULL, root = NULL;
    ART partnerart;

    for (partnerart = kunde; partnerart <= lieferant; partnerart++)
    {
        // Dateien KUNDEN.DAT, LIEFERANTEN.DAT neu schreiben
        fp = partnerart == kunde ? fopen("KUNDEN.DAT", "w") : fopen("LIEFERANTEN.DAT", "w");
        maxindex = partnerart == kunde ? LetzteKundenNr : LetzteLieferantenNr;
        for (index = 1; index <= maxindex; index++)
        {
            // Wurzel des passenden Binaerbaums ermitteln
            root = partnerart == kunde ? kundeRoot : lieferantRoot;
            // Suche des Elements anhand der PartnerNr.
            pPartner = getPartner(root, index, "", 0);
            // Partner nicht gefunden
            if (pPartner == NULL)
            {
                printf("\nPartner-Satz im Binaerbaum nicht gefunden!");
                exit(99);
            }
            // Partner gefunden
            fprintf(fp, "%6u %20s %20s %6s %20s %6s %20s %6.2f\n",
            pPartner->partner.Nr,
            pPartner->partner.firmenname,
            pPartner->partner.anschrift.strasse,
            pPartner->partner.anschrift.hausnummer,
            pPartner->partner.anschrift.ort,
            pPartner->partner.anschrift.plz,
            pPartner->partner.ansprechpartner,
            pPartner->partner.wert);
        }
        fclose(fp);
    }
}

/* --- */
/* --- Aufgabenteil (c) --- Hauptroutine --- int main */
/* --- */
void Initialisierung(void)
{
// Kundenbaum
    kundeRoot = NULL;
    LetzteKundenNr = 0;

// Lieferantenbaum
    lieferantRoot = NULL;
    LetzteLieferantenNr = 0;
}

int main(void)
{
    Initialisierung();
    DateienEinlesen();

    Hauptmenue();

    DateienSchreiben();
    return 1;
}
