/*EXERCICIO 1*/
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
/*=============================================================*/
/*EXERCICIO 2*/
float busca(char* arquivo, char* matricula){
    FILE *arq;
    char linha[256];
    char mat[50];
    float nota;
    arq = fopen(arquivo, "r");
    if(arq==NULL){printf("ERRO"); exit(1);}
    while(fgets(linha, sizeof linha, arq)!=NULL){
        if(sscanf(linha, "%s %f", mat, &nota)==2){
            if(strcmp(mat, matricula)==0){
                return nota;
            }
        }
    }
    fclose(arq);
    return nota = -1.0;
}
/*=============================================================*/
/*EXERCICIO 3*/
float media(char* mat, char* nome_arquivo){
    FILE *arq;
    char linha[256];
    char matric[50];
    float p1, p2, p3;
    float mediaAluno;
    arq = fopen(nome_arquivo, "r");
    if(arq ==NULL){printf("ERRO"); exit(1);}
    while(fgets(linha, sizeof linha, arq)!= NULL){
        if(sscanf(linha, "%s %f %f %f", matric, &p1, &p2, &p3)==4){
            if(strcmp(matric, mat)==0){
                mediaAluno = (p1 + p2 + p3)/3;
                return mediaAluno;
            }
        }
    }
    fclose(arq);
    return mediaAluno = -1.0;
}
/*=============================================================*/
/*EXERCICIO 4*/
int main(){
    char arqNome[100];
    printf("Insira o nome do arquivo: ");
    scanf(" %99[^\n]", arqNome);
    FILE* arq;
    arq = fopen(arqNome, "r");
    if(arq==NULL){printf("ERRO"); exit(1);}

    FILE* arq2 = fopen("arqRefinado.c", "w");
    if(arq2==NULL){printf("ERRO"); exit(1);}

    char linha[256];
    while(fgets(linha, sizeof linha, arq)!=NULL){
        int comentario = 0;
        for(int i = 0; linha[i] != '\0'; i++){
            if(linha[i] == '/' && linha[i+1] == '/'){
                linha[i] = '\n';
                linha[i+1] = '\0';
                break;}
        }
        fputs(linha, arq2);
    }

    fclose(arq);
    fclose(arq2);
    return 0;
}
/*=============================================================*/
/*EXERCICIO 5*/
int main(){
    char nomeArq[100];
    char linha[256];
    int i , nElem = 0;
    int lidos = 0;
    float media =0;

    printf("Insira o nome do arquivo: ");
    scanf(" %99[^\n]", nomeArq);
    FILE *arq = fopen(nomeArq, "r");
    if(arq==NULL){printf("ERRO"); exit(1);}

    while(fgets(linha, sizeof linha, arq)!= NULL){
        nElem ++;
    }
    if(nElem ==0){printf("Arquivo vazio"); fclose(arq); return 7;}
    fclose(arq);
    arq = fopen(nomeArq, "r");

    float *vet = (float*) malloc(nElem * sizeof(float));
    if(vet==NULL){printf("Memoria Insuficiente"); exit(1);}

    for(i = 0; i<nElem; i++){
        if(fscanf(arq, "%f", &vet[i])!=1){
            break;}
        lidos ++;
        media += vet[i];
    }
    fclose(arq);
    media = media/lidos;
    printf("%.2f", media);
    return 0;
}
/*=============================================================*/
/*EXERCICIO 6*/
int main(){
    char nome[] = "teste00.txt";
    int i;
    for(i=0; i<10; i++){
        nome[5] = '0' + (i+1)/10;
        nome[6] = '0' + (i+1)%10;
        FILE *arq = fopen(nome, "w");

        if(arq==NULL){printf("ERRO"); exit(-1);}
        fprintf(arq, "Texto do arquivo %d", i+1);

        fclose(arq);
    }
    return 0;
}
/*=============================================================*/
/*EXERCICIO 7*/
