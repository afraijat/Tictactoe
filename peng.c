#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Board_Size_x 12
#define Board_Size_y 7
#define Penguins 8
#define Max_Rounds 10
#define player_count 4
int player = 1;
int board[Board_Size_x][Board_Size_y];
int score[player_count];

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
		if(sum_of_tiles1 >= Penguins){
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

void place_penguin(int player_n){
	int x, y, n;
	printf("Placement phase started \n");
	printf("---------------------------\n");
	int exit = 1;
	while(exit = 1){
		print_board();
		printf("Player%d: ", player_n);
		scanf("%d %d", &x, &y);
		printf("---------------------------\n");
		if((board[x][y]==0)||(board[x][y]>1)||(x<1)||(y<1)||(x>Board_Size_x)||(y>Board_Size_y)){
			printf("Unable to place penguin on this tile, please choose another one.\n");
			printf("---------------------------\n");
		}
		else{
			board[x][y] = 3+player_n;
			exit = 0;
			break;
		}
	}
}
int check_movement(int x, int y){
	int movement = 0;
	int odd_even = y%2;
	switch(odd_even){
		case 1:
			movement = 0;
			if(board[x][y]>3){
				if((x+1<=Board_Size_x)&&(y-1>=1)&&(board[x+1][y-1]>0)&&(board[x+1][y-1]<4)){
					movement += 1;
				}
				if((x+1<=Board_Size_x)&&(y>=1)&&(board[x+1][y]>0)&&(board[x+1][y]<4)){
					movement += 1;
				}
				if((x+1<=Board_Size_x)&&(y+1<=Board_Size_y)&&(board[x+1][y+1]>0)&&(board[x+1][y+1]<4)){
					movement += 1;
				}
				if((x>=1)&&(y-1>=1)&&(board[x][y-1]>0)&&(board[x][y-1]<4)){
					movement += 1;
				}
				if((x>=1)&&(y+1<=Board_Size_y)&&(board[x][y+1]>0)&&(board[x][y+1]<4)){
					movement += 1;
				}
				if((x-1>=1)&&(y>=1)&&(board[x-1][y]>0)&&(board[x-1][y]<4)){
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
			break;
		case 0:
			movement = 0;
			if(board[x][y]>3){
				if((x-1>=1)&&(y-1>=1)&&(board[x-1][y-1]>=1)&&(board[x-1][y-1]<4)){
					movement += 1;
				}
				if((x-1>=1)&&(y>=1)&&(board[x-1][y]>=1)&&(board[x-1][y]<4)){
					movement += 1;
				}
				if((x-1>=1)&&(y+1<=Board_Size_y)&&(board[x-1][y+1]>=1)&&(board[x-1][y+1]<4)){
					movement += 1;
				}
				if((x>=1)&&(y-1>=1)&&(board[x][y-1]>=1)&&(board[x][y-1]<4)){
					movement += 1;
				}
				if((x>=1)&&(y+1<=Board_Size_y)&&(board[x][y+1]>=1)&&(board[x][y+1]<4)){
					movement += 1;
				}
				if((x+1<=Board_Size_x)&&(y>=1)&&(board[x+1][y]>=1)&&(board[x+1][y]<4)){
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
			break;
	}
	return movement;
}
void move_penguin(){
	print_board();
	int i;
	int n = 1;
	for(i = 0; (i < Max_Rounds*player_count)||(n!=1); i++){
		printf("Choose penguin to move: ");
		int p_x, p_y, x, y;
		scanf("%d %d", &p_x, &p_y);
		if(check_movement(p_x, p_y) == 0){
			printf("---------------------------\n");
			printf("You cant move your penguin\n");
			printf("---------------------------\n");
		}
		
		
		//printf("Where do you want to move your penguin to: ");
		//scanf("%d %d", &x, &y);

	}

}

int main(){
	create_board();
	int i, j;
	for(j = 0;j < (Penguins/player_count); j++){
		for(i = 0; i < player_count; i++){
			place_penguin(player+i);
		}
	}
	move_penguin();
	int y;
	scanf("%d", &y);
	return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Board_Size_x 12
#define Board_Size_y 7
#define Penguins 8
#define Max_Rounds 10
#define player_count 4
int player = 1;
int board[Board_Size_x][Board_Size_y];
int score[player_count];

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
		if(sum_of_tiles1 >= Penguins){
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

void place_penguin(int player_n){
	int x, y, n;
	printf("Placement phase started \n");
	printf("---------------------------\n");
	int exit = 1;
	while(exit = 1){
		print_board();
		printf("Player%d: ", player_n);
		scanf("%d %d", &x, &y);
		printf("---------------------------\n");
		if((board[x][y]==0)||(board[x][y]>1)||(x<1)||(y<1)||(x>Board_Size_x)||(y>Board_Size_y)){
			printf("Unable to place penguin on this tile, please choose another one.\n");
			printf("---------------------------\n");
		}
		else{
			board[x][y] = 3+player_n;
			exit = 0;
			break;
		}
	}
}
int check_movement(int x, int y){
	int movement = 0;
	int odd_even = y%2;
	switch(odd_even){
		case 1:
			movement = 0;
			if(board[x][y]>3){
				if((x+1<=Board_Size_x)&&(y-1>=1)&&(board[x+1][y-1]>0)&&(board[x+1][y-1]<4)){
					movement += 1;
				}
				if((x+1<=Board_Size_x)&&(y>=1)&&(board[x+1][y]>0)&&(board[x+1][y]<4)){
					movement += 1;
				}
				if((x+1<=Board_Size_x)&&(y+1<=Board_Size_y)&&(board[x+1][y+1]>0)&&(board[x+1][y+1]<4)){
					movement += 1;
				}
				if((x>=1)&&(y-1>=1)&&(board[x][y-1]>0)&&(board[x][y-1]<4)){
					movement += 1;
				}
				if((x>=1)&&(y+1<=Board_Size_y)&&(board[x][y+1]>0)&&(board[x][y+1]<4)){
					movement += 1;
				}
				if((x-1>=1)&&(y>=1)&&(board[x-1][y]>0)&&(board[x-1][y]<4)){
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
			break;
		case 0:
			movement = 0;
			if(board[x][y]>3){
				if((x-1>=1)&&(y-1>=1)&&(board[x-1][y-1]>=1)&&(board[x-1][y-1]<4)){
					movement += 1;
				}
				if((x-1>=1)&&(y>=1)&&(board[x-1][y]>=1)&&(board[x-1][y]<4)){
					movement += 1;
				}
				if((x-1>=1)&&(y+1<=Board_Size_y)&&(board[x-1][y+1]>=1)&&(board[x-1][y+1]<4)){
					movement += 1;
				}
				if((x>=1)&&(y-1>=1)&&(board[x][y-1]>=1)&&(board[x][y-1]<4)){
					movement += 1;
				}
				if((x>=1)&&(y+1<=Board_Size_y)&&(board[x][y+1]>=1)&&(board[x][y+1]<4)){
					movement += 1;
				}
				if((x+1<=Board_Size_x)&&(y>=1)&&(board[x+1][y]>=1)&&(board[x+1][y]<4)){
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
			break;
	}
	return movement;
}
void move_penguin(){
	print_board();
	int i;
	int n = 1;
	for(i = 0; (i < Max_Rounds*player_count)||(n!=1); i++){
		printf("Choose penguin to move: ");
		int p_x, p_y, x, y;
		scanf("%d %d", &p_x, &p_y);
		if(check_movement(p_x, p_y) == 0){
			printf("---------------------------\n");
			printf("You cant move your penguin\n");
			printf("---------------------------\n");
		}
		
		
		//printf("Where do you want to move your penguin to: ");
		//scanf("%d %d", &x, &y);

	}

}

int main(){
	create_board();
	int i, j;
	for(j = 0;j < (Penguins/player_count); j++){
		for(i = 0; i < player_count; i++){
			place_penguin(player+i);
		}
	}
	move_penguin();
	int y;
	scanf("%d", &y);
	return 0;
}
