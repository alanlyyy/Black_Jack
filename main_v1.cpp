/* 
 * File:   main.cpp
 * Author: Alan Ly
 *
 * Created on November 24, 2018, 8:21 AM
 * 
 * A game of blackjack implemented using functions
 */

#include <cstdlib>            
#include <iostream>         //std:cout
#include <algorithm>        //std:shuffle
#include <random>           //std:default_random_engine
#include <chrono>           // std::chrono::system_clock
#include <vector>           //std:vector
#include <string>
using namespace std;

/*
 * 
 */

struct Player
{
    vector<string> player_hand;
    vector<string> player_deck;
};

Player deal_hand(vector<string> Deck)
    {
    
    vector<string> hand;
    
    //deal 2 cards to the hand
    for(int index = 0; index < 2; index++)
        {
        
         //append to the beginning of hand by drawing from end of the deck
         hand.insert(hand.begin(),Deck[Deck.size()-1]);
         
         //pop the end index since the card already has been drawn
         Deck.pop_back();
         
        }
    return { hand, Deck };
 }

Player draw_card( vector<string> hand, vector<string> Deck )
{
    hand.push_back(Deck[Deck.size()-1]); //draw the last card of the deck
    Deck.pop_back();           //remove the last card since it was drawn
    
    return {hand, Deck};
}


//array template class to return array of 52 cards
vector<string> create_deck()
{
    
    vector<string> Deck;        //to store the deck of different cards  
    
    vector<string> Cards = {"A","2","3","4",
                        "5","6","7","8",
                        "9","10","J","Q","K"}; //stores all the different card types
                                
    int count = 0;              //stores the index for Deck 
    
    //index each card type append to the deck
    for(int card_index = 0; card_index < 13; card_index++)
        
        {
            //append each suit of the specific card type to the deck
            Deck.insert(Deck.begin(),4 , Cards[card_index]);
            
        }
    
    /*Test
    cout << "Deck: ";
    for(int card_index = 0; card_index < Deck.size(); card_index++)
    {
        cout << Deck[card_index];
    }
    */   
    
    return Deck;
}

vector<string> shuffle_deck( vector<string> Deck )
{
  // obtain a time-based seed to randomize shuffling of indexes:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   
  //shuffles the deck 52 cards
  shuffle(Deck.begin(),Deck.end(),default_random_engine(seed));
  
  /*Test
  cout << "shuffled elements:";
  
  for (string& x: Deck) cout << ' ' << x;
  cout << '\n';
  */
  
  return Deck;
}



int score_hand(Player player)
{
   int score = 0;
   int num_ace = 0;     //holds the position of the number of aces in a hand
   
   for(int index = 0; index < player.player_hand.size(); index++)   
   {
       if( player.player_hand[index] == "J" or player.player_hand[index] == "Q"
               or player.player_hand[index] == "K")
       {
           score += 10;
       }
       else if(player.player_hand[index] == "A")
       {
           num_ace += 1;
       }
       else
       {
           score += stoi(player.player_hand[index]);
       }
   }
   
   //update the number aces in the score
   if (num_ace > 0)
       {
            if (score > 10)
            {
                score += 1;
            }
            else
            {
                score += 11;
            }
       }
   
   return score;
}

void display_hand(Player player)
{
    cout << "Hand: ";
    for(int index = 0; index < player.player_hand.size(); index++)
    {
    cout << player.player_hand[index] << " ";
    }
    cout << endl;
}

void display_Deck(Player player)
{
    cout << "Deck: ";
    for(int index = 0; index < player.player_deck.size(); index++)
    {
    cout << player.player_deck[index] << " ";
    }
    cout << endl;
}

void compare_score(int player_score, int COM_score)
{
    if (player_score > COM_score and player_score < 22 or COM_score > 21 )
    {
        cout << "Player 1 has won. ";
    }
    else
    {
        cout << "COM has won. ";
    }
            
}


void play_game()
{
    //keeps a running sum of the score
    int score;
    int COM_score;
    
    //create a deck with 52 cards
    vector<string> create_Deck = create_deck();
    
    //shuffle the cards in randomize order
    vector<string> shuffled_Deck = shuffle_deck(create_Deck);
    
    //create a player for the game player contains a hand and a deck
    Player player1 = deal_hand(shuffled_Deck);
    
    //update the shuffled deck
    shuffled_Deck = player1.player_deck;
    
    //create player 2 computer
    Player COM = deal_hand(shuffled_Deck);
    
    //display hand
    display_hand(player1);
    
    string choice;
    cout << "Do you hit or stay? hit/stay " << endl; 
    cin >> choice;
    
    while (choice != "stay")
    {   
        // draw card
        player1 = draw_card(player1.player_hand,shuffled_Deck);
        
        //update the deck
        shuffled_Deck = player1.player_deck;
        
        //check the score
        score = score_hand(player1);
        
        if (score > 21)
        {
            break;
        }
        //reset score for next iteration
        score = 0;
                
        //show the hand
        display_hand(player1);
        
        //prompt the user
        cout << "Do you hit or stay? hit/stay " << endl; 
        cin >> choice;
    }
    
    //reset score
    score = 0;
    //calculate score
    score = score_hand(player1);
    
    if (score > 21)
    {
        cout << "You Bust. " <<endl;
        
        //prevents memory from returning random values
        COM_score = 0;
    }
    else
    {
        while (1)
        {   
        
        //display hand
        display_hand(COM);
        
        //calculate the score
        COM_score = score_hand(COM);
        
        //break out of the loop if computer has a score in the range of 18 - 21
        //or bust
        if ((COM_score <= 21 and COM_score > 17) or COM_score > 21) 
        {
            display_hand(COM);
            break;
        }
        
        // draw card
        COM = draw_card(COM.player_hand,shuffled_Deck);
        
        //update the deck
        shuffled_Deck = COM.player_deck;
        
        //reset score for calculation again
        COM_score = 0;
        
        }  
        
    }
    
    cout << endl << "Com score: " << COM_score;
    cout << endl <<  "Player score: " << score;
    cout << endl;
    
    compare_score(score,COM_score);
     
}

int main() {
    
    char choice;
    
    while(1)
    {
        play_game();
        
        cout << "Play again?Y/N ";
        cin >> choice;
        
        if (choice == 'N')
        {
            break;
        }
                
    }
    
    return 0;
}

