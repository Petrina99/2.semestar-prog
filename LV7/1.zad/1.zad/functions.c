#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "header.h"

int ucitajBroj(FILE* fp) {

	int n;

	fscanf(fp, "%d", &n);

	return n;
}

void unosStudenata(FILE* fp, int n) {

	int i;

	char ime[40];
	char prezime[40];

	for (i = 0; i < n; i++) {
		printf("Ime %d. studenta: \n", i + 1);
		scanf("%39s", ime);

		printf("Prezime %d. studenta: \n", i + 1);
		scanf("%39s", prezime);

		fprintf(fp, "Student broj: %d\tIme: %s\tPrezime: %s\n", i + 1, ime, prezime);
	}
}