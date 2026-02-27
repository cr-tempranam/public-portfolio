#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef M_PI
    #define M_PI 3.14159265359
#endif


typedef double (*Signal)(double A, double f, int N, double t);

double SenoidalSignal(double A, double f, int N, double t)
{
    return A * sin(2 * M_PI * f * t);
}

double SquareSignal(double A, double f, int N, double t)
{
    double acum = 0;    
    for(int k = 1; k <= N; k+=2)
    {
        acum += (1.0/k) * sin( k * 2 * M_PI * f * t);
    }
        
    return ((4*A)/M_PI) * acum; 

}

double TriangularSignal(double A, double f, int N, double t)
{

    double acum = 0;    
    for(int k = 1; k <= N; k+=2)
    {
        acum += pow(-1, (k-1)/2) / pow(k,2) * sin( k * 2 * M_PI * f * t);
    }
        
    return ((8*A)/pow(M_PI,2)) * acum; 
}

//Program1.exe    s=    A=  f=  N=
int main (int argc, char const* argv[])
{

    double A = 1;
    double f = 1;
    int N = 3;
    double ts = 1/(1000 * f);
    int s = 0;

    Signal sgnl[] = {SenoidalSignal, SquareSignal, TriangularSignal};

    for(int i = 1; i < argc; i++)
    {
        char param[2]; //el 2 es el parametro + el "\0"
        int value;

        sscanf(argv[i], "%1[^=]=%d", param, &value);
        
        if(strcmp(param, "s") == 0)
        {
            if( 0 <= value && value <=2) s = value;
        } 

        if(strcmp(param, "A") == 0)
        {
            if( value >= 0) A = value;
        } 

        if(strcmp(param, "f") == 0)
        {
            if( value >= 0) f = value;
        }

        if(strcmp(param, "N") == 0)
        { 
            if( value >= 0) N = value;
        }
    }    

    for(double t = 0; t <= 1; t += ts)
    {        
        printf("%f\t%f\n", t, sgnl[s](A, f, N, t));
    }
    
    return EXIT_SUCCESS;

}