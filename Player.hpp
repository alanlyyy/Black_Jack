/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.hpp
 * Author: Alan Ly
 *
 * Created on November 29, 2018, 8:35 PM
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Player
{
    private:
        vector<string> current_hand;
        int current_points;
    
    public:
        vector<vector<string>> split_hand;
        vector<string> removed_from_current_hand;
        void update_hand(string card);
        void set_hand(vector<string> update_hand);
        vector<string> get_hand();
        void reset_hand();
        void print_hand();
        void set_initial_points(int points);
        int get_points();
        void update_points(int points, string add_or_sub);
        void reset_points();
};

#endif /* PLAYER_HPP */

