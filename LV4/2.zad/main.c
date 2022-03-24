/* 2 Napisati C program koji će u polje struktura artikl omogućiti unos n artikala (struktura ima članove
ime, cijena i kolicina), gdje je n (1 ≤ 𝑛 ≤ 50). Dinamički zauzeti memoriju za polje artikala (u
potpunosti rukovati memorijom). U pokazivač na strukturu artikl max spremiti memorijsku adresu
najskupljeg artikla. Ispisati podatke o najskupljem artiklu. Koristiti isključivo pokazivačku notaciju.
Koristiti typedef.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct artikl {
  char ime[20];
  float cijena;
  int kolicina;
}ARTIKL;

int main(void) {

  int n, i;

  printf("Unesite n artikala [1, 50]: \n");

  do {
    scanf("%d", &n);
  } while (n < 1 || n > 50);

  ARTIKL *artikli = NULL;
  ARTIKL *max = NULL;

  artikli = (ARTIKL*) calloc(n, sizeof(ARTIKL));

  if (artikli == NULL) {
    return 1;
  }

  for (i = 0; i < n; i++) {
    getchar();

    printf("Unesite ime %d. artikla: \n", i + 1);
    fgets(artikli[i].ime, 20, stdin);

    printf("Cijena %d. artikla: \n", i + 1);
    scanf("%f", &artikli[i].cijena);

    printf("Kolicina %d. artikla: \n", i + 1);
    scanf("%d", &artikli[i].kolicina);
  }

  float maks = 0;
  int maksI = 0;

  for (i = 0; i < n; i++) {
    if (artikli[i].cijena > maks) {
      maks = artikli[i].cijena;
      maksI = i;
    }
  }

  max = &artikli[maksI];

  printf("Ime: %s, cijena: %.2f kn, kolicina: %d", max->ime, max->cijena, max->kolicina);

  free(artikli);

  return 0;
}