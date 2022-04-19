#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "functions.h"

int main(void) {

	int odgovor = 1;
	
	char* datoteka = "clanovi.bin";

	while (odgovor) {
		odgovor = izbornik(datoteka);
	}

	printf("Kraj programa");
	
	return 0;
}