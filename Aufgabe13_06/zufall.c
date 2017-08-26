#define FAKTOR 25173UL
#define INCR   13849UL
#define MODULO 65536UL

static unsigned int zufall;
extern unsigned long aufruf_zahler;

void SetSeed(unsigned int seed)
{
    zufall = seed;
}

void NaechsteZufallszahl(void)
{
    zufall = (FAKTOR * zufall + INCR) % MODULO;
}

unsigned int Random(void)
{
    NaechsteZufallszahl();
    return zufall;
}
