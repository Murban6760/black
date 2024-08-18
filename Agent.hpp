#ifndef AGENT_HPP_
#define AGENT_HPP_

#include "CardDeck.hpp"
#include "Dealer.hpp"
#include "Player.hpp"
#include "Strategy.hpp"
#include <vector>

class Agent
{

public:
    Agent();

    typedef struct StateInfo
    {
        int name = 0;
        double numActions = 0.0;
        int numVisits = 0;
        int cardAction = 0;
        int stateAction = 0;
        // double Qvec[4];

        // Constructor
        StateInfo() : name(0), numActions(4.0), numVisits(0), cardAction(0), stateAction(0) {};

        // Parameterized constructor
        StateInfo(int &cardName, double &cardActions, int &nV, int &cA, int &sA)
            : name(cardName), numActions(cardActions), numVisits(nV), cardAction(cA), stateAction(sA) {};
    } StateInfo;

    void loadStrat();
    void printStrat();
    void updateVisits(int i, int j);
    void writeStrat();

private:
    // int policy;
    // double qreward;

    std::vector<std::vector<StateInfo>> newStrat;
    int value;
    // double state;
    // double gamma; // discount factor
    // double ep; // exploration
    // double alpha;  // learning rate
};

#endif /*AGENT_HPP_*/
