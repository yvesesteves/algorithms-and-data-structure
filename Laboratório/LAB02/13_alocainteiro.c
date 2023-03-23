#include <stdio.h>
#include <stdlib.h>

int *aloca_inteiro(int n) {
  return calloc(n, sizeof(int));
}

void print_vet(int *arr, int n) {
  for (int i = 0; i < n; i++) 
    printf("%d\n", arr[i]);
}

int main() {
  int *p;
  p = aloca_inteiro(10);
  print_vet(p, 10);
  free(p);
  return 0;
}