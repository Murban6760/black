
#include <iostream>

#include "Player.hpp"
#include "Dealer.hpp"
#include "Strategy.hpp"


void checkWin(int dealerFlag, int playerFlag, Player &player, Dealer &dealer, int handID)
{
 
	if (dealer.getValue() == 21)
	{
		if (player.getValue(handID) == 21)
		{
			std::cout << "Push" << std::endl;
            playerFlag = 0;
            dealerFlag = 0;
		}
		else
		{
			std::cout << "Dealer Wins" << std::endl;
			playerFlag = 0;
            dealerFlag = 0;
		}
	}
	else if (player.getValue(handID) == 21)
		{
			std::cout << "Player wins!" << std::endl;
        	playerFlag = 0;
			dealerFlag = 1;
		}
    	else {
        	playerFlag = 0;
			dealerFlag = 1;   
    	}
}

int summarizeResults(Dealer &dealer, Player &player, int handID)
{
    std::cout << std::endl;

		if (dealer.getValue() > 21)
		{
			if (player.getValue(handID) > 21)
            {
				std::cout << "PUSH: Player and Dealer Bust, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;
                
				player.addToWallet(player.getBet(handID));

                return 0;
            }
			else
            {
                std::cout << "Player wins, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;
				player.addToWallet(2*player.getBet(handID));
                return 1;
            }
		}
		else
		{
			if (player.getValue(handID) > 21)
			{
				std::cout << "Player Busts, Dealer Wins, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;

                return -1;
			}
			else
			{
				if (player.getValue(handID) == dealer.getValue())
				{
					std::cout << "PUSH, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;
					player.addToWallet(player.getBet(handID));

                    return 0;
				}
				else if (player.getValue(handID) > dealer.getValue())
				{
					std::cout << "Players Wins, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;
					player.addToWallet(2*player.getBet(handID));
                    return 1;
				}
                else
				{
					std::cout << "Dealer Wins, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;

                    return -1;
				}
			}
		}
		
		std::cout << std::endl;
}


void checkAgent (Dealer &dealer, Strategy &strategy, int strategyFlag, int dealerFlag, int handID)
{
	std::cout << std::endl;

	if (dealer.getValue() == 21) 
	{
		if (strategy.getValue(handID) == 21)
		{
			strategyFlag = 0;
			dealerFlag = 0;
		}
		else
		{
			std::cout << "Dealer beats Agent" << std::endl;
			strategyFlag = 0;
			dealerFlag = 0;
		}
	}
	else if (strategy.getValue(handID) == 21)
	{
		std::cout << "Agent wins" << std::endl;
		strategyFlag = 0;
		dealerFlag = 0;
	}
	else
	{
		strategyFlag = 0;
		dealerFlag = 1;
	}
}

int summarizeAgent (Dealer &dealer, Strategy &strategy, int handID)
{
	std::cout << std::endl;

	if (dealer.getValue() > 21)
	{
		if (strategy.getValue(handID) > 21)
		{
			std::cout << "PUSH: agent and dealer bust..." << std::endl;
			return 0;
		}
		else
		{
			std::cout << "Agent wins" << std::endl;
			return 1;
		}
	}
	else
	{
		if (strategy.getValue(handID) > 21)
		{
			return -1;
		} 
		else
		{
			if (strategy.getValue(handID) == dealer.getValue())
			{
				return 0;
			}
			else if (strategy.getValue(handID) > dealer.getValue())
			{
				return 1;
			}
			else
			{
				return -1;
			}
		}
	}

	std::cout << std::endl;
}
