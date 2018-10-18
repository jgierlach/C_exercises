#include <stdio.h>
#include <stdlib.h> 
//Write a program to count blanks, tabs, and newlines. 

main() {
  int c;
  int blankCount = 0;
  int tabCount = 0;
  int newLineCount = 0;
  while((c = getchar()) != EOF) {
    if (c == '\t') {
      ++tabCount;
    }
    if (c == '\n') {
      ++newLineCount;
    }
    if (c == ' ') {
      ++blankCount;
    }
  }
  printf("I have %d blanks I have %d tabs I have %d new lines", blankCount, tabCount, newLineCount);
}