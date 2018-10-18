#include <stdio.h>
#include <stdlib.h> 
// Write a program to copy its input to its output, replacing each string of one or

int main() {
  int c;
  int blankCount = 0;
  while((c = getchar()) != EOF) {
    // In the event that a space has not been seen before and one is found
    // Print the single space character and update blankCount to be 1
    if (blankCount != 1 && c == ' ') {
      putchar(c);
      blankCount++;
    } else if (blankCount == 1 && c == ' ') {
      //print nothing
      ;
     } else if (c != ' ') {
      putchar(c);
      blankCount = 0;
    }  
  }
}