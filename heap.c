#include<stdio.h>
#include<stdlib.h>

#define MAX 1024
#define MENOS_INFINITO (-1000000000)

#define LEFT(x) (x << 1)
#define RIGHT(x) (LEFT(x) + 1)
#define PAI(x) (x >> 1)

typedef struct heap {
  size_t size;      //quantidade de itens armazenados
  size_t length;	//tamanho máximo da heap
  int *A;		//array de chaves(agora vai ser ponteiro :/)
} heap;

void heapify( heap * H, int i ){
	int max = i, aux;
	if(LEFT(i) <= H->size)
		if(H->A[LEFT(i)] > H->A[i]) max = LEFT(i);
	if(RIGHT(i) <= H->size)
		if(H->A[RIGHT(i)] > H->A[max]) max = RIGHT(i);
	if(i != max){
		aux = H->A[i]; H->A[i] = H->A[max]; H->A[max] = aux;
		heapify(H, max);
	}
};

void build_heap( heap * H){
	int *aux, i;

	aux = (int*) malloc (8 * sizeof(int));
	if (aux) H->A = aux;
	else printf("Falha, memória não alocada.\n");
	H->size = 2;
	H->length = 2;

	for ( i = 2/2; i > 0; i-- )
		heapify(H, i);	
}

//aumenta a prioridade da chave do indice i para o valor de rebeca
void increase_key( heap * H, int i, int priorit ){
	int aux;	

	if(priorit <= H->A[i]){
		printf("Prioridade maior que o requisitado.\n");
		return;
	}
	
	H->A[i] = priorit;

	while( i > 1 && H->A[PAI(i)] <  H->A[i]){
		aux = H->A[i]; H->A[i] = H->A[PAI(i)]; H->A[PAI(i)] = aux;
		i = PAI(i);
	}
}

void insert_key( heap * H, int chave ){
	int *aux;

	if(H->size >= H->length){
		H->length = H->length * H->length;
		aux = realloc(H->A, H->length * 8);
		if (aux){
			H->A = aux;
		} else {
			printf("Falha, foi possivel expandir o espaço de memória \n");
			return; 
		}
	}
	H->size++;
	H->A[H->size] = MENOS_INFINITO;
	
	increase_key(H, H->size, chave);
	
}

//retorna o máximo e remove ele da heap
int extract_max(heap * H){
	int aux = H->A[1];

	if(H->size < 1){
		printf("HEAP ainda não foi iniciada.\n");
		return -9999;
	}
	
	H->A[1] = H->A[H->size--];	
	
	heapify(H, 1);
	return aux;
	
}

int main ( void ){
	//seu código aqui
	heap *h;
	int n;
	h = (heap *)malloc(sizeof(heap));
	
	build_heap(h);
	while(scanf("%d", &n)){
		insert_key(h,n);
	}
	printf("%d\n",extract_max(h));
	printf("%d\n",extract_max(h));
	printf("%d\n",extract_max(h));
	printf("%d\n",extract_max(h));
	printf("%d\n",extract_max(h));
	printf("%d\n",extract_max(h));
	printf("%d\n",extract_max(h));
	return 0;
}
