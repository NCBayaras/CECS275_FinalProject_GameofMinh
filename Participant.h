#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;

#include "NimGame.h"
#include "ParticipantProfile.h"

/**
  * @brief Forward declaration of NimGame so it doesn't become a circular dependancy
*/

class NimGame;
class ParticipantProfile;

/**
* @brief The Child Class of ParticipantProfile so the name goes through here
*/

class Participant : public ParticipantProfile{

  public:

/**
* @brief Constructor for the Participant class.
* @param name The name of the player.
*/

    Participant(std::string name);
// Other methods

/**
 * @brief The virtual takeTurn method that must be implemented by derived classes.
 * @param game A reference to the NimGame object representing the game being played.
 * @return The number of marbles removed by the player on their turn.
 */
 
    virtual int takeTurn(NimGame& game) = 0;
};

#endif // PARTICIPANT_H