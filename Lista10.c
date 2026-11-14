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
int main(){
    char *nomeArq = "numeros.txt";
    int i, nElem=0;
    char linha[256];


    FILE *arq = fopen(nomeArq, "r");
    if(arq==NULL){printf("ERRO"); exit(-1);}

    while(fgets(linha, sizeof linha, arq)!=NULL){
        nElem++; }
    fclose(arq);

    float *vet = (float*) malloc(nElem * sizeof(float));
    if(vet==NULL){printf("Memoria Insuficiente"); exit(1);}

    arq = fopen(nomeArq, "r");
    if(arq==NULL){printf("ERRO"); exit(-1);}
    for(i = 0; i<nElem; i++){
        fscanf(arq, "%f", &vet[i]);

        }
    fclose(arq);
    int fim;
    for(fim = nElem-1; fim>0; fim--){
        for(i=0; i<fim; i++){
            if(vet[i]>vet[i+1]){
                float temp = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = temp;
            }
        }
    }
    FILE *arqBin = fopen("numeros.dat", "wb");
    if(arqBin == NULL){ printf("ERRO"); exit(-1);}

    fwrite(vet, sizeof(float), nElem, arqBin);
    fclose(arqBin);
    
    free(vet);
    return 0;
}
/*=============================================================*/
/*EXERCICIO 8*/
int main(){
    ALUNO *turma;
    int nAlunos, i;
    char *alunos = "alunos.dat";
    printf("Quantidade de alunos: ");
    scanf("%d", &nAlunos);
    turma = (ALUNO*) malloc(nAlunos * sizeof(ALUNO));
    if(turma==NULL){ printf("Memoria Insuficiente\n"); exit(-1);}
    for(i=0; i<nAlunos; i++){        
        printf("Nome do aluno: ");
        scanf(" %80[^\n]", turma[i].nome);        

        printf("Notas 1 e 2 respectivamente: ");
        scanf("%f %f", &turma[i].nota1, &turma[i].nota2);
        printf("===================\n");
    }
    FILE *arq = fopen(alunos, "ab");
    if(arq==NULL){ printf("ERRO\n"); exit(-1); }
    fwrite(turma, sizeof(ALUNO), nAlunos, arq);
    fclose(arq);
    free(turma);
    return 0;
}
/*8a)*/
void aprovados(FILE *arquivo){
    fseek(arquivo, 0, SEEK_END);
    int tam = ftell(arquivo);
    int n = tam/sizeof(ALUNO);
    rewind(arquivo);
    if(n==0){ printf("Arquivo vazio.\n"); return;}
    
    ALUNO *alunos = (ALUNO*) malloc(n * sizeof(ALUNO));
    if(alunos == NULL){ printf("Memoria Insuficiente\n"); exit(-1); }
    
    fread(alunos, sizeof(ALUNO), n, arquivo);
    printf("APROVADOS:\n");
    for(int i = 0; i<n; i++){
        float media = (alunos[i].nota1+alunos[i].nota2)/2;
        if(media > 6.0){
            printf("%s: %.2f\n", alunos[i].nome, media);}
    }
    free(alunos);
}
/*8b)*/
int main(){
    ALUNO *turma = NULL;
    int nAlunos, i=0;
    int resp, add = 0;
    int alt;
    char *alunos = "alunos.dat";
    FILE *arq;
    do{
    printf("Escolha uma opcao\n1-Incluir aluno(s)\n2-Alterar aluno(s)\n");
    printf("3-Consultar aluno\n4-Excluir aluno(s)\n0-Encerrar programa\n");
    scanf("%d", &resp);
    if(resp==1){
        printf("Quantidade de alunos a incluir: ");
        scanf("%d", &add);
        if(add <= 0){ printf("Quantidade invalida\n"); continue; }

        ALUNO *novos = (ALUNO*) malloc(add * sizeof(ALUNO));
        if(novos==NULL){ printf("Memoria Insuficiente\n"); exit(-1); }

        for(i=0; i<add; i++){
            printf("Nome do aluno: ");
            scanf(" %80[^\n]", novos[i].nome);
            printf("Notas 1 e 2 respectivamente: ");
            scanf("%f %f", &novos[i].nota1, &novos[i].nota2);
            printf("===================\n");
        }

        arq = fopen(alunos, "ab");
        if(arq==NULL){ printf("ERRO\n"); free(novos); exit(-1); }
        fwrite(novos, sizeof(ALUNO), add, arq);
        fclose(arq);
        free(novos);
    }
        
    if(resp==2){   
        arq = fopen(alunos, "rb");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        fseek(arq, 0, SEEK_END);
        int tam = ftell(arq);
        int n = tam/sizeof(ALUNO);
        fclose(arq);   
    
        ALUNO rep;
        printf("Aluno a ser alterado(1 a %d): ", n);
        scanf("%d", &alt);
        alt = alt - 1;

        printf("Novo nome: ");
        scanf(" %80[^\n]", rep.nome);
        printf("Novas notas n1 e n2: ");
        scanf("%f %f", &rep.nota1, &rep.nota2);
        
        arq = fopen(alunos, "r+b");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        fseek(arq, alt * sizeof(ALUNO), SEEK_SET);
        fwrite(&rep, sizeof(ALUNO), 1, arq);
        fclose(arq);
        printf("Alteracao concluida\n");
    }
    
    if(resp==3){
        arq = fopen(alunos, "rb");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        fseek(arq, 0, SEEK_END);
        int tam = ftell(arq);
        int n = tam/sizeof(ALUNO);
        fclose(arq);  
    
        ALUNO rep;
        printf("Aluno a ser consultado(1 a %d): ", n);
        scanf("%d", &alt);
        alt --;
        
        arq = fopen(alunos, "rb");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        fseek(arq, alt * sizeof(ALUNO), SEEK_SET);
        fread(&rep, sizeof(ALUNO), 1, arq);
        fclose(arq);
        
        printf("Nome: %s\n", rep.nome);
        printf("Nota 1: %.2f // Nota 2: %.2f\n", rep.nota1, rep.nota2);        
    }
    
    if(resp==4){
        arq = fopen(alunos, "rb");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        fseek(arq, 0, SEEK_END);
        int tam = ftell(arq);
        int n = tam/sizeof(ALUNO);
        fclose(arq);            
        
        ALUNO *aluno = (ALUNO*) malloc(n*sizeof(ALUNO));
        if(aluno==NULL){ printf("Memoria Insuficiente\n"); exit(-1);}
        arq = fopen(alunos, "rb");
        if(arq==NULL){ printf("ERRO\n"); exit(-1); }
        
        fread(aluno, sizeof(ALUNO), n, arq);
        fclose(arq);
        
        printf("Aluno a ser excluido(1 a %d): ", n);
        scanf("%d", &alt);
        alt--;
        for(i=alt; i<n-1; i++){
            aluno[i] = aluno[i+1];}
        n--;
        arq = fopen(alunos, "wb");
        fwrite(aluno, sizeof(ALUNO), n, arq);
        fclose(arq);
        free(aluno);        
    }
    }while(resp!=0);
    free(turma);
    return 0;
}
