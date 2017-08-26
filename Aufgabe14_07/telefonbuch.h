#ifndef TELEFONBUCH_H_INCLUDED
#define TELEFONBUCH_H_INCLUDED
#define MAXZEICHEN 80

  /* Knoten fuer den ADT Telefonbuch.
     Knoten nimmt die zu speichernden Daten eines Tel.bucheintrags auf */
  typedef struct tag_knoten
    {
      char              name[20];     /* Der Name */
      char              telefon[15];  /* Die Telefonnummer */
      struct tag_knoten *nachfolger;  /* Ein Zeiger auf den Nachfolger */
    } KNOTEN;

  /* Typ eines Zeigers auf einen Knoten */
  typedef KNOTEN *pKNOTEN;

  /* Loescht alle Knoten der Liste */
  void LoescheGanzeListe(void);
  /* Fuegt einen Knoten am Anfang der Liste ein */
  void FuegeKnotenAmAnfangEin(char *name, char *telefon);
  /* Loescht der ersten Knoten in der Liste */
  void LoescheKnotenAmAnfang(void);
  /* Gibt die Daten des ersten Knoten in der Liste aus */
  void GibKnotenAmAnfangAus(void);
  /* Gibt die Daten aller Knoten in der Liste aus */
  void GibAlleKnotenAus(void);
  /* Ermittelt die Anzahl der Knoten in der Liste */
  unsigned int ErmittleAnzahlDerKnoten(void);
  /* Gibt die Daten des/der Knoten mit dem uebergebenen Namen aus */
  void GibKnotenMitNamenAus(char *name);
  /* Loescht alle Knoten mit dem uebergenenen Namen */
  void LoescheKnotenMitNamen(char *name);
  /* Fuegt einen Knoten sortiert in die Liste ein */
  void FuegeKnotenSortiertEin(char *name, char *telefon);

#endif // TELEFONBUCH_H_INCLUDED
