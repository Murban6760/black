//============================================================================
// Name        : BlackJack.cpp
// Author      : Matt Urban and Tom Urban
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

	Dealer dealer;

	bool playerContFlag = true;

	while (playerContFlag && cardDeck.getDeckCardCount() > 12)
	{
		std::vector<int> hand;
		player.insertHand(hand);
		player.insertValue(0);
		player.insertBet(0);

		round++;

		player.setPlayFlag(1);
		
		if (player.placeBet(0) <= 0){
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

		int playerFlag = 1;
		int dealerFlag = 1;

		checkWin(dealerFlag, playerFlag, player, dealer, 0);

		if (dealerFlag == 1 && playerFlag == 1)
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

		cout << "----------------------------------------------------------" << endl << endl;

		cout << endl;

		dealer.takeTurn(cardDeck);
		for (int j = 0; j < player.getNumHands(); j++){
			playerWins += summarizeResults(dealer, player, j);
		}
		cout << "Player Score: " << playerWins << " // " << "Player Wallet: "<< player.getPlayerWallet() << endl;
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
		}
		else 
		{
			playerContFlag = false;
		}
		
		cout << "----------------------------------------------------------" << endl << endl;

		std::cout << std::endl;
		player.betClear();
	}
	

	printf("Program over \n");
	return 0;
}