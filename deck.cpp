//Made by Tanitoluwa Adebowale and Nathan Stodola

#include "deck.h"
#include "card.h"
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

Deck::Deck() {
    int count = 0;
    const int NUMSUITS = 4;
    const int NUMRANKS = 13;
    for(int i = 0; i < NUMSUITS; i++){
        for(int j = 0; j < NUMRANKS; j++){
            Card c(j+1, (Card::Suit)i);
            myCards[count] = c;
            count++;
        }
    }

    myIndex = 0;
}

void Deck::shuffle() {
    srand((unsigned)time(0));

    for(int i = 0; i < SIZE; i++) {
        int cardIndex1 = rand() % 52;
        int cardIndex2 = rand() % 52;
        Card temp = myCards[cardIndex1];
        myCards[cardIndex1] = myCards[cardIndex2];
        myCards[cardIndex2] = temp;
    }
}

Card Deck::dealCard() {
    Card cardGiven = myCards[myIndex];
    myIndex++;

    return cardGiven;
}

int Deck::size() const {
    return SIZE - myIndex;
}