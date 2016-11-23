#include<stdio.h>

int main()
	{
int x, y;
FILE *brd;
    brd = fopen("C:\\Users\\Abeedo\\Desktop\\University\\Bachelor Studies\\Programming\\Programming Projects\\Game\\Board Set Up\\Read Input.txt","r");
    fscanf(brd, "%d,%d \n", &x, &y);
    printf("%d %d\n", x, y);
int i, j;
char board[x][y];
        for (i = 0; i < x; i++) {
            for (j = 0; j < y; j++) {
            board[x][y] = '1';
            printf("%c", board[x][y]);
        }
        printf("\n");
    }
fclose(brd);
return 0;
}
