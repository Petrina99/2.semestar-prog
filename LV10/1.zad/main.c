#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

int main(void) {

	int b = 0;
	int rez;

	printf("Unesite broj kojem izracunavate sumu: ");
	scanf("%d", &b);

	rez = izracunajSumu(b);
	printf("suma: %d\n", rez);

	FILE* fp = NULL;

	fp = fopen("suma.txt", "w");

	if (fp == NULL) {
		printf("Datoteka ne postoji");
		return 1;
	}

	fprintf(fp, "%d", rez);

	return 0;
}