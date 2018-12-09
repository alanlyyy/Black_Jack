/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <C:\Users\Alan Ly\Documents\NetBeansProjects\Blackjack_classes\Player.hpp>


void Player::set_hand(vector<string> update_hand)
{
    current_hand = update_hand;
}

void Player::update_hand(string card)
{
    current_hand.push_back(card);
}

vector<string> Player:: get_hand()
{
    return current_hand;
}

void Player:: reset_hand()
{
    current_hand.clear();
}

void Player:: print_hand()
{
    cout << "Hand: ";
    for(int card_index = 0; card_index < current_hand.size(); card_index++)
    {
        cout << current_hand[card_index] << " ";
    }
    cout << endl;
}

void Player:: update_points(int points, string add_or_sub)
{
    if (add_or_sub == "add")
    {
        current_points += points;
    }
    
    if(add_or_sub == "sub")
    {
        current_points -= points;
    } 
}

void Player:: set_initial_points(int points)
{
    current_points = points;
}

void Player:: reset_points()
{
  current_points = 0;  
}

int Player:: get_points()
{
    return current_points;
}