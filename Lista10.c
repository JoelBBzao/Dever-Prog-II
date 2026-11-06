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
