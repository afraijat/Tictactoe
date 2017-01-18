extern int board[1000][1000], Board_Size_x, Board_Size_y, no_penguins, no_players;
//code by Rajeev
int check_if_placement(){
	// check whether the game is still in placement phase or movement phase
	// returns 2 when no penguins are placed
	// returns 1 if placement phase is not finished
	// returns 0 if movement phase
	int sum = 0;
	int i,j;
   		for(i = 1; i <= Board_Size_y; i++){
				for(j = 1; j <= Board_Size_x; j++){
					if(board[j][i]>3){
						sum += 1;
					}
				}
			}
	if(sum == no_penguins*no_players){
		return 0;
	}
	else if(sum < no_penguins*no_players && sum > 0){
		return 1;
	}
	else{
		return 2;
	}
}

void place_penguin(int player_n, int which){
	int x, y, n;
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
			board[x][y] = 4 + (player_n-1)*no_penguins +which;
			score[player_n] += 1;
			exit = 0;
			break;
		}
	}
}
void place_penguin_auto(int player){
	int x, y, n;
	int exit = 1;
	int peng_cords[no_penguins][2], h, u, i;
	srand(time(NULL));
	int count_p = 0;
	for(h = 1; h <= Board_Size_y; h++){
		for(u = 1; u <= Board_Size_x; u++){
			if(correct_penguin_selected(player, u, h)==1){
				peng_cords[count_p][0] = u;
				peng_cords[count_p][1] = h;
				count_p += 1;
			}
		}
	}
	while(exit = 1){
		x = (rand() % Board_Size_x) + 1;
		y = (rand() % Board_Size_y) + 1;
		if((board[x][y]==0)||(board[x][y]>1)||(x<1)||(y<1)||(x>Board_Size_x)||(y>Board_Size_y)||(count_p == no_penguins)){

		}
		else{
			board[x][y] = 4 + (player-1)*no_penguins +count_p;
			score[player] += 1;
			exit = 0;
			break;
		}
	}
}
