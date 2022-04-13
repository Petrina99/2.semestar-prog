#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "header.h"

int main(void) {

	FILE* fp = NULL;

	fp = fopen("D:\\Faks\\2.semestar\\2.semestar-prog\\LV7\\3zad\\prva.txt", "r");

	if (fp == NULL) {
		printf("prva.txt ne postoji");

		return 1;
	}

	FILE* fpo = NULL;

	fpo = fopen("druga.txt", "w+");

	if (fpo == NULL) {
		printf("Doslo je do greske");

		return 1;
	}

	pretvori(fp, fpo);

	fclose(fp);
	return 0;
}