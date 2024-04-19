#include "Strategy.hpp"
#include <iostream>

Strategy::Strategy():
    bet(0.0),
    value(0),
    splitCount(0),
    strategyWins(0)
{}



double Strategy::takeTurn(CardDeck &cardDeck, int handID)
{
    printf("Strategy Player(SP) Hand %d: SP is choosing...", handID + 1);

    std::cout << std::endl;

    
}

void Strategy::getCard(int handID, CardDeck &cardDeck)
{
    int card = cardDeck.getCard();
	std::vector<int> x = hands[handID];
    x.push_back(card);
    value = cardDeck.computePlayerValue(x);
    hands[handID] = x;
    values[handID] = value;
    cardDeck.displayHand("SP", hands, handID);
    }

int Strategy::getValue(int handID)
{
    return values[handID];
}

void Strategy::displayHand(CardDeck &cardDeck, int handID)
{
    cardDeck.displayHand("SP", hands, handID);
}

int Strategy::getChoice(int handID)
{
    
}