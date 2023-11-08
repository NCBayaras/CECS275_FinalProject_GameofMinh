#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Participant.h"
#include "NimGame.h"
using namespace std;

/**
  * @brief The Player class which allows the input of a string and overloading of the Particpant
*/

class Player : public Participant {
public:
    // Constructor

/**
* @brief The default constructor for the Player Class
This Overloading Constructor only has 1 parameter which is the desired name when creating a new human player. This name then gets brought into the Participant Overloading Constructor & creates a participant that is a human.
* @param name description name , obtains the words from the user and overrides the Particpant Player 1 or Player 2
* @return name Inputed by the user
*/

    Player(std::string name);

    std::string getName() {
    return "";
    }

    // Overridden method
          /**
    * @brief The default constructor for the Player Class
    The purpose of this function is to do the current turn that the human player has. This function asks for an input which is the number of marbles that the player wants to take. Once the user inputs a number, the program validates that the integer is at least 1, but at most half of the marbles in the current pile. It knows how many marbles are in the pile because of the game parameter we have which tells the program which game we are currently playing. If the user inputs an invalid input, it lets the user know the valid range of integers and then asks for another input. Once we get a valid input, it returns that number which then goes into the NimGame class and takes away that many marbles from the pile.
    * @param game Object
    * @return actions taken by the player, removeMarbles
    */

    int takeTurn(NimGame& game);
};

#endif // PLAYER_H