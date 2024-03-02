#include <stdbool.h>
//The game starts on X's turn. To play, you must input an even amount 
//of numbers corresponding to valid row and column indices - the first
// two numbers will correspond to a row and column index to place X, the 
//second two correspond to a row and column index to place O, the third two 
//correspond to a row and column index to place X, and so on.
const int ROWS = 3;
const int COLS = 3;


// ==================================================================
// row_won(board) returns the player that has won the row at the current
// index otherwise returns ' '
// requires : row position to check
char row_won(const char board[], int row) {
    int won = 0;
 for (int i = row ; i <  row - 1+ ROWS ; ++i) {
   if( board[i] == board[i + 1]) {
     won = 1;
   } else {
     won = 0;
     break;
   }
 }
 if (won == 0) {
   return ' ';
 } else {
   return board[row];
 }   
}
 
 
// col_won(board) returns the player that has won a column at the current
// index otherwise returns ' '
// requires : column position to start checking
char col_won(const char board[], int column) {
  int won = 0;
  
 for (int i = column ; i < (ROWS * COLS) - COLS ; i += COLS) {
   if( board[i] == board[i + ROWS]) {
     won = 1;
   } else {
     won = 0;
     break;
   }
 }
 if (won == 0) {
   return ' ';
 } else {
   return board[column];
 }   
}

// diagn_won(board) returns player that has won the diagnol
// otherwise returns ' '
char diagn_won(const char board[]) {
  int left_diagn_distance = COLS + 1;
  int right_diagn_distance = COLS -1;
  int right_stop_point = (ROWS * COLS) - COLS;
  int left_diagn = 0;
  int right_diagn = 0;
   for (int i = 0; i < (ROWS * COLS) - 1; i += left_diagn_distance) { 
     if (board[i] == board[i + left_diagn_distance]) {
       left_diagn = 1;
     } else {
       left_diagn = 0;
       break;
     }
        
   }
  
  
  // now checking right diagn
  for (int i = (COLS - 1); i < right_stop_point; i += right_diagn_distance) {
    if (board[i] == board[i + right_diagn_distance]) {
    right_diagn = 1; 
    } else {
      right_diagn = 0;
      break;
    }
    
  }
 if (left_diagn == 1) {
   return board[0];
 } else if (right_diagn == 1) {
   return board[COLS -1]; // position of first element in right diagonal
 } else {
   return ' ';
 }
 
}
// won(board) returns the player has won the tic-tac-toe game, 
//  and 0 if nobody has won yet.
// required : Both players can't own a column ,row or diagonal at the same time
char who_won(const char board[]) {
  char winner = ' ';
  int won = 0;
  
   
   // at this point game is over and  we know someone has won
   if (diagn_won(board) != ' ') { //someone won
     winner = diagn_won(board);
     won = 1;
     return winner;
     
   } else { // no one has won in diaganal
     for (int i = 0; i < COLS; ++i) { // checking if any column won
       if (col_won(board,i) != ' ') {
         winner = col_won(board, i);
         won = 1;
         return winner;
       } else {
         won = 0;
       }
     }
     //all thats left is the rows now
     if (won == 0) {
       
         for (int i = 0; i < ROWS; i += COLS) {
         if (row_won(board,i) != ' ') {
           winner = row_won(board, i);
           won = 1;
           return winner;
          
         } else {
           won = 0;
         }
        } 
        
      }
  }
  
  if (won == 0) {
    return 0;
  } else {
  return winner;
  }
}
// ==================================================================

// draw(board) determines if the game is a tie.
bool draw(const char board[]) {
  char winner= ' ';
   for (int i = 0; i < (COLS * ROWS)- 1;  ++i) {
     if (board[i] == ' ') {
      return false;
     }
   }
  
   
   // at this point game is over and  we know someone has won
  if (diagn_won(board) != ' ') {
    winner = diagn_won(board);
     
   } else {
       for (int i = 0; i < COLS; ++i) { // checking if any column won
         if (col_won(board,i) != ' ') {
           winner = col_won(board, i);
         }
       }
       //all thats left is the rows now
     for (int i = 0; i < ROWS; i += COLS) {
         if (row_won(board,i) != ' ') {
           winner = row_won(board, i);
         }
       } 
     }
  if (winner == ' ') {
    return true;
  } else {
      return false;
     }
}


// ==================================================================

// switch player(curr_player) switches the current player from 'X' to 'O'
//  and vice-versa.
char switch_player(char curr_player) {
  if (curr_player == 'X') { return 'O'; }
  else { return 'X'; }
}

// ==================================================================

// read_integer(inp1, inp2) reads two integers from input.
// effects: reads from input
//          modifies *inp1 and *inp2
bool read_2ints(int* inp1, int* inp2) {
  if (scanf("%d %d", inp1, inp2) != 2) {
      return false; // could not read integer
  } return true;
}

// ==================================================================

int main(void) {
  
  char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
  
  printf("GAME START\n");
  print_board(board);
    
  bool keep_playing = true;
  char player = 'X';
    
  printf("It's player %c's turn!\n", player);
  
  while (keep_playing) {
      
    int row = 0;
    int col = 0;

    if (!(read_2ints(&row, &col))) { // no more input left, end game
      break;
    }

    if (fill_spot(board, player, row, col)) {
      print_board(board);
        
      char winner = who_won(board);
      if (winner) { 
        printf("PLAYER %c WON!! :D\n", player);
        keep_playing = false;
      } else if (draw(board)) {
        printf("IT'S A TIE!\n");
        keep_playing = false;
      } 
      if (keep_playing) {
        player = switch_player(player);
        printf("It's player %c's turn!\n", player);
      }
    }
  }
}