#include <stdio.h>
#define LENGTH 10
#define DEBUG

int min(int v[], int l)
{
    #ifdef DEBUG
    printf("L: %d\n", l);
    #endif
    
    if (l==1) 
    {
        #ifdef DEBUG
        printf("Base: %d\n", v[0]);
        #endif
        
        return v[0];
    }
    if (l==2) 
    {
        int m = v[0]<=v[1]? v[0]:v[1];
        
        #ifdef DEBUG
        printf("Base: [%d %d] --> %d\n",v[0], v[1], m);
        #endif
        
        return m;
    }
    
    #ifdef DEBUG
    printf("Nodo izq\n");
    #endif
    
    int minL = min(v, l/2);
    
    #ifdef DEBUG
    printf("Nodo der\n");
    #endif
    
    int minR = min(v+l/2, l-l/2);
    
    int m = minL<=minR? minL:minR;
    
    #ifdef DEBUG
    printf("min local: %d\n", m);
    #endif
    
    return m;
} 

int main() 
{
int v[LENGTH] = {8,9,7,5,6,4,2,1,3,5};
int mn = min(v,LENGTH);

printf("El valor minimo del array es: %d.\n", mn);

    return 0;
}