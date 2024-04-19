#include "CardDeck.hpp"

#include <string>
#include <iostream>

CardDeck::CardDeck():
	cardNum(52 * NUMDECKS),
	cardCount(0)
{
	
	cardDeck.push_back(Card {"A", "H", 11});
	cardDeck.push_back(Card {"A", "D", 11});
	cardDeck.push_back(Card {"A", "S", 11});
	cardDeck.push_back(Card {"A", "C", 11});

	cardDeck.push_back(Card {"2", "H", 2});
	cardDeck.push_back(Card {"2", "D", 2});
	cardDeck.push_back(Card {"2", "S", 2});
	cardDeck.push_back(Card {"2", "C", 2});

	cardDeck.push_back(Card {"3", "H", 3});
	cardDeck.push_back(Card {"3", "D", 3});
	cardDeck.push_back(Card {"3", "S", 3});
	cardDeck.push_back(Card {"3", "C", 3});

	cardDeck.push_back(Card {"4", "H", 4});
	cardDeck.push_back(Card {"4", "D", 4});
	cardDeck.push_back(Card {"4", "S", 4});
	cardDeck.push_back(Card {"4", "C", 4});

	cardDeck.push_back(Card {"5", "H", 5});
	cardDeck.push_back(Card {"5", "D", 5});
	cardDeck.push_back(Card {"5", "S", 5});
	cardDeck.push_back(Card {"5", "C", 5});

	cardDeck.push_back(Card {"6", "H", 6});
	cardDeck.push_back(Card {"6", "D", 6});
	cardDeck.push_back(Card {"6", "S", 6});
	cardDeck.push_back(Card {"6", "C", 6});

	cardDeck.push_back(Card {"7", "H", 7});
	cardDeck.push_back(Card {"7", "D", 7});
	cardDeck.push_back(Card {"7", "S", 7});
	cardDeck.push_back(Card {"7", "C", 7});

	cardDeck.push_back(Card {"8", "H", 8});
	cardDeck.push_back(Card {"8", "D", 8});
	cardDeck.push_back(Card {"8", "S", 8});
	cardDeck.push_back(Card {"8", "C", 8});

	cardDeck.push_back(Card {"9", "H", 9});
	cardDeck.push_back(Card {"9", "D", 9});
	cardDeck.push_back(Card {"9", "S", 9});
	cardDeck.push_back(Card {"9", "C", 9});

	cardDeck.push_back(Card {"10", "H", 10});
	cardDeck.push_back(Card {"10", "D", 10});
	cardDeck.push_back(Card {"10", "S", 10});
	cardDeck.push_back(Card {"10", "C", 10});

	cardDeck.push_back(Card {"J", "H", 10});
	cardDeck.push_back(Card {"J", "D", 10});
	cardDeck.push_back(Card {"J", "S", 10});
	cardDeck.push_back(Card {"J", "C", 10});

	cardDeck.push_back(Card {"Q", "H", 10});
	cardDeck.push_back(Card {"Q", "D", 10});
	cardDeck.push_back(Card {"Q", "S", 10});
	cardDeck.push_back(Card {"Q", "C", 10});

	cardDeck.push_back(Card {"K", "H", 10});
	cardDeck.push_back(Card {"K", "D", 10});
	cardDeck.push_back(Card {"K", "S", 10});
	cardDeck.push_back(Card {"K", "C", 10});

	cardDeck.push_back(Card {"A", "H", 1});
	cardDeck.push_back(Card {"A", "D", 1});
	cardDeck.push_back(Card {"A", "S", 1});
	cardDeck.push_back(Card {"A", "C", 1});

    for (int i = 0; i < cardNum; i++) {
		cardOrder[i] = i;
	}
}

void CardDeck::shuffleDeck()
{
	std::random_device rd;
	auto seed = static_cast<unsigned long>(rd()) ^ static_cast<unsigned long>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::mt19937 rng(seed);

    // This generates a uniform random integer between 0 and cardMax

    // Rest of shuffle algorithm
    for (int i = (cardNum - 1); i > 0; i--){

    	std::uniform_int_distribution<int> uniformNum(0, i);
    	int j = uniformNum(rng);

    	int temp = cardOrder[i];
    	cardOrder[i] = cardOrder[j];
    	cardOrder[j] = temp;

    }
}

int CardDeck::getCard()
{
    int card;
    card = cardOrder[cardCount] % 52;
    cardCount++;

    return card;
}

std::string CardDeck::getCardName(int card)
{
	return cardDeck[card].name;
}


void CardDeck::displayHand(std::string name, std::vector<int> &hand, int offset, int display2)
{
	std::cout << name << ": ";

	for (int j = 0; j < hand.size() - offset; j++) {
		std::cout << cardDeck[hand[j]].name << " ";
	}

	std::cout << std::endl << std::endl;
}

void CardDeck::displayHand(std::string name, std::vector<std::vector<int>> &hand, int handID)
{
	std::vector<int> x = hand[handID];
	std::cout << name << " Hand " << handID + 1 << ": ";

	for (int j = 0; j < x.size(); j++) {
		std::cout << cardDeck[x[j]].name << " ";
	}

	std::cout << std::endl << std::endl;
}

int CardDeck::computePlayerValue(std::vector<int> &hand)
{
	int value = 0;

	int aceIndx = -1;

	for (int i=0; i < hand.size(); i++)
	{
		if (hand[i] < 4 && aceIndx == -1)
		{
			aceIndx = i;
		}

		//value = value + cardValues[hand[i]];
		value = value + cardDeck[hand[i]].value;

		if (value > 21 && aceIndx != -1)
		{
			hand[aceIndx] = hand[aceIndx] + 52;
			value = value - 10;
		}
	}

	return value;
}

int CardDeck::computeDealerValue(std::vector<int> &hand)
{
	int value = 0;
	for (int i=0; i < hand.size(); i++)
	{

		value = value + cardDeck[hand[i]].value;

	}

	return value;
}

int CardDeck::getCardValue(int card)
{
    return cardDeck[card].value;
}

int CardDeck::getCardCount()
{
    return cardCount;
}

int CardDeck::getDeckCardCount()
{
    return cardNum - cardCount;
}