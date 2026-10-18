#include <stdlib.h>
#include <stdio.h>
/* EXERCICIO 1*/
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
    int cont = 0;
    Candidato *cand;
    printf("Quantidade de candidatos: ");
    scanf("%d", &n);
    int resp, cn, alt;

    printf("Selecione uma opcao\n");
    printf("1- Inserir dados do(s) candidato(s)\n2- Mostrar dados do candidato\n"); /* Questão 1b)*/
    printf("3- Alterar o local de prova de um candidato\n"); /* Questão 1c)*/
    scanf("%d", &resp);
    if(resp==1)
        {
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
                cont++;
            }
        }
    if(resp==2){
        if(cont==0){printf("Nenhum candidato encontrado");}
        else{
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
            } }
    }
    if(resp==3) /* Questão 1c)*/
        {
            if(cont==0){printf("Impossivel alterar o local de prova, motivo: Nenhum candidato encontrado");}
            else{
                printf("Qual candidato tera seu local alterado?\n");
                scanf("%d", &cn);
                cn = cn-1;
                printf("1- Alterar o endereco\n2- Alterar a sala\n3- Alterar os dois\n");
                scanf("%d", &alt);
                if(alt==1)
                    {
                        printf("Insira o novo endereco: ");
                        scanf(" %80[^\n]", cand[cn].loc->ender);
                    }
                if(alt==2)
                    {
                        printf("Insira a nova sala: ");
                        scanf("%d", cand[cn].loc->sala);
                    }
                if(alt==3)
                    {
                        printf("Insira o novo endereco: ");
                        scanf(" %80[\n]", cand[cn].loc->ender);
                        printf("Insira a nova sala: ");
                        scanf("%d", cand[cn].loc->sala);
                }
            }

        }
}
/*=============================================================*/
/* EXERCICIO 2*/
2)a) O erro está na linha 21, p_dt2 precisa do asterisco para indicar ponteiro. *p_dt2
2)b) 5 (março) 
/*=============================================================*/
/* EXERCICIO 3*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char * estado[27] =
{"AC","AL","AM","AP","BA","CE","DF","ES","GO","MA","MG","MS","MT","PA",
"PB","PE","PI","PR","RJ","RN","RO","RR","RS","SC","SE","SP","TO"};
typedef struct assalariados {
    char nome[51];
    char sexo;
    int idade;
    float salario;
    char estado[3];
} Assalariados;
void relatorio(Assalariados ** ptr, int numAssalariados);
void imprime(Assalariados ** ptr, int numAssalariados);
Assalariados * cadastra(char *nome, char sexo, int idade, float salario, char *estado) /*Questão 3a)*/
{
    Assalariados *novo = (Assalariados *) malloc(sizeof(Assalariados));
        if(novo== NULL){printf("Memoria insuficiente\n"); exit(1);}
        strcpy(novo->nome, nome);
        novo->sexo = sexo;
        novo->idade = idade;
        novo->salario = salario;
        strcpy(novo->estado, estado);
        return novo;
}
void imprime(Assalariados **ptr, int numAssalariados) /*Questão 3b)*/
    {
        int i;
        for(i=0; i<numAssalariados; i++)
            {
                printf("==========\n");
                printf("Assalariado %d\n", i+1);
                printf("Nome: %s\n", ptr[i]->nome);
                printf("Sexo: %c\n", ptr[i]->sexo);
                printf("Idade: %d\n", ptr[i]->idade);
                printf("Salario: %.2f\n", ptr[i]->salario);
                printf("Estado: %s\n", ptr[i]->estado);
            }

    }
void relatorio(Assalariados ** ptr, int numAssalariados) /*Questão 3c)*/
    {
        int cont = 0;
        int i, j;
        printf("==========\n");
        for(i=0; i<27; i++)
            {
                for(j=0; j<numAssalariados; j++)
                    {
                        if (estado[i][0] == ptr[j]->estado[0] && estado[i][1] == ptr[j]->estado[1])
                            {
                                if(ptr[j]->sexo=='M' && ptr[j]->idade>40 && ptr[j]->salario>1000.00)
                                    {cont++;}
                            }
                    }
                if(cont>0)
                    {
                        printf("Estado= %s com %d homens maiores de 40 anos e salario maior que R$ 1000,00\n", estado[i], cont);
                        cont=0;
                    }

            }
    }
int main() {
    Assalariados **pessoas;
    int numAssalariados=3;
    pessoas = (Assalariados **) malloc (numAssalariados * sizeof(Assalariados *));
    pessoas[0] = cadastra("Fulano de tal", 'M',45,1500.00, "RJ");
    pessoas[1] = cadastra("Ciclano", 'M',50,2500.00, "RS");
    pessoas[2] = cadastra("Beltrano", 'M',42,500.00, "RS");
    imprime(pessoas, numAssalariados);
    relatorio(pessoas, numAssalariados);
}
/*=============================================================*/
/*EXERCÍCIO 4*/
/*4a)*/
void atribui(char **nomes, int indice, char *nome)
    {
        strcpy(nomes[indice], nome);
    }
/*4b)*/
char * get_sobrenome(char *nome)
{
        int fim;
        fim = strlen(nome)-1;
        while(fim >=0 && nome[fim] == ' ')
            {fim--;}
        int j = fim;
        while(nome[j] != ' ')
            {j--;}
        return nome+j+1;
}
/*4c)*/
aparecerá 0
/*4d)*/
aparecerá a
/*=============================================================*/
