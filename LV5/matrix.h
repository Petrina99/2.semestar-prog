#ifndef MATRIX_H
#define MATRIX_H

    short int generiranjeBroja(void);
    short int** zauzimanjeMatrice(short int m);
    short int** brisanjeMatrice(short int **p, short int m);
    void popunjavanjeMatrice(short int **p, short int m);
    short int najveciParniBroj(short int **p, short int m);
    void novaMatrica(short int **p, short int m, short int parni);
    void ispisMatrice (short int **p, short int m);
    
#endif //MATRIX_H