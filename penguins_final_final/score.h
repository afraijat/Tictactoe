extern int board[1000][1000], no_penguins, Board_Size_x, Board_Size_y, curr_turn, max_turn, score[100], no_players;

void add_score(int player, int x, int y){
  if(board[x][y]>0 && board[x][y]<4){
    score[player] += board[x][y];
  }
}
