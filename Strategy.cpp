#include "Strategy.hpp"
#include <iostream>
#include "Dealer.hpp"

const double strategy[53][10]{
    // 2 3 4 5 6 7 8 9 10 A
       1,1,1,1,1,1,1,1,1, 1, // Val 5
       1,1,1,1,1,1,1,1,1, 1, // Val 6
       1,1,1,1,1,1,1,1,1, 1, // Val 7
       1,1,1,1,1,1,1,1,1, 1, // Val 8
       1,4,4,4,4,1,1,1,1, 1, // Val 9
       4,4,4,4,4,4,4,4,1, 1, // Val 10
       4,4,4,4,4,4,4,4,4, 1, // Val 11
       1,1,2,2,2,1,1,1,1, 1, // Val 12
       2,2,2,2,2,1,1,1,1, 1, // Val 13
       2,2,2,2,2,1,1,1,1, 1, // Val 14
       2,2,2,2,2,1,1,1,1, 1, // Val 15
       2,2,2,2,2,1,1,1,1, 1, // Val 16
       2,2,2,2,2,2,2,2,2, 2, // 17
       2,2,2,2,2,2,2,2,2, 2, // 18
       2,2,2,2,2,2,2,2,2, 2, // 19
       2,2,2,2,2,2,2,2,2, 2, // 20
       2,2,2,2,2,2,2,2,2, 2, // 21
       1,1,1,4,4,1,1,1,1, 1, // A + 2
       1,1,1,4,4,1,1,1,1, 1, // A + 3
       1,1,4,4,4,1,1,1,1, 1, // A + 4
       1,1,4,4,4,1,1,1,1, 1, // A + 5
       1,4,4,4,4,1,1,1,1, 1, // A + 6
       2,4,4,4,4,2,2,1,1, 1, // A + 7
       2,2,2,2,2,2,2,2,2, 2, // A + 8
       2,2,2,2,2,2,2,2,2, 2, // A + 9
       2,2,2,2,2,2,2,2,2, 2, // A + 10
       3,3,3,3,3,3,1,1,1, 1, // Pairs of 2
       3,3,3,3,3,3,1,1,1, 1, // P-3
       1,1,1,3,3,1,1,1,1, 1, // P-4
       3,3,3,3,3,3,3,3,1, 1, // P-5
       3,3,3,3,3,1,1,1,1, 1, // P-6
       3,3,3,3,3,3,1,1,1, 1, // P-7
       3,3,3,3,3,3,3,3,3, 3, // P-8
       3,3,3,3,3,2,3,3,2, 2, // P-9
       2,2,2,2,2,2,2,2,2, 2, // P-10
       3,3,3,3,3,3,3,3,3, 3, // P-A
       1,1,1,1,1,1,1,1,1, 1, // Val 6 > 2 cards
       1,1,1,1,1,1,1,1,1, 1, // Val 7 > 2 cards
       1,1,1,1,1,1,1,1,1, 1, // Val 8 > 2 cards
       1,4,4,4,4,1,1,1,1, 1, // Val 9 > 2 cards
       4,4,4,4,4,4,4,4,1, 1, // Val 10 > 2 cards
       4,4,4,4,4,4,4,4,4, 1, // Val 11 > 2 cards
       1,1,2,2,2,1,1,1,1, 1, // Val 12 > 2 cards
       2,2,2,2,2,1,1,1,1, 1, // Val 13 > 2 cards
       2,2,2,2,2,1,1,1,1, 1, // Val 14 > 2 cards
       2,2,2,2,2,1,1,1,1, 1, // Val 15 > 2 cards
       2,2,2,2,2,1,1,1,1, 1, // Val 16  > 2 cards
       2,2,2,2,2,2,2,2,2, 2, // 17 > 2 cards
       2,2,2,2,2,2,2,2,2, 2, // 18 > 2 cards
       2,2,2,2,2,2,2,2,2, 2, // 19 > 2 cards
       2,2,2,2,2,2,2,2,2, 2, // 20 > 2 cards
       2,2,2,2,2,2,2,2,2, 2, // 21 > 2 cards
};

Strategy::Strategy():
    playFlag(1),
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

int Strategy::getDealerValue(Dealer &dealer)
{
    return dealer.getValue();
}

int Strategy::getChoice(CardDeck &cardDeck, Dealer &dealer,int handID)
{
    if (hands.size() > 2)
    {
        int x = getValue(handID) + 36 + (getDealerValue(dealer)* 100);
        return x;
    } else if (cardDeck.getCardName(hands[handID][0]) == cardDeck.getCardName(hands[handID][1])) 
    {
        int x = getValue(handID) + 17 + (getDealerValue(dealer)* 100);
        return x;
    } else if (cardDeck.getCardName(hands[handID][0]) == "A" || cardDeck.getCardName(hands[handID][1]) == "A") 
    {
        
    } else 
    {

    }
}