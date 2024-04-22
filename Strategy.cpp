#include "Strategy.hpp"
#include <iostream>

Strategy::Strategy():
    stratFlag(1),
    stratValue(0),
    stratCount(0),
    strategyWins(0)
{}


const double strategy[52][10]{
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
       3,3,3,3,3,3,3,3,3, 3, // Pairs-A
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
       1,1,1,1,1,1,1,1,1, 1, // Val 6 >2 cards
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

void Strategy::setPlayFlag(int flagValue)
{
    stratFlag = flagValue;
}

int Strategy::getPlayFlag()
{
    return stratFlag;
}

void Strategy::setHand(int handID, Player &player, CardDeck &cardDeck)
{
    for (int j = 0; j < player.g
    stratValue = cardDeck.computePlayerValue(stratHands[handID]);
    stratValues[handID] = stratValue;
    cardDeck.displayHand("SP", stratHands, handID);
}

double Strategy::takeTurn(CardDeck &cardDeck, Dealer &dealer, int handID)
{
    printf("Strategy Player(SP) Hand %d: SP is choosing...", handID + 1);
    int action = strategy[getChoice(cardDeck, dealer, handID)%100][getChoice(cardDeck, dealer, handID)/100];
    std::cout << std::endl;
    switch(action)
    {
    case 1:
        getCard(handID, cardDeck);

        if (getValue(handID) >= 22)
        {
            printf("SP Busted! \n \n");
            
            return 0;
        }
        else 
            return 1;
        break;
    case 2:
    {

        cardDeck.displayHand("SP", stratHands, handID);
        setPlayFlag(0);

        return 0;
        break;
    }
    case 3:
    {
        if (cardDeck.getCardName(stratHands[handID][0]) == cardDeck.getCardName(stratHands[handID][1]))
        {
            stratCount += 1;
            std::vector<int> hand2;
            int x = stratHands[handID][1];
            int y = getValue(handID)/2;
            hand2.push_back(x);
            stratHands[handID].erase(stratHands[handID].begin() + 1);
            stratHands.push_back(hand2);
            hand2.clear();
            stratValues[handID] = y;
            stratValues.push_back(y);
            cardDeck.displayHand("SP", stratHands, 1);
            return 0;
        }
        else
        {
            std::cout << "Error: No matching cards; Unable to split. " << std::endl;
            std::cout << std::endl;
            cardDeck.displayHand("SP", stratHands, 0);
            std::cout << std::endl;
            return 0;
        }
        std::cout << "--------------------------" << std::endl << std::endl;
        break;
    }
    case 4:
    {
        getCard(handID, cardDeck);

        return 0;
        break;
    }
    default:
    {
    std::cout << "SP has made an error, or something has gone wrong..." << std::endl;
    return 1;
    break;
    }
    }

    
}


int Strategy::getValue(int handID)
{
    return stratValues[handID];
}

int Strategy::getNumHands()
{
    return stratHands.size();
}

void Strategy::displayHand(CardDeck &cardDeck, int handID)
{
    cardDeck.displayHand("SP", stratHands, handID);
}

int Strategy::getDealerValue(Dealer &dealer)
{
    return dealer.getValue();
}

int Strategy::getChoice(CardDeck &cardDeck, Dealer &dealer,int handID)
{
    if (stratHands.size() > 2)
    {
        int x = getValue(handID) + 29 + (getDealerValue(dealer)* 100);
        return x;
    } else if (cardDeck.getCardName(stratHands[handID][0]) == "A" || cardDeck.getCardName(stratHands[handID][1]) == "A") 
    {
        int x = getValue(handID) + 6 + (getDealerValue(dealer)* 100);
        return x;
    } else if (cardDeck.getCardName(stratHands[handID][0]) == cardDeck.getCardName(stratHands[handID][1])) 
    {
        int x = (getValue(handID)/2) + 28 + (getDealerValue(dealer)* 100);
        return x;
    } else 
    {
        int x = getValue(handID) + (getDealerValue(dealer)* 100);
        return x;
    }
}

void Strategy::clearHand()
{
    stratHands.clear();
}

