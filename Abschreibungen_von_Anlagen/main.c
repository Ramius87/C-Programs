/* --------------------- Standardbibliotheken ----------------- */
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/* --------------------- Konstanten --------------------------- */
/* max. Anzahl Jahre fuer Abschreibungssummenliste */
#define MAXJAHRE 15

enum abschreibungsmodus {linear, degressiv};

/* -------------------------- Typen ------------------------------ */
/* Anlagensatz */
typedef struct
{
    unsigned int InventarNr;
    char Anlagenbez[15];
    char Standort[15];
    float Basiswert; /* in EUR */
    unsigned int Nutzdauer; /* in Jahren */
    unsigned int AnschJahr;
} ANLAGE;

/* Abschreibungssatz */
typedef struct
{
    unsigned int InventarNr;
    unsigned int AbschrJahr;
    unsigned char AbschrModus; // A = arithmetisch, D = arithm.degr.
    float AbschrBetrag; // in EUR
} ABSCHREIBUNG;

/* --------------------- Prototypen ------------------------------ */
void erstelle_anlagendatei(void);
void verarbeite_anlagendatei(void);
void erstelle_anlagenliste(void);
void berechne_abschreibungen(unsigned char auswahl);
void schreibe_anlage_arithmetisch_ab(ANLAGE anlage);
void schreibe_anlage_arith_degr_ab(ANLAGE anlage);
void erstelle_abschreibungsliste(void);
void erstelle_abschrsummenliste(void);

/* ----------------- Funktion main ------------------------------- */
int main()
{
    unsigned int modus; // 0: Datei anlagen.dat. erstellen,
                        // 1: Berechnungen anhand Datei durchfuehren
    /* Info */
    printf("\n\nProgramm berechnet Abschreibungen von Anlagen");

    /* Eingabe Modus */
    printf("\nModus (0:Anlagendatei erstellen, sonst:Anlagendatei verarb.) ? ");
    scanf("%u",&modus);

    /* ggf. Anlagendatei erstellen
    beachte: vorhandene Datei wird ueberschrieben */
    if (modus == 0)
    erstelle_anlagendatei();

    /* andernfalls Anlagendatei verarbeiten */
    else verarbeite_anlagendatei();

    printf("\nProgrammende");
    return 0;
}

/* ---------------- Funktion erstelle_anlagendatei --------------- */
void erstelle_anlagendatei(void)
{
    ANLAGE anlage;
    FILE *fp;
    unsigned int anzahl, i;

    printf("\n\n<<< Erstellung einer Anlagendatei anlagen.dat >>>");

    /* Anzahl der Anlagen abfragen */
    printf("\nAnzahl der Anlagen ? ");
    scanf("%u",&anzahl);

    /* Datei zum Schreiben oeffnen */
    fp = fopen("anlagen.dat","w");
    if (fp == NULL)
    {
        printf("Datei konnte nicht erstellt werden.");
        exit(99);
    }

    /* Daten der Anlagen einlesen´*/
    for (i=1; i<=anzahl; i++)
    {
        printf("\n\nBitte Daten fuer %3u-te Anlage eingeben", i);
        printf("\nInventar-Nr. ? ");
        scanf("%u",&anlage.InventarNr);
        printf("\nAnlagenbezeichnung ? ");
        scanf("%s", anlage.Anlagenbez);
        printf("\nStandort ? ");
        scanf("%s", anlage.Standort);
        printf("\nBasiswert in EUR ? ");
        scanf("%f", &anlage.Basiswert);
        printf("\nNutzdauer in ganzen Jahren ? ");
        scanf("%u",&anlage.Nutzdauer);
        printf("\nAnschaffungsjahr ? ");
        scanf("%u",&anlage.AnschJahr);

        /* Anlagendaten schreiben */
        fprintf(fp,"%3u %15s %15s %8.2f %3u %4u\n",
            anlage.InventarNr,
            anlage.Anlagenbez,
            anlage.Standort,
            anlage.Basiswert,
            anlage.Nutzdauer,
            anlage.AnschJahr);
    }

    fclose(fp);
    printf("\nAnlagendatei anlage.dat erstellt.");
}

/* --------------------- Funktion verarbeite_anlagendatei ----- */
void verarbeite_anlagendatei(void)
{
    unsigned char auswahl;

    /* Auswahlmenue der angebotenen Programmfunktionen anzeigen */
    /* und Auswahl treffen */
    while (1)
    {
        printf("\n\n<<< Verarbeitung einer Anlagendatei anlagen.dat >>>");
        printf("\n\nBitte eine Funktion waehlen:");
        printf("\nL - Anlagenliste anzeigen");
        printf("\nA - Abschreibungen arithmetisch berechnen");
        printf("\nD - Abschreibungen arithmetisch-degressiv berechnen");
        printf("\nR - Abschreibungsliste zur letzten Berechnung anzeigen");
        printf("\nS - Abschreibungssummenliste zur letzten Berechnung anzeigen");
        printf("\nQ - Programm beenden");
        printf("\nIhre Wahl ? "); fflush(stdin);
        scanf("%c", &auswahl);

        auswahl = (unsigned char)toupper(auswahl);

        /* Verarbeitung fuer ausgewaehlte Programmfunktion starten */
        switch(auswahl)
        {
            case 'L': erstelle_anlagenliste(); break;
            case 'A': ;
            case 'D': berechne_abschreibungen(auswahl); break;
            case 'R': erstelle_abschreibungsliste(); break;
            case 'S': erstelle_abschrsummenliste(); break;
            case 'Q': return;
            default : printf("\nUnbekannte Funktion!"); break;
        } // end switch
    } // end while
}

/* --------------------- Funktion erstelle_anlagenliste ------- */
void erstelle_anlagenliste(void)
{
    unsigned int i;
    ANLAGE anlage;
    FILE *fp;

    /* Anlagendatei zum Lesen oeffnen */
    fp = fopen("anlagen.dat","r");
    if (fp == NULL)
    {
        printf("\nAnlagendatei nicht lesbar");
        exit(99);
    }

    /* Listenkopf ausgeben */
    printf("\n\nAnlagenliste\n\n"
    "Lfd.Nr. Inv.Nr. Anlagenbezeichnung Standort "
    "Basiswert Nutzdauer Ansch.jahr\n");
    printf(""
    "--------------------------------------------"
    "--------------------------------");

    /* Anlagensaetze bis Dateiende lesen und satzweise
    als Liste ausgeben */
    i = 0;
    while (fscanf(fp, "%u %s %s %f %u %u\n",
        &anlage.InventarNr,
        anlage.Anlagenbez,
        anlage.Standort,
        &anlage.Basiswert,
        &anlage.Nutzdauer,
        &anlage.AnschJahr) != EOF)
    {
        i++;
        printf("\n%6u",i);
        printf(" %4u", anlage.InventarNr);
        printf(" %15s", anlage.Anlagenbez);
        printf(" %15s", anlage.Standort);
        printf(" %8.2f",anlage.Basiswert);
        printf(" %6u", anlage.Nutzdauer);
        printf(" %8u", anlage.AnschJahr);
    } // end while

    /* Datei schliessen und Info Anzahl Saetze */
    fclose(fp);

    printf("\nAnlagendatei enthielt - %3u - Saetze",i);
    printf("\nRETURN!");getch();
}

/* --------------------- Funktion berechne_abschreibungen ----- */
void berechne_abschreibungen(unsigned char auswahl)
{
    unsigned int i;
    ANLAGE anlage;
    FILE *fp;

    /* Anlagendatei zum Lesen oeffnen */
    fp = fopen("anlagen.dat","r");
    if (fp == NULL)
    {
        printf("\nAnlagendatei nicht lesbar");
        exit(99);
    }

    /* ggf. alte Abschreibungsdatei loeschen */
    remove("aban.dat");

    /* Anlagensaetze bis Dateiende lesen und satzweise
    bzw. pro Anlage Abschreibungen berechnen */
    i = 0;
    while (fscanf(fp, "%u %s %s %f %u %u\n",
        &anlage.InventarNr,
        anlage.Anlagenbez,
        anlage.Standort,
        &anlage.Basiswert,
        &anlage.Nutzdauer,
        &anlage.AnschJahr) != EOF)
    {
        /* Anlagen mitzaehlen */
        i++;

        /* Berechnung der Abschreibungen pro Anlage */
        if (auswahl == 'A')
        schreibe_anlage_arithmetisch_ab(anlage);
        else if (auswahl == 'D')
        schreibe_anlage_arith_degr_ab(anlage);
    } // end while

    /* Anlagendatei schliessen und Info */
    fclose(fp);

    printf("\nAbschreibungen fuer - %u - Anlagen berechnet", i);
    printf("\nRETURN!");getch();
}

/* -------------- Funktion schreibe_anlage_arithmetisch_ab ---- */
void schreibe_anlage_arithmetisch_ab (ANLAGE anlage)
{
    unsigned int i;
    float AbschrBetrag;
    FILE *fp;

    /* Abschreibungsdatei zum Anhaengen oeffnen */
    fp = fopen("aban.dat","a+");

    /* jaehrl. Abschreibungsbetrag ermitteln */
    if (anlage.Nutzdauer == 0)
    {
        printf("\nInv.Nr: %u, Nutzdauer = 0!",anlage.InventarNr);
        exit(99);
    }
    else
        AbschrBetrag = anlage.Basiswert / anlage.Nutzdauer;

    /* fuer alle Nutzjahre einen Abschreibungssatz schreiben */
    for (i = 1; i <= anlage.Nutzdauer; i++)
    {
        fprintf(fp, "%3u %4u %c %8.2f\n",
        anlage.InventarNr, anlage.AnschJahr + i - 1, 'A', AbschrBetrag);
    }

    /* Abschreibungsdatei schliessen */
    fclose(fp);
}

/* ----------------- Funktion schreibe_anlage_arith_degr_ab --- */
void schreibe_anlage_arith_degr_ab (ANLAGE anlage)
{
    unsigned int i;
    unsigned int sumNutzjahre;
    float degrBetrag;
    FILE *fp;

    /* Abschreibungsdatei zum Anhaengen oeffnen */
    fp = fopen("aban.dat","a+");

    /* Summe der Nutzungsjahre und Degressionsbetrag ermitteln */
    if (anlage.Nutzdauer == 0)
    {
        printf("\nInv.Nr: %u, Nutzdauer = 0!",anlage.InventarNr);
        exit(99);
    }
    else
    {
        sumNutzjahre = anlage.Nutzdauer * (anlage.Nutzdauer + 1) / 2;
        degrBetrag = anlage.Basiswert / sumNutzjahre;
    }

    /* fuer alle Nutzjahre einen Abschreibungssatz schreiben */
    for (i = 1; i <= anlage.Nutzdauer; i++)
    {
        fprintf(fp, "%3u %4u %c %8.2f\n",
        anlage.InventarNr, anlage.AnschJahr + i - 1, 'D',
        degrBetrag*(float)(anlage.Nutzdauer - i + 1));
    }

    /* Abschreibungsdatei schliessen */
    fclose(fp);
}

/* ------------------ Funktion erstelle_abschreibungsliste ---- */
void erstelle_abschreibungsliste(void)
{
    unsigned int i;
    int res;
    ANLAGE anlage;
    ABSCHREIBUNG abschr;
    FILE *fp_an, *fp_ab;

    /* Anlagendatei zum Lesen oeffnen */
    fp_an = fopen("anlagen.dat","r");
    if (fp_an == NULL)
    {
        printf("\nAnlagendatei nicht lesbar");
        exit(99);
    }

    /* Abschreibungsdatei zum Lesen oeffnen */
    /* ersten Abschreibungssatz vorab lesen */
    fp_ab = fopen("aban.dat","r");
    if (fp_ab == NULL)
    {
        printf("\nAbschreibungsdatei nicht vorhanden!");
        return;
    }
    else
    {
        fscanf(fp_ab, "%u %u %c %f\n", &abschr.InventarNr,
            &abschr.AbschrJahr,
            &abschr.AbschrModus,
            &abschr.AbschrBetrag);
    }

    /* Listenkopf ausgeben */
    printf("\n\nAbschreibungsliste\n\n"
    "Lfd.Nr. Inv.Nr. Anlagenbezeichnung Abschr.modus "
    "Abschr.jahr Abschr.betrag\n");
    printf(""
    "--------------------------------------------"
    "--------------------------------");

    /* Anlagensaetze bis Dateiende lesen und ausgeben
    und pro Anlage alle Abschreibungssaetze lesen und ausgeben */
    i = 0;
    while (fscanf(fp_an, "%u %s %s %f %u %u\n",
        &anlage.InventarNr,
        anlage.Anlagenbez,
        anlage.Standort,
        &anlage.Basiswert,
        &anlage.Nutzdauer,
        &anlage.AnschJahr) != EOF)
    {
        /* Ausgabe Anlagensatz */
        i++;
        printf("\n%6u",i);
        printf(" %4u", anlage.InventarNr);
        printf(" %15s", anlage.Anlagenbez);
        printf(" %c", abschr.AbschrModus);

        /* lesen und ausgeben zugehoerige Abschreibungssaetze */
        do
        {
            /* letzten Abschreibungssatz ausgeben */
            printf("\n*** %7u %.2f",
            abschr.AbschrJahr, abschr.AbschrBetrag);

            /* naechsten Abschreibungssatz lesen */
            res = fscanf(fp_ab, "%u %u %c %f\n", &abschr.InventarNr,
                &abschr.AbschrJahr,
                &abschr.AbschrModus,
                &abschr.AbschrBetrag);
        } while (res != EOF && abschr.InventarNr == anlage.InventarNr);
    } // end while

    /* Info Listenende, Dateien schliessen */
    printf("\nENDE der Abschreibungsliste\nRETURN!");getch();
    fclose(fp_an);
    fclose(fp_ab);
}

/* --------------------- Funktion erstelle_abschrsummenliste -- */
void erstelle_abschrsummenliste(void)
{
    ABSCHREIBUNG abschr;
    FILE *fp;
    float Jahresabschr[1+MAXJAHRE];
    unsigned int vonJahr, bisJahr;
    int anzJahre, i;

    /* Abschreibungsdatei zum Lesen oeffnen */
    fp = fopen("aban.dat","r");
    if (fp == NULL)
    {
        printf("\nAbschreibungsdatei nicht vorhanden!");
        return;
    }

    /* Zeitraum fuer Summenliste erfragen */
    printf("\n\nAbschreibungssummenliste");
    printf("\n Erstes Jahr ? "); scanf("%u",&vonJahr);
    printf(" Letztes Jahr ? "); scanf("%u",&bisJahr);
    if (vonJahr > bisJahr || bisJahr - vonJahr + 1 > MAXJAHRE)
    {   printf("\nZeitraum unzulaessig!");
        return;
    }

    /* Vektor der Abschreibungssummen initialisieren */
    anzJahre = bisJahr - vonJahr + 1;
    for (i = 1; i <= anzJahre; i++)
        Jahresabschr[i] = 0.0f;
    /* Abschreibungsdatei lesen und Abschreibungssummen fuer
    gewuenschte Jahre bestimmen */
    while (fscanf(fp, "%u %u %c %f\n", &abschr.InventarNr,
            &abschr.AbschrJahr,
            &abschr.AbschrModus,
            &abschr.AbschrBetrag)
            != EOF)
    {
        /* Vektorindex zu gegebenem Abschr.jahr bestimmen */
        i = abschr.AbschrJahr - vonJahr + 1;

        /* Abschreibungssaetze uebergehen, die nicht in gewuenschten
        Zeitraum fallen */
        if (i < 1 || i > anzJahre)
        continue;

        /* Abschreibungssumme fuer gegebenes Abschr.jahr aktual. */
        Jahresabschr[i] += abschr.AbschrBetrag;
    } // end while

    /* Abschreibungssummenliste ausgeben */
    printf("\nJahr Summe aller Abschreibungen");
    printf("\n--------------------------------");
    for (i = 1; i <= anzJahre; i++)
    {
        printf("\n%4u %10.2f",
        vonJahr + i - 1, Jahresabschr[i]);
    }

    /* Info Listenende, Datei schliessen */
    fclose(fp);
    printf("\nENDE der Abschreibungssummenliste");
    printf("\nRETURN!");getch();
}
