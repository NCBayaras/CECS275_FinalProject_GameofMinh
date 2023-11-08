#ifndef NIMGAME_H
#define NIMGAME_H
#include <string>
#include <fstream>
#include "Participant.h"
#include "Account.h"
#include "PlayByPlay.h"
#include "ParticipantProfile.h"

class Account;
class Participant;
class PlayByPlay;
class ParticipantProfile;
/**

@brief The NimGame Class keeps all the actions that is occuring within the Game. From generating the number of marbles to closing the game

The purpose of this class was to be able to establish an area where we wanted to create and be able to play the Game of Nim & to be able to display the Play by Play. Without this class, the game would have no instructions on what to do next after certain turns or whether we are playing PvP or PvE. In the private section of this class, it contains variables marbles (an int indicating the number of marbles in the current game), player1 (a participant pointer of the 1st player), player2 (a participant pointer of the 2nd player), currentPlayer (an int indicating the player that has the current turn), stats (an account pointer indicating the current stats), Playable (an int indicating whether its PvP or PvE), file (a PlayByPlay object that writes the Play By Play into a txt file), and currentGame (an integer indicating the game number we are on). The public section of this class contains a default constructor & functions void removeMarbles(int r), int getMarbles() const, void playNimGame(NimGame &game), void currentStats(), and void fileClose()

*/

class NimGame {
  private:
    int marbles;
    Participant* player1;
    Participant* player2;
    int currentPlayer;
    Account* stats;
    int Playable;
    int currentGame; 
    PlayByPlay file;

  public:
  /**
  * @brief The default constructor for the NimGame Class
  This default constructor initializes the stats by calling the default constructor made by Account. It also initializes currentGame as 1 to indicate that the 1st game will be Game #1. Lastly, the constructor opens/creates a file called PlaybyPlay.txt and then double checks if it is open. If it is open, it writes “Welcome to Group 2’s Game of Nim!” into the txt file.
  */

    NimGame();                // Default constructor
    /**
  * @brief Get the winning percentage against the computer in PvE games
  * @param  r integer that the user inputs that is removed from the Marbles generated
  * @return The integer that would be removed from the pile
  */  

    void removeMarbles(int r); // remove marble amount

  /**
  * @brief The purpose of this function is to return the current number of marbles in the pile.
  * 
  * @return The new updated marble count
  */

  int getMarbles() const;   // return marble amount after removeMarbles

   /**
  * @brief Being able to play the game itself. Starting from the selection of who they want to play against and what difficulty it would be if it was CPU. It also outputs the PlayByPlay.txt file
  * The purpose of this function is to be able to play the game & also to write the Play By Play into PlayByPlay.txt. The function parameter helps us be able to know that we are currently playing a specific game instead of trying to override stats from another game if we were to have another NimGame created. This function also creates a random number of marbles to include in the pile that Player 1 and Player 2 will be playing from. Player 1 & Player 2 are then created depending on whether the user chooses to play PvP or PvE. If it chooses PvP, Player 2 becomes a Player, but if it chooses PvE, Player 2 becomes a CPU. If PvE is chosen, the user then gets to choose whether it wants to play on easy mode or hard mode. To add on, this function randomly selects a player to start & then, once it starts, it runs on a loop until either player decides to quit or one player loses. If a player inputs 0, he quits the game and the game ends. If there is only 1 marble left, then the current player loses and it exits the loop while adding a win or loss to the stats. While it does all of this, it also writes every process into the PlayByPlay.txt file line by line so that after the game ends, the user has a Play By Play of what happened that entire time until the user stops playing. 
  * @return game object "game"
  */

    void playNimGame(NimGame &game);
  
  /**
  * @brief It prints out the current stat percentage depending on the game type
  * The purpose of this function is to print out the current stats of the game which include total win percentage, total win percentage against a Human Player 2, & total win percentage against a CPU.
  * @return The updated Account info for win percentage
  */

    void currentStats();

   /**
  * @brief Ends the .txt file that is generated after the game is over
  * The purpose of this function is to simply close the file that we opened from the constructor
  * @return the updated PlayByPlay.txt
  */
  
    void fileClose();

  
    friend class Computer;
    friend class Player;
    friend class Account;
};

#endif // NIMGAME_H