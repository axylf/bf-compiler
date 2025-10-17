/*
to run program: 
cat test1.bf | ./a.out
*/

#include <stdio.h>
#include <fstream>

int main(void) {
  FILE *fptr;
  fptr = fopen("blah.c", "w");
  
  fputs("#include <stdio.h>\nint main(void) {\nchar arr[30000];\nchar *p = arr;\n", fptr);
  //pointer to first value, changes over course of program
  
  char c;
  while (scanf("%c",&c) > 0) {
    switch (c) {
      case '>':
        fputs("p++;\n", fptr);
      break;
      case '<':
        fputs("p--;\n", fptr);
      break;
      case '+':
        fputs("(*p)++;\n", fptr);
      break;
      case '-':
        fputs("(*p)--;\n", fptr);
      break;
      case ',':
        fputs("*p = getchar();\n", fptr);
      break;
      case '.':
        fputs("putchar(*p);\n", fptr);
      break;
      case '[':
        fputs("while(*p) {\n", fptr);
      break;
      case ']':
        fputs("}\n", fptr);
      break;
    }
  }
  fputs("}", fptr);

  fclose(fptr);
}
