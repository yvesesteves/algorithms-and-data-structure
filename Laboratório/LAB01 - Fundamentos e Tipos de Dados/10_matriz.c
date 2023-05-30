#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() { 

    int mat[4][4] = {
        { 1,  2,  3,  4  },
        { 5,  6,  7,  8  },
        { 9,  10, 11, 12 },
        { 13, 14, 15, 16 },
    };

    int soma = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4 - i; j++) {
            soma = soma + mat[i][j];
        }
    }
    
    printf("soma = %d\n", soma);

    return 0; 
}