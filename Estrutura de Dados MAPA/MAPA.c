
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define tam 100

// Criacao da estrutura no para criacao da fila e pilha a serem usadas
typedef struct no {
  char dado;
  struct no *prox;
}NO;

//criacao da estrutura fila apontado para os nos
typedef struct fila{
  NO *ini;
  NO *fim;
}FILA;
//criacao da estrutura pilha apontado para os nos
typedef struct pilha{
  NO *topo;
}PILHA;
void ClearWindow();
//Funcao que ira fazer a insercao de dados na fila 
void Enfileirar(char dado, FILA *f) {
  NO *ptr = (NO*) malloc(sizeof(NO));
  if (ptr == NULL) {
    printf("Erro de Alocacao\n");
    return;
  } else {
    ptr->dado = dado;
    ptr->prox = NULL;
    if (f->ini == NULL) {
      f->ini = ptr;
    } else {
      f->fim->prox = ptr;

    };
    f->fim = ptr;  
  };
};
//funcao que ira remover os elementos da fila 
char desenfileirar(FILA *f){
  if (f->ini == NULL){
    printf("A fila esta vazia\n");
    return '\0';
  } else{
    char nucleotideo = f->ini->dado;
    NO *temp = f->ini;
    f->ini = f->ini->prox;
    free(temp);
    return nucleotideo;
  };
};
//funcao para imprimir a fila na tela
void FilaView(FILA *f){
  NO *ptr = f->ini;
    printf("FILA: \t");
  if (ptr==NULL){
    printf("Fila Vazia");
  }else{

    while (ptr != NULL){
      printf("%c ", ptr->dado);
      ptr = ptr->prox;
    };
    printf("\n");
  };
};
//funcao que imprime a pilha na tela 
void PilhaView(PILHA *p){
  NO *ptr = p->topo;
  printf("PILHA: \t");
  if (p->topo == NULL){
    printf("Pilha Vazia ");
  }else{
    while (ptr != NULL){
      printf("%c ", ptr->dado);
      ptr = ptr->prox;
    };
  }
  printf("\n");
}

//Funcao para inicializar a fila
void iniciar_fila(FILA *f){
  f->ini = NULL;
  f->fim = NULL;
};
// funcao para inicializar a pilha 
void InicializarPilha(PILHA *p){
  p->topo = NULL;
};

//funcao para inserir dados na pilha
void empilhar(char dado, PILHA *p){
    NO *ptr = (NO*) malloc(sizeof(NO));
    if (ptr == NULL){
            printf("Erro de Alocacao\n");
    };
	  ptr->dado = dado;
      ptr->prox = p->topo;
      p->topo = ptr;
    };

//funcao que faz a conversao do nucleotideos,e  insere na pilha removendo o elemento da fila
void Conversao(FILA *f, PILHA *p){
          while (f->ini != NULL){
            switch (desenfileirar(f)){
            case 'A':
              empilhar('T', p);
            break;
            case 'C':
              empilhar('G', p);
            break;

            case 'T':
              empilhar('A', p);
            break;

            case 'G':
              empilhar('C', p);
            break;
          };
  };
};
// funcao que imprime o meu inicial do programa e retorna a op��o escolhida pelo usuario
int MenuView(){
  int op;
  printf("|------------ MENU ------------|\n\n");
  printf("1 -\tInserir Sequ�ncia DNA:\n2 -\tImprimir Pilha\n0 -\tSAIR\n");
  scanf("%d", &op);
  system("cls");
  return op;
};
//funcao que ira esperar e limpar a tela 
void ClearWindow(){
	system("pause");
	system("cls");
};

// funcao que verifica a sequencia de nucleotideos que foi inserida, retornando um valor correnpondente ao resultado da verificacao
int verificacaoFita(char dadosfita[tam]){
  int i =0;
  int controle=0;
  while (controle != 1 && dadosfita[i] != '\0'){
    dadosfita[i] = toupper(dadosfita[i]);
    if (dadosfita[i] != 'A' && dadosfita[i] != 'C' && dadosfita[i] != 'G' && dadosfita[i] != 'T'){
      controle = 1;
      printf("Cont�m Dados Inval�dos! Tente Novamente\n");
      ClearWindow();
      break;
    } 
    
    i++;
  }
  return controle;
};


int main() {
    setlocale(LC_ALL, "Portuguese");

    FILA *fila = (FILA*) malloc(sizeof(FILA));
    PILHA *pilhaDNA = (PILHA*) malloc(sizeof(PILHA));
    iniciar_fila(fila);
    InicializarPilha(pilhaDNA);
    int selecao = -1;
    int verificacao;
    char fita[tam];
    while (selecao!= 0){
          selecao = MenuView();
          switch (selecao){
            case 1:
              verificacao = 1;
                while (verificacao != 0){
                  printf("Digita a Fita de DNA: ");
                  scanf("%s", fita);
                  verificacao = verificacaoFita(fita);
                  if (verificacao == 0){
                    int i;
                    for (i=0; fita[i]!='\0';i++){
                      fita[i] = toupper(fita[i]);
                      Enfileirar(fita[i], fila);
                    };
                    printf("-----------------------------------------\n");
                    FilaView(fila);
                    Conversao(fila, pilhaDNA);
                    PilhaView(pilhaDNA);
                    printf("-----------------------------------------\n\n");
                          
                    ClearWindow();
                  }
                  };
              break;
            case 2:
                printf("-----------------------------------------\n");
                PilhaView(pilhaDNA);
                printf("-----------------------------------------\n\n");
                ClearWindow();
            break;
            case 0:
                break;
              break;

            default:
                printf("Opera��o desconhecida! Tente Novamente\n");     
                ClearWindow();
                break;
                    };
      };

      return 0;
};
