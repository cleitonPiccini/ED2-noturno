#include <stdlib.h>
#include <stdio.h>
//Itens da struct.
//chave de identificação do nodo e ponteiros para os filhos
struct node_{
	int key;  						
	struct	node_ * left, * right, *raiz;		
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
//Busca o menor.
node * search_menor (node *r)
{
	node *aux;
	aux = r;
	while (aux->left != NULL)
	{
		aux = aux->left;
	}
	return aux;
}

//Deleta os nodos.
node * delete (node *r, int key)
{
	node *y, *z = r;
	
	if (z == NULL){
		printf("Árvore Vazia\n");
		return NULL;	
	} 
	z = search(z,key);
	if (z == NULL){
		printf("Valor não encontrado\n");
		return r;	
	} 
	//Caso 1 - Sem filhos.
	if (z->left == NULL && z->right == NULL)
	{
		if (z == z->raiz->left) {
			z->raiz->left = NULL;
			free(z);
			return r;
		} else {
			z->raiz->right = NULL;
			free(z);
			return r;
		}
	}	
	//Caso 2 - Somente um filho.
	if (z->left == NULL)
	{
		if (z->raiz != NULL){ 
			z->right->raiz = z->raiz;//Re-aponta raiz do nodo a direita.
			if(z == z->raiz->left) z->raiz->left = z->right;//Re-aponta o pai quando filho a esquerda.
			else z->raiz->right = z->right;//Re-aponta o pai quando filho a direita.
		} else z->right->raiz = NULL;// z->right;//Re-aponta raiz do nodo a direita, no caso de ser raiz deletada.
		free(z);
		return r; 
	}
	if (z->right == NULL) {
		if (z->raiz != NULL){ 
			z->left->raiz = z->raiz;//Re-aponta raiz do nodo a esquerda.
			if(z == z->raiz->left) z->raiz->left = z->left;//Re-aponta o pai quando filho a esquerda.
			else z->raiz->right = z->left;//Re-aponta o pai quando filho a direita.
		}else z->left->raiz = z->raiz;//Re-aponta raiz do nodo a direita, no caso de ser raiz deletada.
		free(z);
		return r; 
	}
	//Caso 3.
	y = search_menor(z->right);
	z->raiz->left = y;
	y->left = z->left;
	free(z);
	return r; 
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
	n->raiz = NULL;
	if(r == NULL) return n;		
	if(key < it->key){
		(it->left == NULL) ? it->left = n : insert(it->left,key);
	}else{
		(it->right == NULL) ? it->right = n : insert(it->right,key);
	}
	n->raiz = it;
	return r;
}	
//Testes.
int main ( void ){

	int n;
	
	node * root = NULL;
	printf("Digite números aleatorios para inserir na arvore\n");
	while(scanf("%d", &n)){
		root = insert(root, n);
	}
	getchar();
	printf("Digite um numero para ser deletado\n");
	scanf("%d", &n);
	root = delete(root,n);
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




