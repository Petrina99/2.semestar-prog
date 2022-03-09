/* 2. Proširiti prvi zadatak tako da se provjerio koji dan ima najviše suglasnika, te ispisati naopako dan s
najvećim brojem suglasnika. Koristiti isključivo pokazivačku notaciju! */

#include <stdio.h>
#include <string.h>

int main(void) {

  int i, j, s, priv = 0;
  char *dani[] = { "ponedjeljak", "utorak", "srijeda", "cetvrtak", "petak", "subota", "nedjelja" };
  char *dan[] = { NULL };

  for (i = 0; i < 7; i++) {
    s = 0;

    for (j = 0; *(*(dani + i) + j) != '\0'; j++) {
      
      if (*(*(dani + i) + j) != 'a' && *(*(dani + i) + j) != 'e' && *(*(dani + i) + j) != 'o' && *(*(dani + i) + j) != 'i' && *(*(dani + i) + j) != 'u') {
        s++;
      }
    }

    if (s > priv) {
      priv = s;
      *dan = *(dani + i);
    }
  }

  int n = strlen(*dan);

  for (i = n - 1; i >= 0; i--) {
    printf("%c", *(*dan + i));
  }

  printf("\n");

  printf("%s", *dan);

  return 0;
}