#ifndef DEALER_HPP_
#define DEALER_HPP_

#include <vector>

#include "CardDeck.hpp"

class Dealer{

public:

    Dealer();

    void setFlag(int value);
    int getFlag();
    void getCard(CardDeck &cardDeck);
    void takeTurn(CardDeck &cardDeck);
    void clearHand();
    void displayHand(CardDeck &cardDeck);

    int getFaceValue(CardDeck &cardDeck);

    int getValue();

private:

    int dealerFlag;
	std::vector<int> hand;
	int value = 0;

};

#endif /* DEALER_HPP_ */