#include <stdio.h>

void createChessLine(int scale, int line)
{
    int height = 8;
    char c1 = line%2? ' ' : 'X';
    char c2 = line%2? 'X' : ' ';
        
        for(int i = 0 ;i < height; i++) 
        {
            for(int r = 0 ;r < scale; r++)
            {
                char cellColor = (i %2 == 0)? c1 : c2;
                printf("%c", cellColor);
            }
        }
        printf("\n");
}

void createChessBoard(int scale)
{
    int width = 8;
    for(int m = 0 ;m < width; m++)
    {
       for(int j = 0 ;j < scale/2; j++)
       {
            createChessLine(scale, m);
       }
    }
}

int main() {
   
   createChessBoard(8);
   
    return 0;
}