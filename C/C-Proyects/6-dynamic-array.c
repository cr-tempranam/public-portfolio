#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int a[], int n)
{
    int r = a[0];
    
    if (n==0) return r;
        
    for(int i=1; i<n; i++)
    {
        if (r > a[i])
            r = a[i];
    }
    return r;
} 

int max(int a[], int n)
{
    int r = a[0];
    
    if (n==0) return r;
        
    for(int i=1;i<n;i++)
    {
        if (r < a[i])
            r = a[i];
    }
    return r;
} 

float avg(int a[], int n)
{
    int t = a[0];
    
    if (n==0) return 0;
    if (n==1) return t;
        
    for(int i=1; i<n; i++)
    {
        t += a[i];
    }
    return (float)t/n;
} 

float p2(float x)
{
    return (x*x);
}

float varianza(int a[], float u, int n)
{
    float t = 0;

    if (n==0) return 0;
    if (n==1) return 0;
        
    for(int i=0; i<n; i++)
    {
        t += p2(a[i]- u);
    }
    return t/(n-1);
}

float stdDev(int a[], float u, int n)
{
    return sqrt(varianza(a, u, n));
}


int main() 
{
    int n = 10;
    char califications[] = "8,10,7,6,3,7,9,8,5,10";

    int* a = (int*) malloc(sizeof(int)*n);

    int nextValue = 0;

    for(int i=0; i<n; i++)
    {
        sscanf(califications+nextValue, "%d", a+i);

        for (; califications[nextValue] != ',' && califications[nextValue] !='\0'; nextValue++);  
        nextValue++;      
    }

    printf("CALIFICACIONES\n");
    for(int i=0 ;i<n ;i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    float media = avg(a,n);
    printf("La calificación promedio es %.2f.\n", media);

    float minimo = min(a,n);
    printf("La nota menor es %.f.\n", minimo);

    float maximo = max(a,n);
    printf("La nota mayor es %.f.\n", maximo);

    float desvio = stdDev(a, media, n);
    printf("El desvio estandar es %.2f.\n", desvio);


    free(a);
        

    return EXIT_SUCCESS;
}