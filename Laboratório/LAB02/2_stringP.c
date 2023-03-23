#include <stdio.h>
#include <stdlib.h>

int main(){
    char nome[] = "Jose Augusto";
    char *p;
    int i;

    p = &nome[0];

    for(i = 0; i < 12; i++){
        printf("%c", *p);
        p++;
    }

    /*
    outro modo de fazer:
        char nome[] = "jose augusto";
        char *p = &nome;
        scanf("%s", p);

        for(int i=0; i < p[i] != '\0'; i++){
            printf("%c", p[i]);
        }
    */

    return 0;
}