#ifndef TELEFONBUCH_H_INCLUDED
#define TELEFONBUCH_H_INCLUDED

 /* Knoten fuer Binaeren Baum.
     Knoten nimmt die zu speichernden Daten auf. */
  typedef struct tag_Knoten
  {
    char              name[30];
    char              telefon[30];
    struct tag_Knoten *links;
    struct tag_Knoten *rechts;
  } KNOTEN;

  /* Typ eines Zeigers auf einen Knoten */
  typedef KNOTEN *pKNOTEN;

  /* Fuegt einen Knoten in den binaeren Baum ein */
  extern void FuegeKnotenEin(char *name, char *telefon);

  /* Gibt die Daten des Baums aus */
  extern void AusgabePraeorder(void);
  extern void AusgabeInorder(void);
  extern void AusgabePostorder(void);

#endif // TELEFONBUCH_H_INCLUDED
