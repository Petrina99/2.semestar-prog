#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.h"

int main(void) {

	int odgovor = 1;

	char* datoteka = "clanovi.bin";
	char* datoteka2 = "filmovi.bin";

	while (odgovor) {
		odgovor = izbornik(datoteka, datoteka2);
	}

	printf("Kraj programa");

	return 0;
}