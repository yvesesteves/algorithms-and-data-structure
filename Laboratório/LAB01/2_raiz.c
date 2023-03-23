#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    printf("-------------DISTANCIA-------------\n");
    int x, y, d;

    printf("Digite as coordenadas de x e y respectivamente\n");
    scanf("%d %d", &x, &y);

    d = sqrt((x*x) + (y*y));
    
    printf("A distancia entre os pontos (%d,%d) e (0,0) eh: %d \n", x, y, d);

    return 0;
}