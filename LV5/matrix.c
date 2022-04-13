#include <stdio.h>
#include <stdlib.h>

short int generiranjeBroja(void) {
    
    short int m = 3 + (float)rand() / RAND_MAX * (18 - 3);
    
    return m;
}

short int** zauzimanjeMatrice(short int m) {
    
    int i;
    short int **p = NULL;
    
    p = (short int**)calloc(m, sizeof(short int*));
    
    if (p == NULL) {
        return NULL;
    }
    
    for (i = 0; i < m; i++) {
        
        *(p + i) = (short int*)calloc(m, sizeof(short int));
    
        if (*(p + i) == NULL) {
            return NULL;
        }
    }
    
    return p;
}

short int** brisanjeMatrice(short int **p, short int m) {
    
    int i;
    
    for (i = 0; i < m; i++) {
        free(*(p + i));
    }
    
    free(p);
    
    return NULL;
}

void popunjavanjeMatrice(short int **p, short int m) {
    
    int i, j;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            *(*(p + i) + j) = -1550 + (float)rand() / RAND_MAX * (250 - (-1550));
        }
    }
}

short int najveciParniBroj(short int **p, short int m) {
    int i, j;
    
    short int max = **p;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            
            if (i + j >= m) {
                
                if (*(*(p + i) + j) % 2 == 0 && *(*(p + i) + j) > max) {
                    max = *(*(p + i) + j);
                }
            }
        }
    }
    
    return max;
}

void novaMatrica(short int **p, short int m, short int parni) {
    
    int i, j;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            
            if (i + j < m - 1) {
                *(*(p + i) + j) = parni;
            }
        }
    }
}

void ispisMatrice (short int **p, short int m) {
    
    int i, j;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < m; j++) {
            printf("%3d ", *(*(p + i) + j));
        }
        
        printf("\n");
    }
}