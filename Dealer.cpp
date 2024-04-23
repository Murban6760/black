#include "Dealer.hpp"

#include <iostream>

Dealer::Dealer():
    value(0)
{}

void Dealer::getCard(CardDeck &cardDeck)
{
    int handSize = hand.size();

    int card = cardDeck.getDealerCard();
	hand.push_back(card);

    value = cardDeck.computePlayerValue(hand);
    
    if (handSize == 1)
        cardDeck.displayHand("Dealer", hand, 1, 1);  
    else
        cardDeck.displayHand("Dealer", hand, 0, 1);  

}

void Dealer::takeTurn(CardDeck &cardDeck)
{
   		displayHand(cardDeck);

		while (getValue() < 17)
		{

			getCard(cardDeck);

			if (getValue() > 21)
			{
				std::cout << "Dealer busted!" << std::endl;
			}
		}
}

void Dealer::clearHand()
{
    hand.clear();
}

void Dealer::displayHand(CardDeck &cardDeck)
{
    cardDeck.displayHand("Dealer", hand, 0, 1);
}

int Dealer::getValue()
{
    return value;
}

int Dealer::getFaceValue(CardDeck &cardDeck)
{
    return cardDeck.getCardValue(hand[0]);
}