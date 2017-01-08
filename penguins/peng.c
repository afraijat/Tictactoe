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
	char option[1][3];
	manual();
	read_file();
	int r = 1;
	while (r == 1){
		int n_rounds;
		printf("What do you want to do? ");
		scanf("%c", &option[0][0]);
		if (option[0][0] == 'm' || option[0][0] == 'M'){
			manual();
		}
		else if (option[0][0] == 'x' || option[0][0] == 'X'){
			if(curr_turn == max_turn){
				announce_winner();
			}

			print_file();
			r = 0;
			break;
		}
		else if (option[0][0] == 'g' || option[0][0] == 'G'){
			int i;
			scanf("%d", &n_rounds);
			for (i = 0; i < n_rounds; i++){
				if (check_if_placement() == 2){
					int i, j;
					printf("Placement phase started \n");
					for(j = 0;j < no_penguins; j++){
						for(i = 0; i < no_players; i++){
							place_penguin(player+i, j);
						}
					}
				}
				if (check_if_placement() == 1){
					int i, j, k, x[no_players];
					for(i = 1; i <= no_players; i++){
						x[i] = 0;
					}
					for (k = 1; k <= no_players; k++) {
						for(i = 1; i <= Board_Size_y; i++){
							for (j = 1; j <= Board_Size_x; j++){
								if(correct_penguin_selected(k, j, i) == 1){
									x[k] += 1;
								}
							}
						}
					}
					int any = 0;
					for(k = 1; k <= no_players; k++){
						if (x[k]>= 1){
							any += 1;
						}
					}
					while(any > 0){
						any = 0;
						for(k = 1; k <= no_players; k++){
							if (x[k]>= 1){
								any += 1;
							}
						}
						for(k = 1; k <= no_players; k++){
							if(x[k] > 0){
								place_penguin(k, no_penguins-x[k]);
								x[k] -= 1;
							}
						}
					}
				if(check_if_placement() == 0){
					int e = 1;
					if (curr_turn == max_turn){
						announce_winner();
						print_file();
						r = 0;
						break;
					}
					else{
						int i;
						for(i = 0; i < no_players; i++){
							print_positions_of_penguins(player+i);
							printf("---------------------------\n");
							move_penguin(player+i);
						}
						curr_turn += 1;
					}
				}
			}
			print_file();
		}
	}
		else if (option[0][0] == 's' || option[0][0] == 'S'){
			int i;
			for (i = 1; i <= no_players; i++){
				printf("Player%d: %d\n", i, score[i]);
			}
		}
	}
}
