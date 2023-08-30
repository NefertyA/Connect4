// Prevents redefinitions
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include "player.hpp"
using namespace std;

class Game
{

// Data members should be private
private:
vector<Player> players;

// All other functions are public
public:

// Adds a player to the game records
int addPlayer(Player);

// Prints the stats of all the players
void printPlayers();

// Updates the stats of each player in a round
void updateStats(bool, int, int);

// Prints the rules of the game
void printRules();

// Prints the main menu
int printMenu();

};

// Adds a player to the game records
int Game::addPlayer(Player p)
{
  int i;

  // If the user is already in the game records...
  for (i = 0; i < players.size(); i++)
  {
    if (players.at(i).getName() == p.getName())
      return i; // Return their ID
  }

  // Otherwise, add a new player to the list
  players.push_back(p);

  // And create their new ID
  i = players.size()-1;
  return i;
}

// Prints the stats of all the players
void Game::printPlayers()
{
  cout << "\n";

  // There are no stats until the user finishes at least 1 game
  if (players.size() == 0)
    cout << "There are no players yet!\n";

  // Otherwise, print the stats of each player in the program's records
  for (int i = 0; i < players.size(); i++)
    cout << players.at(i);
}

// Updates the stats of each player in a round
void Game::updateStats(bool tie, int p1, int p2)
{
  
  // If the game was not a tie, then someone won the game
  if (!tie)
    players.at(p1).setNumWins();

  // Regardless, both players played a game
  players.at(p1).setTotalGames();
  players.at(p2).setTotalGames();
}

// Prints the rules of the game
void Game::printRules()
{
  cout << "\n=== RULES ===";
  cout << "\n1. Each player takes turns placing their piece in a\n"
       << "\tparticular slot on either a 4-by-4 or 5-by-5 grid.";
  cout << "\n2. Pieces must ONLY be placed on the bottom row or\n"
       << "\ton top of another piece.";
  cout << "\n3. The first person to connect 4 of their pieces in\n"
       << "\ta row, either vertically, horizontally, or diagonally,\n"
       << "\twins the round.";
  cout << "\n4. If the entire grid is filled before a player connects\n"
       << "\t4, the round ends in a tie.\n";
}

// Prints the main menu
int Game::printMenu()
{
  cout << "\n=== MAIN MENU ===\n"
       << "[1] Read the rules\n"
       << "[2] Play a new game\n"
       << "[3] View player stats\n"
       << "[4] Exit\n";

  // Returns what the user wishes to do
  int choice;
  cout << "What would you like to do? ";
  cin >> choice;

  return choice;
}

#endif

