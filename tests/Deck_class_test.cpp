/*Test cases for testing the Deck class
 * 
 * How to use destructors and constructors:
 * https://www.daniweb.com/programming/software-development/threads/304160/why-we-use-destructor
 * 
 */

/* 
 * File:   newsimpletest.cpp
 * Author: Alan Ly
 *
 * Created on December 2, 2018, 12:37 PM
 */
/*
#include <stdlib.h>
#include <iostream>
#include <C:\Users\Alan Ly\Documents\NetBeansProjects\Blackjack_classes\Deck.hpp>
#include <C:\Users\Alan Ly\Documents\NetBeansProjects\Blackjack_classes\Player.hpp>
#define BOOST_TEST_MODULE Simple testcases
#include <boost/test/unit_test.hpp>

struct Fixture{
    
    //initializing pointer that point to the type: Deck
    Deck * point_to_current_deck;
    
    //constructor for test setup
    Fixture(){ 
        
    //pointer points to a constructor 
    point_to_current_deck = new Deck();
    
    //pointer invokes the create_deck function for the constructor
    point_to_current_deck->create_deck();
    
    //pointer invokes the shuffle_deck function for the constructor
    point_to_current_deck->shuffle_deck(); 
    }
    
    //destructor is invoked automatically at the end of each test case
    ~Fixture()
    {
        //destroy the constructor objects where the pointers were pointing
        delete point_to_current_deck;
        std::cout << "Object is being deleted" << endl;
    
    }
};

BOOST_AUTO_TEST_SUITE(suite1);

//test if 2 cards are dealt from the deck
BOOST_AUTO_TEST_CASE(test_deal_hand) {
  Fixture f;
  vector<string> temp = f.point_to_current_deck->deal_hand();
  BOOST_CHECK_EQUAL(temp.size(), 2);
}

//test if 1 card is drawn from deck
BOOST_AUTO_TEST_CASE(test_draw_card) {
    Fixture f;
    string temp = f.point_to_current_deck->draw_card();
    BOOST_CHECK_EQUAL(temp.length(), 1);
}

BOOST_AUTO_TEST_CASE(deck_size_deal_hand) {
    Fixture f;
    vector<string> temp = f.point_to_current_deck->deal_hand();
    vector<string> current_deck = f.point_to_current_deck->get_current_deck();
    BOOST_CHECK_EQUAL(current_deck.size(), 50);
}

BOOST_AUTO_TEST_CASE(deck_size_draw_card) {
    Fixture f;
    string temp = f.point_to_current_deck->draw_card();
    vector<string> current_deck = f.point_to_current_deck->get_current_deck();
    BOOST_CHECK_EQUAL(current_deck.size(), 51);
}

BOOST_AUTO_TEST_SUITE_END();

// EOF
 */


