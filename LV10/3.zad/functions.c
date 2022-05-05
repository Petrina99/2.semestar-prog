#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <string.h>

void zamjena(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

void obrnuto(char s[], int prvi, int zadnji) {

	if (prvi < zadnji) {

		zamjena(&s[prvi], &s[zadnji]);


		obrnuto(s, prvi + 1, zadnji - 1);
	}

}

void ispisi(char s[]) {

	int z = strlen(s) - 1;

	FILE* fp = NULL;

	fp = fopen("string.txt", "w");

	if (fp == NULL) {
		perror("Datoteka nije kreirana.\n");
		exit(EXIT_FAILURE);
		return;
	}

	obrnuto(s, 0, z);

	fprintf(fp, "%s", s);
	printf("%s", s);

}