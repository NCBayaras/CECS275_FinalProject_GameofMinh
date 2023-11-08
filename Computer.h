#ifndef COMPUTER_H
#define COMPUTER_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

#include "Participant.h"
#include "NimGame.h"

class Mode;
/**
@brief This file contains the declaration of the Computer class as well as all its functionality.
*
Similar to Player, the purpose of this class is to create a CPU Participant in the case that the user selects PvE as their playing option & it also is a child class of Participant. This class has only 1 new variable which is mode which indicates the CPU mode that the user wants to play against (easy or hard) while also sharing the name variable from Participant. In the public section of this class, we have an Overloading Constructor & the derived int takeTurn(NimGame &game) function.
*/

class Computer : public Participant {
private:
/**
 * @brief Gets the current difficulty mode.
 * @return The current difficulty mode for Easy or Hard.
 */
  int mode; // difficulty setting
 /**
  * @class Mode
 * @brief The enumurated class for Mode
 * @return Returns Easy if 0 and returns hard if 1
 */
  enum Mode {Easy, Hard};
public:
/**
  * @brief Sets the name for Computer to be "Computer" and 
  * @param This constructor has 2 parameters which are the name and the mode. The name gets brought into the Participant Overloading Constructor & helps in the creation of a CPU Participant.
  * @return "Computer" and Easy Or Hard Mode
*/
  Computer(std::string name, int mode); // sets the difficulty and default constructor
  /**
@brief Takes a turn for the computer participant.
The purpose of the takeTurn() function in this class is to do essentially the same exact thing as Player,
but it changes depending on mode and only asks for an input from the first player, since the CPU takes the 
role of the second player. In mode 0 (easy mode), the CPU selects a random integer between a range of 1 and 
half of the currently remaining marbles. In mode 1 (hard mode), the CPU knows the winning strategy no matter what 
happens. We have a variable in this function called target that grabs the highest power of 2 that it can reach, 
then subtracts 1 and forces a legal move to get to that amount of marbles. This is because the optimal playing 
strategy is to leave the amount of marbles as a power of 2 minus 1. If the CPU can’t force its way to the target, 
it randomly selects a number of marbles to take away from the pile. 

@param game The current Nim game being played.
@return The number of marbles taken by the computer participant.
*/
  int takeTurn(NimGame& game); // Sets the difficulty and actions for the difficulty
  std::string getName() {
    return "";
  }
  friend class NimGame; // Have it here just in case NimGame actions are wrong
};

#endif // COMPUTER_H