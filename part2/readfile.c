#include <stdio.h>

int main () {
  FILE *fp;
  fp = fopen("little_bin_file", "r");
  size_t mem_block_size = 1;
  int num1;
  double num2;
  char num3;
  float num4;
  fread(&num1, sizeof(int), mem_block_size, fp);
  fread(&num2, sizeof(double), mem_block_size, fp);
  fread(&num3, sizeof(char), mem_block_size, fp);
  fread(&num4, sizeof(float), mem_block_size, fp);
  printf("%d \n", num1);
  printf("%f \n", num2);
  printf("%c \n", num3);
  printf("%f \n", num4);
  fclose(fp);
  return 0;
}