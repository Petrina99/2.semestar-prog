#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataType.h"
#include "functions.h"

static int brojClanova = 0;
static int brojFilmova = 0;

void kreiranjeDatoteke(const char* const ime) {

	brojClanova = 0;

	FILE* fp = fopen(ime, "wb");

	if (fp == NULL) {
		perror("Kreiranje datoteke");
		exit(EXIT_FAILURE);
	}

	fwrite(&brojClanova, sizeof(int), 1, fp);

	printf("Kreirana datoteka\n\n");
	fclose(fp);

}

void kreiranjeDatotekeFilmovi(const char* const ime) {
	
	brojFilmova = 0;
	
	FILE* fp = fopen(ime, "wb");

	if (fp == NULL) {
		perror("Kreiranje datoteke");
		exit(EXIT_FAILURE);
	}

	fwrite(&brojFilmova, sizeof(int), 1, fp);

	printf("Kreirana datoteka\n\n");
	fclose(fp);
}

void dodajKorisnika(const char* const ime) {

	FILE* fp = fopen(ime, "rb+");

	if (fp == NULL) {
		perror("Dodavanje clanova u datoteku clanovi.bin");
		exit(EXIT_FAILURE);
	}

	//citamo prvi red datoteke i zapisujemo broj clanova u varijablu brojClanova
	fread(&brojClanova, sizeof(int), 1, fp);
	printf("Broj clanova: %d\n\n", brojClanova);

	CLAN temp = { 0 };
	temp.id = brojClanova + 1;
	getchar();

	printf("Unesite ime clana: ");
	scanf("%24[^\n]", temp.ime);
	getchar();

	printf("Unesite prezime clana: ");
	scanf("%24[^\n]", temp.prezime);
	getchar();

	printf("Unesite adresu clana: ");
	scanf("%49[^\n]", temp.adresa);
	getchar();

	printf("Unesite broj mobitela clana: ");
	scanf("%10[^\n]", temp.brojMobitela);

	temp.brojPodignutihFilmova = 0;

	//pomicemo se na kraj datoteke i zapisujemo novog clana tamo
	fseek(fp, sizeof(CLAN) * brojClanova, SEEK_CUR);
	fwrite(&temp, sizeof(CLAN), 1, fp);
	printf("Novi clan dodan.\n\n");

	// povratak na pocetak datoteke
	rewind(fp);
	brojClanova++;

	// zapis novog broja clanova
	fwrite(&brojClanova, sizeof(int), 1, fp);

	fclose(fp);
}

void* ucitajKorisnike(const char* const ime) {

	FILE* fp = fopen(ime, "rb");

	if (fp == NULL) {
		perror("Ucitavanje korisnika iz clanovi.bin");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(&brojClanova, sizeof(int), 1, fp);
	printf("Broj clanova: %d\n", brojClanova);

	CLAN* poljeClanova = (CLAN*)calloc(brojClanova, sizeof(CLAN));

	if (poljeClanova == NULL) {
		perror("Zauzimanje memorije za studente");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(poljeClanova, sizeof(CLAN), brojClanova, fp);

	printf("Svi clanovi uspjesno ucitani.\n\n");

	return poljeClanova;
}

void ispisiSveKorisnike(const CLAN* const polje) {

	if (polje == NULL) {
		printf("Polje clanova prazno\n");
		return;
	}

	int i;

	for (i = 0; i < brojClanova; i++) {
		printf("Clan broj %d\tID: %d\tIme: %s\tPrezime: %s\tAdresa: %s\tMobitel: %s\tBroj posudenih filmova: %d\n\n",
			i + 1,
			(polje + i)->id,
			(polje + i)->ime,
			(polje + i)->prezime,
			(polje + i)->adresa,
			(polje + i)->brojMobitela,
			(polje + i)->brojPodignutihFilmova);
	}
}

void* pretraziClanove(CLAN* const polje) {

	if (polje == NULL) {
		printf("Polje clanova prazno\n");
		return NULL;
	}

	int i;

	int trazeniId;

	printf("Unesite ID clana kojeg trazite: \n");
	scanf("%d", &trazeniId);

	// ako nademo clana vracamo cijeli element polja s trazenim id-em
	for (i = 0; i < brojClanova; i++) {

		if (trazeniId == (polje + i)->id) {
			printf("Clan pronaden.\n");

			return (polje + i);
		}
	}

	// vracamo NULL u slucaju da ne nademo nijednog clana s tim id
	return NULL;
}

int izlazIzPrograma(CLAN* poljeClanova, FILM* poljeFilmova) {

	free(poljeClanova);
	free(poljeFilmova);

	return 0;
}

void dodajFilm(const char* const ime) {
	FILE* fp = fopen(ime, "rb+");

	if (fp == NULL) {
		perror("Dodavanje filmova u datoteku filmovi.bin");
		exit(EXIT_FAILURE);
	}

	//citamo prvi red datoteke i zapisujemo broj clanova u varijablu brojClanova
	fread(&brojFilmova, sizeof(int), 1, fp);
	printf("Broj filmova: %d\n\n", brojFilmova);

	FILM temp = { 0 };
	temp.id = brojFilmova + 1;
	getchar();

	printf("Unesite ime filma: ");
	scanf("%24[^\n]", temp.ime);
	getchar();

	printf("Unesite zanr filma: ");
	scanf("%24[^\n]", temp.zanr);
	getchar();

	temp.datumPodizanja = 0;

	temp.idKorisnika = 0;

	fseek(fp, sizeof(FILM) * brojFilmova, SEEK_CUR);
	fwrite(&temp, sizeof(FILM), 1, fp);
	printf("Novi film dodan.\n\n");

	// povratak na pocetak datoteke
	rewind(fp);
	brojFilmova++;

	// zapis novog broja clanova
	fwrite(&brojFilmova, sizeof(int), 1, fp);

	fclose(fp);
}

void* ucitajFilmove(const char* const ime) {

	FILE* fp = fopen(ime, "rb");

	if (fp == NULL) {
		perror("Ucitavanje filmova iz filmovi.bin");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(&brojFilmova, sizeof(int), 1, fp);
	printf("Broj filmova: %d\n", brojFilmova);

	FILM* poljeFilmova = (FILM*)calloc(brojFilmova, sizeof(FILM));

	if (poljeFilmova == NULL) {
		perror("Zauzimanje memorije za filmove");
		return NULL;
		exit(EXIT_FAILURE);
	}

	fread(poljeFilmova, sizeof(FILM), brojFilmova, fp);

	printf("Svi filmovi uspjesno ucitani.\n\n");

	return poljeFilmova;
}

void ispisiSveFilmove(const FILM* const polje) {

	if (polje == NULL) {
		printf("Polje filmova prazno\n");
		return;
	}

	int i;

	for (i = 0; i < brojFilmova; i++) {
		printf("Film broj %d\tID: %d\tIme: %s\tZanr: %s\tDatum podizanja: %d\tID korisnika: %d\n\n",
			i + 1,
			(polje + i)->id,
			(polje + i)->ime,
			(polje + i)->zanr,
			(polje + i)->datumPodizanja,
			(polje + i)->idKorisnika);
	}

}

void* pretraziFilmove(FILM* const polje) {

	if (polje == NULL) {
		printf("Polje filmova prazno\n");
		return NULL;
	}

	int i;

	int trazeniId;

	printf("Unesite ID filma kojeg trazite: \n");
	scanf("%d", &trazeniId);

	// ako nademo clana vracamo cijeli element polja s trazenim id-em
	for (i = 0; i < brojClanova; i++) {

		if (trazeniId == (polje + i)->id) {
			printf("Film pronaden.\n");

			return (polje + i);
		}
	}

	// vracamo NULL u slucaju da ne nademo nijednog clana s tim id
	return NULL;
}

//odvratno ruzan kod al radi jebo ga bog
void posudba(CLAN* poljeClanova, FILM* poljeFilmova, const char* const datClanovi, const char* const datFilmovi) {

	if (poljeClanova == NULL) {
		printf("Polje clanova prazno\n");
		return;
	}

	if (poljeFilmova == NULL) {
		printf("Polje filmova prazno\n");
		return;
	}

	FILE* fpc = fopen(datClanovi, "rb+");

	if (fpc == NULL) {
		perror("Ucitavanje clanova iz clanovi.bin");
		exit(EXIT_FAILURE);
	}

	FILE* fpf = fopen(datFilmovi, "rb+");
	
	if (fpf == NULL) {
		perror("Ucitavanje filmova iz filmovi.bin");
		exit(EXIT_FAILURE);
	}

	int n;

	printf("Unesite id clana koji podize film: ");
	
	do {
		scanf("%d", &n);
	} while (n < 1 || n > brojClanova);

	CLAN* temp = (poljeClanova + n - 1);

	printf("Trenutni broj posudenih filmova korisnika s id-em %d : %d filmova.\n", temp->id, temp->brojPodignutihFilmova);

	int m = 4 - temp->brojPodignutihFilmova;

	if (m == 0) {
		printf("Korisnik je posudio maksimalan broj filmova. (%d)\n", temp->brojPodignutihFilmova);
		return;
	}
	else {
		printf("Koliko filmova korisnik zeli posuditi?: (moguce jos %d)\n", m);
	}
	
	int br;

	do {
		scanf("%d", &br);
		
		if (br > m) {
			printf("Ne mozete posuditi toliko filmova. Odaberite drugi broj: \n");
		}
	} while (br > m);

	int i, ind;

	for (i = 0; i < br; i++) {
		printf("Unesite id %d. filma koji zelite posuditi: \n", i + 1);

		do {
			scanf("%d", &ind);

			if (ind < 1 || ind > brojFilmova) {
				printf("Film s id-om %d ne postoji. Odaberite neki drugi film\n", ind);
			}

			if ((poljeFilmova + ind)->datumPodizanja != 0) {
				printf("Nazalost taj film je vec posuden. Probajte neki drugi\n");
			}

		} while (ind < 1 || ind > brojFilmova || (poljeFilmova + ind)->datumPodizanja != 0);

		(poljeFilmova + ind)->idKorisnika = temp->id;

		printf("Unesite datum podizanja (od 1 do 365): \n");

		int datum;

		do {
			scanf("%d", &datum);

			if (datum < 1 || datum > 365) {
				printf("Ne postojec datum. Unesite ponovono (1 do 365):\n");
			}
		} while (datum < 1 || datum > 365);

		(poljeFilmova + i)->datumPodizanja = datum;
		temp->brojPodignutihFilmova++;

		rewind(fpc);
		fseek(fpc, sizeof(int) * 1, SEEK_CUR);
		fseek(fpc, sizeof(CLAN) * temp->id - 1, SEEK_CUR);
		fwrite(&temp, sizeof(CLAN), 1, fpc);

		rewind(fpf);
		fseek(fpf, sizeof(int) * 1, SEEK_CUR);
		fseek(fpf, sizeof(FILM) * ind, SEEK_CUR);
		fwrite((poljeFilmova + i), sizeof(FILM), 1, fpf);
	}
}