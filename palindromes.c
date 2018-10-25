/* KR p. 20 */
//#include <stdio.h>
// Get the length of the string passed in
// See if the string is an even or odd number
// Two pointers on either end of the string
// One pointer is set to 0 and the other is set to the length of the string
// Compare are the first and last equal
// if they are increment the one pointer and decrement the next

int isPalindrome (char input[]) {
  int j = sizeof(input) -2;
  int i = 0;
  while(input[i] != '\0') {
    if (input[i] == input[j]) {
      ++i;
      --j;
    } else {
      printf("NOT a palindrome");  
      return 0;      
    }
  }
  printf("IS a palindrome");
  return 1;
}

int main(int argc, char*str[]) {
  if(argc < 2) {
    printf("You have entered the incorrect number of command line args");
    exit(2); 
  }
  int i = 1;
  while(i < argc) {
   printf("Arg: %d \t", i);   
   printf("%c \n", isPalindrome(str[i]));
   ++i;
  }  
}