#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "dataType.h"

int izbornik(const char* const, const char* const);
void kreiranjeDatoteke(const char* const);
void kreiranjeDatotekeFilmovi(const char* const);
void dodajKorisnika(const char* const);
void* ucitajKorisnike(const char* const);
void ispisiSveKorisnike(const CLAN* const);
void* pretraziClanove(CLAN* const);
void dodajFilm(const char* const);
void* ucitajFilmove(const char* const);
void ispisiSveFilmove(const FILM* const);
void* pretraziFilmove(FILM* const);
void posudba(CLAN*, FILM*, const char* const, const char* const);
int izlazIzPrograma(CLAN*, FILM*);

#endif
