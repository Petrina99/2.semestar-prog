/* Napisati C program u kojemu treba napraviti novi složeni tip podatka struct kompleksni pod
nazivom KOMPLEKSNI i kreirati strukturne varijable br1, br2, rez. Struktura KOMPLEKSNI treba
sadržavati sljedeće realne članove: re i im. Omogućiti unos dva kompleksna broja. Izračunati i
ispisati zbroj, razliku, produkt, količnik dva kompleksna broja u obliku re + im*i, pripaziti na
predznak ako je imaginarna komponenta negativna, te izračunati modul svakog kompleksnog
broja 

Opći oblik kompleksnog broja:
𝑧 = 𝑎 + 𝑏 ∙ 𝑖

Zbrajanje i oduzimanje:
(𝑎 + 𝑏𝑖) ± (𝑐 + 𝑑𝑖) = (𝑎 ± 𝑐) + (𝑏 ± 𝑑) ∙ 𝑖

Množenje:
(𝑎 + 𝑏𝑖) ∙ (𝑐 + 𝑑𝑖) = (𝑎 ∙ 𝑐 − 𝑏 ∙ 𝑑) + (𝑎 ∙ 𝑑 + 𝑏 ∙ 𝑐) ∙ 𝑖

Dijeljenje:
𝑎 + 𝑏𝑖 / 𝑐 + 𝑑𝑖 = 𝑎 + 𝑏𝑖 / 𝑐 + 𝑑𝑖 * 𝑐 − 𝑑𝑖 / 𝑐 − 𝑑𝑖 = (𝑎𝑐 + 𝑏𝑑) + (𝑏𝑐 − 𝑎𝑑) ∙ 𝑖 / 𝑐2 + 𝑑2

𝑧 = √𝑎2 + 𝑏2
*/ 

#include <stdio.h>
#include <math.h>

typedef struct kompleksni {
  float re, im;
}KOMPLEKSNI;

int main(void) {

  KOMPLEKSNI br1;
  KOMPLEKSNI br2;
  KOMPLEKSNI rez;

  printf("Unesite dva kompleksna broja: \n");

  printf("Realni dio 1. broja: \n");
  scanf("%f", &br1.re);

  printf("Imaginarni dio 1. broja: \n");
  scanf("%f", &br1.im);

  printf("Realni dio 2. broja: \n");
  scanf("%f", &br2.re);

  printf("Imaginarni dio 2. broja: \n");
  scanf("%f", &br2.im);

  printf("Opci oblik prvog broja: %.2f %c %.2fi\n", br1.re, br1.im < 0 ? '-' : '+', fabs(br1.im));
  printf("Opci oblik drugog broja: %.2f %c %.2fi\n", br2.re, br2.im < 0 ? '-' : '+', fabs(br2.im));

  //zbroj
  rez.re = br1.re + br2.re;
  rez.im = br1.im + br2.im;

  printf("Zbroj iznosi: %.2f %c %.2fi\n", rez.re, rez.im < 0 ? '-' : '+', fabs(rez.im));

  //razlika
  rez.re = br1.re - br2.re;
  rez.im = br1.im - br2.im;

  printf("Razlika iznosi: %.2f %c %.2fi\n", rez.re, rez.im < 0 ? '-' : '+', fabs(rez.im));

  // umnozak
  rez.re = br1.re * br2.re - br1.im * br2.im; 
  rez.im = br1.re * br2.im + br1.im * br2.re; 

  printf("Umnozak iznosi: %.2f %c %.2fi\n", rez.re, rez.im < 0 ? '-' : '+', fabs(rez.im));

  // kvocijent - ne valja neznam matku
  rez.re = (br1.re * br2.re + br1.im * br2.im) / pow(br2.re, 2) + pow(br2.im, 2);
  rez.im = (br1.im * br2.re - br1.re * br2.im) / pow(br2.re, 2) + pow(br2.im, 2);

  printf("Kvocijent iznosi: %.2f %c %.2fi\n", rez.re, rez.im < 0 ? '-' : '+', fabs(rez.im));
  return 0;
}