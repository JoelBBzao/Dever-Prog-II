#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    int maior;
    int menor;
    float media;
    printf("Insira o valor de A: ");
    scanf("%d", &a);
    printf("Insira o valor de B: ");
    scanf("%d", &b);
    printf("Insira o valor de C: ");
    scanf("%d", &c);
   if ((a>=b)&(a>=c)){
    maior = a;
   }
    if ((b>=a)&(b>=c)){
    maior = b;
   }
    if ((c>=a)&(c>=b)){
    maior = c;
   }
    if ((b>=a)&(c>=a)){
    menor = a;
   }
   if ((a>=b)&(c>=b)){
    menor = b;
   }
   if ((a>=c)&(b>=c)){
    menor = c;
   }
   media = (a+b+c)/3;

   printf("Maior: %d, Menor: %d, Media: %f, ", maior, menor, media);
   printf("Pares: ");
   if ((a%2)==0){
    printf("%d ", a);
   }
   if ((b%2)==0){
    printf("%d ", b);
   }
    if ((c%2)==0){
    printf("%d ", c);
   }
}
