/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player_class_test.cpp
 * Author: Alan Ly
 *
 * Created on December 2, 2018, 4:54 PM
 */


#include <stdlib.h>
#include <iostream>
#include <C:\Users\Alan Ly\Documents\NetBeansProjects\Blackjack_classes\Deck.hpp>
#include <C:\Users\Alan Ly\Documents\NetBeansProjects\Blackjack_classes\Player.hpp>
#define BOOST_TEST_MODULE Simple testcases 2
#include <boost/test/unit_test.hpp>

struct Fixture{
    
    //initializing pointer that point to the type: Deck
    Deck * point_to_current_deck;
    
    //initializing pointer that points to the type: Player
    Player * point_to_current_player;
    
    //constructor for test setup
    Fixture(){ 
        
    //pointer points to a constructor 
    point_to_current_deck = new Deck();
    point_to_current_player = new Player();
    
    //pointer invokes the create_deck function for the constructor
    point_to_current_deck->create_deck();
    
    //pointer invokes the shuffle_deck function for the constructor
    point_to_current_deck->shuffle_deck(); 
    }
    
    //destructor is invoked automatically at the end of each test case
    ~Fixture()
    {
        //destroy the constructor objects where the pointers were pointing
        delete point_to_current_deck,point_to_current_player;
        std::cout << "Object is being deleted" << endl;
    
    }
};

BOOST_AUTO_TEST_SUITE(suite1);

//test if 2 cards are dealt from the deck
BOOST_AUTO_TEST_CASE(set_hand_1) {
  Fixture f;
  f.point_to_current_player->set_hand(f.point_to_current_deck->deal_hand());
  BOOST_CHECK_EQUAL(f.point_to_current_player->get_hand().size(), 2);
}

//test if 1 card is drawn from deck
BOOST_AUTO_TEST_CASE(set_hand_2) {
    Fixture f;
    f.point_to_current_player->set_hand({"A","2","6", "9","A"});
    BOOST_CHECK_EQUAL(f.point_to_current_player->get_hand().size(), 5);
}

BOOST_AUTO_TEST_CASE(reset_hand) {
    Fixture f;
    f.point_to_current_player->set_hand(f.point_to_current_deck->deal_hand());
    f.point_to_current_player->reset_hand();
    BOOST_CHECK_EQUAL(f.point_to_current_player->get_hand().size(), 0);
}

BOOST_AUTO_TEST_CASE(update_hand) {
    Fixture f;
    f.point_to_current_player->set_hand({"A","B","C"});
    f.point_to_current_player->update_hand("A");
    BOOST_CHECK_EQUAL(f.point_to_current_player->get_hand().size(),3);
}

BOOST_AUTO_TEST_CASE(set_inital_score_1) {
    Fixture f;
    f.point_to_current_player->set_initial_points(500);
    BOOST_CHECK_EQUAL(f.point_to_current_player->get_points(),500);
}

BOOST_AUTO_TEST_CASE(update_score_1) {
    Fixture f;
    f.point_to_current_player->update_points(200,"add");
    BOOST_CHECK_EQUAL(f.point_to_current_player->get_points(),500);
}

BOOST_AUTO_TEST_CASE(reset_score_1) {
    Fixture f;
    f.point_to_current_player->update_points(200,"add");
    f.point_to_current_player->reset_points();
    BOOST_CHECK_EQUAL(f.point_to_current_player->get_points(),0);
}

BOOST_AUTO_TEST_SUITE_END();

BOOST_AUTO_TEST_SUITE(suite2);

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

//EOF