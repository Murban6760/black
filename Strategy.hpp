#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

#include "CardDeck.hpp"
#include "Dealer.hpp"
#include <vector>


class Strategy{
    
    public:

        Strategy();

        int getStrategy(int i, int j);

        void displayHand(CardDeck &cardDeck, int handID);
        double takeTurn(CardDeck &cardDeck, Dealer &dealer, int handID);

        int getHand(int handID, int index);
        int getValue(int handID);
        void insertHand(std::vector<int> &hand);

        int getDealerValue(Dealer &dealer);
        int getChoice(CardDeck &cardDeck, Dealer &dealer, int handID);
        void setPlayFlag(int flagValue);
        int getPlayFlag();
        int getNumHands();
        int getNumCards(int handID);
        void getCard(int handID, CardDeck &cardDeck);
        void clearHand();
        void clearValues();

        

    private:
        std::vector<std::vector<int>> stratHands;

        int stratValue;
        std::vector<int> stratValues;

        int stratFlag;
        int stratCount;
        int strategyWins;

};


#endif /*STRATEGY_HPP_*/