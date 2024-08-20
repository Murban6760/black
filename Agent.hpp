#ifndef AGENT_HPP_
#define AGENT_HPP_

#include "CardDeck.hpp"
#include "Player.hpp"
#include "Dealer.hpp"
#include <vector>

class Agent{

public:
    Agent();

    typedef struct StateInfo
    {
        int name = 0;
        int numActions = 0;
        int numVisits = 0;
        int cardAction = 0;
        int learnedStrat = 0;
        double Qvec[4];

        // Constructor
        StateInfo() : name(0), numActions(4), numVisits(0), cardAction(0), learnedStrat(0), Qvec{0.0, 0.0, 0.0, 0.0} {};

        // Parameterized constructor
        StateInfo(int &cardName, int &cardActions, int &nV, int &cA, int &sA)
            : name(cardName), numActions(cardActions), numVisits(nV), cardAction(cA), learnedStrat(sA), Qvec{0.0, 0.0, 0.0, 0.0} {};
    } StateInfo;

    void loadStrat();
    void printStrat();
    void printElement(int i, int j);
    void updateVisits(int i, int j);
    void writeStrat();
    void updateQ(int k);

    void setHand(int handID, Player &player, Dealer &dealer, CardDeck &cardDeck);
    void displayHand(CardDeck &cardDeck, int handID);
    void getCard(int handID, Dealer &dealer, CardDeck &cardDeck);
    void clearHand();
    double takeTurn(CardDeck &cardDeck, Dealer &dealer, int handID);
    void clearValues();

    int getChoice(CardDeck &cardDeck, Dealer &dealer, int handID);
    int getDealerValue(Dealer &dealer);
    int getValue(int handID);
    int getNumHands();

    void setPlayFlag(int flagValue);
    int getPlayFlag();

    void loss();

private:
    std::vector<int> handHistory;
    std::vector<int> choiceHistory;
    std::vector<std::vector<int>> agentHands;
    std::vector<int> agentValues;
    
    std::vector<std::vector<StateInfo>> newStrat;

    int agentCount;
    int agentValue;
    int agentWins;
    int agentFlag;
};

#endif /*AGENT_HPP_*/
