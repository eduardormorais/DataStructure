/*
	Objetivo: FILA. Enqueue, dequeue, listar.
 	Eduardo Morais.
*/

#include <stdio.h>

// Tipo para Dados
typedef struct tDado
{
  int numero;
} tDado;

// Tipo para Nodo
typedef struct tNodo
{
  struct tDado dado;
  struct tNodo *prox;
} tNodo;

// Tipo para Descritor
typedef struct tDescritor
{
  struct tNodo *ini;
  struct tNodo *fim;
  int qtd;
} tDescritor;

// Prototipo de funcoes
int menu(void);
void inicializar(struct tDescritor *);
void destruir(struct tDescritor);
void enqueue(struct tDescritor *, struct tNodo *);
struct tNodo *dequeue(struct tDescritor *);
void listar(struct tDescritor); 

int main(void)
{
  struct tDescritor fila1;
  struct tNodo *q;
  int op;

  inicializar(&fila1);
  do
  {
    op = menu();
    switch (op)
    {
    case 1:
      printf("\n\n* EnQueue *\n\n");
      q = (struct tNodo *)malloc(sizeof(struct tNodo));
      printf("Digite o valor: ");
      scanf("%d", &(q->dado.numero));
      enqueue(&fila1, q);
      break;
    case 2:
      printf("\n\n* DeQueue *\n\n");
      q = dequeue(&fila1);
      if (q == NULL)
        printf("Fila vazia!");
      else
      {
        printf("Valor: %d", q->dado.numero);
        free(q);
      }
      break;
    case 3:
      printf("\n\n* Listar *\n\n");
      listar(fila1);
    }
  } while (op != 0);
  destruir(fila1);

  return 0;
}

//Objetivo: Apresentar menu
//Parametro: void
//Retorno: Opcao 
int menu(void)
{
  int op;
  printf("\n\n*** Menu ***\n\n");
  printf("1. EnQueue\n");
  printf("2. DeQueue\n");
  printf("3. Listar\n");
  printf("0. Sair\n\n");
  printf("Digite sua opcao: ");
  scanf("%d", &op);
  return op;
}

//Objetivo: Inicializa fila 
//Parametro: Ponteiro para o descritor
void inicializar(struct tDescritor *desc)
{
  (*desc).qtd = 0;
  (*desc).ini = NULL;
  //(*desc).fim = NULL;
}

//Objetivo: Destruir fila
//Parametro: Descritor
void destruir(struct tDescritor desc)
{
  struct tNodo *p;
  int i;
  for (i = 0; i < desc.qtd; i++)
  {
    p = desc.ini;
    desc.ini = desc.ini->prox;
    free(p);
  }
}

//Objetivo: Realizar enqueue na fila 
//Parametro: Ponteiro para o descritor da fila, ponteiro para novo nodo
void enqueue(struct tDescritor *fila, struct tNodo *n)
{
  if ((*fila).ini == NULL) // Fila vazia
    (*fila).ini = n;
  else
    (*fila).fim->prox = n;
  (*fila).fim = n;
  (*fila).qtd++;
  n->prox = NULL;
}

//Objetivo: Realizar dequeue na fila 
//Parametro: Ponteiro para o descritor da fila
//Retorno: Nodo removido da fila
struct tNodo *dequeue(struct tDescritor *fila)
{
  struct tNodo *p = (*fila).ini;

  if ((*fila).ini != NULL)
  {
    (*fila).ini = (*fila).ini->prox;
    (*fila).qtd--;
  }
  return p;
}

//Objetivo: Lista valores da fila 
//Parametro: Descritor da fila
void listar(struct tDescritor desc)
{
  struct tNodo *p = desc.ini;
  int i;
  printf("Num\n");
  printf("=====\n");
  for (i = 0; i < desc.qtd; i++)
  {
    printf("%5d\n", p->dado.numero);
    p = p->prox;
  }
}
