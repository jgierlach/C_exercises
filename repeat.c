/* KR p. 20 */
#include <stdio.h>

int isRepeat (char input[]) {
  int i = 0;
  while(input[i] != '\0') {
    if (input[i] == input[i + 1]) {
      return 0;
      break;
    }
    i++;
  }
}

int main(int argc, char*str[]) {
  int repeats = 0;
  int numWords = argc -1;
  if(argc < 2) {
    printf("You have entered the incorrect number of command line args");
    exit(2); 
  }
  int i = 1;
  while(i < argc) {
   if(isRepeat(str[i]) == 0) {
     ++repeats;
   }
   ++i;
  }
  printf("the number of words were %d and %d of those words had repeats", numWords, repeats);  
}
