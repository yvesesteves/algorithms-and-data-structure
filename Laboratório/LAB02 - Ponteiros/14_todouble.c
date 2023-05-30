#include <stdio.h>
#include <stdlib.h>

double *to_double(int *int_arr, int n) {
  double *double_arr = malloc(n * sizeof(double));

  for (int i = 0; i < n; i++) {
    double_arr[i] = int_arr[i];
  }

  return double_arr;
}

int main() {
  int *int_arr = malloc(5 * sizeof(int));
  int_arr[0] = 1;
  int_arr[1] = 2;
  int_arr[2] = 3;
  int_arr[3] = 4;
  int_arr[4] = 5;

  double *double_arr = to_double(int_arr, 5);

  for (int i = 0; i < 5; i++) {
    printf("%lf\n", double_arr[i]);
  }

  free(int_arr);
  free(double_arr);
  return 0;
}