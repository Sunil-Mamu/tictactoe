#include <stdbool.h>
const int ROWS = 3;
const int COLS = 3;


// print_board(board) prints a tic tac toe board to the console.
// requires: length of board must equal ROWS * COLUMNS
// effects: writes to console
void print_board(const char board[]) {
  // print two lines at the end
  int line_num = (2 * ROWS) - 1; // 5
  int line_length = (4 * COLS) -1; // 11
  int count = 0;
  
  for (int i = 0; i < line_num; ++i) {
    if (i % 2 == 0) {  // print vertical bars
      for (int j = 1; j < line_length + 1; ++j) {
        if (j % 4 == 0) {
          printf("|");
        }else if (j % 2 == 0) {
           printf("%c",board[count]);
        
           count += 1;
        } else {
          printf(" ");
        }
      }
      printf("\n");
    } else { // print dashes
        for (int j = 1; j < line_length + 1; ++j) {
          if (j % 4 == 0) {
            printf(" ");
          } else {
            printf("-");
          }
        }
        printf("\n");
    } 
  }
  printf("\n");
  printf("\n");
}


// ==================================================================

// fill_spot(board, player, row, col) places player on the board at spot [row][col].
//  returns true if successful, false if spot is already filled.
// effects: modifies board
bool fill_spot(char board[], const char player, const int row, const int col) {
  assert(row >= 0);
  assert(col >= 0);
  assert(row < ROWS);
  assert(col < COLS);
  
  int position = (row  * COLS ) +col;
  
  if (board[position] != ' ') {
    return false;
  } else {
    board[position] = player;
    return true;
  }

  
}

// ==================================================================

// read_2ints(inp1, inp2) reads two integers from input.
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
  
  print_board(board);
  
  int row = 0;
  int col = 0;
  char player = 0;
  
 
   while ((read_2ints(&row, &col) && (scanf(" %c", &player) == 1))) {
    
    if (fill_spot(board, player, row, col)) {
      print_board(board);
    }
    
  }  
  
}