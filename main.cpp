#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;
// Header file for the Game class
#include "NimGame.h"
#include "Computer.h"
#include "Participant.h"
#include "Player.h"
#include "Account.h"

void mainMenu();

void mainMenu() {
  cout << "Main Menu:" << endl;
  cout << "1) Play Game of Nim" << endl;
  cout << "2) See Win Percentage" << endl;
  cout << "3) Stop Playing" << endl;
}

int main(){
  // Seed the random number generator
  srand(time(nullptr));
  // Create a new Game object
  NimGame game;
  int choice;
  cout << "Welcome to Group 2's Game of Nim!" << endl;
  //Loops Game of Nim until user chooses to stop playing
  while(choice != 3) {
    mainMenu();
    cout << "Please select an option: ";
    cin >> choice;
    //Makes sure that option is valid
    while(choice < 1 || choice > 3) {
      if(choice < 1 || choice > 3) {
        cout << "Invalid Option..." << endl;
      }
      cout << "Please select an option: ";
      cin >> choice;
    }
    //Play Game of Nim
    if(choice == 1) {
      cout << endl;
      game.playNimGame(game);
    }
    //Display Stats
    else if(choice == 2) {
      game.currentStats();
      cout << endl;
    }
    //End Game
    else {
      continue;
    }
  }
  //Closes the Play By Play
  game.fileClose();
  cout << "Thanks for Playing!" << endl;
  
  return 0;
}