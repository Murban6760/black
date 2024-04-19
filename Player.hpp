#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <vector>

#include "CardDeck.hpp"

class Player{

public:

    Player();

    double placeBet(int handID);

    void getCard(CardDeck &cardDeck);
    void getCard(int handID, CardDeck &cardDeck);

    double takeTurn(CardDeck &cardDeck, int handID);
    void clearHand();

    void displayHand(CardDeck &cardDeck);
    void displayHand(CardDeck &cardDeck, int handID);

    int getNumHands();
    int getValue(int handID);
    int getPlayFlag();
    int getPlayerWins();
    double getPlayerWallet();
    double getBet();
    double getBet(int handID);
    double betDown(int handID);

    void setPlayFlag(int flagValue);
    void setPlayerWins(int value);

    void insertHand(std::vector<int> &hand);
    void insertValue(int value);
    void insertBet(double value);

    void addToWallet(double money);

    void betClear();

private:
    double wallet;

    std::vector<std::vector<int>> hands;  
	
    double bet;
    std::vector<double> bets;

    int value;
    std::vector<int> values;

    int playFlag;
    int splitCount;
    int playerWins; 

};

#endif /* PLAYER_HPP_ */