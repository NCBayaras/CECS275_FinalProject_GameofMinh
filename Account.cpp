#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "Account.h"

using namespace std;
    Account::Account() {
        totalGames = 0;
        totalHumanGames = 0;
        totalCompWins = 0;
        totalCompGames = 0;
        totalHumanWins = 0;
        }
    void Account::addGame(bool humanWon, int mode) {
            //Add 1 Game Played
            totalGames++;
            //PvP
            if(mode == 1) {
                //Add 1 to PvP Games Played
                totalHumanGames++;
                //If P1 won
                if(humanWon) {
                    //Add 1 PvP Win
                    totalHumanWins++;
                }
            }
            //PvE
            else if(mode == 2) {
                //Add 1 to PvE Games Played
                totalCompGames++;
                //If P1 won
                if(humanWon) {
                    //Add 1 PvE Win
                    totalCompWins++;
                }
            }
        }
    
    double Account::overallWinningPercentage(){
        //If either one is 0
        if((totalCompWins + totalHumanWins) == 0 || totalGames == 0) {
            return 0;
        }
        return ((totalCompWins + totalHumanWins) / static_cast<double>(totalGames)) * 100;
    }
    
    double Account::winningPercentageAgainstHuman() {
        //If either is 0
        if(totalHumanWins == 0 || totalHumanGames == 0) {
            return 0;
        }
        return (totalHumanWins / static_cast<double>(totalHumanGames)) * 100;
    }
    
    double Account::winningPercentageAgainstComputer() {
        //If either is 0
        if(totalCompWins == 0 || totalCompGames == 0) {
            return 0;
        }
        return (totalCompWins / static_cast<double>(totalCompGames)) * 100;
    }