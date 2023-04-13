
#include "game.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
#include <algorithm>
#include <stdexcept>
#include <cassert>


using namespace std;

namespace ariel{

    Game::Game(Player &pl1, Player &pl2):p1(pl1) ,p2(pl2)
    {
        string arr[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};
        for (int i = 0; i < 4; i++)
        {
            for (int j = 1; j <= 13; j++)
            {
                Card temp(arr[i], j);
                this->deck.push_back(temp);
            }
            
        }
        // shuffels the deck randomally. using a special algorithm - Mersen twister 19937, from 
        //the algorithms library.

        random_device rd;
        mt19937 g(rd());
        shuffle(this->deck.begin(), this->deck.end(), g);

            for (size_t i = 0; i < 26; i++)
            {
                this->p1.get_packet().push_back(this->deck[i]);
                this->p2.get_packet().push_back(this->deck[i+26]);
            }

        this->win_p1 = 0;
        this->win_p2 = 0;
        this->draws_amount = 0;
            
    }
    

    void Game::playTurn(){
        string str = "";
        int num_rownds = 0;
        while (true)
        {
            // checks if the cards of the players are over.
            if(this->p1.stacksize()==0 && this->p2.stacksize() ==0) {
                throw out_of_range{"out of range vector's players"};
            }

            Card c1 = this->p1.get_packet()[this->p1.get_packet().size()-1];
            Card c2 = this->p2.get_packet()[this->p2.get_packet().size()-1];

            str += this->p1.getName()+ " played " + c1.toString()+ " "
            +this->p2.getName()+ " played " + c2.toString() + ". ";
           
            // compares between the cards.
            if (c1 > c2)
            {
                str += this->p1.getName() +" wins.\n";
                p1.cardesTaken()+= (2+ (4*num_rownds));
                this->win_p1++;
                break;
            }

            else if (c2 > c1)
            {
                str += this->p2.getName()+" wins.\n";
                p2.cardesTaken()+= (2 +(4*num_rownds));
                this->win_p2++;
                break;
            }

            else // Draw situation -> c1 == c2:
            {
                //First of all, remove the cards from the packets.
                this->p1.get_packet().pop_back();
                this->p2.get_packet().pop_back();

                str += " Draw. ";
                this->draws_amount++;

                //checks again after the pop(), if the cards aren't over.
                if(this->p1.stacksize()== 0 && this->p2.stacksize() == 0)
                {
                    this->p1.cardesTaken()++;
                    this->p2.cardesTaken()++;
                    return;
                }
                // checks if only one left.
                else if (this->p1.stacksize()== 1 && this->p2.stacksize() == 1)
                {
                    this->p1.cardesTaken()+=2;
                    this->p2.cardesTaken()+=2;
                    break;
                }

                else //there are more than 2 cards left - enougth for other round.
                {
                    //First of all draw one more card - it will be the "opposite card".
                    this->p1.get_packet().pop_back();
                    this->p2.get_packet().pop_back();
                    // Calculate the amount of rounds of the "Draw situation".
                    num_rownds++;
                } 
            }
        }
        this->p1.get_packet().pop_back();
        this->p2.get_packet().pop_back();

        this->turns.push_back(str); 

    }

    void Game::playAll(){
        while (p1.stacksize() > 0 && p2.stacksize() > 0)
        {
            this->playTurn();
        }
        
    }

    void Game::printLastTurn(){

        cout << this->turns[this->turns.size()-1];
    }

    void Game::printLog(){

        for (size_t i = 0; i < this->turns.size(); i++)
        {
            cout << "turn number: " << i <<" "<< this->turns[i];

        }
    }

    void Game::printStats(){

        cout <<"The stats of p1:\n\n";
        cout <<"win rate: "<<this->win_p1<< " victories out of "<<this->get_turns().size()<< " turns."<<endl;
        cout <<"Cards won: "<<this->p1.cardesTaken()<<" ."<<endl;

        cout <<"The stats of p2:\n\n";
        cout <<"win rate: "<<this->win_p2<< " victories out of "<<this->get_turns().size()<< " turns."<<endl;
        cout <<"Cards won: "<<this->p2.cardesTaken()<<" ."<<endl;

        cout <<"The amount of darws are: "<<this->draws_amount<<" draws out of "<<this->get_turns().size()<<
        " turns"<<endl;

    }

    void Game::printWiner(){

        string str = "";
        if(this->p1.cardesTaken() > this->p2.cardesTaken())
        {
            str += ("The winner is: " + this->p1.getName() +"\n");
        }

        else if(this->p2.cardesTaken() > this->p1.cardesTaken())
        {
            str += ("The winner is: " + this->p2.getName() +"\n");
        }

        else
        {
            str += "There is a Draw. No one has won.\n";
        }
        
        cout <<str;
    }

    vector <Card> Game::get_deck(){
        return this->deck;
    }
    vector <string> Game::get_turns(){
        return this->turns;
    }


}