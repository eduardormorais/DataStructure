/*
	Objetivo: Pilha. Push, Pop.
 	Eduardo Morais.
*/

#include <stdio.h>

// Tipo para Dados
typedef struct tDado {
  int numero;
} tDado;

// Tipo para Nodo
typedef struct tNodo {
  struct tDado dado;
  struct tNodo *prox;	
} tNodo;

// Tipo para Descritor
typedef struct tDescritor {
  struct tNodo *topo;	
  int qtd;
} tDescritor;

// Prototipo de funcoes
int menu(void);
void inicializar(struct tDescritor*);
void destruir(struct tDescritor);
void push(struct tDescritor*, struct tNodo*);
struct tNodo* pop(struct tDescritor*);
void listar(struct tDescritor); // NAO EH OPERACAO DE PILHA

int main(void) {
  struct tDescritor pilha1;
  struct tNodo *q;
  int op;
  
  inicializar(&pilha1);
  do {
    op = menu();
    switch (op) {
	  case 1:
        printf("\n\n* Push *\n\n");
      	q = (struct tNodo*) malloc(sizeof(struct tNodo));
      	printf("Digite o valor: ");
		scanf("%d", &(q->dado.numero));
		push(&pilha1, q);
   	    break;
	  case 2:
        printf("\n\n* Pop *\n\n");
        q = pop(&pilha1);
        if (q == NULL)
      	  printf("Pilha vazia!");
      	else {
      	  printf("Valor: %d", q->dado.numero);
      	  free(q);
		}
   	    break;
      case 3: 
        printf("\n\n* Listar *\n\n");
        listar(pilha1);
	}
  } while (op != 0);
  destruir(pilha1);
	
  return 0;
}

//Objetivo: Apresentar menu
//Parametro: void
//Retorno: Opcao 
int menu(void) {
  int op;
  printf("\n\n*** Menu ***\n\n");
  printf("1. Push\n");
  printf("2. Pop\n");
  printf("3. Listar\n");
  printf("0. Sair\n\n");
  printf("Digite sua opcao: ");
  scanf("%d", &op);
  return op;
}

//Objetivo: Inicializa descritor da pilha
//Parametro: Ponteiro para o descritor
void inicializar(struct tDescritor *desc) {
  (*desc).qtd = 0;
  (*desc).topo = NULL;
  //(*desc).fim = NULL;
}

//Objetivo: Destruir pilha
//Parametro: Descritor
void destruir(struct tDescritor desc) {
  struct tNodo *p;
  int i;
  for (i=0; i<desc.qtd; i++) {
    p = desc.topo;
    desc.topo = desc.topo->prox;
    free(p);
  }
}

//Objetivo: Incluir(Push) valor na pilha.
//Parametro: Ponteiro para o descritor da pilha, ponteiro para novo nodo 
void push(struct tDescritor *pilha, struct tNodo *n) {
  n->prox = (*pilha).topo;
  (*pilha).topo = n;
  (*pilha).qtd++;
}

//Objetivo: Remove(Pop) valor da pilha.
//Parametro: Ponteiro para o descritor da pilha
//Retorno: Ponteiro para o nodo removido. 
struct tNodo* pop(struct tDescritor *pilha) {
  struct tNodo *p = (*pilha).topo;

  if ((*pilha).topo != NULL) {
    (*pilha).topo = (*pilha).topo->prox;
    (*pilha).qtd--;
  }
  return p;
}

//Objetivo: Listar valores da pilha.
//Parametro: Ponteiro para o descritor da pilha. 
void listar(struct tDescritor desc) {
  struct tNodo *p = desc.topo;
  int i;
  printf("Num\n");
  printf("=====\n");
  for (i=0; i<desc.qtd; i++) {
    printf("%5d\n", p->dado.numero);
    p = p->prox;
  }
}
