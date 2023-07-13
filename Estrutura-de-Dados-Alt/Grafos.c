#include <stdio.h>

#define maximo 5

int tam = 0;
int vertices[maximo][maximo];
char recebido;
int vertice1, vertice2;

int tam_grafo(){
        do {
        printf("Informe a quantidade de vertices: ");
        scanf("%i", &tam);
    } while (tam > maximo || tam < 1);
    return tam;
}

void inserirAresta(int num1, int num2){
    if (num1 > tam -1 || num2 > tam -1  || num1 < 0 || num2 < 0){
        printf("Erro\n");
    }else {
        vertices[num1][num2] = 1;
    }
};

void removerAresta(int num1, int num2){
       if (num1 > tam-1  || num2 > tam -1 || num1 < 0 || num2 < 0){
        printf("Erro\n");
    }else {
        vertices[num1][num2] = 0;
    }
};

void visualizarMatriz(){
    int i, j, v;
    for(v=0; v <= tam; v++){
        if (v == 0){
            printf(" ");
        }
        printf("  %i  ", v);}
    printf("\n");
    for (i=0; i <= tam;i++){
        printf("%i", i);
        for (j=0;j<=tam;j++){
            printf("| %i |", vertices[i][j]);
        }
        printf("\n");
    }
}
int main(){



    tam = tam_grafo();
     while (recebido != 'S'){
        printf("informe o vertice i: ");
        scanf("%i", &vertice1);
        printf("informe o vertice j: ");
        scanf("%i", &vertice2);
        inserirAresta(vertice1, vertice2);
 
        printf("Deseja parar ? [S/N]\n");
        scanf(" %c", &recebido);
    };
    visualizarMatriz();

}

    