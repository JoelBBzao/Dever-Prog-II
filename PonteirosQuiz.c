#include <stdio.h>
#include <stdlib.h>



int main()
{
    int i=3,j=5;
    int *p,*q;
    p= &i;
    q = &j;
    printf("p == %d\n",&i);
    printf("*p -*q = %d\n", (*p-*q));
    printf("**&p = %d\n", (**&p));
    printf("3*-*p/(*q)+7 = %d", (3* - *p/(*q)+7));
}
