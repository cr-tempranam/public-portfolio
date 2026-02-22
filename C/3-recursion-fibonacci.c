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
   
   printf("Cuál valor de la sucesión de Fibonacci desea ver? \n");
    scanf("%d",&n);
    
    f = fibonacci(n);
    printf("El valor es %d \n", f);
   
    return 0;
}