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
//Code by Rajeev, Damian, Wojtek, Abdullah
int main(int argc, char*argv[]){
  char *file_out;
	char *file_in;
	int q = 0;
	if(argc > 1){
		file_in = argv[1];
		file_out = argv[2];
	}
	char option[1];
	manual();
	read_file(file_in);
		int n_rounds;
    scanf("%c", &option[0]);
    if(option[0] == 'm' || option[0] == 'M'){
      manual();
    }
    else if(option[0] == 'a' || option[0] == 'A'){
      int rounds;
      scanf(" %d", &rounds);
      int l, k;

      if (curr_turn <=   max_turn){
        for(l = 0; l < rounds; l++){
          for(k = 1; k <= no_players; k++){
            move_penguin_auto(k);
          }
          curr_turn += 1;
        }
        print_board();
        print_file(file_out);
      }
      else{
        printf("The file you used as input has reached the end of rounds\n");
      }
    }
    else if(option[0] == 'p' || option[0] == 'P'){
      int rounds, i, j;
      scanf(" %d", &rounds);
      if(curr_turn < max_turn){
        for(j = 0; j < rounds; j++){
          for(i = 1; i <= no_players; i++){
            greedy(i);
          }
          curr_turn += 1;
          print_file(file_out);
        }
      }
      else{
        printf("The game has reached the limit of rounds\n");
      }
    }
    else if(option[0] == 'r' || option[0] == 'r'){
      Board_Size_x = (rand() % 30) + 1;
      Board_Size_y = (rand() % 30) + 1;
      no_players = (rand() % 5) + 1;
      no_penguins = (rand() % 5) + 1;
      create_board();
      max_turn = (rand() % 20) + 1;
      int h;
      for(h = 1; h <= no_players; h++){
        score[h] = 0;
      }
      print_file(file_out);
    }
    else if (option[0] == 'c' || option[0] == 'C'){
      scanf("%d %d %d %d %d", &Board_Size_x, &Board_Size_y, &no_players, &no_penguins, &max_turn);
      curr_turn = 0;
      create_board();
      int u;

      for(u = 1; u <= no_players; u++){
        score[u] = 0;
      }
      print_file(file_out);
      printf("New game created!\n");
    }
    else if (option[0] == 'x' || option[0] == 'X'){
      if(curr_turn == max_turn){
        announce_winner();
      }
      print_file(file_out);
    }
    else if (option[0] == 'g' || option[0] == 'G'){
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
        }
        if(check_if_placement() == 0){
          int e = 1;
          if (curr_turn == max_turn){
            announce_winner();
            print_file(file_out);
          }
          else{
            int i;
            for(i = 0; i < no_players; i++){
              move_penguin(player+i);
            }
            curr_turn += 1;
          }
        }
      }
      print_file(file_out);
    }

    else if (option[0] == 's' || option[0] == 'S'){
      int i;
      printf("Current Round = %d/%d\n", curr_turn, max_turn);
      for (i = 1; i <= no_players; i++){
        printf("Player%d: %d\n", i, score[i]);
      }
    }
}
