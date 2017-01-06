#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "board.h"
#include "movement.h"
#include "placement.h"
#include "input_output_file.h"
#include "score.h"
extern int board[1000][1000], no_penguins, Board_Size_x, Board_Size_y, curr_turn, max_turn, score[100], no_players;
int player = 1;
int main(){
	char option = 'a';
	manual();
	read_file();
	create_board();
	int r = 1;
	while (r == 1){
		printf("What do you want to do? ");
		scanf("%c", &option);
		if (option == 'm' || option == 'M'){
			manual();
		}
		else if (option == 'x' || option == 'X'){
			if(curr_turn == max_turn){
				announce_winner();
			}

			print_file();
			r = 0;
			break;
		}
		else if (option == 'g' || option == 'G'){
			if (check_if_placement() == 2){
				int i, j;
				printf("Placement phase started \n");
				for(j = 0;j < no_penguins; j++){
					for(i = 0; i < no_players; i++){
						place_penguin(player+i, j);
					}
				}
			}
			if(check_if_placement() == 0){
				int e = 1;
				if (curr_turn >= max_turn){
					announce_winner();
					print_file();
					r = 0;
					break;
				}
				else{
					int i;
					for(i = 0; i < no_players; i++){
						print_positions_of_penguins(player+i);
						move_penguin(player+i);
					}
					curr_turn += 1;
				}
			}
		}
		else if (option == 's' || option == 'S'){
			int i;
			for (i = 0; i < no_players; i++){
				printf("Player%d: %d\n", (i+1), score[i]);
			}
		}
	}
}
