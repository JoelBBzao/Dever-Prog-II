#include <stdio.h>
#include <stdlib.h>
/*5. Implemente a função max_vet, que recebe como parâmetro um vetor de números de ponto
flutuante (vet) de tamanho n e retorna o maior número armazenado nesse vetor. Essa função deve
obedecer o protótipo: float max_vet (int n, float * vet);
Faça também a função main.*/
float max_vet(int n, float *vet)
{
    *vet;
    int i;
    float *max;
    *max = vet[0];
    for(i=0; i<n; i++)
        {
            if(*(vet+i)>*max)
                {
                    *max= *(vet+i);
                }
        }
    return *max;
}
int main()
{
 int i, n;
 float x;
 printf("Tamanho do vetor: ");
 scanf("%d", &n);
 float vet[n];
 float resp;
 for(i=0; i<n; i++)
 {
     printf("%dn Item do vetor: ", (i+1));
     scanf("%f", &x);
     vet[i] = x;
 }
 resp = max_vet(n, vet);
 printf("%.2f", resp);
}

