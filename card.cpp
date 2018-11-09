#include "card.h"
#include <string>
using namespace std;

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    return rankString(myRank) + suitString(mySuit);
}

bool Card::sameSuitAs(const Card &c) const {
    if(c.mySuit == mySuit){
        return true;
    }
    return false;
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Card::Suit s) const {
    string myCard;

    if(s == spades){
        myCard = "s";
    }else if(s == hearts){
        myCard =  "h";
    }else if(s == diamonds){
        myCard = "d";
    }else if(s == clubs){
        myCard = "c";
    }

    return myCard;
}

string Card::rankString(int r) const {
    string Ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    return Ranks[r-1];
}

bool Card::operator==(const Card &rhs) const {
    return(myRank == rhs.myRank && mySuit == rhs.mySuit);
}

bool Card::operator!=(const Card &rhs) const {
    return(myRank != rhs.myRank || mySuit != rhs.mySuit);
}

ostream& operator << (ostream& out, const Card& c){
    out << c.toString();
    return out;
}

