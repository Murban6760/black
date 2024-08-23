#ifndef AGENT_HPP_
#define AGENT_HPP_

#include "CardDeck.hpp"
#include "Strategy.hpp"
#include "Dealer.hpp"
#include <vector>

class Agent{

public:
    Agent();

    typedef struct StateInfo
    {
        int name = 0;
        int numActions[3];
        int numVisits[4];
        int cardAction = 0;
        int learnedStrat = 0;
        double epsilon = 0.5;
        double Qvec[4];

        // Constructor
        StateInfo() : name(0), numActions{0, 0, 0}, numVisits{0, 0, 0, 0}, cardAction(0), learnedStrat(0), epsilon(0.5), Qvec{0.0, 0.0, 0.0, 0.0} {};

        // Parameterized constructor
        StateInfo(int &cardName, int &cA1, int &cA2, int &cA3, int &nV1, int &nV2, int &nV3, int &nV4, int &cA, int &sA)
            : name(cardName), numActions{cA1, cA2, cA3}, numVisits{nV1, nV2, nV3, nV4}, cardAction(cA), learnedStrat(sA), epsilon(0.5), Qvec{0.0, 0.0, 0.0, 0.0} {};
    } StateInfo;

    void loadStrat();
    void printStrat();
    void printElement(int i, int j);
    void updateVisits(int i, int j, int n);
    void writeStrat();
    void updateQ(int k);

    void setHand(int handID, Strategy &strategy, Dealer &dealer, CardDeck &cardDeck);
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

    int getEpsilon(int x);
    int qChoice(int x);

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
