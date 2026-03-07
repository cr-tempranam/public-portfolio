#include <stdio.h>
#include <math.h>

int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
    
}
    
int main (){
   int n;
   int f;
   
   printf("Hasta qué valor de la sucesión de Fibonacci desea ver?\t");
   scanf("%d",&n);
   printf("\n");
    
    for(int i=0; i<=n;i++)
    {
        f = fibonacci(i);
        printf("El valor en n = %d de Fibonacci es %d \n", i,f);
    };
    
   
   
    return 0;
}