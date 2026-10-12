#include <stdlib.h>
#include <stdio.h>

typedef struct data {
    int dia, mes, ano;
} Data;

typedef struct local {
    char ender[81]; /* endereço do local de provas */
    int sala; /* numero sala */
} Local;

typedef struct notas {
    float geral; /* prova de conhecimentos gerais */
    float especifica; /* prova de conhecimentos
    especificos */
} Notas;

typedef struct candidato {
    int inscr; /* numero de inscricao */
    char nome[81]; /* nome do candidato */
    Data nasc; /* data de nascimento */
    Local *loc; /* local de prova */
    Notas nt; /* notas de prova */
} Candidato;

void main()
{
    int n, i;
    Candidato *cand;
    printf("Quantidade de candidatos: ");
    scanf("%d", &n);

    cand = (Candidato *) malloc(n * sizeof(Candidato));
    if(cand == NULL){ printf("Memoria Insuficiente\n");}

    for(i=0; i<n; i++)
        {
            printf("====Candidato %d====\n", i+1);

            printf("Inscricao: ");
            scanf("%d", &cand[i].inscr);

            printf("Nome: ");
            scanf(" %80[^\n]", &cand[i].nome);

            printf("Data de nascimento: ");
            scanf("%d %d %d", &cand[i].nasc.dia, &cand[i].nasc.mes, &cand[i].nasc.ano);

            cand[i].loc = (Local *) malloc(sizeof(Local));
            if(cand[i].loc == NULL){ printf("Memoria insuficiente");}

            printf("Endereco: ");
            scanf(" %80[^\n]", &cand[i].loc->ender);
            printf("Sala: ");
            scanf("%d", &cand[i].loc->sala);

            printf("Nota geral: ");
            scanf("%f", &cand[i].nt.geral);
            printf("Nota especifica: ");
            scanf("%f", &cand[i].nt.especifica);
        }
    printf("====Candidatos Inscritos====\n");
    for(i=0; i<n; i++){
        printf("-Candidato %d-\n", i+1);
        printf("Inscricao: %d\n", cand[i].inscr);
        printf("Nome: %s\n", cand[i].nome);
        printf("Data de nascimento: %d/%d/%d\n", cand[i].nasc.dia, cand[i].nasc.mes, cand[i].nasc.ano);
        printf("Local de prova: %s\nSala: %d\n", cand[i].loc->ender, cand[i].loc->sala);
        printf("Nota da prova geral: %.2f\n", cand[i].nt.geral);
        printf("Nota da prova especifica: %.2f\n", cand[i].nt.especifica);
        printf("============================\n");

    }



}
