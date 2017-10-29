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
node * new_node (int key)
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
	new->key = key;
	new->color = 1;
	return new;	
}
//Inicia o NILL.
node * nill ()
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
	new->parent = NULL;
	return new;	
}
//Busca
node * search (node * r, int key){
	node *it = r;
	if(!r || it->key == key ) return r;
	if(key <= it->key) return search (it->left, key);
	return search (it->right, key); 	
}
//Impressão in ordem.
void inorder (node *raiz, node *r){
	node *p = r;

	if (p != raiz->parent){		
		inorder (raiz, p->left);		
		printf ("Valor : %d, ",p->key);
		if (p->color == 0) printf ("black.\n");
		else printf ("red.\n");		
		inorder (raiz, p->right);
	} 
}
//Impressão em pos order.
void posorder (node *raiz, node *r){
	node *p = r;
	
	if (p != raiz->parent){
		posorder (raiz, p->left);
		posorder (raiz, p->right);
		printf ("Valor : %d, ",p->key);
		if (p->color == 0) printf ("black.\n");
		else printf ("red.\n");		
	}
}
//Impressão em pre order
void preorder (node *raiz, node *r){
	node *p = r;
	
	if (p != raiz->parent){
		printf ("Valor : %d, ",p->key);
		if (p->color == 0) printf ("black.\n");
		else printf ("red.\n");		
		preorder (raiz, p->left);
		preorder (raiz, p->right);
	}
}
//Rotação da arvore a esquerda.
node * rLeft (node *r, node *new)
{
	node *aux;
	aux = new->right;
	new->right = aux->left;
	aux->parent = new->parent;
	
	if (new->parent == r->parent)
	{
		r = aux;
	} else if (new == new->left->parent) //Se for esquerda.
	{
		new->parent->left = aux;
	}else{
		new->parent->right = aux;
	}
	aux->left = new;
	new->parent = aux;
	return r;
}
//Rotação da arvore a direita.
node * rRight (node *r, node *new)
{
	node *aux;
	aux = new->left;
	new->left = aux->right;
	aux->parent = new->parent;

	if (new->parent == r->parent)
	{
		r = aux;
	} else if (new == new->left->parent) //Se for esquerda.
	{
		new->parent->left = aux;
	}else{
		new->parent->right = aux;
	}
	aux->right = new;
	new->parent = aux;
	return r;
}
//Arruma a inserção
node * insert_fixup (node *r, node *new)
{
	node *aux;
	while (new->parent->color)
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
			}else{ 
				if (new == new->left->parent)
				{
					new = new->parent;
					r = rLeft(r,new);
				}
			//Terceiro caso.
				new->parent->color = 0;
				new->parent->parent->color = 1;
				r = rRight(r, new->parent->parent);
			}
		//Direita.
		} else {
			aux = new->parent->parent->left;

			//Primeiro caso.
			if (aux->color == 1){
				new->parent->color = 0;
				aux->color = 0;
				new->parent->parent->color = 1;
				new = new->parent->parent;
			//Segundo caso.
			}else{ 
				if (new == new->right->parent)
				{
					new = new->parent;
					r = rRight(r,new);
				}
			//Terceiro caso.
				new->parent->color = 0;
				new->parent->parent->color = 1;
				r = rLeft(r, new->parent->parent);	
			}
		}
	}

	r->color = 0;
	return r;
}
//Inserção
node * insert (node *r, int key)
{
	node *new, *pai, *aux;
	new = new_node(key);
	
	if (!new) return r;
	if (!r){
		new->parent = nill();
		new->left = new->parent;
		new->right = new->parent;
		new->color = 0;	
		return new;
	}
	new->left = r->parent;
	new->right = r->parent;
	aux = r;
	while(aux != r->parent)
	{
		printf("oi for do insert\n");
		pai = aux;
		if(key < aux->key){
			if (aux->left == r->parent)
			{
				aux->left = new;
				break;
			}else aux = aux->left;
		}else{
			if (aux->right == r->parent) 
			{
				aux->right = new;
				break;
			}else aux = aux->right;
		}
	}
	new->parent = pai;
	printf("oi vou para o fix\n");
	return insert_fixup(r, new);
}

//Testes
int main ()
{
	int n;
	
	node * root = NULL;
	printf("Digite números aleatorios para inserir na arvore\n");
	while(scanf("%d", &n)){
		root = insert(root, n);
	}
	printf("inorder\n");
	inorder(root,root);
	printf("preorder\n");
	preorder(root, root);
	return 0;	
}
