#include <stdio.h>
#include <stdlib.h>

void printTriangle(int size);
int factorial(int x);

int main(int argc, char **argv) {
  int size = atoi(argv[1]);
  printTriangle(size);
  return 0;
}

void printTriangle(int size) {
  int prod;
  for (int n = 0; n < size; n++) {
    for (int k = 0; k <= n; k++) {
      prod = factorial(n)/(factorial(k) * factorial(n - k));
      printf("%d ", prod);
    }
    printf("\n");
  }
}

int factorial(int x) {
  int result = 1;
  for (int i = x; i > 0; i--) {
    result = result * i;
  }
  return result;
}