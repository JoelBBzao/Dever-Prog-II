#include <stdio.h>
#include <stdlib.h>
int maiores(int n, int * vet, int x);
int main()
{
    int n, x, a;
    int resp;
    int i;
    printf("Tamanho do vetor: ");
    scanf("%d", &n);
    int vet[n];
    printf("Insira um numero: ");
    scanf("%d", &x);
    for(i=0; i<n; i++)
        {
            printf("%do valor do vetor: ", i+1);
            scanf("%d", &a);
            vet[i] = a;
        }

    resp = maiores(n, vet, x);
    printf("Maiores que %d: %d", x, resp);
}
 int maiores(int n, int * vet, int x)
{
    int i;
    x;
    *vet;
    int cont = 0;
    for(i=0; i<n; i++)
    {
        if(*(vet+i)>x)
        {
            cont+=1;
        }
    }
    return cont;
}
