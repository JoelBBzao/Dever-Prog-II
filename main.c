#include <stdio.h>
#include <stdlib.h>
struct funcionario {
char nome[81]; /* nome do funcionário */
float valor_hora; /* valor da hora de trabalho em Reais */
int horas_mes; /* horas trabalhadas em um mês */
};
typedef struct funcionario Funcionario;
void carrega (int n, Funcionario** vet, char* arquivo){
    FILE *arq;
    int i;
    arq = fopen(arquivo, "r");
    if(arq == NULL){
        printf("ERRO"); exit(1);}
    for(i=0; i<n; i++){
        vet[i] = (Funcionario*) malloc(sizeof(Funcionario));

        if(vet[i] == NULL){
            printf("Memoria Insuficiente\n"); exit(1);
            }
        if(fscanf(arq, " %80[^\n] %f %d", vet[i]->nome, &vet[i]->valor_hora, &vet[i]->horas_mes)!=3){
            free(vet[i]);
            vet[i] = NULL;
        }
        }
    fclose(arq);
}


int main()
{
    int n = 6;
    int i;
    Funcionario **vet;
    char *arq = "funciArq.txt";
    vet = (Funcionario **) malloc(n* sizeof(Funcionario*));
    if(vet == NULL){printf("Memoria Insuficiente\n"); exit(1);}

    for(i=0; i<n; i++){
        vet[i] = NULL;}

    carrega(n, vet, arq);

    for(i=0; i<n; i++){
        if(vet[i] != NULL){
            printf("Funcionario: %s\n", vet[i]->nome);
            printf("Valor hora: %.2f // Horas por mes: %d\n", vet[i]->valor_hora, vet[i]->horas_mes);
        }
    }
    for(i=0; i<n; i++){
        free(vet[i]);
    }
    free(vet);
    return 0;
}
