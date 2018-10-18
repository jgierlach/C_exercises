#include <stdio.h>
#include <stdlib.h> 
// Take the temperature converter and turn it into a function. 

void temperatureConversion() {
  int upper = 300;
  int step = 20;
  int fahr = 0;
  int celsius = 0;
  while(fahr <= upper) {
    celsius = 5 * (fahr - 32) / 9;
    printf("%d\t%d\n", fahr, celsius);
    fahr = fahr + step;
  }      
}

main() {
  temperatureConversion();
}