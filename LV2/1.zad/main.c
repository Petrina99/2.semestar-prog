/* 1. Napisati C program koji omogućava unos broja n, (1 ≤ 𝑛 ≤ 7) koji predstavlja dane u tjednu.
Ukoliko je unesen broj koji ne odgovara broju dana u tjednu, ispisati poruku "Krivo uneseni broj za
dan" i zatražiti novi unos broja n. Za inicijalizaciju imena dana koristiti polje pokazivača. Ispisati
traženi dan. Koristiti isključivo pokazivačku notaciju! */

#include <stdio.h>

int main(void) {

  int n;
  char *dani[] = { "Pon", "Uto", "Sri", "Cet", "Pet", "Sub", "Ned" };

  printf("Unesite broj koji predstavlja dan u tjednu [1, 7]: ");

  do {
    scanf("%d", &n);

    if (n < 1 || n > 7) {
      printf("Krivo uneseni broj za dan. Probaj ponovno: \n");
    }
  } while (n < 1 || n > 7);

  switch(n) {
    case 1:
      printf("%s", *(dani + n - 1));
      break;
    case 2:
      printf("%s", *(dani + n - 1));
      break;
    case 3:
      printf("%s", *(dani + n - 1));
      break;
    case 4:
      printf("%s", *(dani + n - 1));
      break;
    case 5:
      printf("%s", *(dani + n - 1));
      break;
    case 6:
      printf("%s", *(dani + n - 1));
      break;
    case 7:
      printf("%s", *(dani + n - 1));
      break;
    default:
      break;
  }

  return 0;
}