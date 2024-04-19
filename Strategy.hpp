#ifndef STRATEGY_HPP_
#define STRATEGY_HPP_

#include "CardDeck.hpp"
#include <vector>


class Strategy {
    
    public:

        Strategy();

        void displayHand(CardDeck &cardDeck, int handID);
        double takeTurn(CardDeck &cardDeck, int handID);
        void getCard(int handID, CardDeck &cardDeck);
        int getValue(int handID);
        int getChoice(int handID);

    private:
        std::vector<std::vector<int>> hands;

        double bet;
        std::vector<double> bets;

        int value;
        std::vector<int> values;

        int splitCount;
        int strategyWins;
        int choices[29][10]{
        /// 2 3 4 5 6 7 8 9 10 A
        /*17+*/    {2,2,2,2,2,2,2,2, 2,2},
        /*16*/    {2,2,2,2,2,1,1,1, 1,1},
        /*15*/    {2,2,2,2,2,1,1,1, 1,1},
        /*14*/     {2,2,2,2,2,1,1,1, 1,1},
        /*13*/     {2,2,2,2,2,1,1,1 ,1,1},
        /*12*/     {1,1,2,2,2,1,1,1,1,1},
        /*11*/     {4,4,4,4,4,4,4,4,4, 1},
        /*10*/     {4,4,4,4,4,4,4,4,1,1},
        /*9*/     {1,4,4,4,4,1,1,1,1,1},
        /*8*/     {1,1,1,1,1,1,1,1,1,1},
        /*7*/     {1,1,1,1,1,1,1,1,1,1},
        /*6*/     {1,1,1,1,1,1,1,1,1,1},
        /*5*/     {1,1,1,1,1,1,1,1,1,1},
        /*A + 8-10*/     {2,2,2,2,2,2,2,2,2,2},
        /*A 7*/     {2,4,4,4,4,2,2,1,1,1},
        /*A 6*/     {1,4,4,4,4,1,1,1,1,1},
        /*A 5*/     {1,1,4,4,4,1,1,1,1,1},
        /*A 4*/     {1,1,4,4,4,1,1,1,1,1},
        /*A 3*/     {1,1,1,4,4,1,1,1,1,1},
        /*A 2*/     {1,1,1,4,4,1,1,1,1,1},
        /*AA or 88*/     {3,3,3,3,3,3,3,3,3,3},
        /*10-10*/     {2,2,2,2,2,2,2,2,2,2},
        /*9-9*/     {3,3,3,3,3,2,3,3,2,2},
        /*7-7*/     {3,3,3,3,3,3,1,1,1,1},
        /*6-6*/     {3,3,3,3,3,1,1,1,1,1},
        /*5-5*/     {4,4,4,4,4,4,4,4,1,1},
        /*4-4*/     {1,1,1,3,3,1,1,1,1,1},
        /*3-3*/     {3,3,3,3,3,3,1,1,1,1},
        /*2-2*/     {3,3,3,3,3,3,1,1,1,1},
        };
};


#endif /*STRATEGY_HPP_*/