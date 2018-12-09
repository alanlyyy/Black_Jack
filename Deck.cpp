/*
 * This C++ file stores all the functions for the Deck.hpp header file/class
 */

//include the header file  for the deck class
#include <C:\Users\Alan Ly\Documents\NetBeansProjects\Blackjack_classes\Deck.hpp>

void Deck::create_deck()
{
    
    vector<string> Deck;        //to store the deck of different cards  
    
    vector<string> Cards = {"A","2","3","4","5","6","7","8",
                   "9","10","J","Q","K"}; //stores all the different card types
                                
    int count = 0;              //stores the index for Deck 
    
    //index each card type append to the deck
    for(int card_index = 0; card_index < 13; card_index++)
        {
            //append each suit of the specific card type to the deck
            Deck.insert(Deck.begin(),4 , Cards[card_index]);
            
        }
    current_deck = Deck;
}

void Deck:: shuffle_deck()
{
  // obtain a time-based seed to randomize shuffling of indexes:
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   
  //shuffles the deck 52 cards
  shuffle(current_deck.begin(),current_deck.end(),default_random_engine(seed));
}

void Deck:: set_current_deck(vector<string> new_deck)
{
    current_deck = new_deck;
}
vector<string> Deck::get_current_deck()
{
 return current_deck;   
}

void Deck:: print_current_deck()
{
    cout << "Deck: ";
    for(int card_index = 0; card_index < current_deck.size(); card_index++)
    {
        cout << current_deck[card_index];
    }
    cout << endl;
}

vector<string> Deck:: deal_hand()
{
    vector<string> hand;
    
    //deal 2 cards to the hand
    for(int index = 0; index < 2; index++)
        {
        
         //append to the beginning of hand by drawing from end of the deck
         hand.insert(hand.begin(),current_deck[current_deck.size()-1]);
         
         //remove the end index since the card already has been drawn
         current_deck.pop_back();
         
        }
    return hand;
}

string Deck:: draw_card()
{
    //draw the last card of the deck
    string drawn_card = current_deck[current_deck.size()-1]; 
    
    //remove the drawn card from the deck
    current_deck.pop_back();           
    
    return drawn_card;
}