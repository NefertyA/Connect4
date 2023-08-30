#include <iostream>
using namespace std;

// Include the files of all referenced classes
#include "game.h"
#include "player.h"
#include "board.h"
#include "board4.h"
#include "board5.h"

// Function headers
Player createPlayer(Game &, int);
Board* createBoard();
void playGame(Game &);
int menu(Game &);

int main()
{
  Game game; // Creates a new game
  int choice = -1;

  // Header
  cout << "===============\n";
  cout << "|  CONNECT 4  |\n";
  cout << "===============\n";

  // Continues running the program until the user quits
  while (choice != 4)
  {
    choice = menu(game);
  }

  cout << "\nThank you for playing CONNECT 4!\n";
}

// Runs a particular function depending on the user's choice
int menu(Game &game)
{

  // Receives the user's choice from the Game class function
  int choice = game.printMenu();

  switch(choice)
  {
    case 1: game.printRules(); break;
    case 2: playGame(game); break;
    case 3: game.printPlayers(); break;
    case 4: break;
    default: cout << "Invalid input!\n";
  }

  // Returns the choice to the main function in case the user decides to quit
  return choice;
}

// Runs the game
void playGame(Game &game)
{

  // Initializes an array of 2 players
  Player players[2] = {createPlayer(game, 1), createPlayer(game, 2)};

  // Creates the game board
  Board *board = createBoard();

  // Prints the board
  board -> getBoard();

  // Keeps track of which player has their next turn
  int pNum = 0;

  // Allows each player to play until the board is completely filled or someone wins
  while (!(board -> checkCompletion()))
  {

    // Defines the player who is currently playing
    Player p1 = players[pNum % 2];

    // And the player who is not
    Player p2;

    // If the remainder is 1, then the other player must have an index of 0. Vice versa
    if (pNum % 2 == 0)
      p2 = players[pNum % 2 + 1];
    else
      p2 = players[pNum % 2 - 1];

    // Tell the user who's turn it is
    cout << "\nIt is " << p1.getName() << "'s turn!\n";

    int row, col;

    // Continue asking the user for their play until their answer is valid
    do
    {
      cout << "Enter the row and column you would like to place your piece in: ";
      cin >> row >> col;

      /* Since the player will number the board starting at 1,
      reduce the row and column number by 1 */
      row--;
      col--;

      // If their input is invalid...
      if (!(board -> checkBoard(row, col)))
      {

        // Ask them if they would like to view the rules
        char rules;
        cout << "Sorry, you cannot place your piece there.";

        // Continue asking them if their input is invalid
        do
        {
          cout << "\nWould you like to read the rules again? (Y/N) ";

          // Convert their input to uppercase
          cin >> rules;
          rules = toupper(rules);

          // Let the user know if their input is invalid
          if (rules != 'Y' && rules != 'N')
            cout << "Invalid input!\n";
          
        } while(rules != 'Y' && rules != 'N');

        /* If their input is valid and they wish to
        read the rules, print them */
        if (rules == 'Y')
          game.printRules();

        cout << "\n";
      } // End if-statement
      
    } while(!(board -> checkBoard(row, col)));

    // If the input is valid, place their shape in their chosen spot
    board -> setBoard(pNum % 2, row, col);

    // Print the board after each player's turn
    board -> getBoard();

    // If the user has connected 4 in a row...
    if (board -> checkWin())
    {

      // Congratulate them...
      cout << "Congratulations to " << p1.getName() << "! You won this round.\n";

      // And update their number of wins and games
      game.updateStats(false, p1.getId(), p2.getId());

      return;
    } // End if-statement

    // If the board is filled before someone wins...
    if (board -> checkCompletion())
    {

      // Tell the players their game is a tie...
      cout << "The game is a tie! No one wins this round.\n";

      // And update their number of games
      game.updateStats(true, p1.getId(), p2.getId());
    } // End if-statement

    /* Increase this value to produce a different remainder
    (keeps track of each player's turn) */
    pNum++;
  } // End while-loop
} // End function

// Initializes each player
Player createPlayer(Game &game, int num)
{
  Player p;

  cout << "\nHello player " << num << "! Type in your username: ";
  if (num == 1) cin.ignore();
  cin >> p;

  /* Initalizes the player's ID (so their stats
  can be accessed even after the round concludes) */
  p.setId(game.addPlayer(p));
  
  cout << "Your ID is " << p.getId() << ".\n";
  cout << "Your piece is " << (num == 1 ? "'X'" : "'O'") << ".\n";

  return p;
}

// Creates the game board
Board* createBoard()
{
  int size;

  // Continue asking the user for their desired grid until their input is valid
  do
  {
    cout << "\nWould you like to play on a "
      << "4-by-4 (type 4)\nor a "
      << "5-by-5 (type 5) grid? ";
  
    cin >> size;

    if (size != 4 && size != 5)
      cout << "Please enter either 4 or 5!\n";
    
  } while(size != 4 && size != 5);

  // Return a game board depending on the user's requested size
  switch(size)
  {
    case 4: return new Board4;
    case 5: return new Board5;
  }

  // Default to a 4-by-4 grid
  return new Board4;
}
