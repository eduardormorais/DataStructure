/*
	Objetivo: Lista circular. Incluir, listar.
 	Eduardo Morais.
*/
#include <stdio.h>
typedef struct tDado {
  float peso; // chave
  int numero;
} tDado;

// Tipo para Nodo
typedef struct tNodo {
  struct tDado dado;
  struct tNodo *ant;	
  struct tNodo *prox;	
} tNodo;

// Tipo para Descritor
typedef struct tDescritor {
  struct tNodo *ini;	
  int qtd;
  float pesos;
} tDescritor;

// Prototipo de funcoes
int menu(void);
void inicializar(struct tDescritor*);
void destruir(struct tDescritor);
void incluir(struct tDescritor*, struct tNodo*);
void listar(struct tDescritor);

int main(void) {
  struct tDescritor descritor;
  struct tNodo *novo;
  int op;
  
  inicializar(&descritor);
  do {
    op = menu();
    switch (op) {
      case 1:
        printf("\n\n* Incluir *\n\n");
      	novo = (struct tNodo*) malloc(sizeof(struct tNodo));
      	printf("Digite o peso.: ");
		scanf("%f", &(novo->dado.peso));
      	printf("Digite o valor: ");
		scanf("%d", &(novo->dado.numero));
		incluir(&descritor, novo);
   	    break;
      case 2: 
        printf("\n\n* Listar *\n\n");
        listar(descritor);
	}
  } while (op != 0);
  destruir(descritor);
	
  return 0;
}

//Objetivo: Apresentar menu
//Parametro: void
//Retorno: Opcao 
int menu(void) {
  int op;
  printf("\n\n*** Menu ***\n\n");
  printf("1. Incluir\n");
  printf("2. Listar\n");
  printf("0. Sair\n\n");
  printf("Digite sua opcao: ");
  scanf("%d", &op);
  return op;
}

//Objetivo: Inicializar descritor da lista
//Parametro: Ponteiro para o descritor
void inicializar(struct tDescritor *desc) {
  (*desc).pesos = 0; // desc->pesos = 0;
  (*desc).qtd = 0;
  (*desc).ini = NULL;
}

//Objetivo: Destruir a lista
//Parametro: Descritor
void destruir(struct tDescritor desc) {
  struct tNodo *p;
  int i;
  for (i=0; i<desc.qtd; i++) {
    p = desc.ini;
    desc.ini = desc.ini->prox;
    free(p);
  }
}

//Objetivo: Incluir novo nodo na lista
//Parametro: Ponteiro para o descritor, ponteiro para o novo nodo
void incluir(struct tDescritor *desc, struct tNodo *n) {
  struct tNodo *p = (*desc).ini;
  
  if ((*desc).ini == NULL) { // Lista vazia
    n->ant = n;
    n->prox = n;
    (*desc).ini = n;
  }
  else {
  	do {
  	  p = p->prox;
    } while ((p->dado.peso < n->dado.peso) && (p != (*desc).ini));
  	n->ant = p->ant;
  	n->prox = p;
  	p->ant->prox = n;
  	p->ant = n;

  	if (n->dado.peso < (*desc).ini->dado.peso) // Atualizar o ponteiro ini
  	  (*desc).ini = n;
  }
  (*desc).qtd++;
  (*desc).pesos += n->dado.peso;
}

//Objetivo: Listar valores da lista
//Parametro: Descritor
void listar(struct tDescritor desc) {
  struct tNodo *p = desc.ini;
  int i;
  printf("Peso      Num\n");
  printf("=======   =====\n");
  for (i=0; i<desc.qtd; i++) {
    printf("%7.3f - %5d\n", p->dado.peso, p->dado.numero);
    p = p->prox;
  }
}
