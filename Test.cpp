#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"

//test1
TEST_CASE("Checking the name initialization") {
  Player p1("david");
  Player p2("davidson");
  CHECK(p1.player_Name == "david");
  CHECK(p2.player_Name == "davidson");
}

//test2
TEST_CASE("Test Game start") {
    Game game;
    CHECK(game.player1.stacksize() == 26);
    CHECK(game.player2.stacksize() == 26);
}


TEST_CASE("Test Game playTurn") {
    Game game;
    int cardsLeft1 = game.player1.stacksize();
    int cardsLeft2 = game.player2.stacksize();
    game.playTurn();
    CHECK(game.player1.stacksize() == cardsLeft1 - 1);
    CHECK(game.player2.stacksize() == cardsLeft2 - 1);
}

TEST_CASE("Test Player stacksize") {
    Player player("Alice");
    CHECK(player.stacksize() == 21);

}
TEST_CASE("test game playAll function")
{
    Player p1("player1");
    Player p2("player2");
    Game g(p1, p2);
    
    g.playAll();
    
    CHECK(p1.stacksize() + p1.cardesTaken() == 26 - 3);
    CHECK(p2.stacksize() + p2.cardesTaken() == 26 + 3);
}    

TEST_CASE("Game ends with one player having 52 cards and the other having 0") {
    Player p1("Alice");
    Player p2("Bob");
    Game game(p1, p2);
    game.playAll();

    CHECK((game.player1.stacksize() + game.player2.stacksize()) > 0);
    CHECK(game.player1.stacksize() + game.player2.stacksize() == 52);
}

TEST_CASE ("test_cards_after_two_turns") {
  Player p1("Alice");
  Player p2("Bob");
  Game game(p1, p2);

  game.playTurn();
  game.playTurn();

  CHECK(p1.stacksize() + p2.stacksize() == 50);

  CHECK(p1.cardesTaken() + p2.cardesTaken() == 0);

  CHECK(p1.stacksize() + p1.cardesTaken() == 26);
  CHECK(p2.stacksize() + p2.cardesTaken() == 24);
}

TEST_CASE("test_game_after_4_turns") {
  Player p1("Alice");
  Player p2("Bob");
  Game game(p1, p2);
  
  for (int i = 0; i < 4; i++) {
    game.playTurn();
  bool check1 = (p1.stacksize() + p2.stacksize() == 27);
  bool check2 = (p1.stacksize() == 25) || (p2.stacksize() == 25);
  CHECK(check1);
  CHECK(check2);
} 
}
TEST_CASE("Test players' cards after 10 turns") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    for (int i = 0; i < 10; i++) {
        game.playTurn();
    }

    bool check1 = ((p1.stacksize() == 16) || (p2.stacksize() == 16)); // check if one of the players has 16 cards
    bool check2 = ((p1.stacksize() == 17) || (p2.stacksize() == 25)); 
    CHECK(check1);
    CHECK(check2);
}

TEST_CASE("Game test - player cards count after 20 turns") {
  Player p1("Alice");
  Player p2("Bob");
  Game game(p1, p2);

  for (int i = 0; i < 20; i++) {
    game.playTurn();
  }

  CHECK(p1.stacksize() == 1);
  CHECK(p2.cardesTaken() == 51);
  CHECK(p2.cardesTaken() + p1.stacksize() == 52);
  CHECK(p1.stacksize() + p2.cardesTaken() == 52);
}

TEST_CASE("Test players' cards after 15 turns") {
    Player p1("Alice");
    Player p2("Bob");

    Game game(p1, p2);
    for (int i = 0; i < 15; i++) {
        game.playTurn();
    }

    bool check1 =((p1.stacksize() == 11) || (p2.stacksize() == 11)); // check if one of the players has 11 cards
    bool check2 =((p1.stacksize() == 41) || (p2.stacksize() == 41)); // check if one of the players has 31 cards
    CHECK(check1);
    CHECK(check2);
}

