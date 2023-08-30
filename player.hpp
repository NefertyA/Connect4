// Prevents redefinitions
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
using namespace std;

class Player
{

// Make data fields private
private:
string name;
int id;
int numWins;
int totalGames;

// Make all functions public
public:

// Default constructor sets the stats of each player to 0
Player():numWins(0), totalGames(0){}

// Prints the player's stats
friend ostream& operator<<(ostream&, Player&);

// Initializes the player's username
friend istream& operator>>(istream&, Player&);

// Get function for the player's name
string getName()
{
  return name;
}

// Set and get functions for the player's ID
void setId(int id)
{
  this -> id = id;
}

int getId()
{
  return id;
}

// Set function for the player's number of wins
void setNumWins()
{
  numWins++;
}

// Set function for the player's number of games
void setTotalGames()
{
  totalGames++;
}

};

// Prints the player's stats
ostream& operator<<(ostream& out, Player& p)
{

  // Changes the tense (wins vs win, games vs game) if necessary
  out << p.name << ": " << p.numWins << " win";
  (p.numWins == 1) ? (out << "") : (out << "s");
  
  out << " out of " << p.totalGames << " game";
  (p.totalGames == 1) ? (out << "\n") : (out << "s\n");
  
  return out;
}

// Initializes the player's username
istream& operator>>(istream& in, Player& p)
{
  getline(in, p.name);
  return in;
}

#endif
