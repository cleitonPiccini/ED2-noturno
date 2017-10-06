#include <stdlib.h>
#include <stdio.h>
//Itens da struct.
//chave de identificação do nodo e ponteiros para os filhos
struct node_{
	int key;  						
	struct	node_ * left, * right;		
}typedef node;

//busca por uma chave k na árvore com raiz r
//Chave não estiver na árvore retorna NULL
node * search (node * r, int key){
	node *it = r;
	if(!r || it->key == key ) return r;
	if(key <= it->key) return search (it->left, key);
	return search (it->right, key); 	
}

//Impressão in ordem.
void inorder (node *r){
	node *p = r;
	
	if (p != NULL){		
		inorder (p->left);		
		printf ("%d\n",p->key);		
		inorder (p->right);
	}
}
//Impressão em pos order.
void posorder (node *r){
	node *p = r;
	
	if (p != NULL){
		posorder (r->left);
		posorder (r->right);
		printf ("%d\n",r->key);
	}
}
//Impressão em pre order
void preorder (node *r){
	node *p = r;
	
	if (p != NULL){
		printf ("%d\n", r->key);
		preorder (r->left);
		preorder (r->right);
	}
}
node * searchMin(node *r){
	node *aux = r;
	if (aux->left == NULL) return aux;
	return searchMin(aux->left);
}
//void delete (node *r){}
node * delete (node *r, int key){
	node *aux = r;
	node *anteiror, *menor;


	if (aux == NULL) return NULL;
	while (aux != NULL && aux->key != key )
	{
		printf("to no while\n");
		if (key > aux->key)
		{
			printf("entrei no if\n");
			anteiror = aux;
			aux = aux->right;
			printf("passei pelos ponteiros\n");
			continue;
		} 
		anteiror = aux;
		aux = aux->left;
	}
	printf("sai do while\n");
	if(aux == NULL)
	{
		printf("Valor não encontrado\n");
		return r;	
	} 
	// caso 1 : o nó não possui nodos.
	if (aux->left == NULL && aux->right == NULL) 
	{
		//exclui o  nó;
		if (aux->key > anteiror->key)
		{
			anteiror->right = NULL;
			free(aux);
			return r;//rever isso.
		}
		anteiror->left = NULL;
		free(aux);
		return r;
	}
	// caso 2 : o nó possui apenas uma sub-arvore.
	if (aux->left == NULL)
	{
		//exclui o nó e promove outro
		if (aux->key > anteiror->key)
		{
			anteiror->right = aux->right;
			free(aux);
			return r;//rever isso.
		}
		anteiror->left = aux->right;
		free(aux);
		return r;
	}
	if (aux->right == NULL)
	{
		//exclui o nó e promove outro
		if (aux->key > anteiror->key)
		{
			anteiror->right = aux->left;
			free(aux);
			return r;//rever isso.
		}
		anteiror->left = aux->left;
		free(aux);
		return r;
	}
	//busca menor a direira.
	menor = searchMin(aux->right);
	if (aux->key > anteiror->key)
	{
		menor->left = aux->left;
		menor->right = aux->right;
		anteiror->right = menor;
		free(aux);
		return r;//rever isso.
	}
	menor->left = aux->left;
	menor->right = aux->right;
	anteiror->left = menor;
	free(aux);
	return r;//rever isso.
	//reapontera.
}

//mostra todas as chaves da árvore

void print (node * r){}

/* Insere um nodo com chave key na árvore com raiz r.
Usa recursividade para andar entre as folhas da arvore.
retorna um ponteiro para a raiz da árvore
*/
node  *insert (node *r, int key){
	node *n, *it = r;
	n = (node *)malloc(sizeof(node));
	
	n->left = NULL;
	n->right = NULL;
	n->key = key;
	if(r == NULL) return n;		
	if(key < it->key){
		(it->left == NULL) ? it->left = n : insert(it->left,key);
	}else{
		(it->right == NULL) ? it->right = n : insert(it->right,key);
	}
	return r;
}	
//remove o nodo da árvore com raiz r que possui chave igual a key
//(lembra que tem que dar free no nodo)
//void remove (node * r, int key){}



int main ( void ){

	int n;
	
	node * root = NULL;
	//for (n = 0; n < 10; n++){
		//root = insert (root, n);
	//}
	while(scanf("%d", &n)){
		root = insert(root, n);
	}
	//root = insert (root, 15);
	//root = insert (root, -4);
	printf("vou para o delete\n");
	root = delete(root,22);
	printf ("Inoder\n");
	inorder(root);
	printf ("\n");
	printf ("Posorder\n");
	posorder(root);
	printf ("\n");
	printf ("Preorder\n");
	preorder(root);
	printf ("\n");
	return 0;
}




