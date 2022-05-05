#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int unos() {

	int br;

	printf("Unesi broj od 0 do 20 : ");

	do {
		scanf("%d", &br);
	} while (br < 1 || br > 20);

	return br;
}

void popunjavanje(int n, int* p) {

	for (int i = 0; i < n; i++) {

		*(p + i) = -50 + (float)rand() / RAND_MAX * (100 + 50);

		printf("%d\n", *(p + i));
	}
}

int najveci(int n, int* p) {

	if (n == 1) {
		return p[0];
	}

	return max(*(p + n - 1), najveci(n - 1, p));
}

void ispis(int n, int* p) {

	FILE* fp = NULL;

	fp = fopen("najveci.txt", "w");

	if (fp == NULL) {
		return 1;
	}

	printf("\nNajveci element polja je: %d", najveci(n, p));
	fprintf(fp, "%d", najveci(n, p));

	fclose(fp);

}