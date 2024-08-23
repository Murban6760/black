#include "Strategy.hpp"
#include <iostream>

Strategy::Strategy():
    stratFlag(1),
    stratValue(0),
    stratCount(1),
    strategyWins(0)
{
    stratHands.resize(1);
    stratValues.resize(1);
}


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
       2,2,2,2,2,2,2,2,2, 2 // 21 > 2 cards
}; 

int Strategy::getStrategy(int i, int j)
{
    return strategy[i][j];
}

void Strategy::setPlayFlag(int flagValue)
{
    stratFlag = flagValue;
}

int Strategy::getPlayFlag()
{
    return stratFlag;
}

int Strategy::getHand(int handID, int index)
{
    return stratHands[handID][index];
}

void Strategy::insertHand(std::vector<int> &hand) 
{
    stratHands[0] = hand;
}

int Strategy::getNumCards(int handID)
{
    return stratHands[handID].size();
}

/*
void Strategy::setHand(int handID, Player &player, CardDeck &cardDeck)
{
    for (int j = 0; j < player.getNumCards(handID); j++)
    {
        stratHands[handID].push_back(player.getHand(handID, j));
    }
    ///
    stratValue = cardDeck.computePlayerValue(stratHands[handID]);
    stratValues[handID] = stratValue;
    cardDeck.displayHand("SP", stratHands, handID);

}*/

void Strategy::getCard(int handID, CardDeck &cardDeck)
{
    int card = cardDeck.getCard();
	std::vector<int> x = stratHands[handID];
    x.push_back(card);
    stratValue = cardDeck.computePlayerValue(x);
    stratHands[handID] = x;
    stratValues[handID] = stratValue;
    cardDeck.displayHand("SP", stratHands, handID);
}

double Strategy::takeTurn(CardDeck &cardDeck, Dealer &dealer, int handID)
{
    printf("Strategy Player(SP) Hand %d: SP is choosing...", handID + 1);
    //int i = getChoice(cardDeck, dealer, handID)%100;
    //int j = getChoice(cardDeck, dealer, handID)/100;
    int action = strategy[getChoice(cardDeck, dealer, handID)%100][getChoice(cardDeck, dealer, handID)/100]; // i = getChoice(cardDeck, dealer, handID)%100 | j =getChoice(cardDeck, dealer, handID)/100
    ///agent.updateVisits(i, j);
    std::cout << "SP chooses " << action  << " " << getChoice(cardDeck, dealer, handID) << ", SP has a value of " << getValue(handID) << std::endl;
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
            hand2.push_back(x);
            //
            stratHands.resize(stratCount);
            stratValues.resize(stratCount);
            stratHands[handID].erase(stratHands[handID].begin() + 1);
            stratHands[stratCount-1] = hand2;
            hand2.clear();
            getCard(handID, cardDeck);
            getCard(stratCount-1, cardDeck);
            stratValues[handID] = cardDeck.computePlayerValue(stratHands[handID]);
            stratValues[stratCount-1] = cardDeck.computePlayerValue(stratHands[stratCount-1]);
            cardDeck.displayHand("SP", stratHands, handID);
            cardDeck.displayHand("SP", stratHands, stratCount-1);
            return 0;
        }
        else
        {
            std::cout << "Error: No matching cards; Unable to split. " << std::endl;
            std::cout << std::endl;
            cardDeck.displayHand("SP", stratHands, 0);
            std::cout << std::endl;
            return 0;
            break; /// REMOVE WHEN FIXED
        }
        std::cout << "--------------------------" << std::endl << std::endl;
        break;
    }
    case 4:
    {
        setPlayFlag(0);
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
    std::vector<int> hand = stratHands[handID];
    if (hand.size() > 2)
    {
        int x = getValue(handID) + 30 + ((dealer.getFaceValue(cardDeck)-2)* 100);
        return x;
    } else if (cardDeck.getCardName(hand[0]) == "A" || cardDeck.getCardName(hand[1]) == "A") 
    {  
        if (cardDeck.getCardName(hand[0]) == cardDeck.getCardName(hand[1]))
        {
            int x = 17 + ((dealer.getFaceValue(cardDeck)-2)* 100);
        }
        int x = getValue(handID) + 5 + ((dealer.getFaceValue(cardDeck)-2)* 100);
        return x;
    } else if (cardDeck.getCardName(hand[0]) == cardDeck.getCardName(hand[1])) 
    {
        int x = (getValue(handID)/2) + 25 + ((dealer.getFaceValue(cardDeck)-2)* 100);
        return x;
    } else 
    {
        int x = getValue(handID) - 5 + ((dealer.getFaceValue(cardDeck)-2)* 100);
        return x;
    }
}

void Strategy::clearHand()
{
    stratHands.resize(1);
    stratHands.clear();
    stratHands.resize(1);
}

void Strategy::clearValues()
{
    stratValues.resize(1);
    stratValues.clear();
    stratValues.resize(1);
    stratCount = 1;
}

