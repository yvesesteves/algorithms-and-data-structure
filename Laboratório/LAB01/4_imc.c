#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float massa = 0.0;
    float altura = 0.0;
    float altura_2 = 0.0;
    
    float imc;
    printf("----------IMC----------\n");
    printf("Digite a massa(kg) e a altura(m) respectivamente para calcular seu IMC\n");
    scanf("%f %f", &massa, &altura);
    
    altura_2 = pow(altura,2);
    imc = massa/altura_2;

    if(imc < 18.5){
        printf("Seu IMC eh de %.1f --> Magreza\n", imc);
    }
    else if((imc >= 18.5) && (imc <= 24.9)){
        printf("Seu IMC eh de %.1f --> Saudavel\n", imc);
    }else if((imc >= 25.0) && (imc <= 29.9)){
        printf("Seu IMC eh de %.1f --> Sobrepeso\n", imc);
    }else if((imc >= 30.0) && (imc <= 34.9)){
        printf("Seu IMC eh de %.1f --> Obesidade Grau 1\n", imc);
    }else if((imc >= 35.0) && (imc <= 39.9)){
        printf("Seu IMC eh de %.1f --> Obesidade Grau 2 (severa)\n", imc);
    }else{
        printf("Seu IMC eh de %.1f --> Obesidade Grau 3 (morbida)\n", imc);
    }

    return 0;

}