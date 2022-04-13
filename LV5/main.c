#include <stdlib.h>
#include <time.h>

#include "matrix.h"

int main(void) {
    
    srand((unsigned) time(NULL));
    short int m = generiranjeBroja();
    
    short int **polje = NULL;
    
    polje = zauzimanjeMatrice(m);
    
    if (polje == NULL) {
        return 1;
    }
    
    popunjavanjeMatrice(polje, m);
     ispisMatrice(polje, m);
    short int najveciParni = najveciParniBroj(polje, m);
    novaMatrica(polje, m, najveciParni);
    
    ispisMatrice(polje, m);
    
    polje = brisanjeMatrice(polje, m);
    
    return 0;
}