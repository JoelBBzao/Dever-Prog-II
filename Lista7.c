/*EXERCICIO 1*/
será impresso "3"
/*=============================================================*/
/*EXERCICIO 2*/
será impresso "etset Otimo"
p = frase + strlen(frase) - 1; é a mesma coisa que p = frase[10] (ou seja, 'e')
Assim:
misterio[0] = 'e'; 
misterio[1] = 't';
misterio[2] = 's';
misterio[3] = 'e';
misterio[4] = 't'
p[5] = ' '; então o laço para
"misterio[i] = ’ ’; i ++;" ou seja, misterio[5] vira espaço e logo depois 'i' muda para 6;
enquanto frase[j] for diferente de ' ', misterio[i] será igual a frase[j] e, os indices terão seu valor incrementado, ou seja;
misterio[6] = frase[0] == misterio[6] = 'O';
misterio[7] = 't';
misterio[8] = 'i';
misterio[9] = 'm';
misterio[10] = '0';
Dessa forma, a imrpessão de misterio será "etset Otimo";
/*=============================================================*/
/*EXERCICIO 3*/
int * iniciarVetor(int n){
    int *vet = (int*) malloc(n * sizeof(int));
    if(vet == NULL){printf("Memoria Insuficiente\n"); return NULL;}
    for(int i=0; i<n; i++){
        vet[i] = (i+1) * 5;
    }
    return vet;
}

void imprime(int *vet, int n){
    int i;
    printf("{");
    for(i=0; i<n; i++){
        if(i == n-1){
            printf("%d}", vet[i]);
        }
        else{
            printf("%d, ", vet[i]);
        }
    }
    printf("\n");
}

void main(){
    int n;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    int *vetor = iniciarVetor(n);
    imprime(vetor, n);
}
/*=============================================================*/
/*EXERCICIO 4*/
char *iniciaAlfa(char alf[], int n){
    int i;
    for(i=0; i<n; i++){
        alf[i] = 'a' + i;
    }
}

void imprime(char alf[], int n){
    printf("{");
    for(int i =0; i<n; i++){
        if(i == n-1){
            printf("%c}", alf[i]);
        }
        else{
            printf("%c, ", alf[i]);
        }
    }
    printf("\n");
}

int main(){
    char alfabeto[MAX];
    iniciaAlfa(alfabeto, MAX);
    imprime(alfabeto, MAX);
    return 0;
}
/*=============================================================*/
/*EXERCICIO 5*/
