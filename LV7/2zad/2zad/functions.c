#define _CRT_SECURE_NO_WARNINGS

#include "header.h"
#include <stdio.h>
#include <stdlib.h>

#define DG -125.5
#define GG 65.8

int ucitajBroj(FILE* fp) {

	int n;

	fscanf(fp, "%d", &n);

	return n;
}

float** zauzmi(int n, int m) {

	int i;

	float** p = NULL;

	p = (float**)malloc(n * sizeof(float*));

	if (p == NULL) {
		return NULL;
	}

	for (i = 0; i < m; i++) {
		*(p + i) = (float*)malloc(m * sizeof(float));

		if (*(p + i) == NULL) {
			return NULL;
		}
	}

	return p;
}

void generiraj(int n, int m, float** p) {

	int i, j;

	for (i = 0; i < n; i++) {

		for (j = 0; j < m; j++) {
			*(*(p + i) + j) = DG + (float)rand() / RAND_MAX * (GG - DG);
		}
	}
}

void ispis(int n, int m, float** p, FILE* fp) {
	
	int i, j;

	for (i = 0; i < n - 1; i++) {

		for (j = 1; j < m; j++) {
			printf("%.2f ", *(*(p + i) + j));
			fprintf(fp, "%.2f ", *(*(p + i) + j));
		}

		printf("\n");
		fprintf(fp, "\n");
	}
}