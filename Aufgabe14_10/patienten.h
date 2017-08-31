#ifndef PATIENTEN_H_INCLUDED
#define PATIENTEN_H_INCLUDED

  /* Knoten fuer die Schlange.
     Knoten nimmt die zu speichernden Daten auf. */
  typedef struct tag_knoten
  {
    char              name[30];
    char              beschwerden[30];
    struct tag_knoten *nachfolger;  /* Ein Zeiger auf den Nachfolger */
  } KNOTEN;

  /* Typ eines Zeigers auf einen Knoten */
  typedef KNOTEN *pKNOTEN;

  typedef char boolean;
  #define TRUE 1
  #define FALSE 0

  /* Schiebt einen Knoten in die Schlange */
  extern void rear(char *name, char *beschwerden);
  /* Nimmt den ersten (vordersten) Knoten aus der Schlange und liefert die
     Daten*/
  extern boolean front(char *name, char *beschwerden);
  /* Liefert die Daten des ersten Knotens in der Schlange ohne ihn zu
     loeschen */
  extern boolean next(char *name, char *beschwerden);
  /* Liefert die Anzahl der Knoten in der Schlange */
  extern unsigned long Anzahl(void);

#endif // PATIENTEN_H_INCLUDED
