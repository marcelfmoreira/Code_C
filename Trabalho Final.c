#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//Definições de Estruturas
typedef int bool;
#define false 0;
#define true 1;

typedef struct {
	int menor, maior;
} interval;

typedef struct Tree {
	interval *v;
	int height;
	int max;
	struct Tree *left, *right;
} iTree;


//Definição de Funções
iTree *get_max(iTree *raiz){
    if (raiz->right == NULL)
        return raiz;
    else
        get_max(raiz->right);
}

iTree * newNode(interval v) {
    int ant,dps;
	iTree *aux = malloc(sizeof(iTree));
	aux->v = malloc(sizeof(interval));
	aux->max = v.maior;
	ant = v.menor;
	dps = v.maior;
	aux->v->menor = ant;
	aux->v->maior = dps;
	aux->left = aux->right = NULL;
}

int maximus(int num1, int num2){
    if (num1 > num2)
        return num1;
    else
        return num2;
}

int avl_height(iTree *raiz){
    if (raiz==NULL)
        return -1;
    else
        return raiz->height;
}

iTree *avl_rLeft (iTree *raiz){
    iTree *y = raiz -> right;
    raiz->right = y->left;
    y->left = raiz;
    raiz->height = 1 + maximus(avl_height (raiz->left),avl_height(raiz->right));
    y->height = 1 + maximus(avl_height(y->left),avl_height(y->right));
    return y;
}

iTree *avl_rRight (iTree *raiz){
    iTree *y = raiz -> left;
    raiz->left = y->right;
    y->right = raiz;
    raiz->height = 1 + maximus(avl_height (raiz->left),avl_height(raiz->right));
    y->height = 1 + maximus(avl_height(y->left),avl_height(y->right));
    return y;
}

iTree *rebalance(iTree *raiz){
    int lh = avl_height(raiz ->left);
    int rh = avl_height(raiz ->right);
    int fb = lh - rh;

    raiz->height = 1+ maximus(lh,rh);

    if (fb == 2){
        if (avl_height(raiz->left->right) > avl_height(raiz->left->left))
            raiz->left = avl_rLeft(raiz->left);
        raiz = avl_rRight(raiz);
    }
    else if (fb == -2) {
        if (avl_height(raiz->right->left) > avl_height (raiz->right->right))
            raiz->right = avl_rRight (raiz->right);
        raiz =avl_rLeft(raiz);
    }
    return raiz;
}

bool doOverlap(interval v1, interval v2) {
	if (v1.menor <= v2.maior && v2.menor <= v1.maior)
		return true;
	return false;
}

iTree *iTree_insert(iTree *raiz, interval v){
	if (raiz == NULL)
        return newNode(v);
	int l = raiz->v->menor;
	if (v.menor < l)
		raiz->left = iTree_insert(raiz->left, v);
	else
		raiz->right = iTree_insert(raiz->right, v);
	if (raiz->max < v.maior)
		raiz->max = v.maior;

	return rebalance(raiz);
}

iTree *iTree_remove(iTree *raiz, interval v){
    if (raiz == NULL){
        printf("Intervalo nao encontrado");
        return raiz;
    }
    if (doOverlap(*(raiz->v),v)){
        iTree *p;
        interval temp;
        if (raiz->left == NULL){
            p = raiz;
            raiz = raiz->right;
            free(p);

        }
        else if (raiz->right == NULL){
            p = raiz;
            raiz = raiz->right;
            free(p);

        }
       else {
            p = get_max(raiz->left);
            raiz->v = p->v;
            temp = v;
            raiz->left = iTree_remove(raiz->left,temp);

        }
    }
    else if(raiz->v->menor < v.menor)
        raiz->right = iTree_remove(raiz->right, v);
    else if(raiz->v->menor > v.menor)
        raiz->left = iTree_remove(raiz->left, v);
    if(raiz)
        return rebalance(raiz);
    return raiz;
}

void iTree_Display(iTree *raiz, int space){
    if (raiz == NULL)
        return;
    space += 10;
    iTree_Display(raiz->right, space);
    printf("\n");
    for (int i = 10; i<space; i++)
        printf("  ");
    printf("[%d,%d] - max [%d]\n", raiz->v->menor, raiz->v->maior, raiz->max);

    iTree_Display(raiz->left, space);
}

void iTree_Display_aux(iTree *raiz){
    iTree_Display(raiz,0);
}

interval *iTree_Search(iTree *raiz, interval v) {
	if (raiz == NULL)
		return NULL;
	if (doOverlap(*(raiz->v), v))
		return raiz->v;
	if ((raiz->left != NULL) && (raiz->left->max >= v.menor))
		return iTree_Search(raiz->left, v);
	return iTree_Search(raiz->right, v);
}

void ordenar(iTree *raiz) {
	if (raiz == NULL)
		return;
	ordenar(raiz->left);
	printf("\n[%d,%d] max = %d\n", raiz->v->menor, raiz->v->maior, raiz->max);
	ordenar(raiz->right);
}

void iTree_overlap_list(iTree *raiz, interval v){
   /* if (raiz == NULL)
		return NULL;
	if (doOverlap(*(raiz->v), v))
		printf("[%d,%d]\n", raiz->v->menor, raiz->v->maior);
    if ((raiz->v->menor > v.maior) && (raiz->left != NULL))
            iTree_overlap_list(raiz->left, v);
    if ((raiz->v->maior < v.menor) && (raiz->right != NULL))
            iTree_overlap_list(raiz->right, v);*/
    if (raiz == NULL)
		return;
	iTree_overlap_list(raiz->left,v);
	if (doOverlap(*(raiz->v), v))
		printf("[%d,%d]\n", raiz->v->menor, raiz->v->maior);
	iTree_overlap_list(raiz->right,v);

}

void menu(){

    printf("\n\n\n\n\n\n\n\t\t\t\t--------------------------------------------------\n");
    printf("\n\t\t\t\t\t\tInterval Tree Ver + de 8.000");
    printf("\n\n\t\t\t\t--------------------------------------------------");
    printf("\n\n                            Bem Vindo ao Simulador de Arvores de Intervalo :D");
    printf("\n\n                            Digite o numero da operacao para realiza-la");
    printf("\n\n\n                            Menu Principal\n\n                            1 - Inserir intervalo na arvore\n\n                            2 - Remover intervalo na arvore\n\n                            3 - Buscar interseccoes na arvore\n\n                            4 - Listar Nos Sobrepostos a um intervalo\n\n                            5 - Exibir Arvore\n\n                            0-Sair :( \n");
    printf("\n                            >");

}

int main (){

    int operacao;
    char continuar;
    iTree *raiz = NULL;
    interval x;

    menu();
    scanf("%d", &operacao);

while (operacao != 0){
    switch (operacao){
        case 1:
            while (continuar != '0'){
            printf("\n\nDigite o intervalo a ser inserido na arvore (apenas numeros):\n");
            scanf("%d%d", &x.menor, &x.maior);
            raiz = iTree_insert(raiz,x);
            printf("Intervalo [%d,%d] inserido com sucesso", x.menor, x.maior);
            printf("\n\nPara continuar inserindo pressione Enter\n");
            printf("\n\Para voltar ao menu principal pressione Zero\n");
            fflush(stdin);
            continuar = getchar();
            }
        break;

        case 2:
            while (continuar != '0'){
            printf("\n\nDigite o intervalo a ser removido da arvore (apenas numeros):\n");
            scanf("%d%d", &x.menor, &x.maior);
            raiz = iTree_remove(raiz,x);
            printf("Intervalo [%d,%d] removido com sucesso", x.menor, x.maior);
            printf("\n\nPara continuar removendo pressione Enter\n");
            printf("\n\Para voltar ao menu principal pressione Zero\n");
            fflush(stdin);
            continuar = getchar();
            }
        break;

        case 3:
            while (continuar != '0'){
            printf("\n\nDigite o intervalo a ser buscado da arvore (apenas numeros):\n");
            scanf("%d%d", &x.menor, &x.maior);
            interval *res = iTree_Search(raiz,x);
            if (res == NULL)
                printf("\n Interseccao com o Intervalo nao encontrada na arvore!!\n");
            else
                printf("Interseccao encontrada: [%d,%d]", res->menor, res->maior);
            printf("\n\nPara continuar buscando pressione Enter\n");
            printf("\n\Para voltar ao menu principal pressione Zero\n");
            fflush(stdin);
            continuar = getchar();
            }

        break;

        case 4:
            printf("\n\nDigite o intervalo a ser buscado da arvore (apenas numeros):\n");
            scanf("%d%d", &x.menor, &x.maior);
            printf("Intervalos sobrepostos a X:\n");
            iTree_overlap_list(raiz,x);
            fflush(stdin);
            getchar();
        break;

        case 5:
            printf("\n\n                       Arvore de Intervalos:     \n\n\n\n");
            iTree_Display_aux(raiz);
            fflush(stdin);
            getchar();
        break;

        case 0:
            operacao =  0;
    }
    /*if(operacao != 0);{
        printf("\n\n\nPara continuar pressione Enter\n");
        printf("\n\Para voltar ao menu principal pressione Zero\n");
        fflush(stdin);
        continuar = getchar();
        if (continuar == '0')
            operacao = 0;
        else{*/
            menu();
            scanf("%d", &operacao);
        //}
    //}
}


/*
    interval ints[]={{15,20},{10,30},{17,19},{5,20},{3,15},{30,40}};

    int n = sizeof(ints)/sizeof(ints[0]);
    iTree *raiz = NULL;
    for (int i=0;i<n;i++)
        raiz = iTree_insert(raiz,ints[i]);
    printf("Intervalos:\n");
    ordenar(raiz);
    interval x = {6,7};
    printf("Intervalos sobrepostos a X:\n");
    iTree_overlap_list(raiz,x);
    printf("Removendo raiz com interseccao com o intervalo [%d,%d]\n",x.menor,x.maior);
    raiz = iTree_remove(raiz,x);
    ordenar(raiz);
    interval *res = iTree_Search (raiz,x);
    if (res == NULL)
        printf("\n não rolou\n");
    else
        printf("%d e %d", res->menor, res->maior);
        */
}
