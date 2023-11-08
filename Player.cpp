#include "Player.h"
#include "NimGame.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "NimGame.h"

using namespace std;

Player::Player(std::string name) : Participant(name) {}

int Player::takeTurn(NimGame& game) {
  //If there is only 1 Marble left
  if(game.getMarbles() == 1) {
    return 0;
  }
  cout << name << "? (Enter 0 to quit): ";
  int n;
  cin >> n;
  while (n < 0 || n > (game.getMarbles() / 2)) { // Add input validation
    cout << "Invalid input. Please enter a number between 1 and " << (game.getMarbles() / 2) << " (Enter 0 to quit): " ;
    cin >> n;
  }
  return n;
}
