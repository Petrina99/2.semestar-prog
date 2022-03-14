/* 3. Napisati program u C jeziku u kojem se treba kreirati novi složeni tip podatka struct cijeli_broj pod
nazivom CIJELI_BROJ. Struktura CIJELI_BROJ treba sadržavati dva cijela člana tipa long za
uneseni_broj i int za broj_znamenaka. U član uneseni_broj potrebno je upisati generirani P-S broj
iz intervala [-2147483648, 2147483647], a u član broj_znamenaka potrebno je upisati koliko
generirani broj ima znamenaka. Za generiranje P-S vrijednosti potrebno je koristiti funkciju koja ne
prima argumente, a vraća P-S generiranu vrijednost, a za izračunavanje broja znamenaka potrebno
je također koristiti funkciju koja prima P-S generirani broj (član uneseni_broj) te izračunava i vraća
broj znamenaka. U glavnom dijelu programa potrebno je kreirati polje struktura CIJELI_BROJ od 40
elemenata, te pomoću ranije spomenutih funkcija popuniti članove pojedine strukture iz polja
struktura. Pronaći i ispisati sve članove strukture koja ima najveći, kao i strukturu koja ima najmanji
broj znamenaka generiranog broja. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct cijeli_broj {
  long int uneseni_broj;
  int broj_znamenaka;
}CIJELI_BROJ;

int generiraj();
int brojZnamenki(long int a);

int main(void) {

  int i;

  CIJELI_BROJ br[40]; 
  
  srand((unsigned) time(NULL));

  for (i = 0; i < 40; i++) {
    br[i].uneseni_broj = generiraj();
    br[i].broj_znamenaka = brojZnamenki(br[i].uneseni_broj);
  }

  int najmanji = br[0].broj_znamenaka;
  int najveci = br[0].broj_znamenaka;
  int manjiIndeks, veciIndeks;

  for (i = 0; i < 40; i++) {
    if (br[i].broj_znamenaka > najveci) {
      veciIndeks = i;
    }

    if (br[i].broj_znamenaka < najmanji) {
      manjiIndeks = i;
    }
  }

  printf("Struktura sa najmanjim brojem znamenki: \n");

  printf("uneseni_broj: %ld\nbroj znamenki: %d\n", br[manjiIndeks].uneseni_broj, br[manjiIndeks].broj_znamenaka);

  printf("Struktura sa najvecim brojem znamenki: \n");

  printf("uneseni_broj: %ld\nbroj znamenki: %d", br[veciIndeks].uneseni_broj, br[veciIndeks].broj_znamenaka);

  return 0;
}

int generiraj() {
  long int a;

  a = -2147483648 + (float)rand() / RAND_MAX * (2147483647 + 2147483648);

  return a;
}

int brojZnamenki(long int a) {

  int br = 0;

  do {
    a /= 10;
    br++;
  } while (a != 0);

  return br;
}