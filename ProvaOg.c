/*==========================================================================*/
typedef struct ponto {
    int x, y, z;
} Ponto;
void troca(Ponto *p1, Ponto *p2);
void imprime(Ponto ponto);
Ponto *novoPonto(int x, int y, int z);

void main(){
    Ponto p1 = {2, 4, 6}, p2 = {5, 7, 9}, *p3;
    troca(&p1, &p2);
    imprime(p1);
    imprime(p2);
    p3 = novoPonto(1, 3, 5);
    imprime(*p3);
}
void troca(Ponto *p1, Ponto *p2){
    Ponto temp;
    temp.x = p1->x; temp.y = p1->y; temp.z = p1->z;
    p1->x = p2->x; p1->y = p2->y; p1->z = p2->z;
    p2->x = temp.x; p2->y = temp.y; p2->z = temp.z;
}
void imprime(Ponto ponto){
    printf("%d\n%d\n%d\n", ponto.x, ponto.y, ponto.z);
    }
Ponto *novoPonto(int x, int y, int z){
    Ponto *ponto;
    ponto = (Ponto*) malloc(sizeof(Ponto));
    ponto->x = x; ponto->y = y; ponto->z = z;
    return ponto;
}
/*==========================================================================*/
