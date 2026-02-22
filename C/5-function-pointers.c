#include <stdio.h>
#include <stdlib.h>

#define LASTNAME_LENGTH 15
#define FIRSTNAME_LENGTH 30

typedef struct 
{
    int id;
    char lastname[LASTNAME_LENGTH];
    char firstname[FIRSTNAME_LENGTH];
    int age;
    
} User;

typedef int (*Comparer)(void*, void*);

void sortArray(void* v[], int l, Comparer cmp, int asc)
{
    if (l<=1) return;    
        
    for (int i = 1; i < l; i++)
    {
        void* vp = v[0];
        void* vi = v[i];        
        
        if (asc? cmp(vi, vp) : cmp(vp, vi)) continue; 
        else
        {
            void* m0 = v[0];
        
            v[0] = v[i];
            v[i] = m0;
        }
    }
    
    sortArray(v+1, l-1, cmp, asc);
}

int compareInt(void* x, void* y)
{
    int n1 = (int)x;
    int n2 = (int)y;

    return n1 >= n2;
}


int compareByAge(void* x, void* y)
{
    User* u1 = (User*)x;
    User* u2 = (User*)y;

    return u1->age >= u2->age;

}

int compareById(void* x, void* y)
{
    User* u1 = (User*)x;
    User* u2 = (User*)y;

    return u1->id >= u2->id;

}

int compareByLastName(void* x, void* y)
{
    User* u1 = (User*)x;
    User* u2 = (User*)y;

    for(int i=0; i<LASTNAME_LENGTH ;i++)
    {
        if (u1->lastname[i] == '\0' && u2->lastname[i] != '\0') return 0;
        if (u2->lastname[i] == '\0' && u1->lastname[i] != '\0') return 1;
        
        if (u1->lastname[i] == u2->lastname[i]) continue;
        
        return u1->lastname[i] > u2->lastname[i];
    }
}

int compareByFirstName(void* x, void* y)
{
    User* u1 = (User*)x;
    User* u2 = (User*)y;

    for(int i=0; i<FIRSTNAME_LENGTH ;i++)
    {
        if (u1->firstname[i] == '\0' && u2->firstname[i] != '\0') return 0;
        if (u2->firstname[i] == '\0' && u1->firstname[i] != '\0') return 1;
        
        if (u1->firstname[i] == u2->firstname[i]) continue;
        
        return u1->firstname[i] > u2->firstname[i];
    }
}

//////////////////////////////////////////////////////////////
int main() 
{
    User u1= {1,"Temprana","Martin",32};
    User u2= {2,"Baleani","Sebastian",34};
    User u3= {3,"Prado","Liliana",63};
    User u4= {4,"Prados","Iris",28};
    User u5= {5,"Perez","Rocio",27};

    User* u[5] ={&u1,&u2,&u3,&u4,&u5};
    
    /*
        SE PUEDE SELECCIONAR EL CRITERIO DE ORDENAMIENTO
        YA SEA POR Nº ID, EDAD, APELLIDO O NOMBRE
        DE MANERA ASCENDENTE O DESCENDENTE    
    */

    sortArray(u,5,compareByAge,0);
    //sortArray(u,5,compareById,1);
    //sortArray(u,5,compareByLastName,1);
    //sortArray(u,5,compareByFirstName,0);

    for(int i=0; i < 5; i++)
    {
        printf("%d, %s, %s, %d.\n", u[i]->id, u[i]->lastname, u[i]->firstname, u[i]->age);
        
    }


    return 0;
}
