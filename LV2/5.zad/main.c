/* 5. Napisati C program koji omogućava unos broja n (2 ≤ 𝑛 ≤ 8) koji predstavlja broj redova i
stupaca matrice, ponavljati sve dok unos ne odgovara traženom intervalu. Dinamički zauzeti
memorijski prostor za realnu matricu mat (primjenom dinamičkog zauzimanja ne kontinuirane
memorije za dvodimenzionalno polje), te ju popuniti pseudo-slučajnim vrijednostima iz intervala
[-1.25, 5,75], popunjavanje matrice obaviti pomoću funkcije. Ispisati matricu mat u matričnom
obliku, ispis matrice obaviti pomoću funkcije. Pronaći najveći element matrice mat iznad sporedne
i glavne dijagonale i ispisati rezultat na standardnom izlazu, pronalaženje najvećeg elementa
obaviti pomoću funkcije koja će ujedno vratiti najveći pronađeni element, te povratnu vrijednost
funkcije ispisati u glavnom dijelu programa. Na kraju programa osloboditi dinamički zauzetu
memoriju, oslobađanje obaviti pomoću funkcije. Koristiti isključivo pokazivački notaciju! */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

  int n;

  srand((unsigned) time(NULL));
  printf("Unesite broj u intervalu [2, 8]: \n");

  do {
    scanf("%d", &n);
  } while (n < 2 || n > 8);


  return 0;
}