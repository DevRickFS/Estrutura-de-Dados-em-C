#include <stdio.h>

#define maximo 5

char recebido;
int vertice1, vertice2, Peso;
typedef struct No{
    int Vi;
    int Vj;
    int Peso;
}NO;

NO aresta[maximo];

void inserirAresta(int num1, int num2, int Peso, int i){
    if (num1 > maximo || num2 > maximo || num1 < 0 || num2 < 0){
        printf("Erro\n");
    } else {
        aresta[i].Vi = num1;
        aresta[i].Vj = num2;
        aresta[i].Peso = Peso;
    }
}

void imprimirVet(int incremento){
    int i;
    printf("{ ");
    for (i =0;i < incremento; i++){
        printf("(%i, %i, %i)", aresta[i].Vi, aresta[i].Vj, aresta[i].Peso);
    }
    printf(" }");
}
int main(){
    int i = 0;
    while (recebido != 'S' && i < maximo){
    printf("informe o vertice i: ");
    scanf("%i", &vertice1);
    printf("informe o vertice j: ");
    scanf("%i", &vertice2);
    printf("informe o peso: ");
    scanf("%i", &Peso);
    inserirAresta(vertice1, vertice2, Peso, i);
    i++;
    printf("Deseja parar ? [S/N]\n");
    scanf(" %c", &recebido);
};
    imprimirVet(i);
    return 0;
}