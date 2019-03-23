/*
	Objetivo: Lista encadeada. Incluir, listar.
 	Eduardo Morais.
*/

#include <stdio.h>
#include <stdlib.h>

// Declaracao do no/nodo da lista
typedef struct registro {
  int chave;
  char valor;
  struct registro *prox;
} registro;

// Prototipo das funcoes
int menu(void); // Menu
void incluir(struct registro**); // Inclui um novo no/nodo na lista
void receberChave(struct registro*); // Recebe do usuario o valor da chave
void receberValores(struct registro*); // Recebe do usuario os demais valores
void listar(struct registro*); // Imprime na tela todos os nos/nodos da lista

int main(void) {
  int op;
  struct registro *inicio = NULL, *p; // inicio = descritor da lista
  do {
    op = menu();
    switch (op) {
      case 1: incluir(&inicio); break;
      case 2: break;
      case 3: break;
      case 4: break;
      case 5: listar(inicio);
    }
  } while (op != 0);
  // Libera memoria ocupada pela lista
  while (inicio != NULL) {
    p = inicio;
    inicio = inicio->prox;
    free(p);
  }
  return 0;
}

//Objetivo: Apresentar menu
//Parametro: void
//Retorno: Opcao 
int menu(void) {
  int op;
  do {
    printf("\n\n*** MENU ***\n\n");
    printf("1. Incluir\n");
    printf("2. Excluir\n");
    printf("3. Alterar\n");
    printf("4. Consultar\n");
    printf("5. Listar\n");
    printf("0. Sair\n\n");
    printf("Digite sua opcao: ");
    scanf("%d", &op);
    if ((op < 0) || (op > 5))
      printf("Opcao invalida!\n\n");
  } while ((op < 0) || (op > 5));
  return op;
}

//Objetivo: Incluir novo nodo na lista
//Parametro: Ponteiro para o descritor, ponteiro para o novo nodo
void incluir(struct registro **ini) {
  struct registro *novo, *p, *q;
  printf("\n\n*** INCLUSAO ***\n\n");
  novo = (struct registro *) malloc(sizeof(struct registro));
  receberChave(novo);
  receberValores(novo);
  // Lista vazia
  if (*ini == NULL) {
    novo->prox = NULL;
    *ini = novo;
  }
  else {
    // Inicio
    if (novo->chave < (*ini)->chave) {
      novo->prox = *ini;
      *ini = novo;
    }
    else {
      p = *ini;
      while ((p != NULL) && (p->prox != NULL)) {
        // meio
        if ((p->prox != NULL) && (p->prox->chave > novo->chave)) {
          novo->prox = p->prox;
          p->prox = novo;
          p = NULL;
        }
        else
          p = p->prox;
      }
      // fim
      if (p != NULL) {
        novo->prox = NULL;
        p->prox = novo;
      }
    }
  }
}

//Objetivo: Recebe o valor da chave
//Parametro: Ponteiro para novo registro. 
void receberChave(struct registro *p) {
  printf("Digite o valor da chave: ");
  scanf("%d", &(p->chave));
}

//Objetivo: Recebe valores
//Parametro: Ponteiro para novo registro. 
void receberValores(struct registro *p) {
  printf("Digite o valor.........: ");
  fflush(stdin);
  scanf("%c", &(p->valor));
}

//Objetivo: Imprimir na tela todos os nos/nodos da lista
//Parametro: Ponteiro para novo registro. 
void listar(struct registro *p) {
  printf("\n\n*** LISTAGEM ***\n\n");
  printf("Chave Valor\n");
  printf("----- -----\n");
  while (p != NULL) {
    printf("%5d %c\n", p->chave, p->valor);
    p = p->prox;
  }
}
