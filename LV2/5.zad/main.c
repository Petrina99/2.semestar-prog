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

// ne radi kak spada al moze posluzit jebiga

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void popuni (float **p, int n);
void ispis (float **p, int n);
float najveciElement (float **p, int n);
float** oslobodi (float **p, int n);

int main(void) {

  int n, i;

  srand((unsigned) time(NULL));
  printf("Unesite broj u intervalu [2, 8]: \n");

  do {
    scanf("%d", &n);
  } while (n < 2 || n > 8);

  float **mat = NULL;

  mat = (float**) calloc(n, sizeof(float*));

  if (mat == NULL) {
    return 1;
  }

  for (i = 0; i < n; i++) {
    *(mat + i) = (float*) calloc(n, sizeof(float));

    if (*(mat + i) == NULL) {
      return 1;
    }
  }

  popuni(mat, n);
  ispis(mat, n);

  float max = najveciElement(mat, n);

  printf("%.2f", max);

  mat = oslobodi(mat, n);

  return 0;
}

void popuni (float **p, int n) {

  int i, j;

  for (i = 0; i < n; i++) {

    for (j = 0; j < n; j++) {
      *(*(p + i) + j) = -1.25 + (float) rand() / RAND_MAX * (5.75 + 1.25);
    }
  }
}

void ispis (float **p, int n) {
  int i, j;

  for (i = 0; i < n; i++) {

    for (j = 0; j < n; j++) {
      printf("%.2f\t", *(*p + i) + j);
    }

    printf("\n");
  }
}

float najveciElement (float **p, int n) {

  int i, j, z = 0;
  float *pom = NULL;
  float max = 0;

  for (i = 0; i < n; i++) {

    for (j = 0; j < n; j++) {

      if (i < j && (i + j < n - 1)) {
        *(pom + z) = *(*(p + i) + j);
        z++;
      }
    }
  }

  for (i = 0; i < z; i++) {
    if (*(pom + i) > max) {
      max = (*pom + i);
    }
  }

  return max;
}

float** oslobodi (float **p, int n) {
  int i;

  for (i = 0; i < n; i++) {
    free(*(p + i));
  }

  free(p);

  return NULL;
}