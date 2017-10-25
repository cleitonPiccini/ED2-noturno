#include <stdio.h>
#include <stdlib.h>

//Struct
typedef struct node_ 
{
	int key;
	int color;//0 - black, 1 - red.
	struct node_ *left, *right, *parent;
}node;

typedef struct tree
{
	struct node_ *root;
}tree;
//Inicia um nodo.
node * new_node (node *r, int key)
{
	node *new;

	new = (node *) malloc (sizeof (node));
	
	if (!new)
	{
		printf ("falha de alocação de memória\n");
		return NULL;
	}
	new->left = r->parent;
	new->right = r->parent;
	new->key = key;
	new->color = 1;
	return new;	
}
//Inicia uma arvore.
node * new_nill ()
{
	node *new;

	new = (node *) malloc (sizeof (node));
	
	if (!new)
	{
		printf ("falha de alocação de memória\n");
		return NULL;
	}
	new->left = NULL;
	new->right = NULL;
	new->key = -9999;
	new->color = 0;
	return new;	
}
//Busca
node * search (node * r, int key){
	node *it = r;
	if(!r || it->key == key ) return r;
	if(key <= it->key) return search (it->left, key);
	return search (it->right, key); 	
}
//Rotação da arvore a esquerda.
node * rLeft (node *r, node *new)
{
	node *aux;
	aux = new->right;
	new->right = aux->left;
	aux->parent->left = new;
	aux->parent = new->parent;
	if (new->parent == r){}

	return r;
}
//Rotação da arvore a direita.
node * rRight (node *r, node *new)
{
	return r;
}
//Arruma a inserção
node * insert_fixup (node *r, node *new)
{
	node *aux;
	while (new->parent->color == 1)
	{
		//Descobre se é a Esquerda.
		if (new->parent == new->parent->parent->left)
		{
			aux = new->parent->parent->right;
			//Primeiro caso.
			if (aux->color == 1){
				new->parent->color = 0;
				aux->color = 0;
				new->parent->parent->color = 1;
				new = new->parent->parent;
			//Segundo caso.
			}else if (new == new->parent->left)
			{
				new = new->parent;
				r = rLeft(r,new);
			//Terceiro caso.
				new->parent->color = 0;
				new->parent->parent->color = 1;
				r = rRight(r, new->parent->parent);
			}
		//Esquerda.
		} else {
			aux = new->parent->parent->right;
			//Primeiro caso.
			if (aux->color == 1){
				new->parent->color = 0;
				aux->color = 0;
				new->parent->parent->color = 1;
				new = new->parent->parent;
			//Segundo caso.
			}else if (new == new->parent->right)
			{
				new = new->parent;
				r = rRight(r,new);
			//Terceiro caso.
				new->parent->color = 0;
				new->parent->parent->color = 1;
				r = rLeft(r, new->parent->parent);	
			}
		}
	}
	return r;
}
//Inserção
node * insert (node *r, int key)
{
	node *new, *pai, *aux;
	new = new_node(r, key);

	if (!new) return r;
	if (!r){
		new->parent = new_nill();	
		return new;
	} 

	aux = r;
	pai = aux;

	if(key < aux->key){
		if (aux->left == NULL) aux->left = new;
		else insert(aux->left, key);
	}else{
		if (aux->right == NULL) aux->right = new;
		else insert(aux->right, key);
	}
	new->parent = pai;
	return insert_fixup(r, new);
}

//Testes
int main ()
{
	return 0;	
}
