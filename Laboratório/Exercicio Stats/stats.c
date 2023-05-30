#include <stdio.h>
#include "stats.h"
#include <math.h>

float soma(float *arr, int n) {
  float s = 0;
  for (int i = 0; i < n; i++) {
    s += arr[i];
  }

  return s;
}

float media(float *arr, int n) {
  float m = soma(arr, n);
  m /= n;
  return m;
}

float desvio(float *arr, int n) {
  float m = media(arr, n);
  float d = 0;
  for (int i = 0; i < n; i++) {
    float diff = (arr[i] - m);
    d += diff * diff;
  }

  d /= (n - 1);
  d = sqrt(d);

  return d;
}
