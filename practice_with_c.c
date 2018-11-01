// Written by Andrew Levering and Jan-Edward Gierlach
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void copy (char src[], char dest[]);
int strlength(char str[]);
int replace(char original[], char replacement[]);
void strtolower(char input[]);
int strcompare(char str1[], char str2[]);

int main(int argc[], char** argv) {
  char hello[] = "Hello world";
	
  // Consider looping through to get size of array
  char world[12];
	
  copy (hello, world);
  int helloLength = strlength(hello);
  int worldLength = strlength(world);
	
  printf("hello = %s (length %d), world = %s (length %d)\n", hello, helloLength, world, worldLength);
  replace(hello, "HELLO");
  printf("hello world replaced with HELLO is %s\n", hello);
  
  char capitalletters[] = "CAPITAL LETTERS";
  strtolower(capitalletters);
  printf("Converting CAPITAL LETTERS to capital letters: %s\n", capitalletters);

  char str1[] = "word";
  char str2[] = "WORD";
  printf("Comparing word with WORD: %d\n", strcompare(str1, str2));
}

void copy (char src[], char dest[]) {
	int i;
	while(src[i] != '\0'){
	  dest[i] = src[i];
	  i++;
	}
}

int strlength(char str[]) {
	int i = 0;
	int count = 0;
	while (str[i] != '\0') {
	  i++;
	  count++;
	}
	return count;
}

int replace(char original[], char replacement[]) {
	int i = 0;
	int count = 0;
	
	while (replacement[i] != '\0') {
		if (replacement[i] != original[i]) {
				original[i] = replacement[i];
				count++;
			}
		i++;
	}
	
	if (count > 0) {
		return count;
	}
	return -1;
}

void strtolower(char input[]) {
	int i = 0;
	while (input[i] != '\0') {
		if ((input[i] >= 'A') && (input[i] <= 'Z')) {
			input[i] += 32; 
		}
		i++;
	}
}

int strcompare(char str1[], char str2[]) {
	int str1count = 0;
	int str2count = 0;
	int i = 0;

	while (str1[i] != '\0') {
		str1count += str1[i];
		i++;
	}
	
	i = 0;
	while (str2[i] != '\0') {
		str2count += str2[i];
		i++;
	}
	if (str1count == str2count) {
		return 0;
	} else if (str1count > str2count) {
		return 1;
	}
	return -1;
}