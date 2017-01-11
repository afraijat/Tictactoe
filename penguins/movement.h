#ifndef _movement_h
#define _movement_h
#include <string.h>
#include <time.h>
#include <stdlib.h>
extern int board[1000][1000], Board_Size_x, Board_Size_y, curr_turn, max_turn, score[100], no_players;

int check_penguin(int x, int y){
	//is_there_a_penguin = 1   - there is a penguin on this tile
	//is_there_a_penguin = 0  - there is no penguin on this tile
	int is_there_a_penguin;
	if(board[x][y]>3){
		is_there_a_penguin = 1;
	}
	else{
		is_there_a_penguin = 0;
	}
	return is_there_a_penguin;
}

int convert_to_int(char direction){
	int x;
	if(direction=='R' || direction=='r'){
		x = 1;
	}
	if(direction=='L' || direction=='l'){
		x = 2;
	}
	if(direction=='U' || direction=='u'){
		x = 3;
	}
	if(direction=='D' || direction=='d'){
		x = 4;
	}
	if(direction==' '){
		x = 0;
	}
	return x;
}
int check_movement(int x, int y, int direct1, int direct2, int operation, int odd_even){
	// operation = 0 makes this function check all the tiles around x and y
	// operation = 1 makes this function check just 1 direction
	int movement = 0;
	int direction_int = 0;
	switch(odd_even){
		case 1:
			movement = 0;
			if((x+1<=Board_Size_x)&&(y-1>=1)&&(board[x+1][y-1]>0)&&(board[x+1][y-1]<4)){
				movement += 1;
				if((direct1==1)&&(direct2==3)){
					direction_int = 1;
				}
			}
			if((x+1<=Board_Size_x)&&(y>=1)&&(board[x+1][y]>0)&&(board[x+1][y]<4)){
				movement += 1;
				if((direct1==1)&&(direct2==0)){
					direction_int = 1;
				}
			}
			if((x+1<=Board_Size_x)&&(y+1<=Board_Size_y)&&(board[x+1][y+1]>0)&&(board[x+1][y+1]<4)){
				movement += 1;
				if((direct1==1)&&(direct2==4)){
					direction_int = 1;
				}
			}
			if((x>=1)&&(y-1>=1)&&(board[x][y-1]>0)&&(board[x][y-1]<4)){
				movement += 1;
				if((direct1==2)&&(direct2==3)){
					direction_int = 1;
				}
			}
			if((x>=1)&&(y+1<=Board_Size_y)&&(board[x][y+1]>0)&&(board[x][y+1]<4)){
				movement += 1;
				if((direct1==2)&&(direct2==4)){
					direction_int = 1;
				}
			}
			if((x-1>=1)&&(y>=1)&&(board[x-1][y]>0)&&(board[x-1][y]<4)){
				movement += 1;
				if((direct1==2)&&(direct2==0)){
					direction_int = 1;
				}
			}
			break;
		case 0:
			movement = 0;
			if((x-1>=1)&&(y-1>=1)&&(board[x-1][y-1]>=1)&&(board[x-1][y-1]<4)){
				movement += 1;
				if((direct1==2)&&(direct2==3)){
					direction_int = 1;
				}
			}
			if((x-1>=1)&&(y>=1)&&(board[x-1][y]>=1)&&(board[x-1][y]<4)){
				movement += 1;
				if((direct1==2)&&(direct2==0)){
					direction_int = 1;
				}
			}
			if((x-1>=1)&&(y+1<=Board_Size_y)&&(board[x-1][y+1]>=1)&&(board[x-1][y+1]<4)){
				movement += 1;
				if((direct1==2)&&(direct2==4)){
					direction_int = 1;
				}
			}
			if((x>=1)&&(y-1>=1)&&(board[x][y-1]>=1)&&(board[x][y-1]<4)){
				movement += 1;
				if((direct1==1)&&(direct2==3)){
					direction_int = 1;
				}
			}
			if((x>=1)&&(y+1<=Board_Size_y)&&(board[x][y+1]>=1)&&(board[x][y+1]<4)){
				movement += 1;
				if((direct1==1)&&(direct2==4)){
					direction_int = 1;
				}
			}
			if((x+1<=Board_Size_x)&&(y>=1)&&(board[x+1][y]>=1)&&(board[x+1][y]<4)){
				movement += 1;
				if((direct1==1)&&(direct2==0)){
					direction_int = 1;
				}
			}
			break;
	}
	if(operation==0)
		return movement;
	else
		return direction_int;
}
int check_movement_x_tiles(int x, int y, int direct1, int direct2, int no_tiles_to_move, int o){
	int possible = 0;
	int i;
	int temp_x = x;
	int temp_y = y;

	for(i = 0; i<no_tiles_to_move; i++){
		int odd_even = (temp_y%2);
		switch(odd_even){
			case 1:
				if((direct1==1)&&(direct2==3)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 1);
					temp_x += 1;
					temp_y -= 1;
				}
				if((direct1==1)&&(direct2==0)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 1);
					temp_x += 1;
				}
				if((direct1==1)&&(direct2==4)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 1);
					temp_x += 1;
					temp_y += 1;
				}
				if((direct1==2)&&(direct2==3)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 1);
					temp_y -= 1;
				}
				if((direct1==2)&&(direct2==4)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 1);
					temp_y += 1;
				}
				if((direct1==2)&&(direct2==0)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 1);
					temp_x -= 1;
				}
				break;
			case 0:
				if((direct1==1)&&(direct2==3)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 0);
					temp_y -= 1;
				}
				if((direct1==1)&&(direct2==0)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 0);
					temp_x += 1;
				}
				if((direct1==1)&&(direct2==4)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 0);
					temp_y += 1;
				}
				if((direct1==2)&&(direct2==3)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 0);
					temp_x -= 1;
					temp_y -= 1;
				}
				if((direct1==2)&&(direct2==4)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 0);
					temp_x -= 1;
					temp_y += 1;
				}
				if((direct1==2)&&(direct2==0)){
					possible += check_movement(temp_x, temp_y, direct1, direct2, 1, 0);
					temp_x -= 1;
				}
				break;

		}

	}
	switch(o){
		case 0:
			if(possible == no_tiles_to_move){
				return 1;
			}
			else{
				return 0;
			}
		case 1:
			return temp_x;
		case 2:
			return temp_y;
	}

}
int correct_penguin_selected(int player, int x, int y){
	//returns 1 if the penguin belongs to this player
	//returns 0 if not
	int peng_of_play[no_penguins], i, true_dat;
	for(i = 0; i < no_penguins; i++){
		peng_of_play[i] = 4 + (player-1)*no_penguins + i;
	}
	for(i = 0; i < no_penguins; i++){
		if (board[x][y] == peng_of_play[i]){
			true_dat = 1;
			break;
		}
		else {
			true_dat = 0;
		}
	}
	return true_dat;
}
void print_positions_of_penguins(int player){
	int i,j,x[no_penguins],y[no_penguins];
	int count = 0;
	for(i = 0; i < Board_Size_y; i++){
		for(j = 0; j < Board_Size_x; j++){
			if(correct_penguin_selected(player, j+1, i+1)==1&&check_movement(j+1, i+1, ' ', ' ', 0, (i+1)%2>0)){
				x[count] = j+1;
				y[count] = i+1;
				count += 1;
			}
		}
	}
	printf("Your penguins are placed on this coordinates: \n");
	char coords[no_penguins*2];
	for(i = 0; i < count; i++){
		printf("%d. x = %d & y = %d\n", i+1, x[i], y[i]);
		if(i == 0){
			//coords[0] = x[i];
			//coords[1] = y[i];
		}
		else{
			//coords[i*2] = x[i];
			//coords[i*2 + 1] = y[i];
		}
	}
}
void move_penguin(int player){
	int i;
	int e = 1;
	int p_x, p_y, x, y, no_tiles_to_move;
	char direction[2] = {' '};
	direction[0] = ' ';
	direction[1] = ' ';
	while(e == 1){
		int possible = 0;
		int i, j;
		for (i = 1; i <= Board_Size_y; i++){
			for(j = 1; j <= Board_Size_x; j++){
				if(correct_penguin_selected(player, j, i) == 1){
					if (check_movement(j, i, ' ', ' ', 0, i%2) > 0){
						possible += 1;
					}
				}
			}
		}
		if (possible == 0){
			e = 0;
			break;
		}
		printf("---------------------------\n");
		print_positions_of_penguins(player);
		printf("---------------------------\n");
		print_board();
		printf("Where do you want to move your penguin to Player%d: ", player);
		scanf("%d %d ", &x, &y);
		scanf("%s ", &direction);
		scanf("%d", &no_tiles_to_move);
		if(correct_penguin_selected(player, x, y) == 1){
			int direct1 = convert_to_int(direction[0]);
			int direct2 = convert_to_int(direction[1]);
			if (direct2 == direct1){
				direct2 = 0;
			}
			if(check_movement_x_tiles(x, y, direct1, direct2, no_tiles_to_move, 0)==0){
				printf("You can't move your penguin there, please try again\n");
			}
			else{
				int temp_x = check_movement_x_tiles(x, y, direct1, direct2, no_tiles_to_move, 1);
				int temp_y = check_movement_x_tiles(x, y, direct1, direct2, no_tiles_to_move, 2);
				score[player] += board[temp_x][temp_y];
				board[temp_x][temp_y] = board[x][y];
				board[x][y] = 0;
				e = 0;
				break;
			}
		}
	}
}
void move_penguin_auto(int player){
	int i;
	int e = 1;
	int p_x, p_y, x, y, no_tiles_to_move;
	char direction[2] = {' '};
	direction[0] = ' ';
	direction[1] = ' ';
	srand(time(NULL));
	while(e == 1){
		int possible = 0;
		int i, j;
		for (i = 1; i <= Board_Size_y; i++){
			for(j = 1; j <= Board_Size_x; j++){
				if(correct_penguin_selected(player, j, i) == 1){
					if (check_movement(j, i, ' ', ' ', 0, i%2) > 0){
						possible += 1;
					}
				}
			}
		}
		if (possible == 0){
			e = 0;
			break;
		}
	  int peng_cords[no_penguins][2], h, u;
		int count_p = 0;
		for(h = 0; h < Board_Size_y; h++){
			for(u = 0; u < Board_Size_x; u++){
				if(correct_penguin_selected(player, u, h)==1){
					peng_cords[count_p][0] = u;
					peng_cords[count_p][1] = h;
					count_p += 1;
				}
			}
		}
		int direct1 = 0;
		int direct2 = 0;
		while (direct1<1){
			direct1 = (rand() % 2) + 1;
		}
		while(direct2 < 2 && direct2 > 0){
			direct2 = rand() % 5;
		}
		int l = rand() % count_p;
		if(Board_Size_x-peng_cords[l][0] > Board_Size_y-peng_cords[l][1]){
			no_tiles_to_move = rand() % (Board_Size_x-peng_cords[l][0]) + 1;
		}
		else{
			no_tiles_to_move = rand() % (Board_Size_x-peng_cords[l][1]) + 1;
		}
		int peng_id = l;
		x = peng_cords[peng_id][0];
		y = peng_cords[peng_id][1];
		printf("x= %d y= %d player = %d\n", x, y, player);
		if(correct_penguin_selected(player, x, y) == 1){
			printf("x=%d y=%d direct1=%d direct2=%d n=%d\n", x, y, direct1, direct2, no_tiles_to_move);
			if (direct2 == direct1){
				direct2 = 0;
			}
			if(check_movement_x_tiles(x, y, direct1, direct2, no_tiles_to_move, 0)!=0){
				int temp_x = check_movement_x_tiles(x, y, direct1, direct2, no_tiles_to_move, 1);
				int temp_y = check_movement_x_tiles(x, y, direct1, direct2, no_tiles_to_move, 2);
				printf("temp_x = %d temp_y = %d\n", temp_x, temp_y);
				score[player] += board[temp_x][temp_y];
				board[temp_x][temp_y] = board[x][y];
				board[x][y] = 0;
				e = 0;
				break;
			}
		}
	}
}
#endif
