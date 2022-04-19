#ifndef DATATYPE_H
#define DATATYPE_H

typedef struct clan {
	int id;
	char ime[25];
	char prezime[25];
	char adresa[50];
	char brojMobitela[11];
	int brojPodignutihFilmova;
}CLAN;

#endif