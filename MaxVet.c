#include <stdio.h>
#include <stdlib.h>
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

