#include <stdio.h>
#include <stdlib.h>

void acha_ai (int e, int n, int *v){
  int esq =0, dir = n, x = (esq+dir)/2;

  while (v[x] != e)
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
      if (esq == dir)
        printf("\nElemento nao existe no vetor");
        return;
    }

    printf ("\n Elemento encontrado na posicao %d", x);

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
