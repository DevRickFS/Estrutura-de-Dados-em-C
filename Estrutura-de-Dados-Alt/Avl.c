#include <stdio.h>

typedef struct No{
    int peso;
    struct no *esquerda;
    struct no *direita;
} NO;

typedef struct no_pai{
    NO *pai;
};