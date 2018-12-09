/* This code is the glue for the Deck and Player class. This class implements
 * the game of blackjack.
 * 
 *Reference:
 * https://stackoverflow.com/questions/19521320/why-do-i-get-an-infinite-loop-if-i-enter-a-letter-rather-than-a-number
 */

/* 
 * File:   main.cpp
 * Author: Alan Ly
 *
 * Created on November 28, 2018, 9:12 PM
 */

//include the header file  for the deck class
#include <C:\Users\Alan Ly\Documents\NetBeansProjects\Blackjack_classes\Deck.hpp>
#include <C:\Users\Alan Ly\Documents\NetBeansProjects\Blackjack_classes\Player.hpp>

using namespace std;

int user_menu()
{
    int selection;
    cout << "Hit (1) or Stay (0)?" << endl;
    cin >> selection;
    
    return selection;
}

int score_hand(Player player)
{
   int score = 0;
   int num_ace = 0;     //holds the position of the number of aces in a hand
   
   for(int index = 0; index < player.get_hand().size(); index++)   
   {
       if( player.get_hand()[index] == "J" or player.get_hand()[index] == "Q"
               or player.get_hand()[index] == "K")
       {
           score += 10;
       }
       else if(player.get_hand()[index] == "A")
       {
           num_ace += 1;
       }
       else
       {
           score += stoi(player.get_hand()[index]);
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

bool rank_player_hand(int score1, int score2)
{
    if (score1 > 21)
    {
        return false;
    }
    else if(score2 > 21)
    {
        return true;
    }
    else
    {
        if (score1 > score2)
        {
            return true;
        }
        else
        {
            return false;
        }
            
    }
}

bool is_black_jack(Player player)
{
    bool ace_flag =false;
    bool face_flag = false;
    
    for (int card = 0; card < player.get_hand().size(); card++)
    { 
     if (player.get_hand()[card] == "J" or    
                player.get_hand()[card] == "Q" or
                    player.get_hand()[card] == "K" or
                        player.get_hand()[card] == "10")
     {
         face_flag = true;
     }
     
     if (player.get_hand()[card] == "A")
     {
         ace_flag = true;
     }    
    }
    
    return (ace_flag and face_flag);
}

bool is_split_condition(Player player, string card)
{
    
    int count = 0;
    for (int index = 0; index < player.get_hand().size(); index++)
    {
        if (card == player.get_hand()[index])
        {
            count++;
        }
    }
    if (count == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void split_hand(Player player,string card)
{
    vector<string> temp_hand = player.get_hand();
    
    for (int index = 0; index < player.get_hand().size(); index++)
    {
        //if the card is equal to the card that the user wants to split
        if (card == player.get_hand()[index])
        {
            //add to list of removed cards for debugging
            player.removed_from_current_hand.push_back(player.get_hand()[index]);
            
            //change card to vector and add it to vector of vectors
            player.split_hand.push_back({player.get_hand()[index]});
        }
    }
    while(1)
    {
        int count = 0;
        
        if (temp_hand[count] == card)
        {
            temp_hand.erase(count);
        }
        
        count++;
        
        if (count > temp_hand.size())
        {
            break;
        }
    } 
}

void function_tester()
{
    cout <<"test all functions";
}

void play_game()
{   
    //initialize the players
    Player player1, COM;
    
    //initialize the game deck
    Deck myDeck;
    
    //create the deck and shuffle it
    myDeck.create_deck();
    myDeck.shuffle_deck();
    
    //set initial points for the players
    player1.set_initial_points(10);
    COM.set_initial_points(10);

    int pot = 0;
    
    while( player1.get_points() > 0 and COM.get_points() > 0)
    {   
        //keeps count of total_card_score
        int COM_score, player_score, player_ante;
        
        //deal hands to player and computer
        player1.set_hand(myDeck.deal_hand());
        COM.set_hand(myDeck.deal_hand());
        
        //test the blackjack condition
        //vector<string> black_jack = {"K", "A"};
        //player1.set_hand(black_jack);
        
        //display the hands of com and player1
        cout << "Player ";
        player1.print_hand();
        cout << "COM "; 
        COM.print_hand();
        
        //display number of points
        cout << "Player 1 Points: "<< player1.get_points() << endl;
        cout << "COM Points: "<< COM.get_points() << endl;
       
        //set player ante----------------------------------
        cout << "Player ante " << endl;
        player_ante = 0;
        //while condition checks error state of input buffer and reprompts user
        while(!(cin >> player_ante))
            {
            //clear the error bit of the input buffer
            cin.clear();
            //ignore values that are not integers
            cin.ignore(1, '\n');
            cout << "Invalid input.  Try again: ";
            }
        cout << "You enterd: " << player_ante << endl;     
        //--------------------------------------------------
        
        player1.update_points( player_ante , "sub");
        pot += player_ante;
        
        COM.update_points( player_ante , "sub");
        pot += player_ante;
        
        
        bool black_jack_condition = is_black_jack(player1);
        
        if (black_jack_condition == true)
        {
            
            cout << "Player got black jack!" << endl;
            
            //update the points for player
            player1.update_points(pot, "add");
            
            //reset the pot
            pot = 0;            
            
            //reset the hand
            player1.reset_hand();
            COM.reset_hand();
        
            //reset the deck
            myDeck.create_deck();
            myDeck.shuffle_deck();
            
            //jump back to the beginning of the loop and start a new round
            continue;
        }
       
        //prompt user to hit or stay
        int user_option = user_menu();
        cout << "----------------------------" << endl;
        
        //while user continues to hit 
        while (user_option == 1)
        {
            //draw card and update user hand
            player1.update_hand(myDeck.draw_card());
            player1.print_hand();
            user_option = user_menu();
            cout << "----------------------------" << endl;
        }
        
        // COM's turn to play      
        while(1)
        {
            COM_score = score_hand(COM);
            
            if(COM_score < 17)
            {
                COM.update_hand(myDeck.draw_card());
                cout << "COM ";
                COM.print_hand();
            }
            else
            {
                break;
            }   
            //reset the score for next iteration
            COM_score = 0;
        }
        cout << "----------------------------" << endl;
        //calculate the score of the hand
        player_score = score_hand(player1);
        COM_score = score_hand(COM);
        
        bool did_player1_win = rank_player_hand(player_score,COM_score);
        
        if (did_player1_win == false)
        { 
           //add pot
           COM.update_points(pot,"add"); 
           
           //reset pot
           pot = 0;
        }
        else 
        { 
           //add pot
           player1.update_points(pot,"add");
           
           //reset pot
           pot = 0;
        }
        
        //reset the hand
        player1.reset_hand();
        COM.reset_hand();
        
        //reset the deck
        myDeck.create_deck();
        myDeck.shuffle_deck();
         
    }
    
}
//Test the functions of the class
int main() {
    
    play_game();
    
    return 0;
}
