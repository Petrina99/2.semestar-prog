/* 3. Napisati C program koji omogućava unos broja n, (1 ≤ 𝑛 ≤ 12) koji predstavlja mjesece u godini.
Ukoliko je unesen broj koji ne odgovara broju mjeseca u godini, ispisati poruku "Krivo uneseni broj
za mjesec" i zatražiti novi unos broja n. Za inicijalizaciju imena mjeseci koristiti polje pokazivača.
Ispisati traženi mjesec. Koristiti isključivo pokazivačku notaciju! */

#include <stdio.h>

int main(void) {

  int n;
  char *mjeseci[] = { 
      "sijecanj", 
      "veljaca", 
      "ozujak", 
      "travanj", 
      "svibanj", 
      "lipanj", 
      "srpanj",
      "kolovoz",
      "rujan",
      "listopad",
      "studeni",
      "prosinac"
    };
  
  printf("Unesite broj koji predstavlja mjesec [1, 12]: ");

  do {
    scanf("%d", &n);

    if (n < 1 || n > 12) {
      printf("Krivo uneseni broj za mjesec. Probaj ponovno: \n");
    }
  } while (n < 1 || n > 12);

  switch(n) {
    case 1:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 2:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 3:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 4:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 5:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 6:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 7:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 8:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 9:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 10:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 11:
      printf("%s", *(mjeseci + n - 1));
      break;
    case 12:
      printf("%s", *(mjeseci + n - 1));
      break;
    default:
      break;
  }

  return 0;
}