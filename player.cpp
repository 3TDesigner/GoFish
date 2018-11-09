//Made by Tanitoluwa Adebowale and Nathan Stodola

#include "player.h"
#include "card.h"
#include "deck.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

Player::Player() {

}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);

    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

int Player::getHandSize() const {
    return myHand.size();
}

int Player::getBookSize() const {
    return myBook.size()/2;
}

bool Player::rankInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++){
        if(c.getRank() == myHand[i].getRank()){
            return true;
        }
    }
    return false;
}

Card Player::chooseCardFromHand() const {
    srand((unsigned)time(0));
    int cardIndex;
    if(getHandSize() != 0) {
        cardIndex = rand() % getHandSize();
    }else{
        cardIndex = 0;
    }

    return myHand[cardIndex];
}

bool Player::cardInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++){
        if(c == myHand[i]){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    int index;
    int count = 0;
    Card removedCard;

    for(int i = 0; i < myHand.size(); i++){
        if(c.getRank() == myHand[i].getRank()){
            index = count;
            removedCard = myHand[i];
            myHand.erase(myHand.begin() + index);
            return removedCard;
        }
        count++;
    }
    return c;
}

string Player::showHand() const {
    string hand = "";

    for(int i = 0; i < myHand.size(); i++){
        hand += myHand[i].toString();
        hand += " ";
    }

    return hand;
}


bool Player::checkHandForPair(Card &c1, Card &c2) {
    if(c1.getRank() == c2.getRank()){
        bookCards(c1,c2);
        return true;
    }
    return false;
}