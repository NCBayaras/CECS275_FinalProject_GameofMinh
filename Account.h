#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
using namespace std;
/**
@brief The Account class keeps track of game statistics for a user

The purpose of this class is to keep track of how many wins Player 1 has in total, versus a Player 2, 
and versus the CPU (easy and hard combined). This class also finds the win ratio for the same 3 
categories, but as a percentage. In the private section of this class, we have totalGames (an integer 
indicating the total number of games played), totalHumanGames (an integer indicating the total number 
of games played versus a Player 2), totalCompGames (an integer indicating the total number of games 
played versus a CPU), totalHumanWins (an integer indicating the total number of wins versus a Player 2), and
totalCompWins (an integer indicating the total number of wins versus a CPU). In the public section of this class, 
we have a Default Constructor & 4 functions which are void addGame(bool humanWon, int mode), double overallWinningPercentage(),
overallWinningPercentageAgainstHuman(), & overallWinningPercentageAgainstComputer().

*/

class Account {
    private:
        int totalGames;
        int totalHumanWins;
        int totalCompWins;
        int totalCompGames;
        int totalHumanGames;
    public:
        public:
/**
* @brief Construct a new Account object with default values for all statistics
This constructor initializes every variable in the private section to 0. When we start playing, we have not played a single game so there is no need to initialize it to any other number since 0 means no game has been played yet.
*/
     Account();
/**
 * @brief 
 *Update the statistics based on the outcome of a game. This function adds a game to one (or more) of the counters depending on the mode that the game was played on (PvP or PvE) & if Player 1 won or not. If Player 1 won, humanWon would be equal to true while if they lost, humanWon would be false. No matter
  what gamemode was played, 1 was added to totalGames. If the mode was PvE, we would add 1 to totalCompGames & if it was PvP, we would add 1 to totalHumanGames. If Player 1 won, we would add 1 to totalHumanWins if we were in PvP mode or add 1 to totalCompWins if we were in PvE mode. If Player 1 didn’t win, we wouldn’t add a win at all.
  * @param humanWon True if the human player won and False if Computer won
  * @param mode 1 for PvP, 2 for PvE
 */

          void addGame(bool humanWon, int mode);
  /**
  * @brief Get the overall winning percentage
  * This function finds the win percentage of Player 1 no matter what game mode they have played. We do this by adding totalHumanWins with totalCompWins to get the total number of wins Player 1 had and then dividing it by totalGames. Since we want it to be as a percentage, we then multiplied that value by 100 to represent the value as a percentage. It then returns that double value, but if either totalGames or totalHumanWins + totalCompWins is equal to 0, we return 0 to indicate that Player 1 has not won or has not played a single game yet
  * @return The overall winning percentage, 0 if no games have been played
  */
        double overallWinningPercentage();
 /**
  * @brief Get the winning percentage against human opponents in PvP games
  * This function finds and returns the win percentage of Player 1 versus a Human (Player 2). We do this by grabbing totalHumanWins and dividing it by totalHumanGames. Since we want to represent the value as a percentage, we multiply it by 100 and then return that double value. If either totalHumanWins or totalHumanGames is equal to 0, we return 0 to represent that Player 1 has either not won or has no played a single game yet against a Human
  * @return The winning percentage against human opponents, 0 if no PvP games have been played
  */
        double winningPercentageAgainstHuman();
 /**
  * @brief Get the winning percentage against the computer in PvE games
  * This function finds and returns the win percentage of Player 1 versus a CPU (easy + hard combined). We do this by grabbing totalCompWins and dividing it by totalCompGames. Since we want to represent the value as a percentage, we multiply it by 100 and then return that double value. If either totalCompWins or totalCompGames is equal to 0, we return 0 to represent that Player 1 has either not won or has no played a single game yet against the CPU.
  * @return The winning percentage against the computer, 0 if no PvE games have been played
  */
        double winningPercentageAgainstComputer();
};

#endif // ACCOUNT_H