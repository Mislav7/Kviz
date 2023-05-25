#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Header.h"

static int brojPitanja = 0;
static PITANJE* poljePitanja = NULL;
static int counter = 0;

void pocetak(void) {

	system("cls");

	printf("\n\n\n\n\t\t\tUnesite svoje ime: ");
	scanf("%s", igrac.ime);
	
	system("cls");


	FILE* hp = NULL;
	hp = fopen("highscore.bin", "ab+");
	if (hp == NULL) {
		printf("\nDatoteka se ne moze otvoriti.\n");
		perror("Otvaranje");
	}

	poljePitanja = (PITANJE*)ucitavanjePitanja();
	if (poljePitanja == NULL) {
		perror("Zauzimanje memorije za sortirana pitanja");
		exit(EXIT_FAILURE);
	}

	PITANJE vraceno;
	char tocno;

	do {
		switch (r1) {
		case 1:
			printf("\n\t********** Pitanje za 100 **********");
			vraceno = sortiranjePolja(poljePitanja, 1);
			tocno = ispisivanjePitanja(vraceno);
			provjeraJokera(publika, polaPola, zovi);
			printf("\n\tDa bi ste odustali odaberite \"O\"");
			j = 1;
			do {
				printf("\n\tUnesite vas odgovor: ");
				znak = getch();
				if (znak == 'j') {
					printf("\n\tUnesite zeljeni joker: ");
					scanf("%d", &var);
					if (var == 1) {
						jokerPublika(tocno, publika);
						publika = -1;
						j = 1;
					}
					if (var == 2) {
						jokerPolaPola(vraceno, polaPola, tocno);
						polaPola = -1;
						j = 1;
					}
					if (var == 3) {
						jokerZovi(tocno, zovi);
						zovi = -1;
						j = 1;
					}
				}
				else if (znak == tocno)
				{
					printf("\n\n\t\tTocno!!!");
					count = 100;
					r1++;
					j = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else if (znak == 'o') {
					printf("\n\tOdustali ste\n");
					count = 0;
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
				else
				{
					printf("\n\n\tNetocno!!! Tocan odgovor je pod %c:%s", toupper(tocno), vraceno.odg1);
					count = 0;
					j = 0;
					r1 = 0;
					printf("\n\t");
					system("pause");
					system("cls");
					break;
				}
			} while (j);
			break;