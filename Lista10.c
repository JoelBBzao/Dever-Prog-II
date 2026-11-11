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
