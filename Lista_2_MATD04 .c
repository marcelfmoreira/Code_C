//Lista 2 - MATD04 - Pilhas


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef char* string;
typedef enum {FALSE, TRUE} bool;

//Definição de Estrutura

struct pilha{
  struct cell* top;
  int size;
}

struct cell{
	char e;
	struct cell* next;

};

//Questao 1:

void push(pilha* pi, int i){
  cell* nova;
  nova = malloc(sizeof(cell));
  nova->e = int i;
  nova->next = pi->top;
  pi->size ++;
  pi->top = nova;
}

int pop(pilha* pi){
  cell* nova;
  nova = malloc(sizeof(cell));
  nova = pi->top;
  pi->top = pi->top->next;
  int x = nova->e;
  free (nova);
  pi->size --;
  return x;
}

int top(pilha* pi){
  cell* nova;
  nova = malloc(sizeof(cell));
  nova = pi->top;
  int x = nova->element;
  return x;
}

int isEmpty (pilha* pi){
  if (pi->top == NULL || pi->size == 0)
    return 1
  else
    return 0
}


//Questao 2:
// Notacao Polonesa

#define MaxStackSize 100
double stk[MaxStackSize];
int stkcount;


void Push( double element)
{
   if (stkcount == MaxStackSize) 
      printf( "Stack size exceeded.\n");
      exit( EXIT_FAILURE);
   }
   stk[stkcount++] = element;
}

double Pop( void)
{
   if (stkcount == 0) {
      printf( "Pop of an empty stack.\n");
      exit( EXIT_FAILURE);
   }
   return stk[--stkcount];
}


void   ApplyOperator( char op);
void   DisplayStack( void);
string getLine( void);

int main( void){
  string line;
  char ch;

  stkcount = 0;
  while (TRUE) {
    printf( "> ");
    line = getLine();
    ch = toupper( line[0]);

    default : if (isdigit( ch)) 
    Push( atof( line));
    else
    ApplyOperator( ch);
    break;
  }
}
void ApplyOperator( char op){
   double lhs, rhs, result;
   
   rhs = Pop(); // operando direito
   lhs = Pop(); // operando esquerdo
   switch (op) {
      case '+': result = lhs + rhs; break;
      case '-': result = lhs - rhs; break;
      case '*': result = lhs * rhs; break;
      case '/': result = lhs / rhs; break;
      default : printf( "Illegal operator\n"); 
                exit( EXIT_FAILURE);
   }
   printf( "%g\n", result);
   Push( result);
}

string getLine( void){
   string line;
   int n, ch;
   
   n = 0;
   line = malloc( 100+1);
   if (line == NULL) exit( EXIT_FAILURE);
   while ((ch = getc( stdin)) != '\n') {
      if (n >= 100) {
         free( line);
         exit( EXIT_FAILURE);
      }
      line[n++] = ch;
   }
   line[n] = '\0';
   return line;
}





