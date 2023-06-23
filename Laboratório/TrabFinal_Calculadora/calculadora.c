#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

// inicializa o inteiro e define os ponteiros
void initBigInt(BigInt* num) {
    num->head = NULL;
    num->tail = NULL;
    num->size = 0;
}

//adiciona um inteiro ao final do numero grande, cria um novo nó e atribui
// o valor do digito e insere-o
void addDigit(BigInt* num, int digit) {
    no* N = (no*)malloc(sizeof(no));
    N->digit = digit;
    N->prox = NULL;

    if (num->head == NULL) {
        N->ant = NULL;
        num->head = N;
        num->tail = N;
    } else {
        N->ant = num->tail;
        num->tail->prox = N;
        num->tail = N;
    }

    num->size++;
}

//imprime o numero inteiro grande na saida padrao, percorre a lista e imprime cada digito
void printBigInt(BigInt num) {
    no* current = num.head;

    while (current != NULL) {
        printf("%d", current->digit);
        current = current->prox;
    }

    printf("\n");
}

//le o numero inteiro grande da entrada padrão, le uma sequencia de caracteres digitados pelo usuario
// e converte cada caractere em um digito inteiro
BigInt readBigInt() {
    char buffer[100];
    BigInt num;
    initBigInt(&num);

    fgets(buffer, sizeof(buffer), stdin);

    for (int i = 0; buffer[i] != '\n'; i++) {
        int digit = buffer[i] - '0';
        addDigit(&num, digit);
    }

    return num;
}

// cria uma copia exata de um numero inteiro grande, percorre a lista e add o digito a nova lista, criando uma copia identica
BigInt copyBigInt(BigInt num) {
    BigInt copy;
    initBigInt(&copy);

    no* current = num.head;
    while (current != NULL) {
        addDigit(&copy, current->digit);
        current = current->prox;
    }

    return copy;
}

// libera a memoria alocada para um numero inteiro grande, percorrimento de lista
void freeBigInt(BigInt* num) {
    no* current = num->head;
    while (current != NULL) {
        no* temp = current;
        current = current->prox;
        free(temp);
    }

    num->head = NULL;
    num->tail = NULL;
    num->size = 0;
}

// realiza a soma de dois numeros inteiros grandes (da direita pra esquerda)
// percorre ambos os numeros e os soma
BigInt addBigInt(BigInt num1, BigInt num2) {
    BigInt sum;
    initBigInt(&sum);

    int carry = 0;
    no* digit1 = num1.tail;
    no* digit2 = num2.tail;

    while (digit1 != NULL || digit2 != NULL) {
        int value1 = (digit1 != NULL) ? digit1->digit : 0;
        int value2 = (digit2 != NULL) ? digit2->digit : 0;

        int digitSum = value1 + value2 + carry;
        carry = digitSum / 10;
        digitSum %= 10;

        addDigit(&sum, digitSum);

        if (digit1 != NULL)
            digit1 = digit1->ant;
        if (digit2 != NULL)
            digit2 = digit2->ant;
    }

    if (carry > 0)
        addDigit(&sum, carry);

    return sum;
}

// realiza a subtraçao dos numeros inteiros grandes
// percorre os digitos de ambos os numeros subtraindo os digitos correspondentes e considrando o emprestimo, se necessario
BigInt subtractBigInt(BigInt num1, BigInt num2) {
    BigInt difference;
    initBigInt(&difference);

    int borrow = 0;
    no* digit1 = num1.tail;
    no* digit2 = num2.tail;

    while (digit1 != NULL || digit2 != NULL) {
        int value1 = (digit1 != NULL) ? digit1->digit : 0;
        int value2 = (digit2 != NULL) ? digit2->digit : 0;

        int digitDiff = value1 - value2 - borrow;

        if (digitDiff < 0) {
            digitDiff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        addDigit(&difference, digitDiff);

        if (digit1 != NULL)
            digit1 = digit1->ant;
        if (digit2 != NULL)
            digit2 = digit2->ant;
    }

    return difference;
}

/*
    Esta função realiza a multiplicação de dois números inteiros grandes  
     Ela percorre os dígitos do segundo número da direita para a esquerda e,
      para cada dígito, multiplica o primeiro número inteiro grande por esse dígito. Os resultados intermediários são somados usando a função addBigInt() para obter o produto final.
*/
BigInt multiplyBigInt(BigInt num1, BigInt num2) {
    BigInt product;
    initBigInt(&product);

    BigInt tempSum;
    initBigInt(&tempSum);

    no* digit2 = num2.tail;
    int zeroPadding = 0;

    while (digit2 != NULL) {
        int value2 = digit2->digit;
        int carry = 0;

        for (int i = 0; i < zeroPadding; i++)
            addDigit(&tempSum, 0);

        no* digit1 = num1.tail;

        while (digit1 != NULL) {
            int value1 = digit1->digit;
            int digitProduct = value1 * value2 + carry;
            carry = digitProduct / 10;
            digitProduct %= 10;
            addDigit(&tempSum, digitProduct);
            digit1 = digit1->ant;
        }

        if (carry > 0)
            addDigit(&tempSum, carry);

        product = addBigInt(product, tempSum);

        digit2 = digit2->ant;
        zeroPadding++;
        initBigInt(&tempSum);
    }

    freeBigInt(&tempSum);

    return product;
}


/*
Esta função realiza a divisão inteira de dois números inteiros grandes
 Ela percorre os dígitos do primeiro número da esquerda para a direita e
  vai subtraindo o divisor (segundo número) múltiplas vezes até não ser mais possível subtrair.
 O resultado é armazenado em um novo BigInt.
*/
BigInt divideBigInt(BigInt num1, BigInt num2) {
    BigInt quotient;
    initBigInt(&quotient);

    if (num2.size == 1 && num2.head->digit == 0 || num1.size == 1 && num1.head->digit == 0 ) {
        printf("Erro: divisao por zero!\n");
        return quotient;
    }

    BigInt remainder = copyBigInt(num1);

    while (remainder.size > 0) {
        int quotientDigit = 0;
        BigInt tempNum = copyBigInt(num2);

        while (compareBigInt(tempNum, remainder) <= 0) {
            quotientDigit++;
            tempNum = subtractBigInt(tempNum, num2);
        }

        addDigit(&quotient, quotientDigit);
        remainder = subtractBigInt(remainder, tempNum);
        freeBigInt(&tempNum);
    }

    return quotient;
}

/*
     Essa função calcula o resto da divisão inteira de dois números inteiros grandes (BigInt). 
     Ela utiliza o algoritmo da divisão inteira descrito anteriormente e retorna o resto da divisão.
*/
BigInt moduloBigInt(BigInt num1, BigInt num2) {
    BigInt remainder = copyBigInt(num1);

    while (compareBigInt(num2, remainder) <= 0) {
        remainder = subtractBigInt(remainder, num2);
    }

    return remainder;
}
/*
    funçao auxiliar para imprimir os numeros inteiros na ordem inversa
*/
void printInversoBigInt(BigInt num) {
    no* current = num.tail;

    while (current != NULL) {
        printf("%d", current->digit);
        current = current->ant;
    }

    printf("\n");
}

/*
    compara os dois numeros inteiros grandes, percorre-os da esquerda pra direita e verifica se sao iguais
    caso diferentes, o numero com maior digito é considerado maior, se nao retorna -1 (menor)
*/
int compareBigInt(BigInt num1, BigInt num2) {
    if (num1.size > num2.size)
        return 1;
    else if (num1.size < num2.size)
        return -1;
    else {
        no* digit1 = num1.head;
        no* digit2 = num2.head;

        while (digit1 != NULL && digit2 != NULL) {
            if (digit1->digit > digit2->digit)
                return 1;
            else if (digit1->digit < digit2->digit)
                return -1;

            digit1 = digit1->prox;
            digit2 = digit2->prox;
        }

        return 0;
    }
}
