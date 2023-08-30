// Prevents redefinitions
#ifndef BOARD5_HPP
#define BOARD5_HPP

#include <iostream>
#include "board.hpp"
using namespace std;

class Board5 : public Board
{

// Make all functions public
public:

// Default constructor makes the empty 5-by-5 board
Board5();

// Places the player's piece in a specific slot on the board
void setBoard(int player, int row, int col);

// Prints the entire board
void getBoard();

// Checks if the user's desired slot is valid
bool checkBoard(int row, int col);

// Checks if the current player has won the round
bool checkWin();

// Checks if the board has been completely filled
bool checkCompletion();

};

// Default constructor makes the empty 5-by-5 board
Board5::Board5()
{

  // Since the grid is 5-by-5
  size = 5;

  // Dynamically creates the grid...
  board = new char*[size];
  for (int i = 0; i < size; i++)
    board[i] = new char[size];

  // And initializes it with dashes
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      board[i][j] = '-';
}

// Places the player's piece in a specific slot on the board
void Board5::setBoard(int player, int row, int col)
{
  if (player == 1)  
    board[row][col] = 'O';
  else
    board[row][col] = 'X';
}

// Prints the entire board
void Board5::getBoard()
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
bool Board5::checkBoard(int row, int col)
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
bool Board5::checkWin()
{

  // For vertical and horizontal scenarios
  for (int i = 0; i < size; i++)
  {
    
    /* Since each row and column has two ways to
    connect 4, account for each case using a for-loop */
    for (int k = 0; k < 2; k++)
    {
      string tempH = "", tempV = "";

      for (int j = k; j < k+4; j++)
      {
        tempH += board[i][j]; // The nth row
        tempV += board[j][i]; // The nth column
      }

      // If a row or column connects 4, the player wins
      if (tempH == p1Win || tempH == p2Win)
        return true;
      if (tempV == p1Win || tempV == p2Win)
        return true;
    } // End for-loop
    
  } // End for-loop

  /* For the longer diagonal scenarios. Again,
  there are two possibilities since the length is 5 */
  for (int k = 0; k < 2; k++)
  {
    string tempD1 = "", tempD2 = "";
    
    for (int i = k; i < k+4; i++)
    {
      tempD1 += board[i][i]; // The downwards diagonal (\)
      tempD2 += board[i][4-i]; // The upwards diagonal (/)
    }

    // If either diagonal connects 4, the player wins
    if (tempD1 == p1Win || tempD1 == p2Win)
      return true;
    if (tempD2 == p1Win || tempD2 == p2Win)
      return true;
  }

  /* For the shorter (length of 4) diagonal scenarios.
  There are two shorter diagonals in each direction,
  so account for all of them */
  for (int k = 0; k < 2; k++)
  {
    string tempD1 = "", tempD2 = "";

    for (int i = k; i < k+4; i++)
    {
      tempD1 += board[i][3+2*k-i]; // The upwards diagonal (/)
      tempD2 += board[i][i+1-2*k]; // The downwards diagonal (\)
    }

    // If either diagonal connects 4, the player wins
    if (tempD1 == p1Win || tempD1 == p2Win)
      return true;
    if (tempD2 == p1Win || tempD2 == p2Win)
      return true;
  }

  // Otherwise, there is no winner yet
  return false;
}

// Checks if the board has been completely filled
bool Board5::checkCompletion()
{
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      if (board[i][j] == '-')
        return false;

  return true;
}

#endif

