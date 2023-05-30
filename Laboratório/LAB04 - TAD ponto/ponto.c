#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ponto.h"

struct ponto{
    int x1, x2, y1, y2;
    float distancia;
};

/*
    Entrada: nenhuma
    Pré-Condição: nenhuma
    Processo: cria um ponto
    Saída: endereço do ponto criado
    Pós-Condição: nenhuma
*/

Ponto *generate(){
    Ponto *p;
    p = (Ponto*)malloc(sizeof(Ponto));
    return p;
}

/*
    Entrada: endereço de um ponto e inteiros de x e y
    Pré-condição: número racional ser valido e diferente de zero
    Processo: atribui os valores das coordenadas x e y
    Saída: 1 se sucesso, 0 se falha
    Pós-condição: valores atribuidos
*/

int set_value(Ponto *p, int X1, int X2, int Y1, int Y2){
    if(p == NULL && p != 0)
        return 0;   // falha
    
    p -> x1 = X1;
    p -> x2 = X2;
    p -> y1 = Y1;
    p -> y2 = Y2;
        return 1;   // sucesso
}

/*
    Entrada: endereço de um ponto e endereço de dois inteiros
    Pré-condição: numero racional ser válido
    Processo: retornar os valores das coordenadas x e y de um ponto
    Saída: 1 se sucesso, 0 se falha
    Pós-condição: os inteiros com valores retornados
*/

int get_value(Ponto *p, int *X1, int *X2, int *Y1, int *Y2){
    if(p == NULL)
        return 0;
    
    *X1 = p->x1;
    *X2 = p->x2;
    *Y1 = p->y1;
    *Y2 = p->y2;
        return 1;
}

/*
    Entrada: coordenadas dos pontos x e y
    Pré-condição: nenhuma
    Processo: calcula a distancia entre os pontos
    Saída: nenhuma
    Pós-condição: distancia dos pontos calculada
*/

float distancia_pto(int x1, int x2, int y1, int y2){
    float distancia = 0;
    sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    return distancia;
}

/*
    Entrada: endereço do endereço de um ponto
    Pré-condição: nenhuma
    Processo: Liberar a memoria usada pelo ponto e limpar seu endereço
    Saída: nenhuma
    Pós-condição: ponto liberado
*/

void libera_pto(Ponto **p){
    free(*p);
    *p == NULL;
}