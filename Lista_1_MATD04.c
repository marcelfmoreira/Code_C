
#include <stdio.h>
#include <stdlib.h>


//Definição de Estrutura

typedef struct Node{
	int e;
	struct Node* next;

} Node;

//Questao 1:

int isEmpty (Node list*){

	node *aux = (Node) malloc (sizeof(Node));
	aux = list;

	if (aux == NULL){
		return 1;				
	}

	else{
		return 0;
	}
}

int size(Node list*){

	int size_v = 0;
	Node *aux = list;

	while (aux != NULL){
		aux = aux->next;
		size_v++;
	}	

	return size_v;
}

void InsertElement (Node list*, int data){

	Node *aux = (Node)malloc{sizeof(Node));
	Node *novo = (Node)malloc{sizeof(Node));

	if(list == NULL){
		aux->e = data;
		aux->next = list;
		list = aux;  
		return;
	}

	aux = list;

	while (aux->next != NULL){
		aux = aux->next;
	}

	novo->e = data;
	novo->next = NULL;
	aux->next= novo;
	
	return;
}


int removeElement (Node list*, int i){

	int cont = 0, value;
	Node *aux = (Node)malloc(sizeof(Node));
	Node *antes = (Node)malloc(sizeof(Node));

	while (cont < i){
		antes = list;
		list = list->next
		cont ++;
	}

	aux = list->next;
	value = list-> e;
	free(list);
	antes->next = aux;
	
	return(value);
}

void printList (Node list*){

	while (list != NULL){
		printf ("\n%d ", list->e);
		list = list->next;
	}

	return

}


//Questao 2:
//Considerando as funções e estruturas ja criadas/utilizadas na Questão 1


int main (){
	Node *list = (node)malloc(sizeof(Node));		
	int arr = [];
	int n, dado;
	printf("\nDigite o numero de elementos do vetor:");
	scanf("%d", &n);
	
	
	for (int i = 0; i<n; i++){
		printf("\nDigite os valores do vetor");
		scanf("%d", &dado);
		arr[i] = dado;		
		InsertElement(list,dado)
	}

  printf("\n Lista inserida:")
  printList(list);
}

//Questao 3:
// funcao de busca binaria chamada "acha_ai" que encontra a posicao
// do dado desejado e a funcao asc_order que ordena a lista em ordem
// crescente

void acha_ai (int e, int n, int *v){
  int esq =0, dir = n-1, x = (esq+dir)/2;

  while (esq <= dir)
    {
      if (e > v[x])
      {
        esq = x;
        x = (esq+dir)/2;
      }
      else
      if (e < v[x])
      {
        dir = x;
        x = (esq+dir)/2;
      }
      if (e == v[x])
      {
        printf ("\n Elemento encontrado na posicao %d", x);
        return;
      }  
    }

    printf("\nElemento nao existe no vetor");
    return;
    
  }

void asc_order (int n, int *v ){

	int temp;
	
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<(n-i) ; j++)
			if(v[j]>v[j+1])
			{
				temp=v[j];
				v[j]=v[j+1];
				v[j+1]=temp;
			}
	}
	
	for(int i=0;i<n;++i)
		printf("%d ", v[i]);
		
	return;
}

 
int main ()
{
	int n;
	int value;
	int e;
	int *v;
	v = malloc (sizeof(v));


	printf("\nEntre com o numero de elementos: ");
	scanf("%d", &n);
	
	for (int i = 0; i<n; i++)
	{
		printf("\nDigite o valor a ser inserido no vetor: ");
		scanf("%d", &value);
		v[i] = value;
	}

	printf("\n\nVetor inserido: ");

	for (int i=0; i<n; i++)
		printf(" %d", v[i]);
	
	printf("\n\nVetor ordenado: ");

	asc_order(n,v);	

  
	printf("\n\nDigite o numero a ser encontrado: ");
  scanf("%d", &e);
	acha_ai (e,n,v);

}


//Questao 4:
//
// Quase todas as funcoes possuem complexidade O(n)
// dependendo unicamente do tamanho da lista
// A excessao e o asc_order, que possui duas funcoes de iteracao,
// possuindo assim complexidade O((n-1)² * n) = O(n(n²-2n+1)) ou 
// O(n³-2n²+n)
