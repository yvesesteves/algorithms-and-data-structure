#include <stdio.h>
#include <stdlib.h>

struct ponto {
  float x;
  float y;
};
typedef struct ponto Ponto;

void inc_dir(Ponto *p, char c) {
  if (c == 'l') {
    p->x += 1;
  } else if (c == 'o') {
    p->x -= 1;
  } else if (c == 'n') {
    p->y += 1;
  } else if (c == 's') {
    p->y -= 1;
  }
}

int main() {
  Ponto p;
  printf("Digite um ponto [x, y]:");
  scanf("%f, %f", &p.x, &p.y);

  char c;
  printf("Digite uma direção: [l]este, [o]este, [n]orte ou [s]ul: "); 
  scanf(" %c", &c);

  inc_dir(&p, c);
  printf("ponto = (%f, %f)\n", p.x, p.y);
  return 0;
}