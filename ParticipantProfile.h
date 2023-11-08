#ifndef PARTICIPANTPROFILE_H
#define PARTICIPANTPROFILE_H
#include <string>
#include "NimGame.h"
#include "Participant.h"

/**
*
* @brief This class’s basic function is to hold the name of the Participant. 
* This class is the parent of Participant & the grandparent of Player & Computer. In the protected section, we have one variable which is name (the name of the participant). It also has an overloading constructor & 1 function which is std::string getName().
*
*/

class ParticipantProfile{
    protected:
        std::string name;
    public:

/**
*
* @brief Constructs a profile with the name of the current player. 
*
*/

        ParticipantProfile(std::string name){
            this->name = name;
        }

/**
*
* @brief This function returns the name that is stored in the profile of the current player
*
*/
    
        std::string getName() {
            return this->name;
        }
};
#endif