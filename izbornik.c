#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

char izbornik(void) {

	printf("\nDobrodošli u nogometni kviz!\n");
	printf("\n Opcija 1: Pocetak igre");
	printf("\n Opcija 2: Pravila igre");
	printf("\n Opcija 3: Izlaz");
	
	char odabir;
	printf("Biranje opcije: ");

	scanf("%c", &odabir);
	
	getchar();

	switch (odabir) {
	case '1':
		pocetak();
		break;
	case '2':
		pravila();
		break;
	case '3':
		odabir = izlaz();
		break;
	
	default:
		printf("Opcija pod tim brojem nije dostupna.\n");
	}
	return odabir;
}

