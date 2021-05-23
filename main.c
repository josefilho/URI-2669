#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned getWeight(char*);

int main() {
  char s[(int) (10e5 + 1)];

  scanf("%s", s);
  int j, k = 0;

  int possibilities = 0;
  for(unsigned i = 1; i <= (int)strlen(s); ++i){
    possibilities += (int) i;
  }
  unsigned weights[possibilities]; // Store all weights

  char str[(int) (10e5 + 1)],
       *p = (char *) malloc(strlen(s) * sizeof(char));
  strcpy(p, s);

  while(strcmp(p, "") ? 1 : 0){
    strcpy(str, p);
    j = 0;
    do {
      weights[k + j++] = getWeight(str),
      str[strlen(str) - 1] = '\0';
    } while (strcmp(str, "") ? 1 : 0);
    k += j;
    p = &p[1];
  }


  for(int i = 0; i < possibilities; ++i){
    for(j = 1+i; j < possibilities; ++j){
      if(weights[j] == 0) continue;
      if(weights[i] == weights[j]){
        weights[j] = 0;
      }
    }
  }

  int T = 0;
  for(int i = 0; i < possibilities; ++i){
    if(weights[i] != 0) ++T;
  }
  printf("%d\n", T);

  return 0;
}

unsigned getWeight(char *string){
  int totalWeight = 0;
  for(int i = 0; i < (int)strlen(string); ++i){
    totalWeight += (string[i] - 96);
  }
  return totalWeight;
}