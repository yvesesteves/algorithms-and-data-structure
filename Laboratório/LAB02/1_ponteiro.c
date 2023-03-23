#include <stdio.h>
#include <stdlib.h>

int main(){  
    int a = 40; // cria uma variável do tipo inteiro, chamada a, e inicializa com valor 40;
    int *p = &a; // cria uma variável do tipo ponteiro para inteiro, chamada p, e o conteúdo inicial é lixo;
     // faz p receber o endereço de a. Dizemos que p aponta para a

    printf("%p\n", &a);
    printf("%p\n", p);

    printf("Digite a: ");
    scanf("%d", p);

    printf("a = %d\n", a);

    return 0;
}