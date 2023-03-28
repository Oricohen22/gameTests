#pragma once
#include "iostream"
#include <stdexcept>
namespace ariel{}
using namespace  ariel;
#include <string>
#include "player.hpp"
using namespace std;

class Game
{
public:
Player player1;
Player player2;

public:
    Game(){};
    Game(Player ori, Player amir){
    this->player1  = ori;
    this->player2 = amir;

    }


   void playTurn();
   void printLastTurn(); // print the last turn stats. For example:
                                                    // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
                                                    // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds. draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins. 
   void playAll(); //playes the game untill the end
   void printWiner(); // prints the name of the winning player
   void printLog(); // prints all the turns played one line per turn (same format as game.printLastTurn())
   void printStats();// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
};


