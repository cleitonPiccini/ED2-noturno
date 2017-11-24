#include <stdio.h>
#include <stdlib.h>

#define t 2

typedef int type_chave; //Usado typedef apenas para uma tentativa de encapsulamento.

typedef struct _node 
{
	int key;
	int folha; //Folha = 1 - nodo = 0.
	type_chave chave[2*t]; //Vetor de chaves que o nodo contem (endereço em bytes no arquivo).
	//long int filho[2*t+1]; //Vetor de filhos que o nodo tem (endereço em bytes no arquivo).
	struct _node *filho;
	int usado;//Recebe o número de vezes que o ja foi usado.
}node;

typedef struct 
{
	node *raiz;
	long int end_raiz;
}tree;

tree * init (tree *r)
{
	r = (tree*) malloc (sizeof(tree));
	r->raiz = NULL;
	return r;
}

node * new_node (int key)
{
	node *new;
	int meio;
	new = (node *) malloc (sizeof (node));
	if (!new)
	{
		printf("Erro, memória não alocada\n");
		return NULL;
	}
	meio = (2*t-1)/2;
	new->key = key;
	new->chave[meio] = key;
	new->folha = 1;
	new->usado = 1;
	return new;
}
//Busca
void search ()
{

}
//Inoder
void inoder (tree *r)
{
	printf("%d\n", r->raiz->key);
}

void split (tree *r)
{
	//faz o split.
}

tree * insert (tree *r, int key)
{
	tree *aux = r;
	node *new;
	printf("oii to no insert\n");
	if (!aux->raiz)
	{
		printf("to indo para o new node\n");
		r->raiz = new_node(key);
		return r;
	}
	printf("não entrei no if\n");
	if (aux->raiz->cheio < (2*t-1)) new = new_node(key);
	else if (key > aux->raiz->key)
	if (!new) return r;
	return aux;
}

int main()
{
	tree *root=NULL;
	int n;
	root = init(root);
	scanf("%d",&n);
	root = insert(root, n);
	n = 2*t-1;
	printf("capacidade %d\n", n);
	printf("valor %d\n", root->raiz->chave[0]);
	printf("valor %d\n", root->raiz->chave[1]);
	printf("valor %d\n", root->raiz->chave[2]);
	printf("valor %d\n", root->raiz->chave[3]);
	return 0;
}