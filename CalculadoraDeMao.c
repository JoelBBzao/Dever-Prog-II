#include <stdio.h>
#include <stdlib.h>
    float soma(float a, float b){
        return a + b;}
    float sub(float a, float b){
        return a - b;}
    float mult(float a, float b){
        return a * b;}
    float divisao(float a,float b){
        return a / b; }
int main()
{
    char op;
    float a,b;
    printf("Digite o operador: ");
    scanf("%c", &op);
    printf("Insira o numero: ");
    scanf("%f", &a);
    printf("Insira o numero: ");
    scanf("%f", &b);

    if (op == '+'){
        printf("Resultado da soma: %f", soma(a,b));
    }
    if (op == '-'){
        printf("Resultado da subtracao: %f", sub(a,b));
    }
    if (op == '*'){
        printf("Resultado da multiplicacao: %f", mult(a,b));
    }
    if (op == '/'){
        printf("Resultado da divisao: %f", divisao(a, b));
    }
}

