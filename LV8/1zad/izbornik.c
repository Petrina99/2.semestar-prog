#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "dataType.h"
#include "functions.h"

static int brojClanova = 0;

int izbornik(const char* const ime) {

	printf("\t\t************************************\n\n");
	printf("\t\tOdaberite jednu od ponudenih opcija: \n\n");
	printf("\t\t************************************\n\n");
	
	printf("\t\tOpcija 1: Kreiranje datoteke!\n");
	printf("\t\tOpcija 2: Dodavanje korisnika!\n");
	printf("\t\tOpcija 3: Ucitaj sve korisnike!\n");
	printf("\t\tOpcija 4: Ispisi podatke o svim korisnicima!\n");
	printf("\t\tOpcija 5: Pretrazivanje korisnika po ID-u!\n");
	printf("\t\tOpcija 6: Izlaz iz programa!\n\n");

	printf("\t\t************************************\n\n");

	int odgovor = 0;

	static CLAN* poljeClanova = NULL;
	static CLAN* pronadeniClan = NULL;

	scanf("%d", &odgovor);

	switch (odgovor) {
		case 1:
			kreiranjeDatoteke(ime);
			break;
		case 2: 
			dodajKorisnika(ime);
			break;
		case 3:
			if (poljeClanova != NULL) {
				free(poljeClanova);
				poljeClanova = NULL;
			}

			poljeClanova = (CLAN*)ucitajKorisnike(ime);

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
			odgovor = izlazIzPrograma(poljeClanova);
			break;
		default:
			odgovor = 0;
	}

	return odgovor;
}

