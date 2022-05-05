#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>

int main() {

	srand((unsigned)time(NULL));

	int n, *polje, max;

	n = unos();

	polje = (int*)calloc(n, sizeof(int));

	if (polje == NULL) {
		printf("Polje prazno.");
		return 1;
	}

	popunjavanje(n, polje);
	ispis(n, polje);

	return 0;
}