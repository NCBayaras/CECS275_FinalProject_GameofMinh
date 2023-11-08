#include "NimGame.h"
#include "Computer.h"
#include "Player.h"
#include "Participant.h"
#include "Account.h"

#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

NimGame::NimGame() { // attempt to initialize the game. Allows user to decide whether they want to go against a CPU or a User
  //Creates a stats account
  this->stats = new Account();
  //Sets Current Game to Game 1
  this->currentGame = 1;
  //Player 1 Info
  std::string name1;
  std::cout << "Enter the name of player 1: ";
  getline(cin, name1);
  this->player1 = new Player(name1);
}

int NimGame::getMarbles() const { return marbles; }

void NimGame::removeMarbles(int r) { marbles -= r; }

void NimGame::playNimGame(NimGame &game) {
  file.inputToPlayByPlay("Starting Game #");
  file.inputToPlayByPlay(to_string(currentGame));
  file.inputToPlayByPlay("...");
  file.endLine();
  srand((unsigned)time(NULL));
  //Generates amount of marbles to have in the pile in the range of 10-999
  marbles = rand() % 991 + 10;
  //Player Info
  std::string name2;
  //Inputs the number of marbles into the txt file
  file.inputToPlayByPlay("Starting Pile: ");
  file.inputToPlayByPlay(to_string(game.getMarbles()));
  file.endLine();
  //Console
  cout << "Do you want to play against a User or a Computer?" << endl;
  cout << "Press 1 for User and 2 for Computer: ";
  cin >> Playable;
  while(Playable != 1 && Playable != 2) {
    if(Playable != 1 && Playable != 2) {
      std::cout << "Invalid input. Please enter 1 for User or 2 for Computer: ";
    }
    cin >> Playable;
  }
  if (Playable == 1) { // if they choose 1 and want against a user itll make Player1 and Player 2 Users
    std::cout << "Enter the name of player 2: ";
    cin.ignore();
    getline(cin, name2);
    //Creates Player 2
    this->player2 = new Player(name2);

  } else if (Playable == 2) { // if they choose 2 and want to go against a CPU , itll prompt them to name the CPU and choose the difficulty
    std::string name1, name2;
    name2 = "Computer";
    int mode = rand() % 2;
    name2 = "Computer";
    if (mode == 0) {
      cout << "Computer is on Easy Mode!" << endl;
    }
    else {
      cout << "Computer is on Hard Mode!" << endl;
    }
    //Creates CPU as Player 2
    this->player2 = new Computer(name2, mode);

    // Infintely loops
  } else { // if they put anything BUT 1 or 2 they'll be put back here
    std::cout << "Invalid input. Please enter 1 for User or 2 for Computer." << std::endl;
    }
  this->currentPlayer = getMarbles();


  // Initialize the game and players
  srand(time(0));                     // Seed the random number generator
  int currentPlayer = rand() % 2 + 1; // Choose a random player to start
  //Inputs who goes 1st into the txt file
  if (currentPlayer == 1) {
    file.inputToPlayByPlay(player1->getName());
    file.inputToPlayByPlay(" goes 1st!");
    file.endLine();
  }
  else if (currentPlayer == 2) {
    file.inputToPlayByPlay(player2->getName());
    file.inputToPlayByPlay(" goes 1st!");
    file.endLine();
  }

  // Start the game loop
  while (game.getMarbles() != 0) {
    // Display game state and prompt for user input
    cout << "There are " << game.getMarbles() << " left in the pile" << endl;
    //Only prints when there is more than 1 marble
    if(game.getMarbles() != 1) {
      cout << "How many marbles do you want to remove ";
    }
    //Current turn Call
    int n = (currentPlayer == 1) ? player1->takeTurn(*this) : player2->takeTurn(*this);

    // Check if the player has quit
    if (game.getMarbles() == 1) {
      //Player 1 Loses
      if(currentPlayer == 1) {
        //Inputs who loses & who wins into the txt file
        file.inputToPlayByPlay(player1->getName());
        file.inputToPlayByPlay(" takes the last marble & lose! ");
        file.inputToPlayByPlay(player2->getName());
        file.inputToPlayByPlay(" wins! Good Game!");
        file.endLine();
        //Console
        cout << player1->getName() << " loses! Good Game!\n" << endl;
        //Adds a Game Played
        stats->addGame(false, Playable);
      }
      //Player 1 Wins
      else if(currentPlayer == 2) {
        //inputs who loses & who wins into the txt file
        file.inputToPlayByPlay(player2->getName());
        file.inputToPlayByPlay(" takes the last marble & lose! ");
        file.inputToPlayByPlay(player1->getName());
        file.inputToPlayByPlay(" wins! Good Game!");
        file.endLine();
        cout << player2->getName() << " loses! Good Game!\n" << endl;
        //Adds a Game Played & Won
        stats->addGame(true, Playable);
      }
      //End Game After Someone Wins
      break;
    }
    //If a Player Quit
    if (n == 0) {
      if(currentPlayer == 1) {
        //Inputs that P1 Quit into the txt file
        file.inputToPlayByPlay(player1->getName());
        file.inputToPlayByPlay(" quits the game...");
        file.endLine();
      }
      else if (currentPlayer == 2) {
        //Inputs that P2 Quit into the txt file
        file.inputToPlayByPlay(player2->getName());
        file.inputToPlayByPlay(" quits the game...");
        file.endLine();
      }
      //Console
      cout << "You have quit the game" << endl;
      //End Game After Someone Quits
      break;
    }

    // Remove the chosen number of marbles
    game.removeMarbles(n);
    //Inputs how many marbles the current player took out and how many marbles remain into the txt file
    if(currentPlayer == 1) {
      file.inputToPlayByPlay(player1->getName());
      file.inputToPlayByPlay(" removes ");
      file.inputToPlayByPlay(to_string(n));
      file.inputToPlayByPlay(" marbles. There are ");
      file.inputToPlayByPlay(to_string(game.getMarbles()));
      file.inputToPlayByPlay(" marbles remaining.");
      file.endLine();
    }
    else if (currentPlayer == 2) {
      file.inputToPlayByPlay(player2->getName());
      file.inputToPlayByPlay(" removes ");
      file.inputToPlayByPlay(to_string(n));
      file.inputToPlayByPlay(" marbles. There are ");
      file.inputToPlayByPlay(to_string(game.getMarbles()));
      file.inputToPlayByPlay(" marbles remaining.");
      file.endLine();
    }
    cout << "You removed " << n << " marbles from the pile" << endl;
    
    // Update the current player's turn
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
  }
  currentGame++;
  file.inputToPlayByPlay("------------------------------------------");
  file.endLine();
}

void NimGame::currentStats() {
  cout << "\nP1 Stats" << endl;
  cout << "----------------" << endl;
  cout << "Win Percentage: " << stats->overallWinningPercentage() << "%" <<endl;
  cout << "Win Percentage Against Human: " << stats->winningPercentageAgainstHuman() << "%" << endl;
  cout << "Win Percentage Against CPU: " << stats->winningPercentageAgainstComputer() << "%" << endl;
}

void NimGame::fileClose() {
  file.endFile();
}