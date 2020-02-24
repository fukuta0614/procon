#include <stdio.h>
#include <stdlib.h>
int main(int argc, char argv[], char envp[]) {
  int   i, ii, A, B, D, E, F;
  char c;

  FILE *ptr;
  ptr = fopen("main", "wb");

  unsigned char buffer[1024];
  int idx = 0;
  while ((i = getchar()) != EOF) {
        ii = getchar();
        D = (i & 0x0f);
        E = (ii & 0xf0) >> 4;
        F = (ii & 0x0f);
        A = D^E;
        B = F;
        buffer[idx++] = ((A<<4)+B);

    printf("\\x%X%X", A, B);
  }

  fwrite(buffer,idx,1,ptr);

  fclose(ptr);

  exit(EXIT_SUCCESS);
}