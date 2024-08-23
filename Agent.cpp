#include "Agent.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
/* Previous implementation that grabbed the determined strategy from a sheet
int strategy[52][10]{
 // 2  3  4  5  6  7  8  9  10 A
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 5
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 6
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 7
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 8
	1, 4, 4, 4, 4, 1, 1, 1, 1, 1, // Val 9
	4, 4, 4, 4, 4, 4, 4, 4, 1, 1, // Val 10
	4, 4, 4, 4, 4, 4, 4, 4, 4, 1, // Val 11
	1, 1, 2, 2, 2, 1, 1, 1, 1, 1, // Val 12
	2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 13
	2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 14
	2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 15
	2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 16
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 17
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 18
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 19
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 20
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 21
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // Pairs-A
	1, 1, 1, 4, 4, 1, 1, 1, 1, 1, // A + 2
	1, 1, 1, 4, 4, 1, 1, 1, 1, 1, // A + 3
	1, 1, 4, 4, 4, 1, 1, 1, 1, 1, // A + 4
	1, 1, 4, 4, 4, 1, 1, 1, 1, 1, // A + 5
	1, 4, 4, 4, 4, 1, 1, 1, 1, 1, // A + 6
	2, 4, 4, 4, 4, 2, 2, 1, 1, 1, // A + 7
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // A + 8
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // A + 9
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // A + 10
	3, 3, 3, 3, 3, 3, 1, 1, 1, 1, // Pairs of 2
	3, 3, 3, 3, 3, 3, 1, 1, 1, 1, // P-3
	1, 1, 1, 3, 3, 1, 1, 1, 1, 1, // P-4
	3, 3, 3, 3, 3, 3, 3, 3, 1, 1, // P-5
	3, 3, 3, 3, 3, 1, 1, 1, 1, 1, // P-6
	3, 3, 3, 3, 3, 3, 1, 1, 1, 1, // P-7
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, // P-8
	3, 3, 3, 3, 3, 2, 3, 3, 2, 2, // P-9
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // P-10
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 6 >2 cards
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 7 > 2 cards
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, // Val 8 > 2 cards
	1, 4, 4, 4, 4, 1, 1, 1, 1, 1, // Val 9 > 2 cards
	4, 4, 4, 4, 4, 4, 4, 4, 1, 1, // Val 10 > 2 cards
	4, 4, 4, 4, 4, 4, 4, 4, 4, 1, // Val 11 > 2 cards
	1, 1, 2, 2, 2, 1, 1, 1, 1, 1, // Val 12 > 2 cards
	2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 13 > 2 cards
	2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 14 > 2 cards
	2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 15 > 2 cards
	2, 2, 2, 2, 2, 1, 1, 1, 1, 1, // Val 16  > 2 cards
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 17 > 2 cards
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 18 > 2 cards
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 19 > 2 cards
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, // 20 > 2 cards
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2  // 21 > 2 cards
}; */

int moves[52][10][3] {
	// 2  3  4  5  6  7  8  9  10 A
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}},						// Val 5
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 6
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 7
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 8
	{{1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}}, // Val 9
	{{1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}},// Val 10
	{{1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}}, // Val 11
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 12
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}},		 				// Val 13
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 14
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 15
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 16
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}},					 	// 17
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// 18
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// 19
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// 20
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// 21
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // Pairs-A
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // A + 2
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // A + 3
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // A + 4
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // A + 5
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // A + 6
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // A + 7
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // A + 8
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // A + 9
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // A + 10
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // Pairs of 2
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // P-3
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // P-4
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // P-5
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // P-6
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // P-7
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // P-8
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // P-9
	{{1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}, {1,2,3}}, // P-10
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 6 >2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 7 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 8 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 9 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 10 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 11 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 12 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}},						// Val 13 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 14 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 15 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// Val 16  > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// 17 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// 18 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// 19 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}}, 					// 20 > 2 cards
	{{1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1,2}, {1, 2}}  					// 21 > 2 cards
};

Agent::Agent() : 
	agentValue(0),
	agentWins(0),
	agentCount(1),
	agentFlag(1)
{
	newStrat.clear();
	agentHands.resize(1);
	agentValues.resize(1);
	handHistory.resize(0);
	choiceHistory.resize(0);
}

void Agent::loadStrat()
{
	std::ifstream inFile("../Policy.txt");
	if (!inFile)
	{
		std::cerr << "Error reading File" << std::endl;
		newStrat.resize(52);
		for (int i = 0; i < 52; i++)
		{
			std::vector<StateInfo> stratRow(10);
			for (int j = 0; j < 10; j++)
			{
				StateInfo stateInfo;
				stateInfo.name = j + 2;
				for (int q = 0; q < 3; q++)
				{
				stateInfo.numActions[q] = moves[i][j][q];
				}
				for (int q = 0; q < 3; q++)
				{
				stateInfo.numVisits[q] = 0;
				}
				stateInfo.cardAction = 1;
				stateInfo.learnedStrat = 0;
				stratRow[j] = stateInfo;
			}
			newStrat[i] = stratRow;
		}
		return;
	}
	else
	{
		std::vector<std::vector<StateInfo>> matrix;
		std::string line;
		while (std::getline(inFile, line))
		{
			std::vector<StateInfo> row;
			std::istringstream iss(line);
			StateInfo element;
			while (iss >> element.name >> element.numActions[0] >> element.numActions[1]  >> element.numActions[2] >> element.numVisits[0] >> element.numVisits[1] >> element.numVisits[2] >> element.numVisits[3] >> element.cardAction >> element.learnedStrat >> element.Qvec[0] >> element.Qvec[1] >> element.Qvec[2] >> element.Qvec[3])
			{
				row.push_back(element);
				// ignore the delimiter between structs (3 spaces)
				iss.ignore(3, ' ');
			}
			matrix.push_back(row);
		}
		inFile.close();
		newStrat = matrix;
	}
}

void Agent::printStrat()
{
	for (int i = 0; i < newStrat.size(); i++)
	{
		for (int j = 0; j < newStrat[i].size(); j++)
		{
			printf("%d: ", i);
			printf("%d,", newStrat[i][j].name);
			for (int q = 0; q < 3; q++)
			{
			printf("%d,", newStrat[i][j].numActions[q]);
			}
			printf("%d,", newStrat[i][j].numVisits);
			printf("%d,", newStrat[i][j].cardAction);
			printf("%d,", newStrat[i][j].learnedStrat);
			printf("%f,", newStrat[i][j].Qvec[0]);
			printf("%f,", newStrat[i][j].Qvec[1]);
			printf("%f,", newStrat[i][j].Qvec[2]);
			printf("%f,", newStrat[i][j].Qvec[3]);
		}
		printf("\n");
	}
}

void Agent::printElement(int i, int j)
{
	printf("%d,", newStrat[i][j].numVisits[0]);
}

void Agent::updateVisits(int i, int j, int n)
{
	newStrat[i][j].numVisits[n] += 1;
}

void Agent::writeStrat()
{
	///printStrat();
	std::ofstream outFile("../Policy.txt");
	if (!outFile)
	{
		std::cerr << "Error writing File" << std::endl;
	}

	auto it = newStrat.begin();
	for (; it != newStrat.end(); ++it)
	{
		for (const auto &element : *it)
		{
			outFile << element.name << " " << element.numActions[0] << " " << element.numActions[1] << " " << element.numActions[2] << " " << element.numVisits[0] << " " << element.numVisits[1] << " " << element.numVisits[2] << " " << element.numVisits[3] << " " << element.cardAction << " " << element.learnedStrat << " " << element.Qvec[0] << " " << element.Qvec[1] << " " << element.Qvec[2] << " " << element.Qvec[3];
			outFile << " ";
		}
		outFile << std::endl;
	}
	outFile.close();
}

double Agent::takeTurn(CardDeck &cardDeck, Dealer &dealer, int handID)
{
    //printf("Agent(AI) Hand %d: AI is choosing...", handID + 1);
    int i = getChoice(cardDeck, dealer, handID);
	///handHistory.push_back(i);
    int action = getEpsilon(i); // i = getChoice(cardDeck, dealer, handID)%100 | j =getChoice(cardDeck, dealer, handID)/100
	updateVisits(i%100, i/100, action-1); //getEpsilon(i);
	choiceHistory.push_back(action);
    //std::cout << "AI chooses " << action  << " " << getChoice(cardDeck, dealer, handID) << ", AI has a value of " << getValue(handID) << std::endl;
    switch(action)
    {
    case 1:
        getCard(handID, dealer, cardDeck);
        if (getValue(handID) > 21)
        {
			///handHistory.push_back(i);
            //printf("AI Busted! \n \n");
            return 0;
        } else if(getValue(handID) == 21) {
			choiceHistory.push_back(2);
			return 1;
		} else {
            return 1;
			}
        break;
    case 2:
    {
        cardDeck.displayHand("AI", agentHands, handID);
        setPlayFlag(0);
        return 0;
        break;
    }
    case 3:
    {
        if (cardDeck.getCardName(agentHands[handID][0]) == cardDeck.getCardName(agentHands[handID][1]))
        {
            agentCount += 1;
            std::vector<int> hand2;
            int x = agentHands[handID][1];
            hand2.push_back(x);
            //
            agentHands.resize(agentCount);
            agentValues.resize(agentCount);
            agentHands[handID].erase(agentHands[handID].begin() + 1);
            agentHands[agentCount-1] = hand2;
            hand2.clear();
            getCard(handID, dealer, cardDeck);
            getCard(agentCount-1, dealer, cardDeck);
            agentValues[handID] = cardDeck.computePlayerValue(agentHands[handID]);
            agentValues[agentCount-1] = cardDeck.computePlayerValue(agentHands[agentCount-1]);
            cardDeck.displayHand("AI", agentHands, handID);
            cardDeck.displayHand("AI", agentHands, agentCount-1);
            return 0;
        }
        else
        {
			choiceHistory.pop_back();
            //std::cout << "Error: No matching cards; Unable to split; Choosing a random action. " << std::endl;
            //std::cout << std::endl;
            cardDeck.displayHand("AI", agentHands, 0);
            //std::cout << std::endl;
			return 0;
            break;
        }
        //std::cout << "--------------------------" << std::endl << std::endl;
		break;
    }
    case 4:
    {
        setPlayFlag(0);
        getCard(handID, dealer, cardDeck);
		choiceHistory.push_back(2);
        return 0;
        break;
    }
    default:
    {
	choiceHistory.pop_back();
    //std::cout << "AI has made an error, or something has gone wrong..." << std::endl;
    return 1;
    break;
    }
    }
}

void Agent::setPlayFlag(int flagValue)
{
    agentFlag = flagValue;
}

int Agent::getPlayFlag()
{
    return agentFlag;
}

void Agent::setHand(int handID, Strategy &strategy, Dealer &dealer, CardDeck &cardDeck)
{
    for (int j = 0; j < strategy.getNumCards(handID); j++)
    {
        agentHands[handID].push_back(strategy.getHand(handID, j));
    }
	agentValue = cardDeck.computePlayerValue(agentHands[handID]);
    agentValues[handID] = agentValue;
    cardDeck.displayHand("AI", agentHands, handID);
	handHistory.push_back(getChoice(cardDeck, dealer, handID));
}

void Agent::getCard(int handID, Dealer &dealer, CardDeck &cardDeck)
{
    int card = cardDeck.getStratCard();
	std::vector<int> x = agentHands[handID];
    x.push_back(card);
    agentValue = cardDeck.computePlayerValue(x);
    agentHands[handID] = x;
    agentValues[handID] = agentValue;
	if (getValue(handID) < 22){
		handHistory.push_back(getChoice(cardDeck, dealer, handID));
		}
    cardDeck.displayHand("AI", agentHands, handID);
}


int Agent::getValue(int handID)
{
    return agentValues[handID];
}

void Agent::displayHand(CardDeck &cardDeck, int handID)
{
    cardDeck.displayHand("AI", agentHands, handID);
}

int Agent::getDealerValue(Dealer &dealer)
{
    return dealer.getValue();
}

int Agent::getNumHands()
{
    return agentHands.size();
}


int Agent::getChoice(CardDeck &cardDeck, Dealer &dealer,int handID) 
{
    std::vector<int> hand = agentHands[handID];
    if (hand.size() > 2)
    {
        int x = getValue(handID) + 30 + ((dealer.getFaceValue(cardDeck)-2)* 100);
        return x;
    } else if (cardDeck.getCardName(hand[0]) == "A" || cardDeck.getCardName(hand[1]) == "A") 
    {  
        if (cardDeck.getCardName(hand[0]) == cardDeck.getCardName(hand[1]))
        {
            int x = 17 + ((dealer.getFaceValue(cardDeck)-2)* 100);
        }
        int x = getValue(handID) + 5 + ((dealer.getFaceValue(cardDeck)-2)* 100);
        return x;
    } else if (cardDeck.getCardName(hand[0]) == cardDeck.getCardName(hand[1])) 
    {
        int x = (getValue(handID)/2) + 25 + ((dealer.getFaceValue(cardDeck)-2)* 100);
        return x;
    } else 
    {
        int x = getValue(handID) - 5 + ((dealer.getFaceValue(cardDeck)-2)* 100);
        return x;
    }
}

void Agent::clearHand()
{
    agentHands.clear();
    agentHands.resize(1);
	handHistory.clear();
	choiceHistory.clear();
	handHistory.resize(0);
	choiceHistory.resize(0);
}

int Agent::getEpsilon(int x)
{
	std::random_device rd;
    auto seed = static_cast<unsigned long>(rd()) ^ static_cast<unsigned long>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::mt19937 rng(seed);
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	double y = dist(rng);
	if (y < newStrat[x%100][x/100].epsilon)
	{
		///printf("%f", y);
		std::vector<int> numbers(3);
		for (int i = 0; i < 3; i++) 
		{
			numbers[i] = newStrat[x%100][x/100].numActions[i];
		}
		std::random_device rand;
		std::mt19937 eng(rand());
		std::uniform_int_distribution<int> dist(0, 2);
		int random_index = dist(eng);
		int j = numbers[random_index];
		if (j == 0)
		{
			std::uniform_int_distribution<int> distr(0, 1);
			int random_index = distr(eng);
			return numbers[random_index];
		} else
			return numbers[random_index];
	} else {
		return qChoice(x);
	}
}

int Agent::qChoice(int x) 
{
	if (std::all_of(newStrat[x%100][x/100].Qvec, newStrat[x%100][x/100].Qvec + 4, [](int i) {return i = 0;})){
	for (int j = 0; j < 4; j ++)
	{
		newStrat[x%100][x/100].Qvec[j] /= newStrat[x%100][x/100].numVisits[j];
	}
	auto it = std::max_element(newStrat[x%100][x/100].Qvec, newStrat[x%100][x/100].Qvec + sizeof(newStrat[x%100][x/100].Qvec));
	newStrat[x%100][x/100].learnedStrat = std::distance(newStrat[x%100][x/100].Qvec, it);
	return newStrat[x%100][x/100].learnedStrat;
	} else {
		return newStrat[x%100][x/100].cardAction;
	}
}

void Agent::updateQ(int k) // 
{
	for (int q = 0; q < handHistory.size(); q++)
	{
		//printf("%d, ", handHistory[q]);
		//printf("%d, ", choiceHistory[q]);
		//printf("%f", newStrat[handHistory[q]%100][handHistory[q]/100].Qvec[choiceHistory[q]-1] += k);
		//printf("\n");
	}
	
}


void Agent::clearValues()
{
    agentValues.resize(1);
    agentValues.clear();
    agentValues.resize(1);
    agentCount = 1;
}
