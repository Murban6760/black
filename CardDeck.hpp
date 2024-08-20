/* CARDDECK_HPP_ */
/*
 * CardDeck.hpp
 *
 *  Created on: Jun 29, 2023
 *      Author: Matt Urban
 */

#ifndef CARDDECK_HPP_
#define CARDDECK_HPP_
#define NUMDECKS 6
#include <map>
#include <random>
#include <string>
#include <chrono>

class CardDeck {

public:

	typedef struct Card
	{
		std::string name = " ";
		std::string suit = " ";
		int value = 0;

    	// Default constructor
    	Card() : name("  "), suit(" "),value(0) {};

    	// Parameterized constructor
    	Card(const std::string  &cardName, const std::string &cardSuit, int cardValue)
        	: name(cardName), suit(cardSuit),value(cardValue) {};

	} Card;

	CardDeck();

	void shuffleDeck();

	void setInverseCount();
	void displayHand(std::string name, std::vector<int> &hand, int offset, int display2);
	void displayHand(std::string name, std::vector<std::vector<int>> &hand, int handID);

	int computePlayerValue(std::vector<int> &hand);
	int computeDealerValue(std::vector<int> &hand);

	int getCard();
	int getDealerCard();
	int getStratCard();
	int getAgentCard();
	int getCardValue(int card);
	std::string getCardName(int card);

	int getCardCount();
	int getDeckCardCount();

private:

	std::vector<Card> cardDeck;

	int cardNum;
	int cardCount;
	int inverseCount;
	int inverseCount2;

	int cardOrder[52*NUMDECKS];

};

#endif /* CARDDECK_HPP_ */
