extern int board[1000][1000], Board_Size_y, Board_Size_x, no_penguins, no_players, score[100];
void manual(){
	printf("Welcome!\n");
	printf("|PLACEMENT|\n");
	printf("If the game is in the placement phase, all you need to do is type: x y \n");
	printf("x - x coordinate of the tile that you want to place your penguin on\n");
	printf("y - y coordinate of the tile that you want to place your penguin on\n");
	printf("|MOVEMENT|\n");
	printf("To move your penguin enter values like this: x y d n\n");
	printf("x - x coordinate of the penguin you choose\n");
	printf("y - y coordinate of the penguin you choose\n");
	printf("d - direction in which you want to move\n");
	printf("n - number of tiles you want to move\n");
	printf("Directions(not case sensitive): L - left, R - right, RU - right up,\nRD - right down, LU - left up, LD - left down\n");
	printf("|MENU|\n");
	printf("'c x y p e m' or 'C x y p e m' to create new game where:\n   p - number of players\n   e - number of penguins per player\n  m - max rounds\n");
	printf("'r' or 'R' for random new game\n");
	printf("p - Print board\n");
	printf("'m' or 'M' for manual\n");
	printf("'g n' or 'G n' to play n rounds of the game\n");
	printf("'x' or 'X to save the current state of the game to output.txt and end the game'\n");
	printf("'s' or 'S' to display the current score\n");
	printf("-----------------------------------------------------------------------------\n");
}

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
		if(sum_of_tiles1 >= no_penguins){
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

void announce_winner(){
	int i;
	int id_of_player, id_of_player_snd;
	int is_tie = 0;
	int score_of_winner = 0;
	if (no_players > 1){
		for(i = 1; i <= no_players; i++){
			if(score[i]>score_of_winner){
				id_of_player = i;
				score_of_winner = score[i];
			}
		}
		for(i = 1; i <= no_players; i++){
			if(score[i]==score_of_winner){
				is_tie = 1;
				id_of_player_snd = i;
			}
		}
	}
	else{
		id_of_player = 1;
		score_of_winner = score[1];
	}
	if(is_tie == 1 && id_of_player != id_of_player_snd){
		printf("There is a tie \n");
	}
	else{
		printf("And the winner is: Player %d, with a score of: %d\n", id_of_player, score_of_winner);
	}
}
