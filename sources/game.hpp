#pragma once

#include "player.hpp"


namespace ariel{

   class Game {

    Player& p1;
    Player& p2;

    vector <string> turns;
    vector <Card> deck;
    
    int win_p1;
        
    
    int win_p2;

    
    int draws_amount;
    
    public:

        Game(Player&, Player&);

        void playTurn();

        void playAll();

        void printLastTurn();

        void printWiner();

        void printStats();

        void printLog();

        vector<Card> get_deck();

        vector <string> get_turns();



   };
   
}