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
//Code by Rajeev, Damian, Wojtek, Abdallah
int main(int argc, char*argv[]){
  char *file_out, *file_in, *phase, *no_penguins_to_place;
	int q = 0;
	if(argc > 4){
    phase = argv[1];
    no_penguins_to_place = argv[2];
		file_in = argv[3];
		file_out = argv[4];
	}
  else{
    phase = argv[1];
    file_in = argv[2];
    file_out = argv[3];
  }
	char option[1];
  option[0] = phase[6];
//  manual();
	read_file(file_in);
	int n_rounds, l, k;
  if(option[0] == 'p' || option[0] == 'P'){
    int rounds = no_penguins_to_place[9] - '0';
    for(l = 0; l < rounds; l++){
      for(k = 1; k <= no_players; k++){
        place_penguin_auto(k);
      }
    }
    print_file(file_out);
  }
  else if(option[0] == 'm' || option[0] == 'M'){
    for(k = 1; k <= no_players; k++){
      move_penguin_auto(k);
    }
    curr_turn += 1;
    print_board();
    print_file(file_out);
  }
}
