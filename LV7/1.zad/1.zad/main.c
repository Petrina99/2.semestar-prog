#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

/* 1. Napisati C program koji će pročitati cijeli broj iz datoteke "dat.txt" i toliko puta tražiti unos imena i
prezimena studenta sa standardnog ulaza. Sva učitana imena i prezimena zapisati u datoteku
"studenti.txt" koju je potrebno kreirati iz programa i to tako da zapis bude u formatu: "Student
broj: %d.\tIme: %s\t Prezime: %s\n", svaki zapis u novi red. Datoteku "dat.txt" kreirati na računalu
pomoću Notepad-a, te upisati cijeli broj i spremiti sadržaj datoteke. Prilikom otvaranja datoteke
"dat.txt" navesti apsolutnu putanju do sam datoteke. */

int main(void) {

	FILE* fp = NULL;

	fp = fopen("D:\\Faks\\2.semestar\\2.semestar-prog\\LV7\\1.zad\\dat.txt", "r");

	if (fp == NULL) {
		printf("dat.txt ne postoji");
		
		return 1;
	}

	int n = 0;

	n = ucitajBroj(fp);

	fclose(fp);

	FILE* fps = NULL;

	fps = fopen("studenti.txt", "w+");

	if (fps == NULL) {
		printf("Došlo je do greške.");

		return 1;
	}

	unosStudenata(fps, n);

	fclose(fps);

	return 0;
}