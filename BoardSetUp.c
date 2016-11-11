#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Here, we define two separate variable for the coordinates
#define x 10
#define y 8

int main()
{
   char board[x][y];
    int i,j;

    for (i = 0; i < x; i++) {
        for (j = 0; j < y; j++) {
            board[i][j] = '1';
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }


    return 0;
}
