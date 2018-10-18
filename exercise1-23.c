#include <stdio.h>
#include <stdlib.h> 

// What are the states we will encounter?
// if we hit a / and it is followed by another slash we are in a single line comment
// Once we are in a single line comment we will signal the end once we hit a new line character \n
// if we hit a /* we are in a multiline comment we must look for a * and then check if it is followed by a / otherwise we are still in a multiline comment

int main() {

  int forwardSlashCount = 0; 
  int c;
  while((c = getchar()) != EOF) {

    if (forwardSlashCount != 1 && c == '/') {
      // We have encountered our first '/' increase the count by 1 
      ++forwardSlashCount;
    } else if (forwardSlashCount == 1 && c == '/') {
      // We are inside of a single line comment
        while((c = getchar()) != '\n') {
          ;
        }
    } else if (forwardSlashCount == 1 && c == '*') {
      // We are inside of a multiline comment
      while(forwardSlashCount == 1) {
        if((c = getchar()) == '*') {
          if((c = getchar()) == '/') {
            forwardSlashCount = 0;
            break;
          }
        } else {
          ;
        }
      } 
    } else {
      // We are not inside of a comment just print what is there
      putchar(c);
      forwardSlashCount = 0;
    }
  }

}