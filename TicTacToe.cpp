#include <iostream>
#include <cstring>

using namespace std;

/* This program plays a game of TicTacToe in the console. Scores from the game are kept, and players have the option
 * to play again.
 * Brandon Huynh, last edited 9/6/2024
 */
int board[3][3];
const int BLANK = 0;
const int X_MOVE = 1;
const int O_MOVE = 2;
const int X_TURN = 0;
const int O_TURN = 1;
void move(int playerTurn);
bool checkWin(int player);
bool checkTie();
void printBoard();

//Primary game function
int main() {
  int turn = X_TURN;
  bool playing = true;
  int x_score = 0;
  int o_score = 0;
  while (playing == true) {
    // Clearing the board at the start of each round
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        board[i][j] = BLANK;
      }
    }
    while (checkWin(X_MOVE) == false && checkWin(O_MOVE) == false && checkTie() == false) {
      // Show the board, player moves
      printBoard();
      move(turn);
      // Switch turns!
        if (turn == X_TURN) {
          turn = O_TURN;
        }
        else {
          turn = X_TURN;
        }
      }
    // Check for wins, edit score appropriately
   if (checkWin(X_MOVE) == true) {
     cout << "X wins! X has " << ++x_score << " wins, and O has " << o_score << " wins."  << endl;
      }
      else if (checkWin(O_MOVE) == true) {
	cout << "O wins! X has " << x_score << " wins, and O has " << ++o_score << " wins."  << endl;
      }
      else {
	cout << "There was a tie." << endl;
      }
   // Check if user wants to play again
   cout << "Would you like to play again? Type \'1\' for yes, and \'0\' for no." << endl;
   char playAgain[20];
   bool validInput = false;
   // Checking for a valid input
   while (validInput == false) {
     cin.get(playAgain, 20);
     cin.get();
     // they don't want to play again
     if (playAgain[0] == '0') {
       cout << "Thanks for playing!" << endl;
       playing = false;
       validInput = true;
     }
     // they want to play again
     else if (playAgain[0] == '1') {
       cout << "Restarting!" << endl;
       validInput = true;
     }
     // they entered an invalid input
     else {
       cout << "Please enter a valid input!" << endl;
     }
   }
  }
  return 0;
}
// Handles player moves
void move(int playerTurn) {
  bool validMove = false;
  char input[2];
  // Goes until a valid move is entered
  while (validMove == false) {
    cout << "Please type the row (a-c), then the column (1-3) which you would like to move." << endl;
    cout << "An example move: \"b2\" " << endl;
    cin.get(input, 3);
    cin.get();
    // If the input is invalid
    if (input[0] != 'a' && input[0] != 'b' && input[0] != 'c') {
      cout << "Please enter a valid input!" << endl;
    }
    else if (input[1] != '1' && input[1] != '2' && input[1] != '3') {
      cout << "Please enter a valid input!" << endl;
    }
    else {
      int row = int(input[0] - 'a');
      int column = int(input[1] - '1');
      // If the space is free, let them move.
      if (board[row][column] == BLANK) {
        if (playerTurn == X_TURN) {
          board[row][column] = X_MOVE;
          return;
        }
        else if (playerTurn == O_TURN) {
          board[row][column] = O_MOVE;
          return;
        }
      }
      // Otherwise, let them know.
      cout << "There is a piece there!" << endl;
    }
  }
  }

// Given X or O, check if they've won
bool checkWin(int player) {
  if (board[0][0] == player && board [0][1] == player && board[0][2] == player) {
    return true;
  }
  if (board[1][0] == player && board [1][1] == player && board[1][2] == player) {
    return true;
  }
  if (board[2][0] == player && board [2][1] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board [1][0] == player && board[2][0] == player) {
    return true;
  }
  if (board[0][1] == player && board [1][1] == player && board[2][1] == player) {
    return true;
  }
  if (board[0][2] == player && board [1][2] == player && board[2][2] == player) {
    return true;
  }
  if (board[0][0] == player && board [1][1] == player && board[2][2] ==player) {
    return true;
  }
  if (board[2][0] == player && board [1][1] == player && board[0][2] == player) {
    return true;
  }
 return false;
}

// Check if there's a tie (all spots are filled)
bool checkTie() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == BLANK) {
        return false;
      }
    }
  }
  return true;
}

// Prints out board 
void printBoard() {
  char output[14];
  int index = 0;
  cout << " \t1\t2\t3" << endl;
  // Inputs "coordinate grid"
  for (int i = 0; i < 3; i++) {
    output[index] = 'a' + i;
    index++;
    output[index] = 1 + i;
    index++;
  }
  // Traverse through grid, seeing if a move has been placed there
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == BLANK) {
        output[index] = ' ';
      }
      else if (board[i][j] == 1) {
        output[index] = 'X';
      }
      else if (board[i][j] == 2){
        output[index] = 'O';
      }
      index++;
    }
}
  // Edge case...
  if (board[2][2] == 1) {
    output[14] = 'X';
  }
  else if (board[2][2] == 2) {
    output[14] = 'O';
  }
  else {
    output[14] = '\0';
  }
  // Print out the board!
  cout << " \t" << output[1] << " \t" << output[3] << " \t" << output[5] << endl;
  cout << output[0] << " \t" << output[6] <<  " \t" << output[7] <<  " \t" << output[8] << endl;
  cout << output[2] <<  " \t" << output[9] <<  " \t" << output[10] <<  " \t" << output[11] << endl;
  cout << output[4] << " \t" << output[12] << " \t" << output[13] << " \t" << output[14] << endl;
}

