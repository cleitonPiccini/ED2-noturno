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
	root = insert (root, 15);
	root = insert (root, -4);
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




