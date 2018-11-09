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
    string myCard = "";
    const int CONVERT_INT = 48;

    if(myRank == 1){
        myCard += "A";
    }else if(myRank >= 2 && myRank <= 9){
        myCard += myRank + CONVERT_INT;
    }else if(myRank == 10){
        myCard += "10";
    }else if(myRank == 11){
        myCard += "J";
    }else if(myRank == 12){
        myCard += "Q";
    }else if(myRank == 13){
        myCard += "K";
    }

    if(mySuit == spades){
        myCard += "s";
    }else if(mySuit == hearts){
        myCard += "h";
    }else if(mySuit == diamonds){
        myCard += "d";
    }else if(mySuit == clubs){
        myCard += "c";
    }

    return myCard;
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
    string myCard = "";
    const int CONVERT_INT = 48;

    if(r == 1){
        myCard += "A";
    }else if(r >= 2 && r <= 10){
        myCard += myRank + CONVERT_INT;
    }else if(r == 10){
        myCard += "10";
    }else if(r == 11){
        myCard += "J";
    }else if(r == 12){
        myCard += "Q";
    }else if(r == 13){
        myCard += "K";
    }

    return myCard;
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

