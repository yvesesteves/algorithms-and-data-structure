#include <stdio.h>

int main()
{
    int *vet;
    int n = 5, i;

    vet = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        printf("Informe um numero: ");
        scanf("%d", &vet[i]);
    }

    printf("\nNumeros informados:\n");
    for (i = 0; i < n; i++)
    {
        printf("%.d\t", vet[i]);
    }

    free(vet);

    return 0;
}