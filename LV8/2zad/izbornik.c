#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"
#include "functions.h"

int izbornik(const char* const datClanovi, const char* const datFilmovi) {

	printf("\t\t************************************\n\n");
	printf("\t\tOdaberite jednu od ponudenih opcija: \n\n");
	printf("\t\t************************************\n\n");

	printf("\t\tOpcija 1: Kreiranje datoteke s clanovima!\n");
	printf("\t\tOpcija 2: Dodavanje korisnika!\n");
	printf("\t\tOpcija 3: Ucitaj korisnike!\n");
	printf("\t\tOpcija 4: Ispisi podatke o svim korisnicima!\n");
	printf("\t\tOpcija 5: Pretrazivanje korisnika po ID-u!\n");
	printf("\t\tOpcija 6: Kreiranje datoteke s filmovima!\n");
	printf("\t\tOpcija 7: Dodavanje novih filmova!\n");
	printf("\t\tOpcija 8: Ucitaj filmove!\n");
	printf("\t\tOpcija 9: Ispisi podatke o svim filmovima!\n");
	printf("\t\tOpcija 10: Posudba filma!\n");
	printf("\t\tOpcija 11: Pretrazivanje filma po ID-u!\n");
	printf("\t\tOpcija 12: Izlaz iz programa!\n\n");

	printf("\t\t************************************\n\n");

	int odgovor = 0;

	static CLAN* poljeClanova = NULL;
	static CLAN* pronadeniClan = NULL;
	static FILM* poljeFilmova = NULL;
	static FILM* pronadeniFilm = NULL;

	scanf("%d", &odgovor);

	switch (odgovor) {
	case 1:
		kreiranjeDatoteke(datClanovi);
		break;
	case 2:
		dodajKorisnika(datClanovi);
		break;
	case 3:
		if (poljeClanova != NULL) {
			free(poljeClanova);
			poljeClanova = NULL;
		}

		poljeClanova = (CLAN*)ucitajKorisnike(datClanovi);

		if (poljeClanova == NULL) {
			exit(EXIT_FAILURE);
		}
		break;
	case 4:
		ispisiSveKorisnike(poljeClanova);
		break;
	case 5:
		pronadeniClan = (CLAN*)pretraziClanove(poljeClanova);

		if (pronadeniClan != NULL) {
			printf("ID: %d\n", pronadeniClan->id);
			printf("Ime: %s\n", pronadeniClan->ime);
			printf("Prezime: %s\n", pronadeniClan->prezime);
			printf("Adresa: %s\n", pronadeniClan->adresa);
			printf("Broj mobitela: %s\n", pronadeniClan->brojMobitela);
			printf("Broj podignutih filmova: %d\n", pronadeniClan->brojPodignutihFilmova);
		}
		else {
			printf("Ne postoji clan s tim ID-em.\n");
		}

		break;
	case 6:
		kreiranjeDatotekeFilmovi(datFilmovi);
		break;
	case 7:
		dodajFilm(datFilmovi);
		break;
	case 8:
		if (poljeFilmova != NULL) {
			free(poljeFilmova);
			poljeFilmova = NULL;
		}

		poljeFilmova = (FILM*)ucitajFilmove(datFilmovi);

		if (poljeFilmova == NULL) {
			exit(EXIT_FAILURE);
		}
		break;
	case 9:
		ispisiSveFilmove(poljeFilmova);
		break;
	case 10:
		posudba(poljeClanova, poljeFilmova, datClanovi, datFilmovi);
		break;
	case 11:
		pronadeniFilm = (FILM*)pretraziFilmove(poljeFilmova);

		if (pronadeniFilm != NULL) {
			printf("ID: %d\n", pronadeniFilm->id);
			printf("Ime: %s\n", pronadeniFilm->ime);
			printf("Zanr: %s\n", pronadeniFilm->zanr);
			printf("Datum podizanja: %d\n", pronadeniFilm->datumPodizanja);
			printf("ID korisnika koji ga je podigao: %d\n", pronadeniFilm->idKorisnika);
		}
		else {
			printf("Ne postoji film s tim ID-em");
		}
	case 12:
		odgovor = izlazIzPrograma(poljeClanova, poljeFilmova);
		break;
	default:
		odgovor = 0;
	}

	return odgovor;
}