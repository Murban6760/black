#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

#include "CardDeck.hpp"
#include "Dealer.hpp"
#include <vector>


class Strategy {
    
    public:

        Strategy();

        void displayHand(CardDeck &cardDeck, int handID);
        double takeTurn(CardDeck &cardDeck, Dealer &dealer, int handID);
        void getCard(int handID, CardDeck &cardDeck);
        int getValue(int handID);
        int getDealerValue(Dealer &dealer);
        int getChoice(CardDeck &cardDeck, Dealer &dealer, int handID);
        void setPlayFlag(int flagValue);
        int getPlayFlag();
        int getNumHands();
        void clearHand();

    private:
        std::vector<std::vector<int>> hands;

        int value;
        std::vector<int> values;

        int playFlag;
        int splitCount;
        int strategyWins;

};


#endif /*STRATEGY_HPP_*/