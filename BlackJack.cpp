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
#include "Player.hpp"
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

	/// Initialize Player and dealer

	Player player;
	int playerWins = 0;

	double bet;

	Strategy strategy;
	int strategyWins = 0;

	Dealer dealer;

	Agent agent;
	int agentWins = 0;
	agent.loadStrat();
	//agent.printStrat();

	bool playerContFlag = true;

	while (playerContFlag && cardDeck.getDeckCardCount() > 12)
	{
		std::vector<int> hand;
		player.insertHand(hand);
		player.insertValue(0);
		player.insertBet(0);

		round++;

		player.setPlayFlag(1);
		strategy.setPlayFlag(1);
		agent.setPlayFlag(1);
		dealer.setFlag(1);

		if (player.initBet(0) <= 0){
			cout << "You ran out of money!" << endl;
			break;
		} else {
			bet = player.placeBet(0);
		}

		player.getCard(0, cardDeck);
		dealer.getCard(cardDeck);


		cout << "----------------------------------------------------------" << endl << endl;

		player.getCard(0, cardDeck);
		dealer.getCard(cardDeck);
		strategy.setHand(0, player, cardDeck);
		agent.setHand(0, player, dealer, cardDeck);


		int playerFlag = 1;
		int dealerFlag = 1;
		int strategyFlag = 1;
		int agentFlag = 1;

		checkWin(dealerFlag, playerFlag, player, dealer, 0);
		checkStrat(dealer, strategy, strategyFlag, dealerFlag, 0);
		checkAgent(dealer, agent, agentFlag, dealerFlag, 0);

		/// Player Actions
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
		}
		// Summarizing for Agent win
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
		for (int j = 0; j < player.getNumHands(); j++){
			playerWins += summarizeResults(dealer, player, j);
		}
		for (int j = 0; j < strategy.getNumHands(); j++){
			strategyWins += summarizeStrategy(dealer, strategy, j);
		}
		for (int j = 0; j < agent.getNumHands(); j++){
			agentWins += summarizeAgent(dealer, agent, j);
		}
		cout << "Player Score: " << playerWins << " // " << "Player Wallet: "<< player.getPlayerWallet() << endl;
		cout << "Strategy Score: " << strategyWins << " // " << endl;
		cout << "AI Score: " << agentWins << " // " << endl;
		cout << "No. of Cards Used: " <<  cardDeck.getCardCount() << " Remaining Cards: " << cardDeck.getDeckCardCount() << endl << endl;
		
		cout << "----------------------------------------------------------" << endl << endl;

		int playerContInput;
		printf("Player Continue: (1) Yes, (2) No: ");
		fflush(stdout);
		scanf("%d", &playerContInput);

		if (playerContInput == 1)
		{
			playerContFlag = true;
			player.clearHand();
			dealer.clearHand();
			strategy.clearHand();
			player.clearValues();
			strategy.clearValues();
			agent.clearValues();
			agent.clearHand();
			cardDeck.setInverseCount();
		}
		else 
		{
			playerContFlag = false;
		}
		
		cout << "----------------------------------------------------------" << endl << endl;

		std::cout << std::endl;
		player.betClear();
	}
	
	agent.writeStrat();
	printf("Program over \n");
	return 0;
}
