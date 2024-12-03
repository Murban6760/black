#include "Agent.hpp"
#include <cmath>
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
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}},						// Val 5
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 6
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 7
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 8
	{{1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}}, // Val 9
	{{1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}},// Val 10
	{{1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}, {1,2,4}}, // Val 11
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 12
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}},		 				// Val 13
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 14
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 15
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 16
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}},					 	// 17
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// 18
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// 19
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// 20
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// 21
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
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 6 >2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 7 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 8 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 9 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 10 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 11 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 12 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}},						// Val 13 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 14 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 15 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// Val 16  > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// 17 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// 18 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// 19 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}, 					// 20 > 2 cards
	{{1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}, {1,2,0}}  					// 21 > 2 cards
};

Agent::Agent() : 
	agentValue(0),
	agentWins(0),
	agentCount(1),
	agentFlag(1),
	Q(-1)
	///,
	///seed(static_cast<unsigned long>(rd()) ^ static_cast<unsigned long>(std::chrono::high_resolution_clock::now().time_since_epoch().count()))
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
		std::cerr << "Error reading File. Creating new file in its place." << std::endl;
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
			for (int q = 0; q < 4; q++){
			printf("%d,", newStrat[i][j].numVisits[q]);
			}
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

int Agent::agCard()
{
	return agentCard;
}

double Agent::takeTurn(CardDeck &cardDeck, Dealer &dealer, int handID, int rounds)
{
    //printf("Agent(AI) Hand %d: AI is choosing...", handID + 1);
    agentCard = getChoice(cardDeck, dealer, handID);
	///handHistory.push_back(i);
    int action = getEpsilon(agentCard, rounds); // i = getChoice(cardDeck, dealer, handID)%100 | j =getChoice(cardDeck, dealer, handID)/100
	//std::cout << action << "  action-1 " << action-1 << std::endl;
	updateVisits(agentCard%100, agentCard/100, action-1); //
	//std::cout << "Checkpoint TT1\n";
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

int Agent::getEpsilon(int x, int rounds)
{
	/// Problem was that epsilon got sooo tiny that it was impossible to explore, thus it never learned... Solidifying threshold at .2
	newStrat[x%100][x/100].epsilon = .4;
	std::random_device rd;
	seed = static_cast<unsigned long>(rd()) ^ static_cast<unsigned long>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::mt19937 rng(seed);
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	double y = dist(rng);
	/// Debug purposes ->    std::cout << "Got Here\n" << y << " is y and next is epsilon: " << newStrat[x%100][x/100].epsilon << std::endl << std::endl;
	if (y < newStrat[x%100][x/100].epsilon)
	{
		///printf("%f", y);
		std::vector<int> numbers(3);
		for (int i = 0; i < 3; i++) 
		{
			numbers[i] = newStrat[x%100][x/100].numActions[i];
			 /// Debug Purposes ->    std::cout << numbers[i] << std::endl;
		}
		std::random_device rand;
		std::mt19937 eng(rand());
		std::uniform_int_distribution<int> dist(0, 2);
		int randomr_index = dist(rng);
		int j = numbers[randomr_index];
		if (j == 0)
		{
			std::uniform_int_distribution<int> distr(0, 1);
			int random_index = distr(rng);
			//std::cout << "Checkpoint 2 " << random_index << "\n";
			Q = random_index;
			return numbers[random_index];
		} else
			Q = randomr_index;
			//std::cout << "Checkpoint 3 " << randomr_index << "\n";
			//std::cout << "Checkpoint 3.1, numbers[index] = " << numbers[randomr_index] << std::endl;
			return numbers[randomr_index];
	} else {
		return qChoice(x);
	}
}

void Agent::updateVisits(int i, int j, int n)
{
	//std::cout << "CheckpointUV1\n";
	newStrat[i][j].numVisits[n] += 1;
	//std::cout << "CheckpointUV2\n";
}

int Agent::qChoice(int x) // Below if statement almost never runs
{
	if (std::all_of(newStrat[x%100][x/100].Qvec, newStrat[x%100][x/100].Qvec + 4, [](int i) {return i = 0;})){
	for (int j = 0; j < 4; j ++)
	{
		newStrat[x%100][x/100].Qvec[j] /= newStrat[x%100][x/100].numVisits[j];
	}
	//std::cout << "No errors here\n";
	auto it = std::max_element(newStrat[x%100][x/100].Qvec, newStrat[x%100][x/100].Qvec + sizeof(newStrat[x%100][x/100].Qvec));
	newStrat[x%100][x/100].learnedStrat = std::distance(newStrat[x%100][x/100].Qvec, it);
	return newStrat[x%100][x/100].learnedStrat;
	} else {
		return newStrat[x%100][x/100].cardAction;
	}
}

int Agent::getQ()
{
	return Q;
}

void Agent::updateQ(int x, int k) // 
{
	//std::cout << "Checkpoint 1\n";
	//std::cout << x << "  is x, and this is k > " << k << std::endl;
	//std::cout << "This is the qvec slot " << newStrat[x%100][x/100].Qvec[k] << std::endl;
	newStrat[x%100][x/100].Qvec[k]++;
	//std::cout << "Checkpoint Q2\n";
}


void Agent::clearValues()
{
    agentValues.resize(1);
    agentValues.clear();
    agentValues.resize(1);
    agentCount = 1;
}
