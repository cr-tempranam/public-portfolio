#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct 
{
    double x;
    double y;
        
} Point;

char** crearMatriz(int n, int m)
{
    char **A= (char**)malloc(sizeof (char*)*n);
    
    for(int i=0;i<n;i++)
    {
        A[i] = (char*)malloc(sizeof(char) * m);
        memset(A[i], 0, sizeof(char) * m);
    }    

    return A;
}

void GeneratePbmFile(char** M, int W, int H)
{
    FILE* output= fopen("output.pbm","w");

    // PBM File Header
    fprintf(output,"P1\n");
    fprintf(output,"%d %d\n", W, H);
    
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            fprintf(output, M[i][j]? "1" : "0");
        }  
        fprintf(output, "\n");      
    }
        
    fclose(output);
}

int main()
{
    int n=100;
    Point* point = (Point*) malloc(sizeof (Point)*n);
    
    char line[100];
    int count=0;

    while (fgets(line, 100, stdin) != NULL)
    {
        sscanf(line, "%lf\t%lf", &point[count].x, &point[count].y);
        
        count++;
        
        if(count == n) 
        {
            n += 50;
            point = realloc(point, n * sizeof(Point));
        
        }              
    }
  
    int H = 200, W = 200;
    int A = 10;

    char **M = crearMatriz(H, W);

    for (int i = 0; i < count; i++)
    {
        int x = (int)(point[i].x * W);
        int y = H/2 - 1 - (int)(point[i].y/(2*A) * H);

        M[y][x] = 1;
    }

    GeneratePbmFile(M, W, H);
    
    return EXIT_SUCCESS;
}