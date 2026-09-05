#include <stdio.h>
#include <stdlib.h>

int divs(int n, int *min, int *max)
{
    *max= 0;
    *min = n;
    int i;
    int resp = 0;
    for(i=2; i<n; i++)
    {
        if(n%i == 0)
            {
            if(i<*min)
            {*min=i;}

            if(i>*max)
            {*max=i;}
            resp=1;
            }
    }
    return resp;
}

int main()
{
   int n;
   int resp;
   int max, min;
   printf("Valor de n: ");
   scanf("%d", &n);
   resp = divs(n, &min, &max);
   printf("E primo?: %d\n", resp);
   if(resp==1)
    {
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);
    }

}

