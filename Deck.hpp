
/* 
 * Defines the functions and variables for the deck class for implementation of
 * Blackjack game.
 * 
 * How to create separate header files and C++ files
 * https://stackoverflow.com/questions/42685649/where-how-to-put-functions-in-a-header-vs-c-source-file
 * 
 * File:   Deck.hpp
 * Author: Alan Ly
 *
 * Created on November 28, 2018, 9:02 PM
 */

#ifndef DECK_HPP
#define DECK_HPP

#include <cstdlib>         
#include <iostream>         //std:cout
#include <algorithm>        //std:shuffle
#include <random>           //std:default_random_engine
#include <chrono>           // std::chrono::system_clock
#include <vector>           //std:vector
#include <string>

using namespace std;

class Deck
{
    private:
    
        vector<string> current_deck;
        
    public:
        
        void create_deck();
        void shuffle_deck();
        void set_current_deck(vector<string> new_deck);
        vector<string> get_current_deck();
        vector<string> deal_hand();
        string draw_card();
        void print_current_deck();
};


#endif /* DECK_HPP */

