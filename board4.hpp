// Prevents redefinitions
#ifndef BOARD4_HPP
#define BOARD4_HPP

#include <iostream>
#include "board.hpp"
using namespace std;

class Board4 : public Board
{

// Make all functions public
public:

// Default constructor creates the empty 4-by-4 board
Board4();

// Places the player's piece in a specific slot on the board
void setBoard(int, int, int);

// Prints the entire board
void getBoard();

// Checks if the user's desired slot is valid
bool checkBoard(int, int);

// Checks if the current player has won the round
bool checkWin();

// Checks if the board has been completely filled
bool checkCompletion();

};

// Default constructor creates the empty board board
Board4::Board4()
{

  // Since the grid is 4-by-4
  size = 4;
  
  // Dynamically creates the grid...
  board = new char*[size];
  for (int i = 0; i < 4; i++)
    board[i] = new char[size];

  // And initializes it with dashes
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      board[i][j] = '-';
}

// Places the player's piece in a specific slot on the board
void Board4::setBoard(int player, int row, int col)
{  
  if (player == 1)  
    board[row][col] = 'O';
  else
    board[row][col] = 'X';
}

// Prints the entire board
void Board4::getBoard()
{
  cout << "\n";
  
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
      cout << board[i][j] << " ";
    
    cout << "\n";
  } // End for-loop
  
} // End function

// Checks if the user's desired slot is valid
bool Board4::checkBoard(int row, int col)
{

  // It cannot be outside of the grid...
  if (row >= size || col >= size)
    return false;
  else if (row < 0 || col < 0)
    return false;

  // Or on a slot that was already played...
  else if (!(board[row][col] == '-'))
    return false;

  /* Or on a slot that is not on the bottom row and
  is not on top of an already played slot */
  else if (row != size-1 && board[row+1][col] == '-')
    return false;

  // Otherwise, it is a valid play
  return true;
}

// Checks if the current player has won the round
bool Board4::checkWin()
{

  // For vertical and horizontal scenarios
  for (int i = 0; i < size; i++)
  {
    string tempH = "", tempV = "";
    
    for (int j = 0; j < size; j++)
    {
      tempH += board[i][j]; // The nth row
      tempV += board[j][i]; // The nth column
    }

    // If a row or column connects 4, the player wins
    if (tempH == p1Win || tempH == p2Win)
      return true;
    if (tempV == p1Win || tempV == p2Win)
      return true;
  }

  // For diagonal scenarios
  string tempD = "";

  // Creates the downwards diagonal
  for (int i = 0; i < size; i++)
    tempD += board[i][i];

  // If the diagonal connects 4, the player wins
  if (tempD == p1Win || tempD == p2Win)
    return true;

  tempD = "";

  // Creates the upward diagonal
  for (int i = 0; i < size; i++)
    tempD += board[i][3-i];

  // If the diagonal connects 4, the player wins
  if (tempD == p1Win || tempD == p2Win)
    return true;

  // Otherwise, there is no winner yet
  return false;
}

// Checks if the board has been completely filled
bool Board4::checkCompletion()
{
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (board[i][j] == '-')
        return false;
  
  return true;
}

#endif
