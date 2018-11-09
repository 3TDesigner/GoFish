//Made by Tanitoluwa Adebowale and Nathan Stodola
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;



// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);
void checkForPair(Player &p, std::ofstream &myFile);
int countPair(Player &p);
void playerTurn(Deck &d, Player &p1, Player&p2, std::ofstream &myFile);




int main( )
{
    const int NUMCARDS = 7;
    int initialPairs;
    ofstream myFile;
    Player p1("Joe");
    Player p2("Jane");
    Deck d;  //create a deck of cards

    myFile.open("gofish_results.txt");

    if(!myFile.is_open()){
        cout << "Something went wrong!" << endl;
        exit(0);
    }


    d.shuffle();

    dealHand(d, p1, NUMCARDS);
    dealHand(d, p2, NUMCARDS);

    myFile << p1.getName() <<" has : " << p1.showHand() << endl;
    myFile << p2.getName() <<" has : " << p2.showHand() << endl << endl;

    initialPairs = countPair(p1);
    for(int i = 0; i < initialPairs; i++){
        checkForPair(p1, myFile);
    }

    initialPairs = countPair(p2);
    for(int i = 0; i < initialPairs; i++){
        checkForPair(p2, myFile);
    }

    myFile << p1.getName() <<" has : " << p1.showHand() << endl;
    myFile << p2.getName() <<" has : " << p2.showHand() << endl << endl;


    //MAIN ALGORITHM
    while(d.size() != 0 || (p1.getHandSize() != 0 && p2.getHandSize() != 0)){
        /*
        *******************
        * PLAYER 1'S TURN *
        *******************
        */

        playerTurn(d,p1,p2,myFile);
        myFile << p1.getName() <<" has : " << p1.showHand() << endl;
        myFile << p2.getName() <<" has : " << p2.showHand() << endl << endl;

        /*
       *******************
       * PLAYER 2'S TURN *
       *******************
       */

        playerTurn(d,p2,p1,myFile);
        myFile << p1.getName() <<" has : " << p1.showHand() << endl;
        myFile << p2.getName() <<" has : " << p2.showHand() << endl << endl;
    }


    if(p1.getHandSize() != 0){
        while(p1.getHandSize() != 0){
            checkForPair(p1,myFile);
        }
    }

    if(p2.getHandSize() != 0){
        while(p2.getHandSize() != 0){
            checkForPair(p2,myFile);
        }
    }


    myFile << "PLAYER 1 HAS " << p1.getBookSize() << " PAIRS" << endl;
    myFile << "PLAYER 2 HAS " << p2.getBookSize() << " PAIRS" << endl;

    if((p1.getHandSize() + p1.getBookSize()) > (p2.getHandSize() + p2.getBookSize())){
        myFile << "PLAYER 1 WINS!" << endl;
    }else if ((p1.getHandSize() + p1.getBookSize()) < (p2.getHandSize() + p2.getBookSize())){
        myFile << "PLAYER 2 WINS!" << endl;
    }else{
        myFile << "ITS A TIE!" << endl;
    }

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

void checkForPair(Player &p, std::ofstream &myFile){
    for(int i = 0; i < p.showHand().size(); i = i+3){
        for(int j = 0; j < p.showHand().size(); j = j+3){
            int rank1;
            int rank2;
            int suit1;
            int suit2;

            if(p.showHand()[i] == '1'){
                i++;
            }
            if(p.showHand()[j] == '1'){
                j++;
            }
            if(p.showHand()[i] == p.showHand()[j] && p.showHand()[i+1] != p.showHand()[j+1]){
                if((int)p.showHand()[i] - '0' > 10 || (int)p.showHand()[i] - '0' < 2){
                    if(p.showHand()[i] == 'A'){
                        rank1 = 1;
                    }else if(p.showHand()[i] == '0'){
                        rank1 = 10;
                    }else if(p.showHand()[i] == 'J'){
                        rank1 = 11;
                    }else if(p.showHand()[i] == 'Q'){
                        rank1 = 12;
                    }else if(p.showHand()[i] == 'K'){
                        rank1 = 13;
                    }
                }else{
                    rank1 = (int)p.showHand()[i] - '0';
                }

                if((int)p.showHand()[j] - '0' > 10 || (int)p.showHand()[j] - '0' < 2){
                    if(p.showHand()[j] == 'A'){
                        rank2 = 1;
                    }else if(p.showHand()[j] == '0'){
                        rank2 = 10;
                    }else if(p.showHand()[j] == 'J'){
                        rank2 = 11;
                    }else if(p.showHand()[j] == 'Q'){
                        rank2 = 12;
                    }else if(p.showHand()[j] == 'K'){
                        rank2 = 13;
                    }
                }else{
                    rank2 = (int)p.showHand()[j] - '0';
                }

                if(p.showHand()[i+1] == 's'){
                    suit1 = 0;
                }else if(p.showHand()[i+1] == 'c'){
                    suit1 = 3;
                }else if(p.showHand()[i+1] == 'd'){
                    suit1 = 2;
                }else if(p.showHand()[i+1] == 'h'){
                    suit1 = 1;
                }

                if(p.showHand()[j+1] == 's'){
                    suit2 = 0;
                }else if(p.showHand()[j+1] == 'c'){
                    suit2 = 3;
                }else if(p.showHand()[j+1] == 'd'){
                    suit2 = 2;
                }else if(p.showHand()[j+1] == 'h'){
                    suit2 = 1;
                }

                Card bookCard1(rank1,(Card::Suit)suit1);
                Card bookCard2(rank2,(Card::Suit)suit2);
                p.bookCards(bookCard1, bookCard2);
                myFile << p.getName() << " books " << bookCard1.toString() << " and " << bookCard2.toString()  << endl << endl;
            }
        }
    }
}

int countPair(Player &p){
    int count = 0;
    for(int i = 0; i < p.showHand().size(); i = i+3){
        for(int j = 0; j < p.showHand().size(); j = j+3){
            if(p.showHand()[i] == '1'){
                i++;
            }
            if(p.showHand()[j] == '1'){
                j++;
            }
            if(p.showHand()[i] == p.showHand()[j] && p.showHand()[i+1] != p.showHand()[j+1]){
                count++;
            }
        }
    }
    return count;
}

void playerTurn(Deck &d, Player &p1, Player &p2, std::ofstream &myFile){
    Card pickedCard = p1.chooseCardFromHand();
    myFile << p1.getName() << " asks - Do you have a " << pickedCard.rankString(pickedCard.getRank()) << "?"
         << endl;

    //Enters while loop if player 2 has the rank player 1 wants
    while (p2.rankInHand(pickedCard)) {
        myFile << p2.getName() << " says - Yes. I have a " << pickedCard.rankString(pickedCard.getRank()) << "."
             << endl;
        Card removedCard = p2.removeCardFromHand(pickedCard);
        p1.addCard(removedCard);
        p1.bookCards(pickedCard, removedCard);
        myFile << p1.getName() << " books the " << pickedCard.toString() << " and " << removedCard.toString() << endl << endl;
        pickedCard = p1.chooseCardFromHand();
        myFile << p1.getName() << " asks - Do you have a " << pickedCard.rankString(pickedCard.getRank()) << "?"
             << endl;
    }
    //Enters if statement if player 2 does not have the card
    if (!p2.rankInHand(pickedCard)) {
        myFile << p2.getName() << " says - Go Fish" << endl;
        if(d.size() != 0) {
            Card drawedCard = d.dealCard();
            p1.addCard(drawedCard);
            myFile << p1.getName() << " draws " << drawedCard.toString() << endl << endl;
            checkForPair(p1,myFile);
        }
    }

}

