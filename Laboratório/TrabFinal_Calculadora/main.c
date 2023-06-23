/* TRABALHO AED1 - Calculadora de números inteiros grandes: 
O programa deverá implementar uma calculadoradenúmeros inteiros de tamanho arbitrário,
sendo capaz de operar com números maiores doqueovalormáximo suportado pelo tipos de dados int e long.
Deverá ser criada uma representaçãoparataisnúmeros que explore os benefícios oferecidos pelas estruturas de dados vistas em sala.
As seguintesoperações deverão ser disponibilizadas: 

+ (adição), 
- (subtração), 
* (multiplicação), 
/ (divisãointeira)e 
% (resto da divisão inteira).

O programa deve oferecer as seguintes opções ao usuário:
1. Informar os operandos e armazená-los para a operação;
2. Exibir os operandos armazenados;
3. Exibir o menor/maior operando;
4. Realizar o cálculo desejado. Note que, como os operandos já estão armazenados noprograma, múltiplas operações (uma de cada vez) poderão ser realizadas comesses operandos. Oresultado deverá ser mostrado na tela da seguinte forma: OPERANDO1\n OPERAÇÃO \n OPERANDO2\n= \n TOTAL.
*/
/* Integrantes do Grupo:
    Jhon Wayne - 
    Yves Yan Esteves Pereira - 12021BCC022
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculadora.h"

int main() {
    BigInt operand1, operand2, result;
    int option;

    initBigInt(&operand1);
    initBigInt(&operand2);
    initBigInt(&result);

    do {
        printf("\n<<Calculadora de numeros inteiros grandes>>\n");
        printf("--------------------Menu--------------------\n");
        printf("1. Informar os operandos\n");
        printf("2. Exibir os operandos\n");
        printf("3. Exibir o menor/maior operando\n");
        printf("4. Realizar o calculo\n");
        printf("0. Sair\n");
        printf("----------------------------------------\n");
        printf("Digite uma opcao: ");
        scanf("%d", &option);
        setbuf(stdin, NULL);

        switch (option) {
            case 1:
                printf("\nDigite o primeiro operando:\n");
                operand1 = readBigInt();
                printf("\nDigite o segundo operando:\n");
                operand2 = readBigInt();
                printf("\nOperandos armazenados com sucesso!\n");
                break;
            case 2:
                printf("\nPrimeiro operando:\n");
                printBigInt(operand1);
                printf("\nSegundo operando:\n");
                printBigInt(operand2);
                break;
            case 3:
                if (compareBigInt(operand1, operand2) > 0) {
                    printf("\nMaior operando:\n");
                    printBigInt(operand1);
                    printf("\nMenor operando:\n");
                    printBigInt(operand2);
                } else if (compareBigInt(operand1, operand2) < 0) {
                    printf("\nMaior operando:\n");
                    printBigInt(operand2);
                    printf("\nMenor operando:\n");
                    printBigInt(operand1);
                } else {
                    printf("\nOs operandos sao iguais!\n");
                }
                break;
            case 4:
                printf("\nDigite a operacao desejada: ");
                printf("\nA = adicao");
                printf("\nS = subtracao");
                printf("\nM = multiplicacao");
                printf("\nD = divisao inteira"); 
                printf("\nR = resto da divisao inteira");
                printf("\nOperacao: ");
                char op;
                scanf(" %c", &op);
                op = toupper(op);
                getchar();  // Capturar o caractere de nova linha
                printf("\n");

                switch (op) {
                    case 'A':
                        result = addBigInt(operand1, operand2);
                        printf("\nResultado:\n");
                        printBigInt(operand1);
                        printf("+\n");
                        printBigInt(operand2);
                        printf("=\n");
                        printInversoBigInt(result);
                        break;
                    case 'S':
                        result = subtractBigInt(operand1, operand2);
                        printf("\nResultado:\n");
                        printBigInt(operand1);
                        printf("-\n");
                        printBigInt(operand2);
                        printf("=\n");
                        printInversoBigInt(result);
                        break;
                    case 'M':
                        result = multiplyBigInt(operand1, operand2);
                        printf("\nResultado:\n");
                        printBigInt(operand1);
                        printf("*\n");
                        printBigInt(operand2);
                        printf("=\n");
                        printBigInt(result);
                        break;
                    case 'D':
                        result = divideBigInt(operand1, operand2);
                        printf("\nResultado:\n");
                        printBigInt(operand1);
                        printf("/\n");
                        printBigInt(operand2);
                        printf("=\n");
                        printInversoBigInt(result);
                        break;
                    case 'R':
                        result = moduloBigInt(operand1, operand2);
                        printf("\nResultado:\n");
                        printBigInt(operand1);
                        printf("%%\n");
                        printBigInt(operand2);
                        printf("=\n");
                        printInversoBigInt(result);
                        break;
                    default:
                        printf("\nOpcao invalida!\n");
                }
                break;
            case 0:
                printf("Saindo...\n");
                printf("<<Fim do programa!!>>\n\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (option != 0);

    freeBigInt(&operand1);
    freeBigInt(&operand2);
    freeBigInt(&result);

    return 0;
}
