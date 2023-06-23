#ifndef CALCULADORA_H
#define CALCULADORA_H

// Estruturas de dados baseadas em um Lista Dinamica Duplamente Encadeada,
//  e usando também alguns conceitos da implementação da lista Recursiva


typedef struct no {
    int digit;
    struct no* prox;
    struct no* ant;
} no;

typedef struct {
    no* head;
    no* tail;
    int size;
} BigInt;

void initBigInt(BigInt* num);
void addDigit(BigInt* num, int digit);
void printBigInt(BigInt num);
BigInt readBigInt();
BigInt copyBigInt(BigInt num);
void freeBigInt(BigInt* num);
BigInt addBigInt(BigInt num1, BigInt num2);
BigInt subtractBigInt(BigInt num1, BigInt num2);
BigInt multiplyBigInt(BigInt num1, BigInt num2);
BigInt divideBigInt(BigInt num1, BigInt num2);
BigInt moduloBigInt(BigInt num1, BigInt num2);
int compareBigInt(BigInt num1, BigInt num2);
void printInversoBigInt(BigInt num);


#endif  // CALCULADORA_H
