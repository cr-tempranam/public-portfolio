#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct
{
    char* lastName;
    char* firstName;
    int Age;
    int Id;
} User;

int main() 
{
    int n = 3;
    char data[] = "Perez,Juan,37,1248\nSosa,Maria,28,1263\nSanchez,Pedro,42,1187";

    User** u = (User**) malloc(sizeof(User*)*n);
    
    int nextValue = 0;

    for(int i=0; i<n; i++) //PIDO MEMORIA Y ASIGNO VALORES
    {      
        u[i]= (User*) malloc(sizeof (User));

        (*u[i]).lastName = (char*) malloc(sizeof (char)*15);
        u[i]->firstName= (char*) malloc(sizeof (char)*15); 

        sscanf(data+nextValue,"%[^,],%[^,],%d,%d\n", u[i]->lastName, u[i]->firstName, &u[i]->Age, &u[i]->Id);

        for (; data[nextValue] != '\n' && data[nextValue] !='\0'; nextValue++);  
        nextValue++;      
    }
   
    for(int i=0; i<n; i++) //IMPRESION
    {
        printf("%s,%s,%d,%d\n", u[i]->lastName, u[i]->firstName, u[i]->Age, u[i]->Id);
        printf("\n");
    }
    

    for(int i=0; i<n ;i++) //LIBERO LOS CHAR Y LOS USERS
    {
        free(u[i]->lastName);
        free(u[i]->firstName);

        free(u[i]);
    }

    free(u); //LIBERO EL ARRAY DE PUNTEROS

    
        

    return 0;
}
