int board[1000][1000], no_penguins, Board_Size_x, Board_Size_y, curr_turn, max_turn, score[100], no_players;
void read_file(char *filename){
	FILE *brd;
   		brd = fopen(filename,"r");
   		fscanf(brd, "%d %d\n", &no_players, &no_penguins);
   		fscanf(brd, "%d %d\n\n", &Board_Size_x, &Board_Size_y);
   		int i,j;
   		for(i = 1; i <= Board_Size_y; i++){
				for(j = 1; j <= Board_Size_x; j++){
					fscanf(brd, "%d ", &board[j][i]);
				}
				fscanf(brd,"\n");
			}
		fscanf(brd, "\n%d/%d\n", &curr_turn, &max_turn);
		for(i = 1; i <= no_players; i++){
			fscanf(brd, "%d ", &score[i]);
		}
   		fclose(brd);
}
void print_file(char *filename){
	FILE *brd1;
		brd1 = fopen(filename, "w+");
		fprintf(brd1, "%d %d\n", no_players, no_penguins);
		fprintf(brd1, "%d %d\n\n", Board_Size_x, Board_Size_y);
		int i,j;
   			for(i = 1; i <= Board_Size_y; i++){
				for(j = 1; j <= Board_Size_x; j++){
					fprintf(brd1, "%d ", board[j][i]);
				}
				fprintf(brd1,"\n");
			}
		fprintf(brd1, "\n%d/%d\n", curr_turn, max_turn);
		for(i = 1; i <= no_players; i++){
			fprintf(brd1, "%d ", score[i]);
		}
		fclose(brd1);
}
