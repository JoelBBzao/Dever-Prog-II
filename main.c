#include <stdio.h>
#include <stdlib.h>
    float media(float a,float b,float c){
        float condicao;
        condicao = (a+b+c)/3;
    return condicao;
    }
int main()
{
    float nota1;
    float nota2;
    float nota3;
    float condicao;
    do {printf("Insira a primeira nota: ");
        scanf("%f", &nota1);
        if (nota1<0 || nota1>10){
            printf("Por favor, insira uma nota valida\n");
        }
        } while (nota1<0 || nota1>10);

    do {printf("Insira a segunda nota: ");
        scanf("%f", &nota2);
        if (nota2<0 || nota2>10) {
                printf("Por favor, insira uma nota valida\n");
        }
        } while(nota2<0 || nota2>10);

    do {printf("Insira a terceira nota: ");
        scanf("%f", &nota3);
        if (nota3<0 || nota3>10){
                printf("Por favor, insira uma nota valida\n");
        }
        } while(nota3<0 || nota3>10);
    condicao = media(nota1, nota2, nota3);
    printf("Media: %.2f\n", condicao);
    if (condicao>=6){
        printf("Aprovado");
    }
    if ((4<=condicao && condicao<6)){
        printf("VS");
    }
    if (condicao<4){
        printf("Reprovado");
    }

}

