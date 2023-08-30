// Prevents redefinitions
#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
using namespace std;

class Board
{

// Data fields are protected so derived classes can access them
protected:
int size;
char** board;

// What a winning entry looks like for player 1 and 2
string p1Win = "XXXX", p2Win = "OOOO";

// All functions are public and abstract
public:

// Set and get functions for the board
virtual void setBoard(int, int, int) = 0;
virtual void getBoard() = 0;

// Checks if the slot the player wants to play is valid
virtual bool checkBoard(int, int) = 0;

// Checks if a player has won or if the board has been filled
virtual bool checkWin() = 0;
virtual bool checkCompletion() = 0;

};

#endif
