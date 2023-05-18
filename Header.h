#ifndef HEADER_H
#define HEADER_H

typedef struct pitanje {
	int pocetak;
	char pitanje[200];
	char odgovor1[100];
	char odgovor2[100];
	char odgovor3[100];
	char odgovor4[100];
}PITANJE;

char izbornik(void);
void pocetak(void);
void pravila(void);
char izlaz(void);
void provjeraJokera(int, int, int);
void jokerPublika(char, int);
void jokerPolaPola(PITANJE, int, char);
void jokerZovi(char, int);

#endif 


