#include <stdio.h>
#include <string.h>

int check_line();

int main() {
   char str[100];
   
   int lines = check_line();
   printf("%d", lines);

   FILE *file = fopen("input.txt", "r");
   fgets(str, 100, file);
   printf("%s", str);
   fclose(file);
  
}

int check_line() {
   FILE *file =  fopen("input.txt", "r");
   int lines = 0;
   
   while (!feof(file))
      if (fgetc(file) == '\n')
         lines++;

   fclose(file);
   return lines;
}
