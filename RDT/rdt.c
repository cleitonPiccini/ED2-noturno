#include <stdio.h>
#include <stdlib.h>

//Struct
typedef struct node_ 
{
	int key;
	int color;
	struct node_ *left, *right, *raiz;
}node;

//Busca
node * search (node * r, int key){
	node *it = r;
	if(!r || it->key == key ) return r;
	if(key <= it->key) return search (it->left, key);
	return search (it->right, key); 	
}
//Rotação da arvore a esquerda.
node * rLeft (node *r)
{
	return r;
}
//Rotação da arvore a direita.
node * rRight (node *r)
{
	return r;
}
//Inserção
node * insert (node *r, int key)
{
	node *new, *pai = r;
	new = (node *) malloc (sizeof (node));
	
	if (!new)
	{
		printf ("falha de alocação de memória\n");
		return r;
	}
	new->left = NULL;
	new->right = NULL;
	new->key = key;
	new->color = 1;
	
	if (!r) return new;
	
	if(key < aux->key){
		if (pai->left == NULL)
		{ 
			pai->left = new
		else : insert(pai->left,key);
	}else{
		(pai->right == NULL) ? pai->right = new : insert(pai->right,key);
	}
	//Primeiro caso.
	if (new->color == 1 && pai->color = 1
	{
		if (aux->color
		// printa o pai de preto.
	//Segundo caso.
	if 
	//Terceiro caso.
	
	
	return r;
}

int main ()
{
	return 0;	
}
