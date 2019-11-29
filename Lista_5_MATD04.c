#include <stdio.h>
#include <stdlib.h>



typedef struct Heap{
  int tail;
  int *heap;
  int size; 
} Heap;

void swap (int A, int B) {
  int t = A;
  A = B;
  B = t;
};

int parent(int i){
    return (i-1)/2;
}

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*(i+1);
}

void heapify(Heap *h){
  
  int v = h->tail;

  if(v == 1) return;
  
  int p = parent(v);
  

  if(h->heap[v] > h->heap[p]){
    swap(h->heap[v], h->heap[p]);
    heapify(p);
  }   
}

void CreateHeap (int m, int v[]){
   for (int k = 1; k < m; ++k) {                   
      int f = k+1;
      while (f > 1 && v[f/2] < v[f]) {  
         swap (v[f/2], v[f]);          
         f /= 2;                       
      }
   }
}

void add(Heap* h, int value) {
    if (h->tail-1 == h->size) {
        printf("Heap cheia. Nao foi possivel inserir %d \n", value);
        return;
    }
    h->tail += 1;
    h->heap[h->tail] = value;
    printf("Inserido %d[%d] em heap (%d)\n", value, h->heap[parent(h->tail)], h->tail);
    heapify(h, h->tail);
}

int remove(Heap *h){
  int e = h->heap[0];
  h->heap[0] = h->heap[h->tail];
  h->tail -= 1;

  heapify(Heap *h);  
}
