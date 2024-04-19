#ifndef DEALER_HPP_
#define DEALER_HPP_

#include <vector>

#include "CardDeck.hpp"

class Dealer{

public:

    Dealer();

    void getCard(CardDeck &cardDeck);
    void takeTurn(CardDeck &cardDeck);
    void clearHand();
    void displayHand(CardDeck &cardDeck);

    int getValue();

private:

	std::vector<int> hand;
	int value = 0;

};

#endif /* DEALER_HPP_ */