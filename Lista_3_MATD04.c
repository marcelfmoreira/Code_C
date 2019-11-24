
#include <stdio.h>
#include <stdlib.h>

//Definição de Estrutura
struct fila{
  node* first, last;
  int size;
};


struct node{
	char e;
	struct node* next;

};

typedef struct fila fila;
typedef struct node node;

//Questao 1:
//Manipulacao realizada considerando que a estrutura da fila ja possui
//os objetos first e last, além o inteiro size que mapeia seu tamanho

void put(fila* q, int i){
  node *aux = malloc(sizeof(node));
  aux ->next = null;
  aux = q->last
  q->last->next = aux;
  aux->e = i;
  q->size ++;
  q->last = aux;
}

int get(fila* q){
  q->size --;
  aux = q->first;
  q->first->next = aux->next;
  int x = q->first->e;
  free (q);
  return x;
}

int isEmpty(fila* q){
  if (q->first == NULL)
    return 1;
  else
    return 0;
}


//Questao 1.1:
// novas funcoes basicas implementadas com arrays ao inves de 
// ponteiros

const int TamanhoFila = 5;

int PU_PosIni = 0;
int PU_QtdElementos = 0;

int PU_Fila[TamanhoFila];

int insere( int PA_Valor )
{
   if( PU_QtdElementos < TamanhoFila )
   {
      int L_PosReal = ( PU_PosIni+PU_QtdElementos );
      if( L_PosReal > TamanhoFila ) L_PosReal = L_PosReal-TamanhoFila;
      PU_Fila[L_PosReal] = PA_Valor;
      printf ("Adicionou[%d] = %d \n", L_PosReal, PU_Fila[L_PosReal]);
      PU_QtdElementos++;
      return 0;
   }
   printf ("Fila cheia!!! \n");
   return 1;
}

int remover()
{
   if( PU_QtdElementos > 0 )
   {
      int LO_Valor = PU_Fila[PU_PosIni];
      printf ("Removeu[%d] = %d \n", PU_PosIni, PU_Fila[PU_PosIni]);
      PU_Fila[PU_PosIni] = 0;
      PU_PosIni++;
      if( PU_PosIni > TamanhoFila ) PU_PosIni = 0;
      PU_QtdElementos--;
      return(LO_Valor);
   }
   printf ("Fila vazia!! \n");
   return(0);
}

int main(int argc, char *argv[]) {
   int R;
   insere(5);
   insere(10);
   insere(7);
   insere(9);
   insere(2);
   insere(2);

   printf ("\nEstado da pilha:\n");
   for( int con = 0; con <= 5; con++)
   {
      printf ("Elemento[%d] = %d \n", con, PU_Fila[con]);
   }
   printf ("\n");
   
   remover();
   remover();
   remover();
   remover();
   
   printf ("\n");

   insere(3);
   insere(2);
   insere(1);

   printf ("\nEstado da pilha:\n");
   for( int con = 0; con <= 5; con++)
   {
      printf ("Elemento[%d] = %d \n", con, PU_Fila[con]);
   }
   printf ("\n");

   remover();
   remover();
   remover();
   remover();
   remover();

   return 0;
}
 
//Questao 1.2:

int main{
  int n = 1;
  fila* q;
  q=malloc(sizeof(fila));

  printf("\Insira dados na fila");
  printf("\nPara encerrar insira nulo")
  while (n!=NULL){
  scanf("d", &n);
  put(q, n);
  }
  
  int tam, x; 
  tam = q->size;
  printf("Fila criada:\n>>")

  for(int i =0, i<tam, i++){
    x = get(q);
    printf("%d",x)
  }

}

//Questao 3:

//R: Em uma implementacao de lista circular utilizando vetores, 
//quando uma insercao ultrapassa o indice que define o tamanho maximo,
//as proximas irao "sobrescrever" os primeiros valores inserido, ou //seja, serao realizados gets para continuar os puts.
//Assim, identificamos que a fila esta cheia.
//Caso esteja vazia, os indices que definem o inicio e o fim da fila serao o mesmo

//Questao 4:

//R: Os beneficios de utilizar um ponteiro que defina o ultimo valor da fila estao relacionados a:
//controle do tamanho da fila, evitando uso desnecessario da memoria
//facilidade na implementacao das funcoes, evitando mapeamentos repetitivos do final da fila
