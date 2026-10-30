#include <stdlib.h>
#include <stdio.h>
/* EXERCICIO 1*/
/*1a)*/
void main(){
    int n, i;
    Candidato *cand;
    printf("Numero de candidatos: ");
    scanf("%d", &n);
    cand = (Candidato *) malloc(n * sizeof(Candidato));
        if(cand == NULL){ printf("Memoria Insuficiente\n");}
        for(i=0; i<n; i++){
                printf("====Candidato %d====\n", i+1);

                printf("Inscricao: ");
                scanf("%d", &cand[i].inscr);

                printf("Nome: ");
                scanf(" %80[^\n]", &cand[i].nome);

                printf("Data de nascimento: ");
                scanf("%d %d %d", &cand[i].nasc.dia, &cand[i].nasc.mes, &cand[i].nasc.ano);

                cand[i].loc = (Local *) malloc(sizeof(Local));
                if(cand[i].loc == NULL){ printf("Memoria insuficiente"); exit(1);}

                printf("Endereco: ");
                scanf(" %80[^\n]", &cand[i].loc->ender);
                printf("Sala: ");
                scanf("%d", &cand[i].loc->sala);

                printf("Nota geral: ");
                scanf("%f", &cand[i].nt.geral);
                printf("Nota especifica: ");
                scanf("%f", &cand[i].nt.especifica);
            }
        }    
    
}
/*1b)*/
 printf("1- Inserir dados do(s) candidato(s)\n2- Mostrar dados do candidato\n");
 if(resp==1)
        {
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
/*1c)*/
 if(resp==3)
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
                        scanf(" %80[^\n]", &cand[cn].loc->ender);
                    }
                if(alt==2)
                    {
                        printf("Insira a nova sala: ");
                        scanf("%d", &cand[cn].loc->sala);
                    }
                if(alt==3)
                    {
                        printf("Insira o novo endereco: ");
                        scanf(" %80[^\n]", &cand[cn].loc->ender);
                        printf("Insira a nova sala: ");
                        scanf("%d", &cand[cn].loc->sala);
                }
            }

        }
/*=============================================================*/
/* EXERCICIO 2*/
2)a) O erro está na linha 21, p_dt2 precisa do asterisco para indicar ponteiro. *p_dt2
2)b) 5 (março) 
/*=============================================================*/
/* EXERCICIO 3*/
/*3a)*/
Assalariados * cadastra(char *nome, char sexo, int idade, float salario, char *estado)
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
/*3b)*/
void imprime(Assalariados **ptr, int numAssalariados)
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
/*3c)*/
void relatorio(Assalariados ** ptr, int numAssalariados)
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
/*EXERCICIO 5*/
/*5A)*/
Aluno ** alocaAlunos(int n)
{
    int i;
    Aluno **alunos = (Aluno **) malloc(n * sizeof(Aluno *));
    if(alunos==NULL){printf("Memoria insuficiente\n"); exit(1);}
    for(i=0; i<n; i++)
        {
            alunos[i]= (Aluno *) malloc(sizeof(Aluno));
            if(alunos[i]==NULL){printf("Memoria Insuficiente\n");}
            alunos[i]->end = (Endereco *) malloc(sizeof(Endereco));
            if(alunos[i]->end==NULL){printf("Memoria Insuficiente\n");}
        }
/*5B)*/
void atribui(Aluno ** a, int indice, int matricula, char *nome, float nota1, float nota2, float nota3, char *nomeRua, int numero)
{
    a[indice]->mat = matricula;
    strcpy(a[indice]->nome, nome);
    a[indice]->nota.p1 = nota1;
    a[indice]->nota.p2 = nota2;
    a[indice]->nota.p3 = nota3;
    strcpy(a[indice]->end->rua, nomeRua);
    a[indice]->end->numero = numero;
}
/*=============================================================*/
/*EXERCICIO 6*/
Pessoa * busca(int n, Pessoa** vet, int codigo) {
    int ini = 0;
    int fim = n-1;
    while(ini <= fim){
        int meio = (ini+fim)/2;
        if(codigo < vet[meio]->codigo)
            {fim = meio-1;}
        else if(codigo > vet[meio]->codigo)
            {ini = meio+1;}
        else
            {return vet[meio];}
    }
    return NULL;
}
int main(){
    Pessoa** pessoas;
    int n = 2;
    int i;
    pessoas = (Pessoa**) malloc(n* sizeof(Pessoa*));
    for(i=0; i<n; i++){
        pessoas[i] = (Pessoa *) malloc(sizeof(Pessoa));
    }
    pessoas[0]->codigo = 1;
    strcpy(pessoas[0]->nome, "Caua");
    pessoas[1]->codigo = 2;
    strcpy(pessoas[1]->nome, "Caio");
    Pessoa *resultado = busca(n, pessoas, 1);
    if(resultado != NULL){
        printf("Pessoa encontrada: %s\n", resultado->nome);
    } else {
        printf("Pessoa nao encontrada.\n");
    }
    free(pessoas);
}
/*=============================================================*/
/*EXERCICIO 7*/
int compara(Prova *a, Prova *b){
    float somaA = 0, somaB = 0;
    somaA = a->q1 + a->q2 + a->q3 + a->q4;
    somaB = b->q1 + b->q2 + b->q3 + b->q4;
    if(somaA == somaB){
            if(strcmp(a->a.nome, b->a.nome) < 0){
                return 0;
            }
            else{
                return 1;
            }
        }
    else if(somaA < somaB){
        return 1;
    }
    return 0;
}

void troca(Prova **a, Prova **b){
    Prova *tmp = *a;
    *a = *b;
    *b = tmp;
}
/*=============================================================*/
/*EXERCICIO 8*/
Compromisso* busca(int n, Compromisso** vet, int d, int m, int a){
int ini = 0;
    int fim = n-1;
    while(ini <= fim){
        int meio = (ini+fim)/2;
        if(a < vet[meio]->dta.aa || (a== vet[meio]->dta.aa && m < vet[meio]->dta.mm)
        || (a==vet[meio]->dta.aa && m==vet[meio]->dta.mm && d < vet[meio]->dta.dd)){
            fim = meio-1;
        }
        else if(a > vet[meio]->dta.aa || (a== vet[meio]->dta.aa && m > vet[meio]->dta.mm)
        || (a==vet[meio]->dta.aa && m==vet[meio]->dta.mm && d > vet[meio]->dta.dd)){
            ini = meio+1;
        }
        else{
            return vet[meio];
                }
    }
    return NULL;
}
/*=============================================================*/
/*EXERCICIO 9*/
void main(){
    int tam;
    int i;
    printf("Alunos na turma: ");
    scanf("%d", &tam);
    ALUNO *turma = (ALUNO*) malloc(tam * sizeof(ALUNO));
    if(turma==NULL){
        printf("Memoria insuficiente\n");
        exit(1);
    }
    for(i=0; i<tam; i++){
        printf("Nome do %d aluno: ", i+1);
        scanf(" %80[^\n]", turma[i].nome);
        printf("Media do %d aluno: ", i+1);
        scanf("%f", &turma[i].media);
    }
    ordena(turma, tam);

    for(i=0; i<tam; i++){
        printf("%f\n", turma[i].media);
    }
    free(turma);
}
/*=============================================================*/
/*EXERCICIO 10*/
void le(ALUNO *a){
    for(int i=0; i<MAX; i++){
        printf(" Digite o nome do aluno %d: ", i+1);
        scanf(" %80[^\n]", a[i].nome);
        printf(" Digite a media do aluno %d: ", i+1);
        scanf("%f", &a[i].media);
    }
    while(getchar()!='\n');
}
void imprime(ALUNO *a){
    for(int i=0; i<MAX; i++){
        printf(" Aluno: %s, Media: %.2f\n", a[i].nome, a[i].media);
    }
}
void ordena_medias(ALUNO *a){
    int fim = MAX-1;
    for(int i=0; i<MAX; i++){
        for(int j=0; j<fim; j++){
            if(a[j].media>a[j+1].media){
                ALUNO temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
        fim--;
    }
}

/*=============================================================*/
/*EXERCICIO 11*/
/*11a)*/
Aluno* fillAluno(){
    int i;
    Aluno * a = (Aluno*) malloc(sizeof(Aluno));
    if(a==NULL){printf("Memoria Insuficiente\n"); exit(1);}
    printf("Matricula do aluno: ");
    scanf("%d", &a->matricula);
    printf("Nome do aluno: ");
    scanf(" %99[^\n]", a->nome);
    a->vNotas = (float*) malloc(5*sizeof(float));
    if(a->vNotas == NULL){printf("Memoria Insuficiente\n"); exit(1);}
    for(i=0; i<5; i++){
        printf("Nota %d: ", i+1);
        scanf("%f", &a->vNotas[i]);
    }
    return a;
}
/*11b)*/
Materia * fillMateria(int numAlunos){
    int i;
    Materia *materia = (Materia*) malloc(sizeof(Materia));
    if(materia == NULL){printf("Memoria Insuficiente\n"); exit(1);}
    materia->nAlunos = numAlunos;
    materia->V = (Aluno*) malloc(numAlunos * sizeof(Aluno));
    for(i=0; i<numAlunos; i++){
        Aluno *temp = fillAluno();
        materia->V[i] = *temp;
        free(temp);
    }
    return materia;
}
/*11c)*/
void mediaMateria(Materia *m1){
    int i;
    float soma = 0.0;
    for(i=0; i<5; i++){
        for(int j=0; j<m1->nAlunos; j++){
            soma = soma + m1->V[j].vNotas[i];
        }
        soma = soma/(m1->nAlunos);
        m1->media[i] = soma;
        soma = 0.0;
    }
}
/*11d)*/
void mostraMateria(Materia *m1){
    int i;
    for(i=0; i<m1->nAlunos; i++){
        printf("==========\n");
        printf("Nome: %s\n", m1->V[i].nome);
        printf("Matricula: %d\n", m1->V[i].matricula);
        printf("Notas: ");
        for(int j=0; j<5; j++){
            if(j==4){
                printf("%.2f", m1->V[i].vNotas[j]);
            }
            else{
            printf("%.2f, ", m1->V[i].vNotas[j]);
            }
        }
        printf("\n");
    }
}
/*11e)*/
void main(){
    int i;
    int numAlunos;
    Materia *mate;
    printf("Insira o numero de alunos: ");
    scanf("%d", &numAlunos);
    mate = fillMateria(numAlunos);
    mediaMateria(mate);
    printf("--Medias--\n");
    for(i=0; i<5; i++){
        printf("%do media: %f\n", i+1, mate->media[i]);
    }
    mostraMateria(mate);
    
    for (i=0;i<numAlunos; i++){
        free(mate->V[i].vNotas);            
        }
    }
    free(mate->V);
    free(mate);
}
/*=============================================================*/
/*EXERCICIO 12*/
/*12a)*/
Livro * fillLivro(){
    Livro *livro = (Livro*) malloc(sizeof(Livro));
    if(livro == NULL){printf("Memoria Insuficiente\n"); exit(1);}
    printf("Ano de lancamento do livro: ");
    scanf("%d", &livro->ano);

    printf("Titulo: ");
    scanf(" %99[^\n]", livro->titulo);

    printf("Autor: ");
    scanf(" %99[^\n]", livro->autor);

    printf("Numero de exemplares: ");
    scanf("%d", &livro->nVolume);

    printf("Preco: ");
    scanf("%f", &livro->preco);
    return livro;
}
/*12b)*/
Biblioteca * fillBiblioteca(int numLivros){
    Biblioteca *biblio = (Biblioteca*) malloc(sizeof(Biblioteca));
    if(biblio == NULL){printf("Memoria Insuficiente"); exit(1);}
    biblio->nLivros = numLivros;
    biblio->V = (Livro**) malloc(numLivros * sizeof(Livro*));
    if(biblio->V == NULL){printf("Memoria Insuficiente"); exit(1);}

    for(int i=0; i<numLivros; i++){
        Livro *tmp = fillLivro();
        biblio->V[i] = tmp;
    }
    return biblio;
}
/*12c)*/
void valorBiblioteca(Biblioteca * b1, int numLivros){
    float valor=0;
    for(int i=0; i<numLivros; i++){
        valor = (b1->V[i]->nVolume * b1->V[i]->preco) + valor;
    }
    printf("Valor de compra de todos os exemplares: %.2f\n", valor);
}
/*12d)*/
Livro * maiorBiblioteca(Biblioteca *b1, int numLivros){
    int i;
    Livro *maior = b1->V[0];
    for(i=0; i<numLivros; i++){
        if(b1->V[i]->nVolume> maior->nVolume){
            maior = b1->V[i];
        }
    }
    return maior;
}
/*12e)*/
void main(){
    int nLivros;
    Biblioteca * bib;
    printf("Quantidade de livros na biblioteca: ");
    scanf("%d", &nLivros);
    bib = fillBiblioteca(nLivros);
    valorBiblioteca(bib, nLivros);
    printf("Livro com mais exemplares: %s", maiorBiblioteca(bib, nLivros)->titulo);
    for(int i=0; i<nLivros; i++){
        free(bib->V[i]);
    }
    free(bib->V);
    free(bib);
}
