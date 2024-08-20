
#include <iostream>

#include "Player.hpp"
#include "Agent.hpp"
#include "Dealer.hpp"
#include "Strategy.hpp"

int check;

void checkWin(int dealerFlag, int playerFlag, Player &player, Dealer &dealer, int handID)
{
 
	if (dealer.getValue() == 21)
	{
		if (player.getValue(handID) == 21)
		{
			std::cout << "Push" << std::endl;
            playerFlag = 0;
            dealerFlag = 0;
			dealer.setFlag(0);
			player.addToWallet(player.getBet(handID));
		}
		else
		{
			std::cout << "Dealer Wins" << std::endl;
			playerFlag = 0;
            dealerFlag = 0;
			dealer.setFlag(0);
		}
	}
	else if (player.getValue(handID) == 21)
		{
			std::cout << "Player wins!" << std::endl;
        	playerFlag = 0;
			dealerFlag = 1;
			dealer.setFlag(1);
			player.addToWallet(2*player.getBet(handID));
		}
    	else {
        	playerFlag = 0;
			dealerFlag = 1;   
			dealer.setFlag(1);
    	}
}

int summarizeResults(Dealer &dealer, Player &player, int handID)
{
    std::cout << std::endl;

		if (dealer.getValue() > 21)
		{
			if (player.getValue(handID) > 21)
            {
				std::cout << "Player busts, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;
                std::cout << "Player bet is " << player.getBet(handID) << std::endl;
				///player.addToWallet(2*player.getBet(handID));

                return -1;
            }
			else
            {
                std::cout << "Player wins, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;
				std::cout << "Player bet is " << player.getBet(handID) << std::endl;
				player.addToWallet(2*player.getBet(handID));
                return 1;
            }
		}
		else
		{
			if (player.getValue(handID) > 21)
			{
				std::cout << "Player Busts, Dealer Wins, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;
				std::cout << "Player bet is " << player.getBet(handID) << std::endl;
                return -1;
			}
			else
			{
				if (player.getValue(handID) == dealer.getValue())
				{
					std::cout << "PUSH, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;
					std::cout << "Player bet is " << player.getBet(handID) << std::endl;
					player.addToWallet(player.getBet(handID));

                    return 0;
				}
				else if (player.getValue(handID) > dealer.getValue())
				{
					std::cout << "Player Wins, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;
					std::cout << "Player bet is " << player.getBet(handID) << std::endl;
					player.addToWallet(2*player.getBet(handID));
                    return 1;
				}
                else
				{
					std::cout << "Dealer Wins, Player: " << player.getValue(handID) << " Dealer: " << dealer.getValue() << std::endl;
					std::cout << "Player bet is " << player.getBet(handID) << std::endl;
                    return -1;
				}
			}
		}
		
		std::cout << std::endl;
}


void checkStrat(Dealer &dealer, Strategy &strategy, int strategyFlag, int dealerFlag, int handID)
{
	std::cout << std::endl;

	if (dealer.getValue() == 21) 
	{
		if (strategy.getValue(handID) == 21)
		{
			strategyFlag = 0;
			dealerFlag = 0;
			dealer.setFlag(0);
		}
		else
		{
			std::cout << "Dealer beats Strategy" << std::endl;
			strategyFlag = 0;
			dealerFlag = 0;
			dealer.setFlag(0);
		}
	}
	else if (strategy.getValue(handID) == 21)
	{
		std::cout << "Strategy wins" << std::endl;
		strategyFlag = 0;
		dealerFlag = 0;
		dealer.setFlag(0);
	}
	else
	{
		strategyFlag = 0;
		dealerFlag = 1;
		dealer.setFlag(1);
	}
}

int summarizeStrategy (Dealer &dealer, Strategy &strategy, int handID)
{
	std::cout << std::endl;

	if (dealer.getValue() > 21)
	{
		if (strategy.getValue(handID) > 21)
		{
			std::cout << "Strategy busts..." << std::endl;
			return -1;
		}
		else
		{
			std::cout << "Strategy wins, Strategy value: " << strategy.getValue(handID) << std::endl;
			return 1;
		}
	}
	else
	{
		if (strategy.getValue(handID) > 21)
		{
			std::cout << "Strategy loses, Strategy value: " << strategy.getValue(handID) << std::endl;
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
				std::cout << "Strategy wins, Strategy value: " << strategy.getValue(handID) << std::endl;
				return 1;
			}
			else
			{
				std::cout << "Strategy loses, Strategy value: " << strategy.getValue(handID) << std::endl;
				return -1;
			}
		}
	}

	std::cout << std::endl;
}

int checkAgent (Dealer &dealer, Agent &agent, int agentFlag, int dealerFlag, int handID)
{
	std::cout << std::endl;
	check = 0;
	if (dealer.getValue() == 21) 
	{
		if (agent.getValue(handID) == 21)
		{
			agentFlag = 0;
			dealerFlag = 0;
			dealer.setFlag(0);
			check = 1;
			return 0;
		}
		else
		{
			std::cout << "Dealer beats AI" << std::endl;
			agentFlag = 0;
			dealerFlag = 0;
			dealer.setFlag(0);
			check = -1;
			return -1;
		}
	}
	else if (agent.getValue(handID) == 21)
	{
		std::cout << "AI wins" << std::endl;
		agentFlag = 0;
		dealerFlag = 0;
		dealer.setFlag(0);
		check = 2;
		return 0;
	}
	else
	{
		agentFlag = 0;
		dealerFlag = 1;
		dealer.setFlag(1);
		return 0;
	}
}

int summarizeAgent (Dealer &dealer, Agent &agent, int handID)
{
	if (check != 0) {
		switch(check){
		case -1:
		{
			return -1;
			break;
		}
		case 1:
		{
			return 0;
			break;
		}
		case 2:
		{
			return 1;
			break;
		}
		}
	} else {
	std::cout << std::endl;

	if (dealer.getValue() > 21)
	{
		if (agent.getValue(handID) > 21)
		{
			std::cout << "AI busts..." << std::endl;
			agent.updateQ(0);
			return -1;
		}
		else
		{
			std::cout << "AI wins, AI value: " << agent.getValue(handID) << std::endl;
			agent.updateQ(1);
			return 1;
		}
	}
	else
	{
		if (agent.getValue(handID) > 21)
		{
			std::cout << "AI loses, AI value: " << agent.getValue(handID) << std::endl;
			agent.updateQ(0);
			return -1;
		} 
		else
		{
			if (agent.getValue(handID) == dealer.getValue())
			{
				return 0;
			}
			else if (agent.getValue(handID) > dealer.getValue())
			{
				std::cout << "AI wins, AI value: " << agent.getValue(handID) << std::endl;
				agent.updateQ(1);	
				return 1;
			}
			else
			{
				std::cout << "AI loses, AI value: " << agent.getValue(handID) << std::endl;
				agent.updateQ(0);
				return -1;
			}
		}
	}

	std::cout << std::endl;
	}
}

