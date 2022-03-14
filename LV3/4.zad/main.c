/* 4. Deklarirati strukturu stan koja ima članove: površina, cijena, adresa, energetski razred, klima
uređaj [1/0]. Omogućiti korisniku unos podataka za željeni broj stanova (max. 20) u polje struktura.
Ponavljati unos dokle god je željeni broj manji od 2, a veći od 20. Ispisati podatke o svim unesenim
stanovima kod kojih je cijena po kvadratu manja od 900 eura i sve stanove kojima je cijena veća od
1100 eura po kvadratu, a nemaju klima uređaj.
Ako nema takvih stanova ispisati tekst: „Niti jedan stan ne odgovara kriterijima.“, a ako ima takvih
stanova ispisati ih u formatu „adresa, cijena“ za svaki takav stan u novi red.*/

#include <stdio.h>

typedef struct stan{
  int povrsina;
  float cijena;
  char adresa[40];
  char energetskiRazred[3];
  int klima;
}STAN;

int main(void) {

  int i, n;
  STAN stanovi[20];

  printf("Unesite broj stanova [2, 20]: \n");

  do {
    scanf("%d", &n);

    if (n < 2 || n > 20) {
      printf("Prevelik broj stanova. Unesi broj u intervalu od 2 do 20: \n");
    }
  } while (n < 2 || n > 20);

  for (i = 0; i < n; i++) {
    printf("Povrsina %d. stana: \n", i + 1);
    scanf("%d", &stanovi[i].povrsina);

    printf("Cijena %d. stana (u EUR): \n", i + 1);
    scanf("%f", &stanovi[i].cijena);

    getchar();

    printf("Adresa %d. stana: \n", i + 1);
    fgets(stanovi[i].adresa, 40, stdin);

    printf("Energetski razred %d. stana (A+ ,A, B, C, D, E, F, G): \n", i + 1);
    scanf("%2s", stanovi[i].energetskiRazred);

    printf("Ima li %d. stan klimu (1 - da, 0 - ne): \n", i + 1);
    scanf("%d", &stanovi[i].klima);
  }

  printf("Stanovi ispod 900 EUR po kvadratu: \n"); 

  int stanoviIspod = 0;

  for (i = 0; i < n; i++) {

    if (stanovi[i].cijena / stanovi[i].povrsina < 900) {
      printf("Adresa: %s Povrsina: %d m^2\n Cijena: %.2f\n Energetski razred: %s\n klima: %s\n", stanovi[i].adresa, stanovi[i].povrsina, stanovi[i].cijena, stanovi[i].energetskiRazred, stanovi[i].klima == 1 ? "da" : "ne");

      stanoviIspod++;
    }
  }

  if (stanoviIspod == 0) {
    printf("Niti jedan stan ne odgovara kriterijima.\n");
  }

  printf("Stanovi iznad 1100 EUR bez klime: \n");

  int stanoviIznad = 0;

  for (i = 0; i < n; i++) {

    if (stanovi[i].cijena / stanovi[i].povrsina > 1100 && stanovi[i].klima == 0) {
      printf("Adresa: %s Povrsina: %d m^2\n Cijena: %.2f\n Energetski razred: %s\n klima: %s\n", stanovi[i].adresa, stanovi[i].povrsina, stanovi[i].cijena, stanovi[i].energetskiRazred, stanovi[i].klima == 1 ? "da" : "ne");

      stanoviIznad++;
    }
  }

  if (stanoviIznad == 0) {
    printf("Niti jedan stan ne odgovara kriterijima.\n");
  }
  return 0;  
}