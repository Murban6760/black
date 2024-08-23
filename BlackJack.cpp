//============================================================================
// Name        : BlackJack.cpp
// Author      : Matt Urban
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <random>
#include <map>

#include <cstdio>
#include <cstdlib>

#include "BlackJackGame.hpp"
#include "CardDeck.hpp"
#include "Dealer.hpp"
#include "Agent.hpp"
#include "Strategy.hpp"


using namespace std;

int main()
{


	cout << endl << "Good Luck Players..." << endl << endl;

	int iMax = 52;

	// Define & initialize card deck

	CardDeck cardDeck;
	cardDeck.shuffleDeck();

	int card;
	int round = 0;

	Strategy strategy;
	int strategyWins = 0;

	Dealer dealer;

	Agent agent;
	int agentWins = 0;
	agent.loadStrat();
	//agent.printStrat();


	while ((round < 1000) && cardDeck.getDeckCardCount() > 12)
	{
		std::vector<int> hand;
		strategy.insertHand(hand);
		round++;

		strategy.setPlayFlag(1);
		agent.setPlayFlag(1);
		dealer.setFlag(1);

		strategy.getCard(0, cardDeck);
		dealer.getCard(cardDeck);


		cout << "----------------------------------------------------------" << endl << endl;

		strategy.getCard(0, cardDeck);
		dealer.getCard(cardDeck);
		agent.setHand(0, strategy, dealer, cardDeck);


		int dealerFlag = 1;
		int strategyFlag = 1;
		int agentFlag = 1;

		///checkWin(dealerFlag, playerFlag, player, dealer, 0);
		checkStrat(dealer, strategy, strategyFlag, dealerFlag, 0);
		checkAgent(dealer, agent, agentFlag, dealerFlag, 0);

		/* Player Actions
		if (dealer.getFlag() == 1 && playerFlag == 1)
		{
			for (int j = 0; j < player.getNumHands(); j++)
			{
				player.setPlayFlag(1);
				while (player.getPlayFlag() && player.getValue(j) < 21)
				{
					if (player.getNumHands() > 1){
						player.displayHand(cardDeck, j);
					}
					int addBet = player.takeTurn(cardDeck, j);
					bet += addBet;
				}
			}
			cout << endl
				 << endl;
		} */
		// Summarizing for Strategy win
		if (dealer.getFlag() == 1 && strategyFlag == 1)
		{
			for (int j = 0; j < strategy.getNumHands(); j++)
			{
				strategy.setPlayFlag(1);
				while (strategy.getPlayFlag() == 1 && strategy.getValue(j) < 21)
				{
					strategy.takeTurn(cardDeck, dealer, j);
				}
			}
			cout << endl
				 << endl;
		}

		//displaying Strategy hands
		for(int j = 0; j < strategy.getNumHands(); j++){
		if (strategy.getNumHands() > 1){
						strategy.displayHand(cardDeck, j);
					}
		}

		// Agent turn
		if (dealer.getFlag() == 1 && agentFlag == 1)
		{
			for (int j = 0; j < agent.getNumHands(); j++)
			{
				agent.setPlayFlag(1);
				while (agent.getPlayFlag() == 1 && agent.getValue(j) < 21)
				{
					agent.takeTurn(cardDeck, dealer, j);
				}
			}
			cout << endl
				 << endl;
		}

		//displaying Agent hands
		for(int j = 0; j < agent.getNumHands(); j++){
		if (agent.getNumHands() > 1){
						agent.displayHand(cardDeck, j);
					}
		}
		/// Turns ^

		cout << "----------------------------------------------------------" << endl << endl;

		cout << endl;

		dealer.takeTurn(cardDeck);
		/*for (int j = 0; j < player.getNumHands(); j++){
			playerWins += summarizeResults(dealer, player, j);
		} */
		for (int j = 0; j < strategy.getNumHands(); j++){
			strategyWins += summarizeStrategy(dealer, strategy, j);
		}
		for (int j = 0; j < agent.getNumHands(); j++){
			agentWins += summarizeAgent(dealer, agent, j);
		}
		///cout << "Player Score: " << playerWins << " // " << "Player Wallet: "<< player.getPlayerWallet() << endl;
		cout << "Strategy Score: " << strategyWins << " // " << endl;
		cout << "AI Score: " << agentWins << " // " << endl;
		cout << "No. of Cards Used: " <<  cardDeck.getCardCount() << " Remaining Cards: " << cardDeck.getDeckCardCount() << endl << endl;
		
		cout << "----------------------------------------------------------" << endl << endl;

			dealer.clearHand();
			strategy.clearHand();
			strategy.clearValues();
			agent.clearValues();
			agent.clearHand();
			cardDeck.setInverseCount();
		cout << "----------------------------------------------------------" << endl << endl;

		std::cout << std::endl;
		if (cardDeck.getDeckCardCount() <= 12)
		{
			cardDeck.shuffleDeck();
		}
	}
	
	agent.writeStrat();
	printf("After %d rounds, the program is over.\n", round);
	printf("Program over \n");
	return 0;
}
