#include "Computer.h"
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

// Rule is last one to get the marble LOSES
Computer::Computer(std::string name, int mode) : Participant(name) {
  this->mode = mode;
}

int Computer::takeTurn(NimGame& game) {
  //Computer Loses
  if(game.getMarbles() == 1) {
    return 0;
  }
  //To finish out the message from NimGame.cpp
  cout << "Computer?" << endl;
  int choice;
  int n;

  if (this->mode == Easy) { // 0 for easy mode
    int n = rand() % (game.getMarbles() / 2) + 1; // h.getMarbles() or h.marbles
    return n;

  } else { // 1 or anything else for hard mode
    int target = pow(2, floor(log2(game.getMarbles()))) - 1;
    cout << target << endl;
    if (game.getMarbles() == (target * 2) + 1)  {
      int n = rand() % (game.getMarbles() / 2) + 1;
    }
    else if (game.getMarbles() == target + 1) {
      return 1;
    }
    else {
      int n = game.getMarbles() - target;
      return n;
    }
  }
  return 0;
}