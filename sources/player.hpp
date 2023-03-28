#pragma once //make shure that this file won't included twice or more times.

#include <string>
#include <stdexcept>

using namespace std;
#include "iostream" 

class Player{
    
    public: 
    std::string player_Name;
    
    public:
    Player(){}; // a default constructor using to create a player object without having to provide a name arg.
    Player(string name){//an overloaded constructor
    this->player_Name = name;
    } 

    int stacksize();        //return the amount of cards left. should be 21 but can be less if a draw was played
    int cardesTaken();      //return the amount of cards this player has won. 

};





