/* KR p. 76-79 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
void swap();

main()
{
  int type; /* is it an operator or and operand */
  double op2; /* for subtraction */
  char s[MAXOP]; /* hold operands (i.e., numbers) */

  while((type = getop(s)) != EOF){
    switch(type){
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
      printf("\t%.8g\n", pop());
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
