#include <stdio.h>

long factorial(int n)
{
    long t = 1;
    for(int i=n;i>0;i--)
    {
        t *= i;
    }
    
    return t;
}

double potencia(double x, int n)
{
    double b = 1;
    for(int i=1; i<=n; i++)
    {
        b *= x;
    }
    return b;
}

double serieTaylor(double x, int N)
{
    double e = 0;
    for(int n=0; n<=N; n++)
    {
        e += potencia(x, n) / factorial(n);
    }
    return e;
}

int main() 
{    
    int N = 20;
    double x;
    double e;
        
    printf("Para calcular e^x, ingrese el valor de x: ");
    scanf("%lf", &x);

    for(int i=0;i<=N;i++)
    {
        e = serieTaylor(x,i);
        printf("El resultado es: %f. \n", e);
    }

    return 0;
}