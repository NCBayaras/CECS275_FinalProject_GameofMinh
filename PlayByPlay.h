#ifndef PLAYBYPLAY_H
#define PLAYBYPLAY_H
#include <string>
#include <fstream>

using namespace std;

/**
*
* @brief The .txt file generator for the Game Of Minh
*
*/

class PlayByPlay {
    private:
        std::ofstream out;
    public:

  /**
  * @brief The .txt file generator for the Game Of Minh
  This function generates all the lines necessary to print out a .txt file from all the classes that is being associated with it. In this case it is NimGame.h and NimGame.cpp
  * @return Strings and the output to the game that has been played.
  */

        //Constructs PlayByPlay object & Opens a PlayByPlay file
        PlayByPlay() {
          //Opens PlayByPlay.txt File
          out.open("PlayByPlay.txt", ios::app);
          //Verifies that it is open. If not, it attempts to reopen and then input the message
          if(out.is_open()) {
            out << "Welcome to Group 2's Game Of Nim!" << std::endl;
            out << "------------------------------------------" << std::endl;
          }
          else {
            out.open("PlayByPlay.txt");
            out << "Welcome to Group 2's Game Of Nim!" << std::endl;
            out << "------------------------------------------" << std::endl;
          }
        }
        //Function that inputs a new string into the file
  
  /**
  * @brief The .txt file generator for the Game Of Minh
  This function generates all the lines necessary to print out a .txt file from all the classes that is being associated with it. In this case it is NimGame.h and NimGame.cpp
  */

        void inputToPlayByPlay(std::string in) {
            out << in;
        }
        //Uses endl to end the current line

  /**
  * @brief After each action is made it outputs that line into the txt file.
  */

        void endLine() {
            out << endl;
        }
        //Closes the file
  
   /**
  * @brief Closes the .txt file that was open after the game ends.
  */

        void endFile() {
            out.close();
        }
};

#endif