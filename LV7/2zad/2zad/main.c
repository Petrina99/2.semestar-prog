#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(void) {

	int brRedova, brStupaca;
	srand((unsigned)time(NULL));

	FILE* fp = NULL;
	float** matrica;

	fp = fopen("D:\\Faks\\2.semestar\\2.semestar-prog\\LV7\\2zad\\in.txt", "r");

	if (fp == NULL) {
		printf("in.txt ne postoji");
		
		return 1;
	}

	brRedova = ucitajBroj(fp);
	brStupaca = ucitajBroj(fp);

	fclose(fp);

	matrica = zauzmi(brRedova, brStupaca);

	if (matrica == NULL) {
		return 1;
	}

	generiraj(brRedova, brStupaca, matrica);

	FILE* fpo = NULL;

	fpo = fopen("out.txt", "w+");

	if (fpo == NULL) {
		printf("Doslo je do pogreske");
		return 1;
	}

	ispis(brRedova, brStupaca, matrica, fpo);

	fclose(fpo);

	return 0;
}