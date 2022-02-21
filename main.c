#include <stdio.h>

void input(int *mode, char *str);

int main() {
   int mode;
   char str[100];

   input(&mode, str);

   puts(str);
}

void input(int *mode, char *str) {
   printf("Select mode for input data:\n 0 - manual input\n 1 - from the file\nMode: ");
   scanf("%d", mode);

   if (*mode == 0) {
      printf("Input string: ");
      while (fgets(str, 100, stdin) != NULL);
   }
}