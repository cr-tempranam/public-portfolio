#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int** crearMatriz(int n)
{
    int **A= (int**)malloc(sizeof (int*)*n);
    
    for(int i=0;i<n;i++)
    {
        A[i] = (int*)malloc(sizeof(int) * n);
        memset(A[i], 0, sizeof(int) * n);
    }    

    return A;
}

int det(int **A)
{
    int r= 
    A[0][0]*A[1][1]*A[2][2]+
    A[0][1]*A[1][2]*A[2][0]+
    A[0][2]*A[1][0]*A[2][1]-
    A[0][2]*A[1][1]*A[2][0]-
    A[0][1]*A[1][0]*A[2][2]-
    A[0][0]*A[1][2]*A[2][1];

    return r;
}

void freeMatriz(int **A, int n)
{
    for(int i=0; i<n; i++)
    {
        free(A[i]);
    }
    free(A);
}

void copiarMatriz(int **A, int **AD, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            AD[i][j] = A[i][j];
        }
    }
}

int** crearAdjunta(int **A, int b[],int n, int c)
{
    int **AD= crearMatriz(n);

    copiarMatriz(A, AD, n);

    for(int i=0; i<n ; i++ )
    {
        AD[i][c] = b[i];
    }

    return AD;
}

double *resolve(int **A, int *b, int n)
{
    
    double *r= (double*)malloc(sizeof (double) * n);

    for(int c=0; c<n; c++)
    {
        int **AD = crearAdjunta(A,b,n,c);

        r[c]= (double)det(AD)/det(A);

        freeMatriz(AD,n);
    }
    return r;
 
}

void imprimirMatriz(int **A, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n;j++)
        {
            printf("%d", A[i][j]);
            printf("\t");
        }
        printf("\n");
    }
}



int main() 
{
    int n= 3;

    int **A = crearMatriz(n);

    int *b= (int*)malloc(sizeof (int) * n);
     
    b[0] = 26;
    b[1] = 11;
    b[2] = -7;

    A[0][0]=1;
    A[0][1]=5;
    A[0][2]=9;
    A[1][0]=1;
    A[1][1]=4;
    A[1][2]=-2;
    A[2][0]=2;
    A[2][1]=-1;
    A[2][2]=3;


    double *R = resolve(A,b,n);

 
    printf("La solución del sistema A x = b es:\n\n");

    printf("[");
    for(int i=0; i<n;i++)
    {   
        printf("%.2f%s",R[i], i < n-1? " " : "");
    }
    printf("]");

    freeMatriz(A,n);
    free(b);
    free(R);
      

    return 0;
}