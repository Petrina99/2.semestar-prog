/* Napisati C program koji omogućuje unos dva broja m i n, gdje je m (3 ≤ 𝑚 ≤ 30), a n (1 ≤ 𝑛 <
11). Omogućiti unos m točaka i n trokuta. Dinamički zauzeti memoriju za polje točaka i polje
trokuta (u potpunosti rukovati memorijom). Pronaći i ispisati trokut koji ima najveći opseg, zajedno
s njegovim indeksom. Opseg najvećeg trokuta ispisati u formatu ("Trokut %d ima opseg %.2f s
koordinatama %f %f %f\n"). Potrebno je izračunati udaljenosti između dvije susjedne točke kako
bi se dobila jedna stranica trokuta, napraviti izračun za preostale dvije stranice i to ponoviti za svaki
trokut iz polja trokuta. Koristiti isključivo pokazivačku notaciju. Koristiti typedef. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct tocka {
  float x;
  float y;
}TOCKA;

typedef struct trokut {
  TOCKA *v1;
  TOCKA *v2;
  TOCKA *v3;
}TROKUT;

int indeks (int i, int m);

int main(void) {

  int m, n, i;

  printf("Unesite broj tocaka [3, 30]: \n");

  do {
    scanf("%d", &m);
  } while (m < 3 || m > 30);

  TOCKA *tocke = NULL;
  TROKUT *trokuti = NULL;

  printf("Unesite broj trokuta [1, 11>: \n");

  do {
    scanf("%d", &n);
  } while (n < 1 || n >= 11);

  tocke = (TOCKA*) calloc(m, sizeof(TOCKA));
  trokuti = (TROKUT*) calloc(n, sizeof(TROKUT));

  if (tocke == NULL || trokuti == NULL) {
    return 1;
  }

  for (i = 0; i < m; i++) {
    printf("Unesite koordinate x,y za tocku %d\n", i + 1);
    scanf("%f %f", &tocke[i].x, &tocke[i].y);
  }

  int ind = 0;

  float opseg, najveciOpseg = 0, a, b, c;

  for (i = 0; i < n; i++) {
    opseg = 0;

    trokuti[i].v1 = &tocke[indeks(i, m)];
    trokuti[i].v2 = &tocke[indeks(i, m)];
    trokuti[i].v3 = &tocke[indeks(i, m)];

    a = sqrt(pow((trokuti[i].v2->x - trokuti[i].v1->x), 2) + pow((trokuti[i].v2->y - trokuti[i].v1->y), 2));
    b = sqrt(pow((trokuti[i].v3->x - trokuti[i].v2->x), 2) + pow((trokuti[i].v3->y - trokuti[i].v2->y), 2));
    c = sqrt(pow((trokuti[i].v3->x - trokuti[i].v1->x), 2) + pow((trokuti[i].v3->y - trokuti[i].v1->y), 2));
    
    opseg = a + b + c;

    if (opseg > najveciOpseg) {
      najveciOpseg = opseg;
      ind = i;
    }
  }

  printf("Trokut %d. ima opseg %.2f s koordinatama (%.2f, %.2f), (%.2f, %.2f), (%.2f, %.2f)\n", ind + 1, najveciOpseg, trokuti[ind].v1->x, trokuti[ind].v1->y, trokuti[ind].v2->x, trokuti[ind].v2->y, trokuti[ind].v3->x, trokuti[ind].v3->y);

  free(tocke);
  free(trokuti);

  return 0;
}

int indeks (int i, int m) {

  int indeks;

  do {
    printf("Odaberite koordinate od 1 do %d za vrh trokuta %d: ", m, i + 1);
    scanf("%d", &indeks);

    if (indeks < 1 || indeks > m) {
      printf("Odabrali ste krivu koordinatu, pokušajte ponovno\n");
    }
  } while (indeks < 1 || indeks > m);

  return indeks - 1;
}