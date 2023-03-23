#include <stdio.h>
#include <stdlib.h>

struct ponto {
  float x;
  float y;
};
typedef struct ponto Ponto;

// |---------p2
// |         |
// p1--------|

float calc_area(Ponto p1, Ponto p2) {
    float largura = p2.x - p1.x; 
    float altura = p2.y - p1.y;
    return largura * altura;
}

int main() {

  Ponto p1 = {.x = 1, .y = 2 };
  Ponto p2 = {.x = 5, .y = 10 };
  float area = calc_area(p1, p2);
  printf("area = %f\n", area);

  return 0;
}