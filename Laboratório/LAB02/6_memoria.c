#include <stdio.h>
#include <stdlib.h>

int isPar(int n)
{
    if (n % 2 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, *vet, i, contPar = 0, contImpar = 0;

    printf("\nQuantos numeros deseja digitar: ");
    scanf("%d", &n);

    vet = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("\nInforme um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("\nNumeros pares:\n");
    for (i = 0; i < n; i++)
    {
        if (isPar(vet[i]) == 1)
        {
            contPar++;
            printf("%.d\t", vet[i]);
        }
    }

    printf("\nNumeros impares:\n");
    for (i = 0; i < n; i++)
    {
        if (isPar(vet[i]) == 0)
        {
            contImpar++;
            printf("%.d\t", vet[i]);
        }
    }

    printf("\nNumeros inseridos:\n");
    for (i = 0; i < n; i++)
    {
        printf("%.d\t", vet[i]);
    }
    printf("\n\nQuantidade de pares: %d", contPar);
    printf("\n\nQuantidade de impares: %d\n", contImpar);

    free(vet);

    return 0;
}
