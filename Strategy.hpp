#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

#include "CardDeck.hpp"
#include "Agent.hpp"
#include "Dealer.hpp"
#include "Player.hpp"
#include <vector>


class Strategy{
    
    public:

        Strategy();

        int getStrategy(int i, int j);

        void displayHand(CardDeck &cardDeck, int handID);
        double takeTurn(CardDeck &cardDeck, Agent &agent, Dealer &dealer, int handID);
        void setHand(int handID, Player &player, CardDeck &cardDeck);
        int getValue(int handID);
        int getDealerValue(Dealer &dealer);
        int getChoice(CardDeck &cardDeck, Dealer &dealer, int handID);
        void setPlayFlag(int flagValue);
        int getPlayFlag();
        int getNumHands();
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