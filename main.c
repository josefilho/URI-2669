#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned getWeight(char*);

int main() {
  char s[(int) (10e5 + 1)];

  strcpy(s, "abaa");
  int lenght = (int)strlen(s), j;
  long long int k = 0;

  int possibilidades = 0;
  for(int i = 1; i <= lenght; ++i){
    possibilidades += i;
  }


  return 0;
}

unsigned getWeight(char *string){
  int pesoTotal = 0;
  for(int i = 0; i < (int)strlen(string); ++i){
    pesoTotal += (string[i] - 96);
  }
  return pesoTotal;
}