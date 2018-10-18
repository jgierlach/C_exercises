#include <stdio.h>
#include <stdlib.h> 
// Write a program to copy its input to its output, replacing each string of one or

int main() {
  int c;
  while((c = getchar()) != EOF) {
    if (c == '\t') {
    //   printf("\\t");
     putchar('\\');
     putchar('t');
   } else if (c == '\\') {
    //   printf("\\\\");
     putchar('\\');
     putchar('\\');   
   } else if(c == '\b') {
    //   printf("\\b");
     putchar('\\');
     putchar('b');
   } else {
      putchar(c);
   } 
 }
}

