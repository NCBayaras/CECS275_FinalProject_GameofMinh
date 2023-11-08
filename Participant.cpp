#include "Participant.h"
#include "NimGame.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "NimGame.h"
#include "ParticipantProfile.h"

using namespace std;
Participant::Participant(std::string name) : ParticipantProfile(name){
    this->name = name;
}