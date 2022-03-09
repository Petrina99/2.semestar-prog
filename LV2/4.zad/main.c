/* Proširiti treći zadatak tako da se provjeri koji mjesec ima najveću srednju vrijednost znakova u
imenu, te tako pronađenom mjesecu ispisati naopako ime. Koristiti isključivo pokazivačku notaciju */

#include <stdio.h>
#include <string.h>

int main(void) {

  int i, j, sv, priv = 0;

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

  char *najveci[] = { NULL };

  for (i = 0; i < 12; i++) {
    sv = 0;

    for (j = 0; *(*(mjeseci + i) + j) != '\0'; j++) {
      sv += *(*(mjeseci + i) + j);
    }

    if (sv > priv) {
      priv = sv;
      *najveci = *(mjeseci + i);
    }
  }

  int n = strlen(*najveci);

  for (i = n - 1; i >= 0; i--) {
    printf("%c", *(*najveci + i));
  }

  printf("\n");
  printf("%s", *najveci);

  return 0;
}