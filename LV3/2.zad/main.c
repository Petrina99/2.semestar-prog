/* 2. Napisati C program koji omogućuje unos podataka o programerima jedne IT tvrtke, kao što je ime,
prezime, OIB, plaća i datum rođenja, od ukupno 15 programera. Tražiti od korisnika unos broj n
(1 ≤ 𝑛 < 16), ponavljati sve dok unos ne odgovara traženom intervalu. Popuniti informacije o
onoliko programera ovisno o broju n, pronaći programera koji ima najbolju plaću, te ispisati sve
informacije o tome programeru. S obzirom na navedene podatke o programeru, formirati
strukturu koristeći ključnu riječ typedef i pripaziti na ispis formata za datum kako bi bio u obliku
DD.MM.GGGG. */

#include <stdio.h>

typedef struct datum {
  unsigned int dan, mjesec, godina;
}DATUM;

typedef struct programer{
  char ime[20];
  char prezime[20];
  char OIB[13];
  float placa;
  DATUM datumRodenja;
}PROGRAMER;

int main(void) {

  PROGRAMER programeri[15];

  int i, n;

  printf("Unesite neki n u intervalu [1, 16>: \n");

  do {
    scanf("%d", &n);

    if (n < 1 || n >= 16) {
      printf("Ponovite unos: \n");
    }
  } while (n < 1 || n >= 16);

  for (i = 0; i < n; i++) {
    printf("Unesite ime %d. programera: ", i + 1);
    scanf("%19s", programeri[i].ime);
    
    printf("Unesite prezime %d. progamera: ", i + 1);
    scanf("%19s", programeri[i].prezime);

    printf("Unesite OIB %d. progamera: ", i + 1);
    scanf("%12s", programeri[i].OIB);

    printf("Unesite placu %d. programera: ", i + 1);
    scanf("%f", &programeri[i].placa);

    printf("Dan rodjendan %d. programera: ", i + 1);
    scanf("%d", &programeri[i].datumRodenja.dan);

    printf("Mjesec rodjendan %d. programera: ", i + 1);
    scanf("%d", &programeri[i].datumRodenja.mjesec);

    printf("Godina rodenja %d. programera: ", i + 1);
    scanf("%d", &programeri[i].datumRodenja.godina);
  }

  int najveca = 0, p;

  for (i = 0; i < n; i++) {
    if (programeri[i].placa > najveca) {
      najveca = programeri[i].placa;
      p = i;
    }
  }

  printf("Programer s najvecom placom u tvrtki: \n");

  printf("Ime: %s\nPrezime: %s\nOIB: %s\nPlaca: %.2fkn\nDatum rodenja: %d.%d.%d. godine.", programeri[p].ime, programeri[p].prezime, programeri[p].OIB, programeri[p].placa, programeri[p].datumRodenja.dan, programeri[p].datumRodenja.mjesec, programeri[p].datumRodenja.godina);

  return 0;
}