#include <conio.h>
#include <stdio.h>
float media(int n, float *v);

void main()
{
    int n;
    float x;
    int i;
    float mid;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    float v[n];
    for(i=0; i<n; i++)
        {
            printf("%do item do vetor: ", (i+1));
            scanf("%f", &x);
            v[i] = x;
        }
    mid = media(n, v);
    printf("Media: %.2f", mid);
}
float media(int n, float *v)
{
    n;
    int i;
    *v;
    float soma, med;

    for(i=0; i<n; i++)
        {
            soma = soma + *(v+i);
        }
    med = soma/n;
    return med;
}
