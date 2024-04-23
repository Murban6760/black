#include "Player.hpp"

#include <iostream>

Player::Player():
    wallet(100.0),
    bet(0.0),
    value(0),
    playFlag(1),
    splitCount(0),
    playerWins(0)
{}

double Player::getPlayerWallet() 
{
    return wallet;
}

double Player::placeBet(int handID) 
{
    bets[handID] = 5;
    if ((wallet - bets[handID]) < 0){
        return 0;
    } else{
    wallet -= bets[handID];

    return bets[handID];
    }
}

double Player::getBet(int handID)
{
    return bets[handID];
}


double Player::getBet()
{
    double x = 0;
    for (int j = 0; j < bets.size(); j++){
        x += bets[j];
    }

    return x;
}

double Player::betDown(int handID)
{
    if ((wallet - bets[handID]) == 0) 
    {
        return 0;
    } else {
    wallet -= bets[handID];
    bets[handID] *= 2;

    return bets[handID];
    }
}

int Player::getPlayFlag()
{
    return playFlag;
}

void Player::setPlayFlag(int flagValue) 
{
    playFlag = flagValue;
}

void Player::addToWallet(double money)
{

    wallet += money;

}

void Player::getCard(int handID, CardDeck &cardDeck)
{
    int card = cardDeck.getCard();
	std::vector<int> x = hands[handID];
    x.push_back(card);
    value = cardDeck.computePlayerValue(x);
    hands[handID] = x;
    values[handID] = value;
    cardDeck.displayHand("Player", hands, handID);
}

void Player::displayHand(CardDeck &cardDeck, int handID)
{
   cardDeck.displayHand("Player", hands, handID);
}

double Player::takeTurn(CardDeck &cardDeck, int handID)
{

    printf("Player Hand %d: Hit (1) / Check (2) / Split (3) / Double Down (4): ", handID + 1);
    fflush(stdout);

    int playerAction;
    scanf("%d", &playerAction);

    std::cout << std::endl;

    if (getValue(handID) < 22){
    switch (playerAction) {
    case 1:
    {
        getCard(handID, cardDeck);

        if (getValue(handID) >= 22)
        {
            printf("Player Busted! \n \n");
            
            return 0;
        }
        else 
            return 1;
        break;
    } 
    case 2:
    {

        cardDeck.displayHand("Player", hands, handID);
        setPlayFlag(0);

        return 0;
        break;
    }
    case 3:
    {
        if (cardDeck.getCardName(hands[handID][0]) == cardDeck.getCardName(hands[handID][1]))
        {
            splitCount += 1;
            std::vector<int> hand2;
            int x = hands[handID][1];
            int y = getValue(handID)/2;
            wallet -= getBet();
            bets.push_back(getBet());
            /* This writes the values in each hand, used for debugging.
            for (int j = 0; j < bets.size(); j++)
            {
                std::cout << bets[j] << std::endl;
            }
            */
            hand2.push_back(x);
            hands[handID].erase(hands[handID].begin() + 1);
            hands.push_back(hand2);
            hand2.clear();
            values[handID] = y;
            values.push_back(y);
            cardDeck.displayHand("Player", hands, 1);
            return 0;
        }
        else
        {
            std::cout << "Error: No matching cards; Unable to split. " << std::endl;
            std::cout << std::endl;
            cardDeck.displayHand("Player", hands, 0);
            std::cout << std::endl;
            return 0;
        }
        std::cout << "--------------------------" << std::endl << std::endl;
        break;
    }
    case 4:
    {
        if ((wallet - bets[handID]) <= 0) 
        {
            std::cout << "Unable to complete action, not enough money in wallet. Wallet is now " << getPlayerWallet() << std::endl << std::endl;

        } else {
        std::cout << "Player Doubled Down. Bet is now " << betDown(handID) << ". Wallet is now " << Player::getPlayerWallet() << std::endl;
        getCard(handID, cardDeck);

        return 0;
        }
        break;
    }
    default:
    {
    std::cout << "Wrong Key Dummy" << std::endl;
    return 1;
    break;
         }
     }
    }
}

void Player::clearHand()
{
    hands.clear();
}

int Player::getValue(int handID)
{
    return values[handID];
} 

int Player::getNumHands()
{
    return hands.size();
}

void Player::insertHand(std::vector<int> &hand) 
{
    hands.push_back(hand);
}

void Player::insertValue(int value)
{
    values.push_back(value);
}

void Player::insertBet(double value)
{
    bets.push_back(value);
}

void Player::betClear()
{
    bets.clear();
}

int Player::getHand(int handID, int index)
{
    return hands[handID][index];
}

int Player::getNumCards(int handID)
{
    return hands[handID].size();
}

void Player::clearValues()
{
    values.clear();
}