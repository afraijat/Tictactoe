#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Board_Size_x 12
#define Board_Size_y 7
#define Penguins 4
#define Max_Rounds 10
int board[Board_Size_x][Board_Size_y];

int create_board(){
	time_t t;
	srand((unsigned) time(&t));
	int i, j;
	int e = 1;
	while(e==1){
		for(i = 1; i <= Board_Size_y; i++){
			for(j = 1; j <= Board_Size_x; j++){
				board[j][i] = (rand() % 4);
			}
		}
		int sum_of_tiles1 = 0;
		for(i = 1; i <= Board_Size_y; i++){
			for(j = 1; j <= Board_Size_x; j++){
				if(board[j][i] == 1){
					sum_of_tiles1 += 1;
				}
			}
		}
		if(sum_of_tiles1 < Penguins){
		}
		else{
			e = 0;
			break;
		}
	}
	

}

void print_board(){
	int i, j;
	for (i = 1; i <= Board_Size_y; i++){
		if((i%2)!=0){
				printf(" ");
			}
		for (j = 1; j <= Board_Size_x; j++)
		{
			printf("%d ", board[j][i]);
		}
		printf("\n");
	}
	printf("---------------------------\n");
}

void place_penguin(){
	int x, y, n, player;
	printf("Placement phase started \n");
	printf("---------------------------\n");
	for(n = 0; n < Penguins; n++){
		if(n%2 == 0){
			player = 1;
		}
		else{
			player = 2;
		}
		int exit = 1;
		while(exit = 1){
			print_board();
			if(player == 1){
				printf("Player1: ");
			}
			else{
				printf("Player2: ");
			}
			scanf("%d %d", &x, &y);
			printf("---------------------------\n");
			if((board[x][y] == 0) || (board[x][y] > 1)){
				printf("Unable to place penguin on this tile, please choose another one.\n");
				printf("---------------------------\n");
			}
			else{
				board[x][y] = 3+player;
				exit = 0;
				break;
			}

		}
		
	}
	print_board();
	printf("Placement phase finished \n");
	printf("---------------------------\n");
}
int check_movement_even(int x, int y){
	int movement = 0;
	if(board[x][y]>3){
		if(((x-1>=1)&&(y-1>=1))&&((board[x-1][y-1]>0)&&(board[x-1][y-1]<4))){
				movement += 1;
		}
		if(((x-1>=1)&&(y>=1))&&((board[x-1][y]>0)&&(board[x-1][y]<4))){
			movement += 1;
		}
		if(((x-1>=1)&&(y+1<=Board_Size_y))&&((board[x-1][y+1]>0)&&(board[x-1][y+1]<4))){
			movement += 1;
		}
		if(((x>=1)&&(y-1>=1))&&((board[x][y-1]>0)&&(board[x][y-1]<4))){
			movement += 1;
		}
		if(((x>=1)&&(y+1<=Board_Size_y))&&((board[x][y+1]>0)&&(board[x][y+1]<4))){
			movement += 1;
		}
		if(((x+1<=Board_Size_x)&&(y>=1))&&((board[x+1][y]>0)&&(board[x+1][y]<4))){
			movement += 1;
		}
		printf("%d\n", movement);
	}
	else{
		movement = -1;
		printf("---------------------------\n");
		printf("There is no penguin on this tile, choose another one.\n");
		printf("---------------------------\n");
	}
	return movement;
}
int check_movement_odd(int x, int y){
	int movement = 0;
	if(board[x][y]>3){
		if(((x+1<=Board_Size_x)&&(y-1>=1))&&((board[x+1][y-1]>0)&&(board[x+1][y-1]<4))){
			movement += 1;
		}
		if(((x+1<=Board_Size_x)&&(y>=1))&&((board[x+1][y]>0)&&(board[x+1][y]<4))){
			movement += 1;
		}
		if(((x+1<=Board_Size_x)&&(y+1<=Board_Size_y))&&((board[x+1][y+1]>0)&&(board[x+1][y+1]<4))){
			movement += 1;
		}
		if(((x>=1)&&(y-1>=1))&&((board[x][y-1]>0)&&(board[x][y-1]<4))){
			movement += 1;
		}
		if(((x>=1)&&(y+1<=Board_Size_y))&&((board[x][y+1]>0)&&(board[x][y+1]<4))){
			movement += 1;
		}
		if(((x-1>=1)&&(y>=1))&&((board[x-1][y]>0)&&(board[x-1][y]<4))){
			movement += 1;
		}
		printf("%d\n", movement);
	}
	else{
		movement = -1;
		printf("---------------------------\n");
		printf("There is no penguin on this tile, choose another one.\n");
		printf("---------------------------\n");
	}
	return movement;
}
void move_penguin(){
	print_board();
	int i;
	int n = 1;
	for(i = 0; (i < Max_Rounds*2)||(n!=1); i++){
		printf("Choose penguin to move: ");
		int p_x, p_y, x, y;
		scanf("%d %d", &p_x, &p_y);
		switch(p_y%2){
			case 1:
				if(check_movement_odd(p_x, p_y)==0){
					printf("---------------------------\n");
					printf("You cant move your penguin\n");
					printf("---------------------------\n");
				}
				break;
			case 0:
				if(check_movement_even(p_x, p_y)==0){
					printf("---------------------------\n");
					printf("You cant move your penguin\n");
					printf("---------------------------\n");
				}
				break;

		}	
		//printf("Where do you want to move your penguin to: ");
		//scanf("%d %d", &x, &y);

	}

}

int main(){
	create_board();
	place_penguin();
	move_penguin();
	int y;
	scanf("%d", &y);
	return 0;
}
