#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


#define MAXOP 100
#define NUMBER '0'
#define FUNCTION 'f'

int getop(char []);
void push(double);
void checkFunction(char[]);
double pop(void);
void swap();
// m by default is initialized to 0
double m = 0;

main()
{
  int type; /* is it an operator or and operand */
  double op2; /* for subtraction */
  char s[MAXOP]; /* hold operands (i.e., numbers) */

  while((type = getop(s)) != EOF){
    switch(type){
    case 'M':
      push(m);
      break; 
    case FUNCTION:
      checkFunction(s);
      break;
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;   
    case '-':
      swap();
      push(pop() - pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '/':
      swap();
      push(pop() / pop());
      break;
    case '%':
      swap();
      push((int) pop() % (int) pop());
      break;
    case '\n':
      m = pop();
      printf("\t%.8g\n", m);
      printf("%lf \n", m);
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push (double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, cant push %g\n",f);
}

double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else
    {
      printf("error: stack empty \n");
      return 0.0;
    }
}

int getch(void);
void ungetch(int);

int getop(char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  // We have to check M first because it is a character so if we put it after the genaric character check we will never hit that conditional logic
  if(c == 'M') {
    return 'M';  
  }
  
  // Check if c is a character
  if(isalpha(c)) {
    while(isalpha(s[++i] = c = getch()))
     ;
     s[i] = '\0';
    if(c != EOF) 
      ungetch(c);
    // If this condition is met we know to return the function case of our switch statement which will then evaluate whether or not the operation is sin or pow or exp
    if(strlen(s) > 1) { 
      return FUNCTION;
    } else {
      return c;
    }
  }

  // check for negative
  if(c == '-') {
    int nextChar = getch();
    // if this condition is true then it is not a number so simply return nextChar
    if(!isdigit(nextChar) && nextChar != '.') {
      return nextChar;
    } 
    // otherwise we know it is a number and should invoke the NUMBER case of of our switch statement
    ungetch(nextChar); 
    if(isdigit(nextChar)) {
      int i = 0;
      while(isdigit(s[++i] = c = getch()))
        ;
      return NUMBER;
    }
  }

  if(!isdigit(c) && c != '.')
    return c; /* not a number */
  i = 0;
  if (isdigit(c)) /* collect integer part */
    while(isdigit(s[++i] = c = getch()))
      ;
  if(c=='.') /* collect fraction part */
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  if(c != EOF)
    ungetch(c);
  return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

void swap() {
  double x, y;
  x = pop();
  y = pop();
  push(x);
  push(y);
}

int getch(void)
{
  return(bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
  if(bufp >= BUFSIZE){
    printf("ungetch: too many characters\n");
  }
  else
    {
      buf[bufp++] = c;
    }
}

// Based on what the string is we will either perform a sin, exp, or pow
void checkFunction(char s[]) {
  if(strcmp(s, "sin") == 0) {
     push(sin(pop()));
  } else if(strcmp(s, "exp") == 0) {
    push(exp(pop()));
  } else if(strcmp(s, "pow") == 0) {
    // We must pop twice for pow to get both the base and exponent  
    push(pow(pop(), pop()));
  }
} 
