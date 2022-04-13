#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void pretvori(FILE* fp, FILE* fpo) {

	char a;

	while ((a = fgetc(fp)) != EOF) {

		// mala u velika
		if ((a >= 'a' && a <= 'z')) {
			a -= 32;
		}

		fputc(a, fpo);
	}

}