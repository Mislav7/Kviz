#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "Header.h"

int main(void) {
	char odabir = '1';


	while (odabir) {
		odabir = izbornik();
	}
	printf("Došli ste do kraja igre!");

	return 0;
}
