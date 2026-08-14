#include <stdio.h>
#include <stdlib.h>

int main()
{
    int segundos ;
    printf("Insira os segundos: \n");
    scanf("%d", &segundos);
    int horas ;
    int minutos;
    horas = segundos/3600;
    minutos = (segundos%3600)/60;
    segundos = segundos%60;
    printf("%d hora(s), %d minuto(s) e %d segundo(s)", horas, minutos, segundos);
    return 0;
}
